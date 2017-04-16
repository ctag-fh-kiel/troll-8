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
Sheet 1 6
Title "CTAG TROLL8"
Date "2015-12-29"
Rev "Rev. A"
Comp "robert.manzke@fh-kiel.de"
Comment1 "www.creative-technologies.de"
Comment2 ""
Comment3 "International License"
Comment4 "Licensed under a Creative Commons Attribution-NonCommercial-ShareAlike 4.0 "
$EndDescr
$Comp
L Hole H101
U 1 1 567FC54A
P 1150 5500
F 0 "H101" H 1000 5750 60  0000 C CNN
F 1 "Hole" H 1150 5550 60  0000 C CNN
F 2 "modules:Hole_3mm" H 1150 5500 60  0001 C CNN
F 3 "" H 1150 5500 60  0000 C CNN
	1    1150 5500
	1    0    0    -1  
$EndComp
$Comp
L Hole H102
U 1 1 567FC617
P 1600 5500
F 0 "H102" H 1450 5750 60  0000 C CNN
F 1 "Hole" H 1600 5550 60  0000 C CNN
F 2 "modules:Hole_3mm" H 1600 5500 60  0001 C CNN
F 3 "" H 1600 5500 60  0000 C CNN
	1    1600 5500
	1    0    0    -1  
$EndComp
$Comp
L Hole H103
U 1 1 567FC6F4
P 1150 5950
F 0 "H103" H 1000 6200 60  0000 C CNN
F 1 "Hole" H 1150 6000 60  0000 C CNN
F 2 "modules:Hole_3mm" H 1150 5950 60  0001 C CNN
F 3 "" H 1150 5950 60  0000 C CNN
	1    1150 5950
	1    0    0    -1  
$EndComp
$Comp
L Hole H104
U 1 1 567FC73C
P 1600 5950
F 0 "H104" H 1450 6200 60  0000 C CNN
F 1 "Hole" H 1600 6000 60  0000 C CNN
F 2 "modules:Hole_3mm" H 1600 5950 60  0001 C CNN
F 3 "" H 1600 5950 60  0000 C CNN
	1    1600 5950
	1    0    0    -1  
$EndComp
$Sheet
S 9300 1800 1000 1000
U 567FD8D1
F0 "touch-keyboard" 60
F1 "touch-keyboard.sch" 60
F2 "RESET" I L 9300 1950 60 
F3 "SPI_CS_CS1" I L 9300 2050 60 
F4 "SPI_MOSI" I L 9300 2250 60 
F5 "SPI_MISO" O L 9300 2350 60 
F6 "SPI_CLK" I L 9300 2450 60 
F7 "SPI_CS_CS2" I L 9300 2150 60 
F8 "INT" O L 9300 2550 60 
$EndSheet
$Sheet
S 4100 750  650  450 
U 5680714F
F0 "power" 60
F1 "power.sch" 60
F2 "PWR_GOOD" O L 4100 1000 60 
F3 "VIN" O L 4100 900 60 
$EndSheet
$Sheet
S 9300 3000 1000 700 
U 5680716E
F0 "adc-potis" 60
F1 "adc-potis.sch" 60
F2 "SPI_CLK" I L 9300 3550 60 
F3 "SPI_MOSI" I L 9300 3350 60 
F4 "SPI_MISO" O L 9300 3450 60 
F5 "SPI_CS" I L 9300 3100 60 
$EndSheet
$Sheet
S 9300 3900 1000 700 
U 568071CD
F0 "fram-ram" 60
F1 "fram-ram.sch" 60
F2 "SPI_MOSI" I L 9300 4250 60 
F3 "SPI_MISO" O L 9300 4350 60 
F4 "SPI_CLK" I L 9300 4450 60 
F5 "SPI_CS1" I L 9300 4050 60 
F6 "SPI_CS2" I L 9300 4150 60 
$EndSheet
$Sheet
S 9300 4800 1000 700 
U 56815DD7
F0 "GPIO" 60
F1 "GPIO.sch" 60
F2 "SPI_MOSI" I L 9300 5100 60 
F3 "SPI_CLK" I L 9300 5300 60 
F4 "RESET" I L 9300 5400 60 
F5 "SPI_MISO" O L 9300 5200 60 
F6 "SPI_CS7" I L 9300 4900 60 
F7 "INT" O L 9300 5000 60 
$EndSheet
$Comp
L 74LS138 U102
U 1 1 568227E6
P 6400 2400
F 0 "U102" H 6500 2900 50  0000 C CNN
F 1 "74LVC138" H 6550 1851 50  0000 C CNN
F 2 "Housings_SSOP:TSSOP-16_4.4x5mm_Pitch0.65mm" H 6400 2400 50  0001 C CNN
F 3 "" H 6400 2400 50  0000 C CNN
	1    6400 2400
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR01
U 1 1 5682483B
P 5650 2900
F 0 "#PWR01" H 5650 2650 50  0001 C CNN
F 1 "GND" H 5650 2750 50  0000 C CNN
F 2 "" H 5650 2900 50  0000 C CNN
F 3 "" H 5650 2900 50  0000 C CNN
	1    5650 2900
	1    0    0    -1  
