EESchema Schematic File Version 2
LIBS:troll-8-rescue
LIBS:power
LIBS:device
LIBS:transistors
LIBS:conn
LIBS:linear
LIBS:regul
LIBS:74xx
LIBS:cmos4000
LIBS:adc-dac
LIBS:memory
LIBS:xilinx
LIBS:microcontrollers
LIBS:dsp
LIBS:microchip
LIBS:analog_switches
LIBS:motorola
LIBS:texas
LIBS:intel
LIBS:audio
LIBS:interface
LIBS:digital-audio
LIBS:philips
LIBS:display
LIBS:cypress
LIBS:siliconi
LIBS:opto
LIBS:atmel
LIBS:contrib
LIBS:valves
LIBS:troll-8-lib
LIBS:ad1938-audio-card-lib
LIBS:arduino
LIBS:troll-8-cache
EELAYER 25 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 2 6
Title "CTAG Troll 8"
Date "2015-12-29"
Rev "Rev. A"
Comp "www.creative-technologies.de"
Comment1 ""
Comment2 ""
Comment3 "International License"
Comment4 "Licensed under a Creative Commons Attribution-NonCommercial-ShareAlike 4.0 "
$EndDescr
$Comp
L Keyboard-16 U203
U 1 1 567FD9D8
P 4100 3150
F 0 "U203" H 4050 3750 60  0000 C CNN
F 1 "Keyboard-16" V 3750 3350 60  0000 C CNN
F 2 "troll-8-footprints:midi-keyboard-16" H 4100 3150 60  0001 C CNN
F 3 "" H 4100 3150 60  0000 C CNN
	1    4100 3150
	0    -1   1    0   
$EndComp
$Comp
L +3.3V #PWR017
U 1 1 567FDBE6
P 7500 750
F 0 "#PWR017" H 7500 600 50  0001 C CNN
F 1 "+3.3V" H 7500 890 50  0000 C CNN
F 2 "" H 7500 750 50  0000 C CNN
F 3 "" H 7500 750 50  0000 C CNN
	1    7500 750 
	1    0    0    -1  
$EndComp
$Comp
L C C201
U 1 1 567FDC29
P 7850 950
F 0 "C201" H 7875 1050 50  0000 L CNN
F 1 "100n" H 7875 850 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603_HandSoldering" H 7888 800 50  0001 C CNN
F 3 "" H 7850 950 50  0000 C CNN
	1    7850 950 
	0    1    1    0   
$EndComp
$Comp
L GND #PWR018
U 1 1 567FDCB7
P 8100 1050
F 0 "#PWR018" H 8100 800 50  0001 C CNN
F 1 "GND" H 8100 900 50  0000 C CNN
F 2 "" H 8100 1050 50  0000 C CNN
F 3 "" H 8100 1050 50  0000 C CNN
	1    8100 1050
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR019
U 1 1 567FDD58
P 7500 3300
F 0 "#PWR019" H 7500 3050 50  0001 C CNN
F 1 "GND" H 7500 3150 50  0000 C CNN
F 2 "" H 7500 3300 50  0000 C CNN
F 3 "" H 7500 3300 50  0000 C CNN
	1    7500 3300
	1    0    0    -1  
$EndComp
$Comp
L LED-RESCUE-troll-8 D201
U 1 1 567FE27C
P 8350 1650
AR Path="/567FE27C" Ref="D201"  Part="1" 
AR Path="/567FD8D1/567FE27C" Ref="D201"  Part="1" 
F 0 "D201" H 8600 1700 50  0000 C CNN
F 1 "LED" H 8100 1700 50  0000 C CNN
F 2 "LEDs:LED-0603" H 8350 1650 50  0001 C CNN
F 3 "" H 8350 1650 50  0000 C CNN
	1    8350 1650
	1    0    0    -1  
$EndComp
Wire Wire Line
	7500 750  7500 1050
Wire Wire Line
	7700 950  7500 950 
Connection ~ 7500 950 
Wire Wire Line
	8100 950  8100 1050
