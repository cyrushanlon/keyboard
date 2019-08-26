EESchema Schematic File Version 4
LIBS:pcb-cache
EELAYER 30 0
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
L keyboard_parts:KEYSW K4
U 1 1 5D62BF68
P 6350 3000
F 0 "K4" V 6350 3000 60  0000 C CNN
F 1 "KEYSW" H 6350 2900 60  0001 C CNN
F 2 "Button_Switch_Keyboard:SW_Cherry_MX_1.00u_PCB" H 6350 3000 60  0001 C CNN
F 3 "" H 6350 3000 60  0000 C CNN
	1    6350 3000
	0    1    1    0   
$EndComp
$Comp
L keyboard_parts:KEYSW K0
U 1 1 5D62CEBB
P 5850 1950
F 0 "K0" V 5850 1950 60  0000 C CNN
F 1 "KEYSW" H 5850 1850 60  0001 C CNN
F 2 "Button_Switch_Keyboard:SW_Cherry_MX_1.00u_PCB" H 5850 1950 60  0001 C CNN
F 3 "" H 5850 1950 60  0000 C CNN
	1    5850 1950
	0    1    1    0   
$EndComp
$Comp
L keyboard_parts:KEYSW K1
U 1 1 5D62E809
P 6350 1950
F 0 "K1" V 6350 1950 60  0000 C CNN
F 1 "KEYSW" H 6350 1850 60  0001 C CNN
F 2 "Button_Switch_Keyboard:SW_Cherry_MX_1.00u_PCB" H 6350 1950 60  0001 C CNN
F 3 "" H 6350 1950 60  0000 C CNN
	1    6350 1950
	0    1    1    0   
$EndComp
$Comp
L keyboard_parts:KEYSW K2
U 1 1 5D62FBB0
P 6850 1950
F 0 "K2" V 6850 1950 60  0000 C CNN
F 1 "KEYSW" H 6850 1850 60  0001 C CNN
F 2 "Button_Switch_Keyboard:SW_Cherry_MX_1.00u_PCB" H 6850 1950 60  0001 C CNN
F 3 "" H 6850 1950 60  0000 C CNN
	1    6850 1950
	0    1    1    0   
$EndComp
$Comp
L keyboard_parts:KEYSW K3
U 1 1 5D63186C
P 5850 3000
F 0 "K3" V 5850 3000 60  0000 C CNN
F 1 "KEYSW" H 5850 2900 60  0001 C CNN
F 2 "Button_Switch_Keyboard:SW_Cherry_MX_1.00u_PCB" H 5850 3000 60  0001 C CNN
F 3 "" H 5850 3000 60  0000 C CNN
	1    5850 3000
	0    1    1    0   
$EndComp
$Comp
L keyboard_parts:KEYSW K5
U 1 1 5D63247A
P 6850 3000
F 0 "K5" V 6850 3000 60  0000 C CNN
F 1 "KEYSW" H 6850 2900 60  0001 C CNN
F 2 "Button_Switch_Keyboard:SW_Cherry_MX_1.00u_PCB" H 6850 3000 60  0001 C CNN
F 3 "" H 6850 3000 60  0000 C CNN
	1    6850 3000
	0    1    1    0   
$EndComp
Wire Wire Line
	6350 1650 6500 1650
Wire Wire Line
	6500 2700 6350 2700
Wire Wire Line
	6850 1650 7000 1650
Wire Wire Line
	7000 2700 6850 2700
Wire Wire Line
	5850 1650 6000 1650
Wire Wire Line
	6000 2700 5850 2700
$Comp
L Device:D D3
U 1 1 5D68F289
P 5850 3500
F 0 "D3" V 5900 3650 50  0000 R CNN
F 1 "D" V 5800 3650 50  0000 R CNN
F 2 "Diode_THT:D_T-1_P10.16mm_Horizontal" H 5850 3500 50  0001 C CNN
F 3 "~" H 5850 3500 50  0001 C CNN
	1    5850 3500
	0    -1   -1   0   
$EndComp
$Comp
L Device:D D4
U 1 1 5D68FE51
P 6350 3500
F 0 "D4" V 6400 3650 50  0000 R CNN
F 1 "D" V 6300 3650 50  0000 R CNN
F 2 "Diode_THT:D_T-1_P10.16mm_Horizontal" H 6350 3500 50  0001 C CNN
F 3 "~" H 6350 3500 50  0001 C CNN
	1    6350 3500
	0    -1   -1   0   
