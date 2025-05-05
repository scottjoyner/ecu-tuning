# ecu-tuning
Learning about Engine Control Modules


# Research
Using the donor ECU, do research into the programming of the device, the neececary modifications etc.

## Notes
Donor Car 
Make: Acura
Model: RDX
Year: 2015
Mileage: 105,742
VIN: 5J8TB4H32FL019302


https://www.rlescalambre.net/obd-ii-communications-protocols
https://zeromanual.com/wiki/How_to_build_a_cable_to_access_the_MBB
https://acurazine.com/forums/3g-tl-2004-2008-93/finally-tuning-solution-stock-ecu-1000960/
🔌 Connections Summary
Component	Pin	Connects To
ESP32	GPIO4 (RX)	SN65HVD230 RXD
	GPIO5 (TX)	SN65HVD230 TXD
	GND	SN65HVD230 GND and ECU A18
	3.3V	SN65HVD230 VCC
SN65HVD230	CANH	ECU Pin B20
	CANL	ECU Pin B21
ECU	A4 (BATT+)	+12V Bench Power
	A9 (IGN)	+12V Switched (can be tied to BATT+ for bench)
	A18 (GND)	Ground
