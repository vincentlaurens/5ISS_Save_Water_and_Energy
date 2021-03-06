EESchema Schematic File Version 4
LIBS:ILYA-cache
EELAYER 26 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L MyRelay:Relay_2_pins U2
U 1 1 5DF78856
P 5650 2000
F 0 "U2" H 5612 1693 50  0000 R CNN
F 1 "Relay_2_pins" H 5612 1784 50  0000 R CNN
F 2 "pinHeads:PinHeader_1x02_P2.54mm_Horizontal" H 5650 2000 50  0001 C CNN
F 3 "" H 5650 2000 50  0001 C CNN
	1    5650 2000
	0    1    1    0   
$EndComp
$Comp
L MyConnectors:Flow_connector U3101
U 1 1 5DF78A93
P 4600 4250
F 0 "U3101" H 4678 4160 50  0000 L CNN
F 1 "Flow_connector" H 4678 4069 50  0000 L CNN
F 2 "pinHeads:PinHeader_1x03_P2.54mm_Horizontal" H 4600 4250 50  0001 C CNN
F 3 "" H 4600 4250 50  0001 C CNN
	1    4600 4250
	-1   0    0    1   
$EndComp
$Comp
L MyConnectors:Temperature_connector U101
U 1 1 5DF80F41
P 3600 3400
F 0 "U101" H 3212 3122 50  0000 R CNN
F 1 "Temperature_connector" H 3212 3213 50  0000 R CNN
F 2 "pinHeads:PinHeader_1x04_P2.54mm_Horizontal" H 3600 3400 50  0001 C CNN
F 3 "" H 3600 3400 50  0001 C CNN
	1    3600 3400
	0    -1   -1   0   
$EndComp
$Comp
L wemos_mini:WeMos_mini U102
U 1 1 5DFA3DEE
P 4450 2600
F 0 "U102" V 4344 3078 60  0000 L CNN
F 1 "WeMos_mini" V 4450 3078 60  0000 L CNN
F 2 "wemos-d1-mini:wemos-d1-mini-withoutpin" H 5000 1900 60  0001 C CNN
F 3 "http://www.wemos.cc/Products/d1_mini.html" V 4556 3078 60  0000 L CNN
	1    4450 2600
	0    1    1    0   
$EndComp
Wire Wire Line
	4800 2100 4800 2050
Wire Wire Line
	4700 3850 4700 3600
NoConn ~ 4000 3500
NoConn ~ 4300 3100
NoConn ~ 4100 3100
NoConn ~ 4500 3100
NoConn ~ 4600 3100
NoConn ~ 4700 3100
NoConn ~ 4100 2100
NoConn ~ 4200 2100
NoConn ~ 4300 2100
NoConn ~ 4400 2100
NoConn ~ 4500 2100
NoConn ~ 4600 2100
$Comp
L power:PWR_FLAG #FLG0101
U 1 1 5DFB7E39
P 3250 2300
F 0 "#FLG0101" H 3250 2375 50  0001 C CNN
F 1 "PWR_FLAG" H 3250 2474 50  0000 C CNN
F 2 "" H 3250 2300 50  0001 C CNN
F 3 "~" H 3250 2300 50  0001 C CNN
	1    3250 2300
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0101
U 1 1 5DFB809D
P 3250 2400
F 0 "#PWR0101" H 3250 2150 50  0001 C CNN
F 1 "GND" H 3255 2227 50  0000 C CNN
F 2 "" H 3250 2400 50  0001 C CNN
F 3 "" H 3250 2400 50  0001 C CNN
	1    3250 2400
	1    0    0    -1  
$EndComp
Wire Wire Line
	3250 2300 3250 2400
$Comp
L power:PWR_FLAG #FLG0102
U 1 1 5DFB832A
P 3650 2300
F 0 "#FLG0102" H 3650 2375 50  0001 C CNN
F 1 "PWR_FLAG" H 3650 2474 50  0000 C CNN
F 2 "" H 3650 2300 50  0001 C CNN
F 3 "~" H 3650 2300 50  0001 C CNN
	1    3650 2300
	1    0    0    -1  
$EndComp
Wire Wire Line
	3650 2300 3650 2400