$EndComp
$Comp
L +3.3V #PWR02
U 1 1 568282A4
P 5650 2500
F 0 "#PWR02" H 5650 2350 50  0001 C CNN
F 1 "+3.3V" H 5650 2640 50  0000 C CNN
F 2 "" H 5650 2500 50  0000 C CNN
F 3 "" H 5650 2500 50  0000 C CNN
	1    5650 2500
	1    0    0    -1  
$EndComp
Text Label 5350 2650 0    60   ~ 0
SPI_CS
Text Label 8850 2450 0    60   ~ 0
SPI_CLK
Text Label 8850 2350 0    60   ~ 0
SPI_MISO
Text Label 8850 2250 0    60   ~ 0
SPI_MOSI
Text Label 8850 3550 0    60   ~ 0
SPI_CLK
Text Label 8850 3450 0    60   ~ 0
SPI_MISO
Text Label 8850 3350 0    60   ~ 0
SPI_MOSI
Text Label 8850 4450 0    60   ~ 0
SPI_CLK
Text Label 8850 4350 0    60   ~ 0
SPI_MISO
Text Label 8850 4250 0    60   ~ 0
SPI_MOSI
Text Label 8850 5300 0    60   ~ 0
SPI_CLK
Text Label 8850 5200 0    60   ~ 0
SPI_MISO
Text Label 8850 5100 0    60   ~ 0
SPI_MOSI
Text Label 5350 2050 0    60   ~ 0
A0
Text Label 5350 2150 0    60   ~ 0
A1
Text Label 5350 2250 0    60   ~ 0
A2
$Comp
L R R102
U 1 1 5682D534
P 3400 5200
F 0 "R102" V 3480 5200 50  0000 C CNN
F 1 "270" V 3400 5200 50  0000 C CNN
F 2 "Resistors_SMD:R_0603_HandSoldering" V 3330 5200 50  0001 C CNN
F 3 "" H 3400 5200 50  0000 C CNN
	1    3400 5200
	0    1    1    0   
$EndComp
$Comp
L R R103
U 1 1 5682D672
P 4100 5200
F 0 "R103" V 4180 5200 50  0000 C CNN
F 1 "680" V 4100 5200 50  0000 C CNN
F 2 "Resistors_SMD:R_0603_HandSoldering" V 4030 5200 50  0001 C CNN
F 3 "" H 4100 5200 50  0000 C CNN
	1    4100 5200
	0    1    1    0   
$EndComp
$Comp
L R R104
U 1 1 5682D798
P 4700 5200
F 0 "R104" V 4780 5200 50  0000 C CNN
F 1 "680" V 4700 5200 50  0000 C CNN
F 2 "Resistors_SMD:R_0603_HandSoldering" V 4630 5200 50  0001 C CNN
F 3 "" H 4700 5200 50  0000 C CNN
	1    4700 5200
	0    1    1    0   
$EndComp
$Comp
L R R105
U 1 1 5682D895
P 4400 6350
F 0 "R105" V 4480 6350 50  0000 C CNN
F 1 "330" V 4400 6350 50  0000 C CNN
F 2 "Resistors_SMD:R_0603_HandSoldering" V 4330 6350 50  0001 C CNN
F 3 "" H 4400 6350 50  0000 C CNN
	1    4400 6350
	-1   0    0    1   
$EndComp
$Comp
L C C103
U 1 1 5682D985
P 3650 5550
F 0 "C103" H 3675 5650 50  0000 L CNN
F 1 "100n" H 3675 5450 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603_HandSoldering" H 3688 5400 50  0001 C CNN
F 3 "" H 3650 5550 50  0000 C CNN
	1    3650 5550
	-1   0    0    1   
