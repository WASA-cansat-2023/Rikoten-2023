import time
import pygame
import itertools

pygame.init()
clock = pygame.time.Clock()
pygame.joystick.init()
joystick = pygame.joystick.Joystick(0)
joystick.init()

#ser = serial.Serial("COM9", 9600)

#Main program
done = False
while not done:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            done = True

        #button
        if 1==joystick.get_button(0):
            print('Green A button pressed') 
        if 1==joystick.get_button(1):
            print('Red B button pressed') 
        if 1==joystick.get_button(2):
            print('Blue X button pressed') 
        if 1==joystick.get_button(3):
            print('Yellow Y button pressed') 
        if 1==joystick.get_button(4):
            print('LB button pressed')
        if 1==joystick.get_button(5):
            print('RB button pressed') 
        if 0.7<joystick.get_axis(4):
            print('LT button pressed')
        if 0.7<joystick.get_axis(5):
            print('RT button pressed')
        if 1==joystick.get_button(6):
            print('BACK button pressed') 
        if 1==joystick.get_button(7):
            print('START button pressed') 
        if 1==joystick.get_button(8):
            print('Left Stick button pressed') 
        if 1==joystick.get_button(9):
            print('Right Stick button pressed') 

        #Left Stick
        if 0.4<joystick.get_axis(0):       
            for i in itertools.count():
                print('Left Stick X axis + ')
                if pygame.event.get():
                    break
            print('Left Stick X axis + ')
        if -0.4>joystick.get_axis(0):
            print('Left Stick X axis - ')
        if 0.4<joystick.get_axis(1):
            print('Left Stick Y axis - ')
        if -0.4>joystick.get_axis(1):
            print('Left Stick Y axis + ')

        #Right Stick
        if 0.4<joystick.get_axis(2):
            print('Right Stick X axis + ')
        if -0.4>joystick.get_axis(2):
            print('Right Stick X axis - ')
        if 0.4<joystick.get_axis(3):
            print('Right Stick Y axis - ')
        if -0.4>joystick.get_axis(3):
            print('Right Stick Y axis +')

        #Cross Button ( front = north )  
        if 0.9<joystick.get_hat(0)[1]:
            while True:
                print('North')
                time.sleep(0.1)
                if pygame.event.get():
                    break

        if 0.9<joystick.get_hat(0)[0]:
            while True:
                print('East')
                time.sleep(0.1)
                if pygame.event.get():
                    break

        if -0.9>joystick.get_hat(0)[1]:
            while True:
                print('South')
                time.sleep(0.1)
                if pygame.event.get():
                    break

        if -0.9>joystick.get_hat(0)[0]:
            while True:
                print('West')
                time.sleep(0.1)
                if pygame.event.get():
                    break



#ser.write(b'0')
#time.sleep(10)
#ser.write(b'1')

#ser.close()