$Comp
L LED-RESCUE-troll-8 D202
U 1 1 567FE9CA
P 8350 1750
AR Path="/567FE9CA" Ref="D202"  Part="1" 
AR Path="/567FD8D1/567FE9CA" Ref="D202"  Part="1" 
F 0 "D202" H 8600 1800 50  0000 C CNN
F 1 "LED" H 8100 1800 50  0000 C CNN
F 2 "LEDs:LED-0603" H 8350 1750 50  0001 C CNN
F 3 "" H 8350 1750 50  0000 C CNN
	1    8350 1750
	1    0    0    -1  
$EndComp
$Comp
L LED-RESCUE-troll-8 D203
U 1 1 567FE9EC
P 8350 1850
AR Path="/567FE9EC" Ref="D203"  Part="1" 
AR Path="/567FD8D1/567FE9EC" Ref="D203"  Part="1" 
F 0 "D203" H 8600 1900 50  0000 C CNN
F 1 "LED" H 8100 1900 50  0000 C CNN
F 2 "LEDs:LED-0603" H 8350 1850 50  0001 C CNN
F 3 "" H 8350 1850 50  0000 C CNN
	1    8350 1850
	1    0    0    -1  
$EndComp
$Comp
L LED-RESCUE-troll-8 D204
U 1 1 567FEA11
P 8350 1950
AR Path="/567FEA11" Ref="D204"  Part="1" 
AR Path="/567FD8D1/567FEA11" Ref="D204"  Part="1" 
F 0 "D204" H 8600 2000 50  0000 C CNN
F 1 "LED" H 8100 2000 50  0000 C CNN
F 2 "LEDs:LED-0603" H 8350 1950 50  0001 C CNN
F 3 "" H 8350 1950 50  0000 C CNN
	1    8350 1950
	1    0    0    -1  
$EndComp
$Comp
L LED-RESCUE-troll-8 D205
U 1 1 567FEA39
P 8350 2050
AR Path="/567FEA39" Ref="D205"  Part="1" 
AR Path="/567FD8D1/567FEA39" Ref="D205"  Part="1" 
F 0 "D205" H 8600 2100 50  0000 C CNN
F 1 "LED" H 8100 2100 50  0000 C CNN
F 2 "LEDs:LED-0603" H 8350 2050 50  0001 C CNN
F 3 "" H 8350 2050 50  0000 C CNN
	1    8350 2050
	1    0    0    -1  
$EndComp
$Comp
L LED-RESCUE-troll-8 D206
U 1 1 567FEA64
P 8350 2150
AR Path="/567FEA64" Ref="D206"  Part="1" 
AR Path="/567FD8D1/567FEA64" Ref="D206"  Part="1" 
F 0 "D206" H 8600 2200 50  0000 C CNN
F 1 "LED" H 8100 2200 50  0000 C CNN
F 2 "LEDs:LED-0603" H 8350 2150 50  0001 C CNN
F 3 "" H 8350 2150 50  0000 C CNN
	1    8350 2150
	1    0    0    -1  
$EndComp
$Comp
L LED-RESCUE-troll-8 D207
U 1 1 567FEA92
P 8350 2250
AR Path="/567FEA92" Ref="D207"  Part="1" 
AR Path="/567FD8D1/567FEA92" Ref="D207"  Part="1" 
F 0 "D207" H 8600 2300 50  0000 C CNN
F 1 "LED" H 8100 2300 50  0000 C CNN
F 2 "LEDs:LED-0603" H 8350 2250 50  0001 C CNN
F 3 "" H 8350 2250 50  0000 C CNN
	1    8350 2250
	1    0    0    -1  
$EndComp
$Comp
L LED-RESCUE-troll-8 D208
U 1 1 567FEAC3
P 8350 2350
AR Path="/567FEAC3" Ref="D208"  Part="1" 
AR Path="/567FD8D1/567FEAC3" Ref="D208"  Part="1" 
F 0 "D208" H 8600 2400 50  0000 C CNN
F 1 "LED" H 8100 2400 50  0000 C CNN
F 2 "LEDs:LED-0603" H 8350 2350 50  0001 C CNN
F 3 "" H 8350 2350 50  0000 C CNN
	1    8350 2350
	1    0    0    -1  
$EndComp
Wire Wire Line
	8550 1650 8800 1650
Wire Wire Line
	8550 1750 8800 1750