$EndComp
$Comp
L C C104
U 1 1 5682DCA3
P 4400 5550
F 0 "C104" H 4425 5650 50  0000 L CNN
F 1 "220n" H 4425 5450 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603_HandSoldering" H 4438 5400 50  0001 C CNN
F 3 "" H 4400 5550 50  0000 C CNN
	1    4400 5550
	-1   0    0    1   
$EndComp
$Comp
L GND #PWR03
U 1 1 5682E4D4
P 4400 5750
F 0 "#PWR03" H 4400 5500 50  0001 C CNN
F 1 "GND" H 4400 5600 50  0000 C CNN
F 2 "" H 4400 5750 50  0000 C CNN
F 3 "" H 4400 5750 50  0000 C CNN
	1    4400 5750
	1    0    0    -1  
$EndComp
$Comp
L C C105
U 1 1 5682E62D
P 4100 6000
F 0 "C105" H 4125 6100 50  0000 L CNN
F 1 "220n" H 4125 5900 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603_HandSoldering" H 4138 5850 50  0001 C CNN
F 3 "" H 4100 6000 50  0000 C CNN
	1    4100 6000
	0    1    1    0   
$EndComp
$Comp
L C C106
U 1 1 5682EF27
P 4700 6000
F 0 "C106" H 4725 6100 50  0000 L CNN
F 1 "1n" H 4725 5900 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603_HandSoldering" H 4738 5850 50  0001 C CNN
F 3 "" H 4700 6000 50  0000 C CNN
	1    4700 6000
	0    1    1    0   
$EndComp
$Comp
L GND #PWR04
U 1 1 5682F323
P 4400 6600
F 0 "#PWR04" H 4400 6350 50  0001 C CNN
F 1 "GND" H 4400 6450 50  0000 C CNN
F 2 "" H 4400 6600 50  0000 C CNN
F 3 "" H 4400 6600 50  0000 C CNN
	1    4400 6600
	1    0    0    -1  
$EndComp
$Comp
L TRS-3 P104
U 1 1 5682F819
P 6000 5000
F 0 "P104" H 6100 5000 60  0000 C CNN
F 1 "Audio Out" H 6200 4600 60  0000 C CNN
F 2 "modules:LUM150302" H 6000 5000 60  0001 C CNN
F 3 "" H 6000 5000 60  0000 C CNN
	1    6000 5000
	-1   0    0    -1  
$EndComp
Text Label 2800 5200 0    60   ~ 0
PWM_OUT
Text Label 2300 2200 0    60   ~ 0
PWM_OUT
Text Label 4600 2250 2    60   ~ 0
A2
Text Label 4600 2350 2    60   ~ 0
A1
Text Label 4600 2450 2    60   ~ 0
A0
Text Label 2300 2100 0    60   ~ 0
SPI_CS
Text Label 850  2150 0    60   ~ 0
SPI_MOSI
Text Label 2300 1900 0    60   ~ 0
SPI_MISO
Text Label 850  1800 0    60   ~ 0
SPI_CLK
$Comp
L GND #PWR05
U 1 1 56829ADE
P 3450 4150
F 0 "#PWR05" H 3450 3900 50  0001 C CNN
F 1 "GND" H 3450 4000 50  0000 C CNN
F 2 "" H 3450 4150 50  0000 C CNN
F 3 "" H 3450 4150 50  0000 C CNN
	1    3450 4150
	1    0    0    -1  
$EndComp
$Comp
L arduino_mini U103
U 1 1 56825B8D
P 3450 2450
F 0 "U103" H 3950 1500 70  0000 C CNN
F 1 "arduino_nano" H 3450 1450 70  0000 C CNN
F 2 "arduino:arduino_mini" H 3450 1350 60  0001 C CNN
F 3 "" H 3450 2450 60  0000 C CNN
	1    3450 2450
	-1   0    0    -1  
$EndComp
$Comp
L Jumper_NC_Small JP101
U 1 1 568479E5
P 4500 2850
F 0 "JP101" H 4650 2900 50  0000 C CNN
F 1 "Jumper_NC_Small" H 4510 2790 50  0001 C CNN
F 2 "Resistors_SMD:R_0603_HandSoldering" H 4500 2850 50  0001 C CNN
F 3 "" H 4500 2850 50  0000 C CNN
	1    4500 2850
	1    0    0    -1  