$EndComp
$Comp
L Device:D D2
U 1 1 5D6920B8
P 6850 2450
F 0 "D2" V 6900 2600 50  0000 R CNN
F 1 "D" V 6800 2600 50  0000 R CNN
F 2 "Diode_THT:D_T-1_P10.16mm_Horizontal" H 6850 2450 50  0001 C CNN
F 3 "~" H 6850 2450 50  0001 C CNN
	1    6850 2450
	0    -1   -1   0   
$EndComp
$Comp
L Device:D D5
U 1 1 5D692852
P 6850 3500
F 0 "D5" V 6900 3650 50  0000 R CNN
F 1 "D" V 6800 3650 50  0000 R CNN
F 2 "Diode_THT:D_T-1_P10.16mm_Horizontal" H 6850 3500 50  0001 C CNN
F 3 "~" H 6850 3500 50  0001 C CNN
	1    6850 3500
	0    -1   -1   0   
$EndComp
Wire Wire Line
	6000 1650 6000 1400
Connection ~ 6000 1650
Wire Wire Line
	6500 1650 6500 1400
Connection ~ 6500 1650
Wire Wire Line
	7000 1650 7000 1400
Connection ~ 7000 1650
$Comp
L Device:D D0
U 1 1 5D68D627
P 5850 2450
F 0 "D0" V 5900 2600 50  0000 R CNN
F 1 "D" V 5800 2600 50  0000 R CNN
F 2 "Diode_THT:D_T-1_P10.16mm_Horizontal" H 5850 2450 50  0001 C CNN
F 3 "~" H 5850 2450 50  0001 C CNN
	1    5850 2450
	0    -1   -1   0   
$EndComp
$Comp
L Device:D D1
U 1 1 5D690906
P 6350 2450
F 0 "D1" V 6400 2600 50  0000 R CNN
F 1 "D" V 6300 2600 50  0000 R CNN
F 2 "Diode_THT:D_T-1_P10.16mm_Horizontal" H 6350 2450 50  0001 C CNN
F 3 "~" H 6350 2450 50  0001 C CNN
	1    6350 2450
	0    -1   -1   0   
$EndComp
Wire Wire Line
	6000 1650 6000 2700
Wire Wire Line
	6500 1650 6500 2700
Wire Wire Line
	7000 1650 7000 2700
Connection ~ 6350 2600
Wire Wire Line
	6350 2600 6850 2600
Wire Wire Line
	6850 2250 6850 2300
Wire Wire Line
	5850 2600 6350 2600
Wire Wire Line
	5550 2600 5850 2600
Connection ~ 5850 2600
$Comp
L pro_micro:ProMicro U1
U 1 1 5D6A7DDA
P 4050 2700
F 0 "U1" H 4050 3737 60  0000 C CNN
F 1 "ProMicro" H 4050 3631 60  0000 C CNN
F 2 "keebs:Pro_Micro" H 4150 1650 60  0001 C CNN
F 3 "" H 4150 1650 60  0000 C CNN
	1    4050 2700
	1    0    0    -1  
$EndComp
Text GLabel 5550 2600 0    50   Input ~ 0
row0
Text GLabel 5550 3650 0    50   Input ~ 0
row1
Text GLabel 6000 1400 1    50   Input ~ 0
col0
Text GLabel 6500 1400 1    50   Input ~ 0
col1
Text GLabel 7000 1400 1    50   Input ~ 0
col2
Text GLabel 3350 2750 0    50   Input ~ 0
row1
Text GLabel 3350 2650 0    50   Input ~ 0
row0
Text GLabel 3350 2850 0    50   Input ~ 0
col0
Text GLabel 3350 3050 0    50   Input ~ 0
col2
Text GLabel 3350 2950 0    50   Input ~ 0
col1
Wire Wire Line
	6350 2250 6350 2300
Wire Wire Line
	5850 2250 5850 2300
Wire Wire Line
	5550 3650 5850 3650
Wire Wire Line
	6350 3650 5850 3650
Connection ~ 5850 3650
Wire Wire Line
	6850 3650 6350 3650
Connection ~ 6350 3650
Wire Wire Line
	6850 3300 6850 3350
Wire Wire Line
	6350 3300 6350 3350
Wire Wire Line
	5850 3300 5850 3350
Text GLabel 3350 2150 0    50   Input ~ 0
GND
Text GLabel 3350 2250 0    50   Input ~ 0
GND
Text GLabel 4750 2050 2    50   Input ~ 0
GND
$EndSCHEMATC