Wire Wire Line
	8550 1850 8800 1850
Wire Wire Line
	8550 1950 8800 1950
Wire Wire Line
	8550 2050 9700 2050
Wire Wire Line
	8550 2150 9800 2150
Wire Wire Line
	8550 2250 9900 2250
Wire Wire Line
	8550 2350 10000 2350
Wire Wire Line
	8000 1650 8150 1650
Wire Wire Line
	8000 1750 8150 1750
Wire Wire Line
	8000 1850 8150 1850
Wire Wire Line
	8000 1950 8150 1950
Wire Wire Line
	8000 2050 8150 2050
Wire Wire Line
	8000 2150 8150 2150
Wire Wire Line
	8000 2250 8150 2250
Wire Wire Line
	8000 2350 8150 2350
Wire Wire Line
	7500 3300 7500 3100
$Comp
L +3.3V #PWR020
U 1 1 568002DF
P 7500 3750
F 0 "#PWR020" H 7500 3600 50  0001 C CNN
F 1 "+3.3V" H 7500 3890 50  0000 C CNN
F 2 "" H 7500 3750 50  0000 C CNN
F 3 "" H 7500 3750 50  0000 C CNN
	1    7500 3750
	1    0    0    -1  
$EndComp
$Comp
L C C202
U 1 1 568002E5
P 7850 3950
F 0 "C202" H 7875 4050 50  0000 L CNN
F 1 "100n" H 7875 3850 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603_HandSoldering" H 7888 3800 50  0001 C CNN
F 3 "" H 7850 3950 50  0000 C CNN
	1    7850 3950
	0    1    1    0   
$EndComp
$Comp
L GND #PWR021
U 1 1 568002EB
P 8100 4050
F 0 "#PWR021" H 8100 3800 50  0001 C CNN
F 1 "GND" H 8100 3900 50  0000 C CNN
F 2 "" H 8100 4050 50  0000 C CNN
F 3 "" H 8100 4050 50  0000 C CNN
	1    8100 4050
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR022
U 1 1 568002F1
P 7500 6300
F 0 "#PWR022" H 7500 6050 50  0001 C CNN
F 1 "GND" H 7500 6150 50  0000 C CNN
F 2 "" H 7500 6300 50  0000 C CNN
F 3 "" H 7500 6300 50  0000 C CNN
	1    7500 6300
	1    0    0    -1  
$EndComp
$Comp
L LED-RESCUE-troll-8 D209
U 1 1 568002FD
P 8350 4650
AR Path="/568002FD" Ref="D209"  Part="1" 
AR Path="/567FD8D1/568002FD" Ref="D209"  Part="1" 
F 0 "D209" H 8600 4700 50  0000 C CNN
F 1 "LED" H 8100 4700 50  0000 C CNN
F 2 "LEDs:LED-0603" H 8350 4650 50  0001 C CNN
F 3 "" H 8350 4650 50  0000 C CNN
	1    8350 4650
	1    0    0    -1  
$EndComp
Wire Wire Line
	7500 3750 7500 4050
Wire Wire Line
	7700 3950 7500 3950
Connection ~ 7500 3950
Wire Wire Line
	8100 3950 8100 4050
$Comp
L LED-RESCUE-troll-8 D210
U 1 1 5680030B
P 8350 4750
AR Path="/5680030B" Ref="D210"  Part="1" 
AR Path="/567FD8D1/5680030B" Ref="D210"  Part="1" 
F 0 "D210" H 8600 4800 50  0000 C CNN
F 1 "LED" H 8100 4800 50  0000 C CNN
F 2 "LEDs:LED-0603" H 8350 4750 50  0001 C CNN
F 3 "" H 8350 4750 50  0000 C CNN
	1    8350 4750
	1    0    0    -1  
$EndComp
$Comp
L LED-RESCUE-troll-8 D211
U 1 1 56800311
P 8350 4850
AR Path="/56800311" Ref="D211"  Part="1" 
AR Path="/567FD8D1/56800311" Ref="D211"  Part="1" 
F 0 "D211" H 8600 4900 50  0000 C CNN
F 1 "LED" H 8100 4900 50  0000 C CNN
F 2 "LEDs:LED-0603" H 8350 4850 50  0001 C CNN
F 3 "" H 8350 4850 50  0000 C CNN
	1    8350 4850
	1    0    0    -1  