$EndComp
$Comp
L Jumper_NC_Small JP102
U 1 1 56847B70
P 4500 2950
F 0 "JP102" H 4650 3000 50  0000 C CNN
F 1 "Jumper_NC_Small" H 4510 2890 50  0001 C CNN
F 2 "Resistors_SMD:R_0603_HandSoldering" H 4500 2950 50  0001 C CNN
F 3 "" H 4500 2950 50  0000 C CNN
	1    4500 2950
	1    0    0    -1  
$EndComp
Text Label 7300 1700 0    60   ~ 0
RESET_CS
Text Label 7000 5400 0    60   ~ 0
RESET_GPIO
$Comp
L 4050 U101
U 5 1 5684B127
P 8000 5400
F 0 "U101" H 8195 5515 50  0000 C CNN
F 1 "4050" H 8190 5275 50  0000 C CNN
F 2 "Housings_SSOP:TSSOP-16_4.4x5mm_Pitch0.65mm" H 8000 5400 60  0001 C CNN
F 3 "" H 8000 5400 60  0000 C CNN
	5    8000 5400
	1    0    0    -1  
$EndComp
$Comp
L 4050 U101
U 1 1 5684B61A
P 8350 1700
F 0 "U101" H 8545 1815 50  0000 C CNN
F 1 "4050" H 8540 1575 50  0000 C CNN
F 2 "Housings_SSOP:TSSOP-16_4.4x5mm_Pitch0.65mm" H 8350 1700 60  0001 C CNN
F 3 "" H 8350 1700 60  0000 C CNN
	1    8350 1700
	1    0    0    -1  
$EndComp
$Comp
L 4050 U101
U 2 1 5684B9E2
P 1700 1800
F 0 "U101" H 1895 1915 50  0000 C CNN
F 1 "4050" H 1890 1675 50  0000 C CNN
F 2 "Housings_SSOP:TSSOP-16_4.4x5mm_Pitch0.65mm" H 1700 1800 60  0001 C CNN
F 3 "" H 1700 1800 60  0000 C CNN
	2    1700 1800
	-1   0    0    -1  
$EndComp
$Comp
L 4050 U101
U 3 1 5684BE56
P 1700 2150
F 0 "U101" H 1895 2265 50  0000 C CNN
F 1 "4050" H 1890 2025 50  0000 C CNN
F 2 "Housings_SSOP:TSSOP-16_4.4x5mm_Pitch0.65mm" H 1700 2150 60  0001 C CNN
F 3 "" H 1700 2150 60  0000 C CNN
	3    1700 2150
	-1   0    0    -1  
$EndComp
$Comp
L C C101
U 1 1 56851820
P 8550 1200
F 0 "C101" H 8575 1300 50  0000 L CNN
F 1 "100n" H 8575 1100 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603_HandSoldering" H 8588 1050 50  0001 C CNN
F 3 "" H 8550 1200 50  0000 C CNN
	1    8550 1200
	0    1    1    0   
$EndComp
$Comp
L GND #PWR06
U 1 1 5685260C
P 8300 1850
F 0 "#PWR06" H 8300 1600 50  0001 C CNN
F 1 "GND" H 8300 1700 50  0000 C CNN
F 2 "" H 8300 1850 50  0000 C CNN
F 3 "" H 8300 1850 50  0000 C CNN
	1    8300 1850
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR07
U 1 1 56853239
P 8750 1300
F 0 "#PWR07" H 8750 1050 50  0001 C CNN
F 1 "GND" H 8750 1150 50  0000 C CNN
F 2 "" H 8750 1300 50  0000 C CNN
F 3 "" H 8750 1300 50  0000 C CNN
	1    8750 1300
	1    0    0    -1  
$EndComp
$Comp
L +3.3V #PWR08
U 1 1 568533DB
P 8300 1100
F 0 "#PWR08" H 8300 950 50  0001 C CNN
F 1 "+3.3V" H 8300 1240 50  0000 C CNN
F 2 "" H 8300 1100 50  0000 C CNN
F 3 "" H 8300 1100 50  0000 C CNN
	1    8300 1100
	1    0    0    -1  
