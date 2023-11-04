import serial 
import time
import pygame

pygame.init()
clock = pygame.time.Clock()
pygame.joystick.init()
joystick = pygame.joystick.Joystick(0)
joystick.init()

ser = serial.Serial("COM9", 9600)

#Main program
done = False
while not done:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            done = True
        if 1==joystick.get_button(1):
            ser.write(b'0')
        if 1==joystick.get_button(0):
            ser.write(b'1')
        if 1==joystick.get_button(4   ):
            break


#ser.write(b'0')
#time.sleep(10)
#ser.write(b'1')

ser.close()