$EndComp
$Comp
L LED-RESCUE-troll-8 D212
U 1 1 56800317
P 8350 4950
AR Path="/56800317" Ref="D212"  Part="1" 
AR Path="/567FD8D1/56800317" Ref="D212"  Part="1" 
F 0 "D212" H 8600 5000 50  0000 C CNN
F 1 "LED" H 8100 5000 50  0000 C CNN
F 2 "LEDs:LED-0603" H 8350 4950 50  0001 C CNN
F 3 "" H 8350 4950 50  0000 C CNN
	1    8350 4950
	1    0    0    -1  
$EndComp
$Comp
L LED-RESCUE-troll-8 D213
U 1 1 5680031D
P 8350 5050
AR Path="/5680031D" Ref="D213"  Part="1" 
AR Path="/567FD8D1/5680031D" Ref="D213"  Part="1" 
F 0 "D213" H 8600 5100 50  0000 C CNN
F 1 "LED" H 8100 5100 50  0000 C CNN
F 2 "LEDs:LED-0603" H 8350 5050 50  0001 C CNN
F 3 "" H 8350 5050 50  0000 C CNN
	1    8350 5050
	1    0    0    -1  
$EndComp
$Comp
L LED-RESCUE-troll-8 D214
U 1 1 56800323
P 8350 5150
AR Path="/56800323" Ref="D214"  Part="1" 
AR Path="/567FD8D1/56800323" Ref="D214"  Part="1" 
F 0 "D214" H 8600 5200 50  0000 C CNN
F 1 "LED" H 8100 5200 50  0000 C CNN
F 2 "LEDs:LED-0603" H 8350 5150 50  0001 C CNN
F 3 "" H 8350 5150 50  0000 C CNN
	1    8350 5150
	1    0    0    -1  
$EndComp
$Comp
L LED-RESCUE-troll-8 D215
U 1 1 56800329
P 8350 5250
AR Path="/56800329" Ref="D215"  Part="1" 
AR Path="/567FD8D1/56800329" Ref="D215"  Part="1" 
F 0 "D215" H 8600 5300 50  0000 C CNN
F 1 "LED" H 8100 5300 50  0000 C CNN
F 2 "LEDs:LED-0603" H 8350 5250 50  0001 C CNN
F 3 "" H 8350 5250 50  0000 C CNN
	1    8350 5250
	1    0    0    -1  
$EndComp
$Comp
L LED-RESCUE-troll-8 D216
U 1 1 5680032F
P 8350 5350
AR Path="/5680032F" Ref="D216"  Part="1" 
AR Path="/567FD8D1/5680032F" Ref="D216"  Part="1" 
F 0 "D216" H 8600 5400 50  0000 C CNN
F 1 "LED" H 8100 5400 50  0000 C CNN
F 2 "LEDs:LED-0603" H 8350 5350 50  0001 C CNN
F 3 "" H 8350 5350 50  0000 C CNN
	1    8350 5350
	1    0    0    -1  
$EndComp
Wire Wire Line
	8550 4650 8800 4650
Wire Wire Line
	8550 4750 8800 4750
Wire Wire Line
	8550 4850 8800 4850
Wire Wire Line
	8550 4950 8800 4950
Wire Wire Line
	8550 5050 9650 5050
Wire Wire Line
	8550 5150 9700 5150
Wire Wire Line
	8550 5250 9750 5250
Wire Wire Line
	8550 5350 9800 5350
Wire Wire Line
	8000 4650 8150 4650
Wire Wire Line
	8000 4750 8150 4750
Wire Wire Line
	8000 4850 8150 4850
Wire Wire Line
	8000 4950 8150 4950
Wire Wire Line
	8000 5050 8150 5050
Wire Wire Line
	8000 5150 8150 5150
Wire Wire Line
	8000 5250 8150 5250
Wire Wire Line
	8000 5350 8150 5350
Wire Wire Line
	7500 6300 7500 6100
Wire Bus Line
	6400 2000 6400 2700
Wire Bus Line
	6400 2550 3050 2550