$EndComp
$Comp
L C C102
U 1 1 568557B1
P 6650 1550
F 0 "C102" H 6675 1650 50  0000 L CNN
F 1 "100n" H 6675 1450 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603_HandSoldering" H 6688 1400 50  0001 C CNN
F 3 "" H 6650 1550 50  0000 C CNN
	1    6650 1550
	0    1    1    0   
$EndComp
$Comp
L GND #PWR09
U 1 1 568557B9
P 6850 1650
F 0 "#PWR09" H 6850 1400 50  0001 C CNN
F 1 "GND" H 6850 1500 50  0000 C CNN
F 2 "" H 6850 1650 50  0000 C CNN
F 3 "" H 6850 1650 50  0000 C CNN
	1    6850 1650
	1    0    0    -1  
$EndComp
$Comp
L +3.3V #PWR010
U 1 1 568557C1
P 6400 1450
F 0 "#PWR010" H 6400 1300 50  0001 C CNN
F 1 "+3.3V" H 6400 1590 50  0000 C CNN
F 2 "" H 6400 1450 50  0000 C CNN
F 3 "" H 6400 1450 50  0000 C CNN
	1    6400 1450
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR011
U 1 1 56855C3A
P 6400 3050
F 0 "#PWR011" H 6400 2800 50  0001 C CNN
F 1 "GND" H 6400 2900 50  0000 C CNN
F 2 "" H 6400 3050 50  0000 C CNN
F 3 "" H 6400 3050 50  0000 C CNN
	1    6400 3050
	1    0    0    -1  
$EndComp
Text Label 5350 2850 2    60   ~ 0
RESET_GPIO
Text Label 5350 2950 2    60   ~ 0
RESET_CS
NoConn ~ 4150 2050
NoConn ~ 4150 2550
NoConn ~ 4150 2650
NoConn ~ 4150 2750
NoConn ~ 2750 3250
NoConn ~ 2750 3150
NoConn ~ 2750 2850
NoConn ~ 2750 2750
NoConn ~ 2750 2500
NoConn ~ 2750 2400
NoConn ~ 2750 2300
NoConn ~ 3300 1300
NoConn ~ 3450 1300
$Comp
L PWR_FLAG #FLG012
U 1 1 568676D9
P 3600 800
F 0 "#FLG012" H 3600 895 50  0001 C CNN
F 1 "PWR_FLAG" H 3600 980 50  0000 C CNN
F 2 "" H 3600 800 50  0000 C CNN
F 3 "" H 3600 800 50  0000 C CNN
	1    3600 800 
	1    0    0    -1  
$EndComp
NoConn ~ 5200 5100
NoConn ~ 4100 1000
$Comp
L GND #PWR013
U 1 1 5686DC34
P 6050 4100
F 0 "#PWR013" H 6050 3850 50  0001 C CNN
F 1 "GND" H 6050 3950 50  0000 C CNN
F 2 "" H 6050 4100 50  0000 C CNN
F 3 "" H 6050 4100 50  0000 C CNN
	1    6050 4100
	-1   0    0    -1  
$EndComp
$Comp
L +3.3V #PWR014
U 1 1 5686DE51
P 6050 3600
F 0 "#PWR014" H 6050 3450 50  0001 C CNN
F 1 "+3.3V" H 6050 3740 50  0000 C CNN
F 2 "" H 6050 3600 50  0000 C CNN
F 3 "" H 6050 3600 50  0000 C CNN
	1    6050 3600
	-1   0    0    -1  
$EndComp
Text Label 6700 3800 0    60   ~ 0
SPI_MOSI
Text Label 6700 3700 0    60   ~ 0
SPI_CLK
Text Label 8000 4250 2    60   ~ 0
SPI_CS
Text Label 6700 3900 0    60   ~ 0
SPI_MISO
$Comp
L 4050 U101
U 4 1 568781DC
P 7300 4250
F 0 "U101" H 7495 4365 50  0000 C CNN
F 1 "4050" H 7490 4125 50  0000 C CNN
F 2 "Housings_SSOP:TSSOP-16_4.4x5mm_Pitch0.65mm" H 7300 4250 60  0001 C CNN
F 3 "" H 7300 4250 60  0000 C CNN
	4    7300 4250
	-1   0    0    1   
