# Flash client with automatic resampling for Troll8
# Duration of inputfile should be integers (in seconds)
#
# Dependencies:
# - pyserial (pip install pyserial)
# - Python Audio Tools (http://audiotools.sourceforge.net/install.html)

import struct
import sys
import getopt
import wave
import audioop
import array
import serial


def ByteToHex( byteStr ):
    """
    Convert a byte string to it's hex string representation e.g. for output.
    """  

    return ''.join( [ "%02X " % ord( x ) for x in byteStr ] ).strip()

def HexToByte( hexStr ):
    """
    Convert a string hex byte values into a byte string. The Hex Byte values may
    or may not be space separated.
    """
 
    bytes = []

    hexStr = ''.join( hexStr.split(" ") )

    for i in range(0, len(hexStr), 2):
        bytes.append( chr( int (hexStr[i:i+2], 16 ) ) )

    return ''.join( bytes )

def main(argv):

    # Resample wavfile
    TARGET_SAMPLERATE = 16384
    inputfile = ''
    comport = ''
    address = 0
    erase = 0

    try:
        opts, args = getopt.getopt(argv, "hi:p:a:e:", ["ifile=", "port=", "address=", "erase"])
    except getopt.GetoptError:
        print 'client.py -i <inputfile> -p <comport> -a address'
        sys.exit(2)
    for opt, arg in opts:
        if opt == '-h':
            print 'client.py -i <inputfile> -p <comport>'
            sys.exit()
        elif opt in ("-i", "--ifile"):
            inputfile = arg
        elif opt in ("-p", "--port"):
            comport = arg
        elif opt in ("-a", "--address"):
            address = int(arg)
        elif opt in ("-e", "--erase"):
            erase = 1


    print 'Loading', inputfile, '...'
    infile = wave.open(inputfile, 'rb')
    length = infile.getnframes()
    duration = infile.getframerate()/length
    print 'Duration: ', duration, 's'
    print 'Samplingrate: ', infile.getframerate()
    audiodata = infile.readframes(length)
    infile.close()
    if infile.getnchannels() == 2:
        audiodata_n = audioop.ratecv(audiodata, 2, 2, infile.getframerate(), TARGET_SAMPLERATE, None)
    else:
        audiodata_n = audioop.ratecv(audiodata, 2, 1, infile.getframerate(), TARGET_SAMPLERATE, None)
    if infile.getnchannels() == 2:
        audiodata_n = audioop.tomono(audiodata_n[0], 2, 0.5, 0.5)
    audiodata_n = audioop.lin2lin(audiodata_n, 2, 1)
    audiodata_n = audioop.bias(audiodata_n, 1, 128)
    byte_data = bytearray(audiodata_n)

    outfile = wave.open('Outfile.wav', 'wb')
    outfile.setparams((1, 1, TARGET_SAMPLERATE, 0, 'NONE', 'not compressed'))
    outfile.writeframes(audiodata_n)
    outfile.close()

    # Convert datasize (int) to 4 bytes
    data_size = bytearray(4) 
    data_size[0] = (len(byte_data)>>24) & 0xff
    data_size[1] = (len(byte_data)>>16) & 0xff
    data_size[2] = (len(byte_data)>>8) & 0xff
    data_size[3] = len(byte_data) & 0xff

    # Convert address (int) to 4 bytes
    address_bytes = bytearray(4)
    address_bytes[0] = (address>>24) & 0xff
    address_bytes[1] = (address>>16) & 0xff
    address_bytes[2] = (address>>8) & 0xff
    address_bytes[3] = address & 0xff

    # Transfer wavfile
    serialport = serial.Serial(comport, 9600, timeout=1)
    if erase:
        serialport.write(bytearray('\x02')) # Erase Flash
    #    success = serialport.read()
    #    if !success:
    #        print 'Failed to write to flash (try --erase)'
    serialport.write(bytearray('\x01')) # Write request
    serialport.write(data_size) # Data size
    serialport.write(address_bytes) # Address
    print 'Tranfering audio file...'
    serialport.write(byte_data)
    print 'Success!'
    serialport.close()

if __name__ == "__main__":
    main(sys.argv[1:])

