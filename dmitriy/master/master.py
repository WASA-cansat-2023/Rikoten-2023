import time
import pygame
import serial

pygame.init()
clock = pygame.time.Clock()
pygame.joystick.init()
joystick = pygame.joystick.Joystick(0)
joystick.init()

#change COM port
ser = serial.Serial("COM10", 9600)

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

        #button
        if 1==joystick.get_button(0):#Green A button
            ser.write(b'0')
        elif 1==joystick.get_button(1):#Red B button
            ser.write(b'1')
        elif 1==joystick.get_button(2):#Blue X button
            ser.write(b'2')
        elif 1==joystick.get_button(3):#Yellow Y button
            ser.write(b'3')

        #Left Stick
        elif -0.4>joystick.get_axis(1):
            ser.write(b'4')
            while True:
                ser.write(b'4')
                if pygame.event.get():
                    break
        elif 0.4<joystick.get_axis(1):
            while True:
                ser.write(b'5')
                if pygame.event.get():
                    break
        elif 0.4<joystick.get_axis(0):
            while True:
                ser.write(b'6')
                if pygame.event.get():
                    break
        elif -0.4>joystick.get_axis(0):
            while True:
                ser.write(b'7')
                if pygame.event.get():
                    break

        #Cross Button ( front = north )
        elif 0.9<joystick.get_hat(0)[1]:
            while True:
                ser.write(b'4')
                if pygame.event.get():
                    break

        elif -0.9>joystick.get_hat(0)[1]:
            while True:
                ser.write(b'5')
                if pygame.event.get():
                    break

        elif 0.9<joystick.get_hat(0)[0]:
            while True:
                ser.write(b'6')
                if pygame.event.get():
                    break

        elif -0.9>joystick.get_hat(0)[0]:
            while True:
                ser.write(b'7')
                if pygame.event.get():
                    break
