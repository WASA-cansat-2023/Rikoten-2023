import itertools
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
desired_hwid_part = "0&9C9C1FCBE1C6"

        
#Main program
done = False
while not done:
    for event in pygame.event.get():

        last_input_time = time.time()  # Initialize time of last input
        current_time = last_input_time
        time_difference = 0

        if event.type == pygame.QUIT:
            #ser.close()
            done = True

        #Left Stick
       
        print(joystick.get_axis(1))
        if 0.0 ==joystick.get_axis(1):
            continue
            

        
        