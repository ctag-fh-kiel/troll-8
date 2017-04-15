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
Sheet 3 6
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
L MCP1824-LDO U301
U 1 1 56810A55
P 4450 3050
F 0 "U301" H 4500 3300 60  0000 C CNN
F 1 "MCP1824-LDO" H 4850 3200 60  0000 C CNN
F 2 "Housings_SOT-23_SOT-143_TSOT-6:SOT-23-5" H 4450 3050 60  0001 C CNN
F 3 "" H 4450 3050 60  0000 C CNN
	1    4450 3050
	1    0    0    -1  
$EndComp
$Comp
L BARREL_JACK CON301
U 1 1 56810AEE
P 2900 3100
F 0 "CON301" H 2900 3350 50  0000 C CNN
F 1 "BARREL_JACK" H 2900 2900 50  0000 C CNN
F 2 "modules:BARELL_CLIFF_DC10L" H 2900 3100 50  0001 C CNN
F 3 "" H 2900 3100 50  0000 C CNN
	1    2900 3100
	1    0    0    1   
$EndComp
Wire Wire Line
	3650 3000 4250 3000
Connection ~ 4050 3000
Wire Wire Line
	4800 3400 4800 3650
$Comp
L GND #PWR024
U 1 1 56810B9D
P 4800 3650
F 0 "#PWR024" H 4800 3400 50  0001 C CNN
F 1 "GND" H 4800 3500 50  0000 C CNN
F 2 "" H 4800 3650 50  0000 C CNN
F 3 "" H 4800 3650 50  0000 C CNN
	1    4800 3650
	1    0    0    -1  
$EndComp
Connection ~ 4800 3500
Wire Wire Line
	4050 2550 4050 3100
Wire Wire Line
	3850 2550 4200 2550
$Comp
L CP C301
U 1 1 56810C35
P 4350 2550
F 0 "C301" H 4375 2650 50  0000 L CNN
F 1 "10u" H 4375 2450 50  0000 L CNN
F 2 "Capacitors_SMD:c_elec_4x5.7" H 4388 2400 50  0001 C CNN
F 3 "" H 4350 2550 50  0000 C CNN
	1    4350 2550
	0    -1   1    0   
$EndComp
Wire Wire Line
	3200 3200 4050 3200
Wire Wire Line
	4050 3200 4050 3500
Wire Wire Line
	4050 3500 5950 3500
$Comp
L GND #PWR025
U 1 1 56810D01
P 4650 2600
F 0 "#PWR025" H 4650 2350 50  0001 C CNN
F 1 "GND" H 4650 2450 50  0000 C CNN
F 2 "" H 4650 2600 50  0000 C CNN
F 3 "" H 4650 2600 50  0000 C CNN
	1    4650 2600
	1    0    0    -1  
$EndComp
Wire Wire Line
	4500 2550 4650 2550
Wire Wire Line
	4650 2550 4650 2600
Connection ~ 4050 2550
$Comp
L CP C302
U 1 1 56810D42
P 5950 3300
F 0 "C302" H 5975 3400 50  0000 L CNN
F 1 "10u" H 5975 3200 50  0000 L CNN
F 2 "Capacitors_SMD:c_elec_4x5.7" H 5988 3150 50  0001 C CNN
F 3 "" H 5950 3300 50  0000 C CNN
	1    5950 3300
	-1   0    0    -1  
$EndComp
Wire Wire Line
	5550 3100 6300 3100
Wire Wire Line
	5950 3100 5950 3150
Wire Wire Line
	5950 3500 5950 3450
$Comp
L +3.3V #PWR026
U 1 1 56810DCF
P 6300 3050
F 0 "#PWR026" H 6300 2900 50  0001 C CNN
F 1 "+3.3V" H 6300 3190 50  0000 C CNN
F 2 "" H 6300 3050 50  0000 C CNN
F 3 "" H 6300 3050 50  0000 C CNN
	1    6300 3050
	1    0    0    -1  
$EndComp
Wire Wire Line
	6300 3100 6300 3050
Connection ~ 5950 3100
Text HLabel 5900 2650 2    60   Output ~ 0
PWR_GOOD
Wire Wire Line
	5550 3000 5700 3000
Wire Wire Line
	5700 3000 5700 2650
Wire Wire Line
	5700 2650 5900 2650
Text HLabel 3850 2550 0    60   Output ~ 0
VIN
$Comp
L D_Schottky D301
U 1 1 5683DA9E
P 3500 3000
F 0 "D301" H 3500 3100 50  0000 C CNN
F 1 "D_Schottky" H 3500 2900 50  0000 C CNN
F 2 "Diodes_SMD:SOD-123" H 3500 3000 50  0001 C CNN
F 3 "" H 3500 3000 50  0000 C CNN
	1    3500 3000
	-1   0    0    1   
$EndComp
Wire Wire Line
	3200 3000 3350 3000
Wire Wire Line
	3200 3100 3300 3100
Wire Wire Line
	3300 3100 3300 3000
Connection ~ 3300 3000
Wire Wire Line
	4050 3100 4250 3100
$EndSCHEMATC
