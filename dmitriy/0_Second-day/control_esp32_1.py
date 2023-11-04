import time
import pygame
import serial
import serial.tools.list_ports 

pygame.init()
clock = pygame.time.Clock()
pygame.joystick.init()
joystick = pygame.joystick.Joystick(0)
joystick.init()

ports = list(serial.tools.list_ports.comports())
desired_hwid_part = "&0&08B61FED797A"

for p in ports:
    if desired_hwid_part in p.hwid:
        print("目標のポートを見つけました:", p.name) #p.hwid 
        ser = serial.Serial(port=p.device, baudrate=9600)
        break
    
    
#Main program
done = False
while not done:
    for event in pygame.event.get():

        last_input_time = time.time()  # Initialize time of last input
        current_time = last_input_time
        time_difference = 0

        if event.type == pygame.QUIT:
            ser.close()
            done = True

        #Left Stick
        if -0.8>joystick.get_axis(1):
            while True:
                ser.write(b'0')
                if pygame.event.get():
                    break
        elif 0.8<joystick.get_axis(1):
            while True:
                ser.write(b'1')
                if pygame.event.get():
                    break
        elif 0.8<joystick.get_axis(0):
            while True:
                ser.write(b'2')
                if pygame.event.get():
                    break
        elif -0.8>joystick.get_axis(0):
            while True:
                ser.write(b'3')
                if pygame.event.get():
                    break

        #Cross Button ( front = north )
        elif 0.9<joystick.get_hat(0)[1]:
            while True:
                ser.write(b'0')
                if pygame.event.get():
                    break

        elif -0.9>joystick.get_hat(0)[1]:
            while True:
                ser.write(b'1')
                if pygame.event.get():
                    break

        elif 0.9<joystick.get_hat(0)[0]:
            while True:
                ser.write(b'2')
                if pygame.event.get():
                    break

        elif -0.9>joystick.get_hat(0)[0]:
            while True:
                ser.write(b'3')
                if pygame.event.get():
                    break



        #button
        elif 1==joystick.get_button(0):#Green A button
            ser.write(b'4')
        elif 1==joystick.get_button(1):#Red B button
            ser.write(b'5')
        elif 1==joystick.get_button(2):#Blue X button
            ser.write(b'6')
        elif 1==joystick.get_button(3):#Yellow Y button
            ser.write(b'7')
