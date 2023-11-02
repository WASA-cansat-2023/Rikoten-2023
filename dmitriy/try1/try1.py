import serial 
import serial.tools.list_ports
import time
import pygame

#setup for controller
pygame.init()
clock = pygame.time.Clock()
pygame.joystick.init()
joystick = pygame.joystick.Joystick(0)
joystick.init()

#setup for esp32 

ser = serial.Serial("COM10", 9600)


#Main program
done = False
while not done:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            done = True

        # Cautions
        # if you turn on "mode button", turn on light,
        # then the role of hat and Left stick are switched

        #button
        if 1==joystick.get_button(0): # Green A button
            ser.write(b'0')            
            print("A")
        if 1==joystick.get_button(1): # Red B button
            ser.write(b'1')
            print("B")
        if 1==joystick.get_button(2): # Blue X button
            ser.write(b'2')
        if 1==joystick.get_button(3): # Yellow Y button
            ser.write(b'3')
        if 1==joystick.get_button(4): # LB button
            ser.write(b'4')
        if 1==joystick.get_button(5): # RB button
            ser.write(b'5')
        if 0.7<joystick.get_axis(4):  # LT button
            ser.write(b'r')
        if 0.7<joystick.get_axis(5):  # RT button
            ser.write(b'l')
        if 1==joystick.get_button(6): # BACK button
            ser.write(b'6')
        if 1==joystick.get_button(7): # START button
            ser.write(b'7')
        if 1==joystick.get_button(8): # Left stick button
            ser.write(b'8')
        if 1==joystick.get_button(9): # Right stick button
            ser.write(b'9')
            

        #Left Stick
        if -0.4>joystick.get_axis(1): # Left Stick Y axis + 
            ser.write(b'w')
        if -0.4>joystick.get_axis(0): # Left Stick X axis - 
            ser.write(b'a')
        if 0.4<joystick.get_axis(1): # Left Stick Y axis - 
            ser.write(b's')
        if 0.4<joystick.get_axis(0): # Left Stick X axis + 
            ser.write(b'd')
            

        #Right Stick
        if -0.4>joystick.get_axis(3): # Right Stick Y axis +
            ser.write(b'u')
        if -0.4>joystick.get_axis(2): # Right Stick X axis -
            ser.write(b'h')
        if 0.4<joystick.get_axis(3): # Right Stick Y axis - 
            ser.write(b'j')
        if 0.4<joystick.get_axis(2): # Right Stick X axis + 
            ser.write(b'k')
            

        #Cross Button ( front = north )
        if (0,1)==joystick.get_hat(0): # North
            ser.write(b'w')
                
        # if (1,1)==joystick.get_hat(0): # Northeast
        #     ser.write(b'z')
        #     
        if (1,0)==joystick.get_hat(0): # East
            ser.write(b'd')
        # if (1,-1)==joystick.get_hat(0): # Southeast
        #     ser.write(b'x')
        #     
        if (0,-1)==joystick.get_hat(0): # South
            ser.write(b's')
        # if (-1,-1)==joystick.get_hat(0): # Southwest
        #     ser.write(b'c')
        #     
        if (-1,0)==joystick.get_hat(0): # West
            ser.write(b'a')
        # if (-1,1)==joystick.get_hat(0): # Northwest
        #     ser.write(b'v')
        #     

#ser.write(b'0')
time.sleep(10)
#ser.write(b'1')
ser.close()