Wire Bus Line
	3050 2550 3050 4650
Wire Bus Line
	4600 2550 4600 5100
Wire Bus Line
	4600 5100 6400 5100
Wire Bus Line
	6400 5000 6400 5700
Entry Wire Line
	6400 2100 6500 2200
Entry Wire Line
	6400 2000 6500 2100
Entry Wire Line
	6400 2300 6500 2400
Entry Wire Line
	6400 2200 6500 2300
Entry Wire Line
	6400 2400 6500 2500
Entry Wire Line
	6400 2500 6500 2600
Entry Wire Line
	6400 2600 6500 2700
Entry Wire Line
	6400 2700 6500 2800
Wire Wire Line
	6500 2100 6750 2100
Wire Wire Line
	6500 2200 6750 2200
Wire Wire Line
	6500 2300 6750 2300
Wire Wire Line
	6500 2400 6750 2400
Wire Wire Line
	6500 2500 6750 2500
Wire Wire Line
	6500 2600 6750 2600
Wire Wire Line
	6500 2700 6750 2700
Wire Wire Line
	6500 2800 6750 2800
Text Label 5100 2550 0    60   ~ 0
CS[1..16]
Entry Wire Line
	6400 5000 6500 5100
Entry Wire Line
	6400 5100 6500 5200
Entry Wire Line
	6400 5200 6500 5300
Entry Wire Line
	6400 5300 6500 5400
Entry Wire Line
	6400 5400 6500 5500
Entry Wire Line
	6400 5500 6500 5600
Entry Wire Line
	6400 5600 6500 5700
Entry Wire Line
	6400 5700 6500 5800
Wire Wire Line
	6500 5100 6750 5100
Wire Wire Line
	6500 5200 6750 5200
Wire Wire Line
	6500 5300 6750 5300
Wire Wire Line
	6500 5400 6750 5400
Wire Wire Line
	6500 5500 6750 5500
Wire Wire Line
	6500 5600 6750 5600
Wire Wire Line
	6500 5700 6750 5700
Wire Wire Line
	6500 5800 6750 5800
Text Label 6500 2100 0    60   ~ 0
CS1
Text Label 6500 2200 0    60   ~ 0
CS2
Text Label 6500 2300 0    60   ~ 0
CS3
Text Label 6500 2400 0    60   ~ 0
CS4
Text Label 6500 2500 0    60   ~ 0
CS5
Text Label 6500 2600 0    60   ~ 0
CS6
Text Label 6500 2700 0    60   ~ 0
CS7
Text Label 6500 2800 0    60   ~ 0
CS8
Text Label 6500 5100 0    60   ~ 0
CS9
Text Label 6500 5200 0    60   ~ 0
CS10
Text Label 6500 5300 0    60   ~ 0
CS11
Text Label 6500 5400 0    60   ~ 0
CS12
Text Label 6500 5500 0    60   ~ 0
CS13
Text Label 6500 5600 0    60   ~ 0
CS14
Text Label 6500 5700 0    60   ~ 0
CS15
Text Label 6500 5800 0    60   ~ 0
CS16
Entry Wire Line
	4500 3050 4600 2950
Entry Wire Line
	4500 3250 4600 3150
Entry Wire Line
	4500 3450 4600 3350
Entry Wire Line
	4500 3650 4600 3550
Entry Wire Line
	4500 3850 4600 3750
Entry Wire Line
	4500 4050 4600 3950
Entry Wire Line
	4500 4250 4600 4150
Entry Wire Line
	4500 4450 4600 4350
Entry Wire Line
	4500 4650 4600 4550
Entry Wire Line
	4500 4850 4600 4750
Entry Wire Line
	3050 3250 3150 3350
Entry Wire Line
	3050 3450 3150 3550
Entry Wire Line
	3050 3850 3150 3950
Entry Wire Line
	3050 4050 3150 4150
Entry Wire Line
	3050 4250 3150 4350
Entry Wire Line
	3050 4650 3150 4750
Wire Wire Line
	3150 3350 3300 3350
Wire Wire Line
	3300 3550 3150 3550
Wire Wire Line
	3150 3950 3300 3950
Wire Wire Line
	3150 4350 3300 4350