$EndComp
$Comp
L 4050 U101
U 6 1 56878395
P 8000 6250
F 0 "U101" H 8195 6365 50  0000 C CNN
F 1 "4050" H 8190 6125 50  0000 C CNN
F 2 "Housings_SSOP:TSSOP-16_4.4x5mm_Pitch0.65mm" H 8000 6250 60  0001 C CNN
F 3 "" H 8000 6250 60  0000 C CNN
	6    8000 6250
	1    0    0    -1  
$EndComp
NoConn ~ 8450 6250
NoConn ~ 7550 6250
$Comp
L R R101
U 1 1 56832C00
P 2400 2800
F 0 "R101" V 2480 2800 50  0000 C CNN
F 1 "10k" V 2400 2800 50  0000 C CNN
F 2 "Resistors_SMD:R_0603_HandSoldering" V 2330 2800 50  0001 C CNN
F 3 "" H 2400 2800 50  0000 C CNN
	1    2400 2800
	1    0    0    -1  
$EndComp
NoConn ~ 2750 2950
$Comp
L +3.3V #PWR015
U 1 1 5683347B
P 2400 2500
F 0 "#PWR015" H 2400 2350 50  0001 C CNN
F 1 "+3.3V" H 2400 2640 50  0000 C CNN
F 2 "" H 2400 2500 50  0000 C CNN
F 3 "" H 2400 2500 50  0000 C CNN
	1    2400 2500
	1    0    0    -1  
$EndComp
Text Label 1900 3050 0    60   ~ 0
INT
Text Label 8850 2550 0    60   ~ 0
INT
Text Label 8850 5000 0    60   ~ 0
INT
$Comp
L CONN_02X04 P101
U 1 1 568349CC
P 6400 3850
F 0 "P101" H 6400 4100 50  0000 C CNN
F 1 "SPI_EXT" H 6400 3600 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_2x04" H 6400 2650 50  0001 C CNN
F 3 "" H 6400 2650 50  0000 C CNN
	1    6400 3850
	1    0    0    1   
$EndComp
Wire Wire Line
	7000 2050 9300 2050
Wire Wire Line
	9300 2150 7000 2150
Wire Wire Line
	5800 2750 5650 2750
Wire Wire Line
	5650 2750 5650 2900
Wire Wire Line
	5800 2550 5650 2550
Wire Wire Line
	5650 2550 5650 2500
Wire Wire Line
	5800 2650 5350 2650
Wire Wire Line
	9300 2250 8850 2250
Wire Wire Line
	9300 2350 8850 2350
Wire Wire Line
	9300 2450 8850 2450
Wire Wire Line
	9300 3350 8850 3350
Wire Wire Line
	9300 3450 8850 3450
Wire Wire Line
	9300 3550 8850 3550
Wire Wire Line
	9300 4250 8850 4250
Wire Wire Line
	9300 4350 8850 4350
Wire Wire Line
	9300 4450 8850 4450
Wire Wire Line
	9300 5100 8850 5100
Wire Wire Line
	9300 5200 8850 5200
Wire Wire Line
	9300 5300 8850 5300
Wire Wire Line
	5800 2250 5350 2250
Wire Wire Line
	5800 2150 5350 2150
Wire Wire Line
	5800 2050 5350 2050
Wire Wire Line
	4250 5200 4550 5200
Wire Wire Line
	4400 5400 4400 5200
Connection ~ 4400 5200
Wire Wire Line
	4400 5700 4400 5750
Wire Wire Line
	3550 5200 3950 5200
Wire Wire Line
	3800 5200 3800 6000
Wire Wire Line
	3800 6000 3950 6000
Wire Wire Line
	4250 6000 4550 6000
Wire Wire Line
	4400 6200 4400 6000
Connection ~ 4400 6000
Wire Wire Line
	4850 5200 5200 5200
Wire Wire Line
	5000 5200 5000 6000
Wire Wire Line
	5000 6000 4850 6000
Wire Wire Line
	4400 6500 4400 6600
Connection ~ 3800 5200
Wire Wire Line
	3650 5200 3650 5400
Connection ~ 3650 5200
Wire Wire Line
	3650 5700 3650 6550
Wire Wire Line
	3650 6550 5100 6550
Connection ~ 4400 6550
Connection ~ 5000 5200
Wire Wire Line
	5200 5300 5100 5300
Wire Wire Line
	5100 5300 5100 6550
Wire Wire Line
	3250 5200 2800 5200
Wire Wire Line
	4100 900  3600 900 
Wire Wire Line
	2750 2200 2300 2200
Wire Wire Line
	4150 2250 4600 2250
