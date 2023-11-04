import serial
import serial.tools.list_ports 

ports = list(serial.tools.list_ports.comports())

desired_hwid_part = "&0&08B61FED797A"

for p in ports:
    if desired_hwid_part in p.hwid:
        print("目標のポートを見つけました:", p.name) #p.hwid 
        ser = serial.Serial(port=p.device, baudrate=9600)
        break

#print(ser)