$Comp
L power:+5V #PWR0102
U 1 1 5DFB86BA
P 3650 2400
F 0 "#PWR0102" H 3650 2250 50  0001 C CNN
F 1 "+5V" H 3665 2573 50  0000 C CNN
F 2 "" H 3650 2400 50  0001 C CNN
F 3 "" H 3650 2400 50  0001 C CNN
	1    3650 2400
	-1   0    0    1   
$EndComp
$Comp
L power:+5V #PWR0104
U 1 1 5DFB8C0D
P 4800 2050
F 0 "#PWR0104" H 4800 1900 50  0001 C CNN
F 1 "+5V" H 4815 2223 50  0000 C CNN
F 2 "" H 4800 2050 50  0001 C CNN
F 3 "" H 4800 2050 50  0001 C CNN
	1    4800 2050
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR0105
U 1 1 5DFB8C28
P 5150 2050
F 0 "#PWR0105" H 5150 1900 50  0001 C CNN
F 1 "+5V" V 5165 2178 50  0000 L CNN
F 2 "" H 5150 2050 50  0001 C CNN
F 3 "" H 5150 2050 50  0001 C CNN
	1    5150 2050
	0    -1   -1   0   
$EndComp
$Comp
L power:GND #PWR0106
U 1 1 5DFB8CDD
P 5150 2200
F 0 "#PWR0106" H 5150 1950 50  0001 C CNN
F 1 "GND" V 5155 2072 50  0000 R CNN
F 2 "" H 5150 2200 50  0001 C CNN
F 3 "" H 5150 2200 50  0001 C CNN
	1    5150 2200
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR0107
U 1 1 5DFB8EC7
P 4700 2100
F 0 "#PWR0107" H 4700 1850 50  0001 C CNN
F 1 "GND" H 4705 1927 50  0000 C CNN
F 2 "" H 4700 2100 50  0001 C CNN
F 3 "" H 4700 2100 50  0001 C CNN
	1    4700 2100
	-1   0    0    1   
$EndComp
$Comp
L power:GND #PWR0108
U 1 1 5DFB9080
P 4100 3600
F 0 "#PWR0108" H 4100 3350 50  0001 C CNN
F 1 "GND" V 4105 3472 50  0000 R CNN
F 2 "" H 4100 3600 50  0001 C CNN
F 3 "" H 4100 3600 50  0001 C CNN
	1    4100 3600
	0    -1   -1   0   
$EndComp
$Comp
L power:GND #PWR0109
U 1 1 5DFB9123
P 4700 3600
F 0 "#PWR0109" H 4700 3350 50  0001 C CNN
F 1 "GND" H 4705 3427 50  0000 C CNN
F 2 "" H 4700 3600 50  0001 C CNN
F 3 "" H 4700 3600 50  0001 C CNN
	1    4700 3600
	-1   0    0    1   
$EndComp
Wire Wire Line
	5150 2050 5200 2050
Wire Wire Line
	4800 3100 4900 3100
Wire Wire Line
	4600 3750 4600 3850
Wire Wire Line
	5150 2200 5200 2200
Wire Wire Line
	4000 3600 4100 3600
Wire Wire Line
	4000 3700 4300 3700
$Comp
L MyRelay:Pin_socket_1x8 U103
U 1 1 5DFCAC32
P 4550 1900
F 0 "U103" H 4212 1693 50  0000 R CNN
F 1 "Pin_socket_1x8" H 4212 1784 50  0000 R CNN
F 2 "pinSocket:PinSocket_1x08_P2.54mm_Vertical" H 4550 1900 50  0001 C CNN
F 3 "" H 4550 1900 50  0001 C CNN
	1    4550 1900
	-1   0    0    1   
$EndComp
$Comp
L MyRelay:Pin-socket2_1x08 U104
U 1 1 5DFCBECA
P 8600 1950
F 0 "U104" V 8399 1819 50  0000 L CNN
F 1 "Pin-socket2_1x08" V 8490 1819 50  0000 L CNN
F 2 "pinSocket:PinSocket_1x08_P2.54mm_Vertical2" H 8500 1600 50  0001 C CNN
F 3 "" H 8500 1600 50  0001 C CNN
	1    8600 1950
	0    1    1    0   