Wire Wire Line
	4150 2350 4600 2350
Wire Wire Line
	4150 2450 4600 2450
Wire Wire Line
	2750 2100 2300 2100
Wire Wire Line
	2250 2000 2750 2000
Wire Wire Line
	2750 1900 2300 1900
Wire Wire Line
	3450 4000 3450 4150
Wire Wire Line
	4400 2850 4150 2850
Wire Wire Line
	4150 2950 4400 2950
Wire Wire Line
	4600 2850 5350 2850
Wire Wire Line
	4600 2950 5350 2950
Wire Wire Line
	8450 5400 9300 5400
Wire Wire Line
	9300 1950 8850 1950
Wire Wire Line
	7550 5400 7000 5400
Wire Wire Line
	8850 1950 8850 1700
Wire Wire Line
	8850 1700 8800 1700
Wire Wire Line
	7900 1700 7300 1700
Wire Wire Line
	1250 1800 850  1800
Wire Wire Line
	2250 2000 2250 2150
Wire Wire Line
	2250 2150 2150 2150
Wire Wire Line
	1250 2150 850  2150
Wire Wire Line
	8400 1200 8300 1200
Wire Wire Line
	8300 1100 8300 1600
Wire Wire Line
	8300 1800 8300 1850
Wire Wire Line
	8700 1200 8750 1200
Wire Wire Line
	8750 1200 8750 1300
Connection ~ 8300 1200
Wire Wire Line
	6500 1550 6400 1550
Wire Wire Line
	6400 1450 6400 1950
Wire Wire Line
	6800 1550 6850 1550
Wire Wire Line
	6850 1550 6850 1650
Connection ~ 6400 1550
Wire Wire Line
	6400 3050 6400 2850
Connection ~ 3600 900 
Wire Wire Line
	2750 1800 2150 1800
Wire Wire Line
	6150 4000 6050 4000
Wire Wire Line
	6050 4000 6050 4100
Wire Wire Line
	6150 3700 6050 3700
Wire Wire Line
	6050 3700 6050 3600
Wire Wire Line
	6650 3800 6700 3800
Wire Wire Line
	6650 3700 6700 3700
Wire Wire Line
	6650 4000 6800 4000
Wire Wire Line
	6700 3900 6650 3900
Wire Wire Line
	7000 2250 8650 2250
Wire Wire Line
	8650 2250 8650 3100
Wire Wire Line
	8650 3100 9300 3100
Wire Wire Line
	9300 4050 8500 4050
Wire Wire Line
	8500 4050 8500 2350
Wire Wire Line
	8500 2350 7000 2350
Wire Wire Line
	9300 4150 8400 4150
Wire Wire Line
	8400 4150 8400 2450
Wire Wire Line
	8400 2450 7000 2450
Wire Wire Line
	9300 4900 8300 4900
Wire Wire Line
	8300 4900 8300 2550
Wire Wire Line
	8300 2550 7000 2550
Wire Wire Line
	1900 3050 2750 3050
Wire Wire Line
	2400 3050 2400 2950
Wire Wire Line
	2400 2500 2400 2650
Connection ~ 2400 3050
Wire Wire Line
	9300 2550 8850 2550
Wire Wire Line
	9300 5000 8850 5000
Wire Wire Line
	7000 2650 7350 2650
Wire Wire Line
	7350 2650 7350 3350
Wire Wire Line
	7350 3350 5600 3350
Wire Wire Line
	5600 3350 5600 3800
Wire Wire Line
	5600 3800 6150 3800
Wire Wire Line
	7000 2750 7300 2750
Wire Wire Line
	7300 2750 7300 3300
Wire Wire Line
	7300 3300 5550 3300
Wire Wire Line
	5550 3300 5550 3900
Wire Wire Line
	5550 3900 6150 3900
Text Label 5650 3800 0    60   ~ 0
MUX_CS1
Text Label 5650 3900 0    60   ~ 0
MUX_CS2
Wire Wire Line
	6800 4000 6800 4250
Wire Wire Line
	6800 4250 6850 4250
Wire Wire Line
	7750 4250 8000 4250
$Comp
L CONN_01X15 P103
U 1 1 568383E2
P 1700 4150
F 0 "P103" H 1700 4950 50  0000 C CNN
F 1 "~" V 1800 4150 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x15" H 1700 4150 50  0001 C CNN
F 3 "" H 1700 4150 50  0000 C CNN
	1    1700 4150
	1    0    0    -1  
