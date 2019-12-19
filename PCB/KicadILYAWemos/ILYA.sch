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
F 2 "" H 5650 2000 50  0001 C CNN
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
F 2 "" H 4600 4250 50  0001 C CNN
F 3 "" H 4600 4250 50  0001 C CNN
	1    4600 4250
	-1   0    0    1   
$EndComp
$Comp
L MyConnectors:Temperature_connector U?
U 1 1 5DF80F41
P 3600 3400
F 0 "U?" H 3212 3122 50  0000 R CNN
F 1 "Temperature_connector" H 3212 3213 50  0000 R CNN
F 2 "" H 3600 3400 50  0001 C CNN
F 3 "" H 3600 3400 50  0001 C CNN
	1    3600 3400
	0    -1   -1   0   
$EndComp
NoConn ~ 4300 3750
$Comp
L wemos_mini:WeMos_mini U?
U 1 1 5DFA3DEE
P 4450 2600
F 0 "U?" V 4344 3078 60  0000 L CNN
F 1 "WeMos_mini" V 4450 3078 60  0000 L CNN
F 2 "" H 5000 1900 60  0000 C CNN
F 3 "http://www.wemos.cc/Products/d1_mini.html" V 4556 3078 60  0000 L CNN
	1    4450 2600
	0    1    1    0   
$EndComp
Wire Wire Line
	4800 2100 4800 2050
Wire Wire Line
	4800 2050 5200 2050
Wire Wire Line
	5100 2400 5100 2200
Wire Wire Line
	5100 2200 5200 2200
Wire Wire Line
	5550 3600 5550 2400
Wire Wire Line
	4200 3100 4200 3400
Wire Wire Line
	4200 3400 4000 3400
Wire Wire Line
	4800 3700 4600 3700
Wire Wire Line
	4400 3100 4400 3250
Wire Wire Line
	4800 3100 4800 3700
Wire Wire Line
	4600 3850 4600 3700
Connection ~ 4600 3700
Wire Wire Line
	4600 3700 4000 3700
Wire Wire Line
	4000 3600 4700 3600
Wire Wire Line
	4750 3250 4750 3850
Wire Wire Line
	4400 3250 4750 3250
Wire Wire Line
	4700 3850 4700 3600
Connection ~ 4700 3600
Wire Wire Line
	4700 3600 5550 3600
NoConn ~ 4000 3500
NoConn ~ 4300 3100
NoConn ~ 4100 3100
NoConn ~ 4500 3100
NoConn ~ 4600 3100
NoConn ~ 4700 3100
Wire Wire Line
	5100 2400 5550 2400
Connection ~ 5550 2400
Wire Wire Line
	5550 2400 5550 1800
Wire Wire Line
	4700 1800 4700 2100
Wire Wire Line
	4700 1800 5550 1800
NoConn ~ 4100 2100
NoConn ~ 4200 2100
NoConn ~ 4300 2100
NoConn ~ 4400 2100
NoConn ~ 4500 2100
NoConn ~ 4600 2100
$EndSCHEMATC