Wire Wire Line
	3300 4150 3150 4150
Wire Wire Line
	3150 4750 3300 4750
Wire Wire Line
	4500 3050 4300 3050
Wire Wire Line
	4500 3250 4300 3250
Wire Wire Line
	4300 3450 4500 3450
Wire Wire Line
	4500 3650 4300 3650
Wire Wire Line
	4300 3850 4500 3850
Wire Wire Line
	4500 4050 4300 4050
Wire Wire Line
	4500 4250 4300 4250
Wire Wire Line
	4300 4450 4500 4450
Wire Wire Line
	4500 4650 4300 4650
Wire Wire Line
	4300 4850 4500 4850
Text Label 4300 3050 0    60   ~ 0
CS1
Text Label 4300 3250 0    60   ~ 0
CS2
Text Label 3150 3350 0    60   ~ 0
CS3
Text Label 4300 3450 0    60   ~ 0
CS4
Text Label 3150 3550 0    60   ~ 0
CS5
Text Label 4300 3650 0    60   ~ 0
CS6
Text Label 4300 3850 0    60   ~ 0
CS7
Text Label 3150 3950 0    60   ~ 0
CS8
Text Label 4300 4050 0    60   ~ 0
CS9
Text Label 3150 4150 0    60   ~ 0
CS10
Text Label 4300 4250 0    60   ~ 0
CS11
Text Label 3150 4350 0    60   ~ 0
CS12
Text Label 4300 4450 0    60   ~ 0
CS13
Text Label 4300 4650 0    60   ~ 0
CS14
Text Label 3150 4750 0    60   ~ 0
CS15
Text Label 4300 4850 0    60   ~ 0
CS16
Wire Wire Line
	6050 800  6050 4500
Wire Wire Line
	6050 4500 6750 4500
Connection ~ 6050 1500
Text HLabel 5600 1400 0    60   Input ~ 0
RESET
Wire Wire Line
	5600 1400 6750 1400
Wire Wire Line
	6150 1400 6150 4400
Wire Wire Line
	6150 4400 6750 4400
Connection ~ 6150 1400
Text HLabel 5600 1650 0    60   Input ~ 0
SPI_CS_CS1
Text HLabel 5600 1750 0    60   Input ~ 0
SPI_MOSI
Text HLabel 5600 1850 0    60   Output ~ 0
SPI_MISO
Text HLabel 5600 1950 0    60   Input ~ 0
SPI_CLK
Wire Wire Line
	5600 1650 6750 1650
Wire Wire Line
	5600 1750 6750 1750
Wire Wire Line
	5600 1850 6750 1850
Wire Wire Line
	6750 1950 5600 1950
Wire Wire Line
	5950 1750 5950 4750
Wire Wire Line
	5950 4750 6750 4750
Connection ~ 5950 1750
Wire Wire Line
	5600 4650 6750 4650
Wire Wire Line
	5850 1850 5850 4850
Wire Wire Line
	5850 4850 6750 4850
Connection ~ 5850 1850
Text HLabel 5600 4650 0    60   Input ~ 0
SPI_CS_CS2
Wire Wire Line
	5750 1950 5750 4950
Wire Wire Line
	5750 4950 6750 4950
Connection ~ 5750 1950
Wire Wire Line
	6750 1500 6050 1500
$Comp
L GND #PWR023
U 1 1 56805DEE
P 5700 900
F 0 "#PWR023" H 5700 650 50  0001 C CNN
F 1 "GND" H 5700 750 50  0000 C CNN
F 2 "" H 5700 900 50  0000 C CNN
F 3 "" H 5700 900 50  0000 C CNN
	1    5700 900 
	1    0    0    -1  
$EndComp
Wire Wire Line
	5700 800  6050 800 
Wire Wire Line
	5700 800  5700 900 
$Comp
L R R201
U 1 1 56812328
P 6300 3000
F 0 "R201" V 6380 3000 50  0000 C CNN
F 1 "10k" V 6300 3000 50  0000 C CNN
F 2 "Resistors_SMD:R_0603_HandSoldering" V 6230 3000 50  0001 C CNN
F 3 "" H 6300 3000 50  0000 C CNN
	1    6300 3000
	1    0    0    -1  