$EndComp
$Comp
L power:+5V #PWR0110
U 1 1 5DFCC40D
P 4800 1600
F 0 "#PWR0110" H 4800 1450 50  0001 C CNN
F 1 "+5V" V 4815 1728 50  0000 L CNN
F 2 "" H 4800 1600 50  0001 C CNN
F 3 "" H 4800 1600 50  0001 C CNN
	1    4800 1600
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0103
U 1 1 5DFCC4FC
P 4700 1600
F 0 "#PWR0103" H 4700 1350 50  0001 C CNN
F 1 "GND" V 4705 1472 50  0000 R CNN
F 2 "" H 4700 1600 50  0001 C CNN
F 3 "" H 4700 1600 50  0001 C CNN
	1    4700 1600
	-1   0    0    1   
$EndComp
NoConn ~ 8100 2050
NoConn ~ 8100 1950
NoConn ~ 8100 1850
NoConn ~ 8100 1650
NoConn ~ 8100 1450
Text GLabel 4200 3100 3    50   Input ~ 0
SIGTemp
Text GLabel 4000 3400 2    50   Input ~ 0
SIGTemp
Text GLabel 8100 1550 0    50   Input ~ 0
SIGTemp
Text GLabel 8100 1750 0    50   Input ~ 0
SIGFlow
Text GLabel 4750 3850 1    50   Input ~ 0
SIGFlow
Text GLabel 4400 3100 3    50   Input ~ 0
SIGFlow
NoConn ~ 4600 1600
NoConn ~ 4500 1600
NoConn ~ 4400 1600
NoConn ~ 4300 1600
NoConn ~ 4200 1600
NoConn ~ 4100 1600
$Comp
L power:PWR_FLAG #FLG0103
U 1 1 5DFFCC45
P 2800 2300
F 0 "#FLG0103" H 2800 2375 50  0001 C CNN
F 1 "PWR_FLAG" H 2800 2474 50  0000 C CNN
F 2 "" H 2800 2300 50  0001 C CNN
F 3 "~" H 2800 2300 50  0001 C CNN
	1    2800 2300
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR0111
U 1 1 5DFFCC72
P 2800 2400
F 0 "#PWR0111" H 2800 2250 50  0001 C CNN
F 1 "+3.3V" H 2815 2573 50  0000 C CNN
F 2 "" H 2800 2400 50  0001 C CNN
F 3 "" H 2800 2400 50  0001 C CNN
	1    2800 2400
	-1   0    0    1   
$EndComp
Wire Wire Line
	2800 2300 2800 2400
$Comp
L power:+3.3V #PWR0112
U 1 1 5DFFCE95
P 8100 2150
F 0 "#PWR0112" H 8100 2000 50  0001 C CNN
F 1 "+3.3V" V 8115 2278 50  0000 L CNN
F 2 "" H 8100 2150 50  0001 C CNN
F 3 "" H 8100 2150 50  0001 C CNN
	1    8100 2150
	0    -1   -1   0   
$EndComp
$Comp
L power:+3.3V #PWR0113
U 1 1 5DFFD007
P 4900 3100
F 0 "#PWR0113" H 4900 2950 50  0001 C CNN
F 1 "+3.3V" V 4915 3228 50  0000 L CNN
F 2 "" H 4900 3100 50  0001 C CNN
F 3 "" H 4900 3100 50  0001 C CNN
	1    4900 3100
	0    1    1    0   
$EndComp
$Comp
L power:+3.3V #PWR0114
U 1 1 5DFFD090
P 4300 3700
F 0 "#PWR0114" H 4300 3550 50  0001 C CNN
F 1 "+3.3V" V 4315 3828 50  0000 L CNN
F 2 "" H 4300 3700 50  0001 C CNN
F 3 "" H 4300 3700 50  0001 C CNN
	1    4300 3700
	0    1    1    0   
$EndComp
$Comp
L power:+3.3V #PWR0115
U 1 1 5DFFD0AD
P 4600 3750
F 0 "#PWR0115" H 4600 3600 50  0001 C CNN
F 1 "+3.3V" H 4615 3923 50  0000 C CNN
F 2 "" H 4600 3750 50  0001 C CNN
F 3 "" H 4600 3750 50  0001 C CNN
	1    4600 3750
	1    0    0    -1  
$EndComp
$EndSCHEMATC