$EndComp
$Comp
L CONN_01X15 P102
U 1 1 56838505
P 1100 4150
F 0 "P102" H 1100 4950 50  0000 C CNN
F 1 "~" V 1200 4150 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x15" H 1100 4150 50  0001 C CNN
F 3 "" H 1100 4150 50  0000 C CNN
	1    1100 4150
	-1   0    0    -1  
$EndComp
NoConn ~ 1300 3450
NoConn ~ 1300 3550
NoConn ~ 1300 3650
NoConn ~ 1300 3750
NoConn ~ 1300 3850
NoConn ~ 1300 3950
NoConn ~ 1300 4050
NoConn ~ 1300 4150
NoConn ~ 1300 4250
NoConn ~ 1300 4350
NoConn ~ 1300 4450
NoConn ~ 1300 4550
NoConn ~ 1300 4650
NoConn ~ 1300 4750
NoConn ~ 1300 4850
NoConn ~ 1500 4850
NoConn ~ 1500 4750
NoConn ~ 1500 4650
NoConn ~ 1500 4550
NoConn ~ 1500 4450
NoConn ~ 1500 4350
NoConn ~ 1500 4250
NoConn ~ 1500 4150
NoConn ~ 1500 4050
NoConn ~ 1500 3950
NoConn ~ 1500 3850
NoConn ~ 1500 3750
NoConn ~ 1500 3650
NoConn ~ 1500 3550
NoConn ~ 1500 3450
$Comp
L Jumper_NC_Small JP103
U 1 1 56840220
P 1450 6600
F 0 "JP103" H 1450 6680 50  0000 C CNN
F 1 "Jumper_NC_Small" H 1460 6540 50  0001 C CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" H 1450 6600 50  0001 C CNN
F 3 "" H 1450 6600 50  0000 C CNN
	1    1450 6600
	1    0    0    -1  
$EndComp
$Comp
L Jumper_NC_Small JP104
U 1 1 568408EB
P 1450 6750
F 0 "JP104" H 1450 6830 50  0000 C CNN
F 1 "Jumper_NC_Small" H 1460 6690 50  0001 C CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" H 1450 6750 50  0001 C CNN
F 3 "" H 1450 6750 50  0000 C CNN
	1    1450 6750
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR016
U 1 1 568409D1
P 1600 6800
F 0 "#PWR016" H 1600 6550 50  0001 C CNN
F 1 "GND" H 1600 6650 50  0000 C CNN
F 2 "" H 1600 6800 50  0000 C CNN
F 3 "" H 1600 6800 50  0000 C CNN
	1    1600 6800
	1    0    0    -1  
$EndComp
Wire Wire Line
	1550 6600 1600 6600
Wire Wire Line
	1600 6450 1600 6800
Wire Wire Line
	1550 6750 1600 6750
Connection ~ 1600 6750
Wire Wire Line
	1350 6750 1250 6750
Wire Wire Line
	1250 6750 1250 6450
Wire Wire Line
	1250 6450 1600 6450
Connection ~ 1600 6600
Wire Wire Line
	1350 6600 1250 6600
Connection ~ 1250 6600
$Comp
L CONN_01X02 P105
U 1 1 5684E2AD
P 5450 5750
F 0 "P105" H 5450 5900 50  0000 C CNN
F 1 "AOUT" V 5550 5750 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x02" H 5450 5750 50  0001 C CNN
F 3 "" H 5450 5750 50  0000 C CNN
	1    5450 5750
	1    0    0    1   
$EndComp
Wire Wire Line
	5250 5700 5000 5700
Connection ~ 5000 5700
Wire Wire Line
	5250 5800 5100 5800
Connection ~ 5100 5800
$Comp
L Jumper_NC_Small JP105
U 1 1 568509B2
P 3600 1100
F 0 "JP105" H 3600 1180 50  0000 C CNN
F 1 "Jumper_NC_Small" H 3610 1040 50  0001 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x02" H 3600 1100 50  0001 C CNN
F 3 "" H 3600 1100 50  0000 C CNN
	1    3600 1100
	0    1    1    0   
$EndComp
Wire Wire Line
	3600 1200 3600 1300
Wire Wire Line
	3600 1000 3600 800 
NoConn ~ 4150 3750
$EndSCHEMATC