$EndComp
Wire Wire Line
	6300 3150 6300 3200
Wire Wire Line
	6300 3200 7500 3200
Connection ~ 7500 3200
Wire Wire Line
	6300 2850 6300 1400
Connection ~ 6300 1400
$Comp
L EXBA10P-RES U204
U 1 1 5687ABB0
P 9000 5000
F 0 "U204" H 9050 5550 60  0000 C CNN
F 1 "EXBA10P-RES" H 9250 4950 60  0000 C CNN
F 2 "troll-8-footprints:EXBA10P" V 9000 5050 60  0001 C CNN
F 3 "" V 9000 5050 60  0000 C CNN
	1    9000 5000
	1    0    0    -1  
$EndComp
Wire Wire Line
	9650 5050 9650 4850
Wire Wire Line
	9650 4850 9550 4850
Wire Wire Line
	9700 5150 9700 4750
Wire Wire Line
	9700 4750 9550 4750
Wire Wire Line
	9750 5250 9750 4650
Wire Wire Line
	9750 4650 9550 4650
Wire Wire Line
	9800 5350 9800 4550
Wire Wire Line
	9800 4550 9550 4550
$Comp
L EXBA10P-RES U201
U 1 1 5687B3B0
P 9000 2000
F 0 "U201" H 9050 2550 60  0000 C CNN
F 1 "EXBA10P-RES" H 9250 1950 60  0000 C CNN
F 2 "troll-8-footprints:EXBA10P" V 9000 2050 60  0001 C CNN
F 3 "" V 9000 2050 60  0000 C CNN
	1    9000 2000
	1    0    0    -1  
$EndComp
Wire Wire Line
	9700 2050 9700 1850
Wire Wire Line
	9700 1850 9550 1850
Wire Wire Line
	9800 2150 9800 1750
Wire Wire Line
	9800 1750 9550 1750
Wire Wire Line
	9900 2250 9900 1650
Wire Wire Line
	9900 1650 9550 1650
Wire Wire Line
	10000 2350 10000 1550
Wire Wire Line
	10000 1550 9550 1550
Wire Wire Line
	8100 950  8000 950 
Wire Wire Line
	8750 800  8750 1550
Wire Wire Line
	8750 1550 8800 1550
Wire Wire Line
	10100 800  10100 1950
Wire Wire Line
	10100 1950 9550 1950
Wire Wire Line
	8000 3950 8100 3950
Wire Wire Line
	7500 3850 9850 3850
Wire Wire Line
	8750 3850 8750 4550
Wire Wire Line
	8750 4550 8800 4550
Connection ~ 7500 3850
Wire Wire Line
	9850 3850 9850 4950
Wire Wire Line
	9850 4950 9550 4950
Connection ~ 8750 3850
Wire Wire Line
	7500 800  10100 800 
Connection ~ 7500 800 
Text HLabel 10100 2500 2    60   Output ~ 0
INT
Wire Wire Line
	10100 2500 8000 2500
Wire Wire Line
	8000 5500 9950 5500
Wire Wire Line
	9950 5500 9950 2500
Connection ~ 9950 2500
$Comp
L CAP1188 U205
U 1 1 5683BD6A
P 6950 5400
F 0 "U205" H 7000 6650 60  0000 C CNN
F 1 "CAP1188" H 7400 5200 60  0000 C CNN
F 2 "Housings_DFN_QFN:QFN-24-1EP_4x4mm_Pitch0.5mm" H 6950 5250 60  0001 C CNN
F 3 "" H 6950 5250 60  0000 C CNN
	1    6950 5400
	1    0    0    -1  
$EndComp
$Comp
L CAP1188 U202
U 1 1 5683BF2C
P 6950 2400
F 0 "U202" H 7000 3650 60  0000 C CNN
F 1 "CAP1188" H 7400 2200 60  0000 C CNN
F 2 "Housings_DFN_QFN:QFN-24-1EP_4x4mm_Pitch0.5mm" H 6950 2250 60  0001 C CNN
F 3 "" H 6950 2250 60  0000 C CNN
	1    6950 2400
	1    0    0    -1  
$EndComp
Connection ~ 8750 800 
$EndSCHEMATC
