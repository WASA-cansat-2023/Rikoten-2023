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

# ser = serial.Serial()
# ser.baudrate = 9600
# devices = serial.tools.list_ports.comports()
# port_found = False

# for device in devices:
#     if device.usb_description()=='ESP32LED':
#         ser.port=device[0]
#         port_found = True


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
            time.sleep(0.1)
            print("A")
        if 1==joystick.get_button(1): # Red B button
            ser.write(b'1')
            time.sleep(0.1)
            print("B")
        if 1==joystick.get_button(2): # Blue X button
            ser.write(b'2')
            time.sleep(0.1)
        if 1==joystick.get_button(3): # Yellow Y button
            ser.write(b'3')
            time.sleep(0.1)
        if 1==joystick.get_button(4): # LB button
            ser.write(b'4')
            time.sleep(0.1)
        if 1==joystick.get_button(5): # RB button
            ser.write(b'5')
            time.sleep(0.1)
        if 0.7<joystick.get_axis(4):  # LT button
            ser.write(b'r')
            time.sleep(0.1)
        if 0.7<joystick.get_axis(5):  # RT button
            ser.write(b'l')
            time.sleep(0.1)
        if 1==joystick.get_button(6): # BACK button
            ser.write(b'6')
            time.sleep(0.1)
        if 1==joystick.get_button(7): # START button
            ser.write(b'7')
            time.sleep(0.1)
        if 1==joystick.get_button(8): # Left stick button
            ser.write(b'8')
            time.sleep(0.1)
        if 1==joystick.get_button(9): # Right stick button
            ser.write(b'9')
            time.sleep(0.1)

        #Left Stick
        if -0.4>joystick.get_axis(1): # Left Stick Y axis + 
            ser.write(b'w')
            time.sleep(0.1) 
        if -0.4>joystick.get_axis(0): # Left Stick X axis - 
            ser.write(b'a')
            time.sleep(0.1)
        if 0.4<joystick.get_axis(1): # Left Stick Y axis - 
            ser.write(b's')
            time.sleep(0.1)
        if 0.4<joystick.get_axis(0): # Left Stick X axis + 
            ser.write(b'd')
            time.sleep(0.1)

        #Right Stick
        if -0.4>joystick.get_axis(3): # Right Stick Y axis +
            ser.write(b'u')
            time.sleep(0.1)
        if -0.4>joystick.get_axis(2): # Right Stick X axis -
            ser.write(b'h')
            time.sleep(0.1) 
        if 0.4<joystick.get_axis(3): # Right Stick Y axis - 
            ser.write(b'j')
            time.sleep(0.1)
        if 0.4<joystick.get_axis(2): # Right Stick X axis + 
            ser.write(b'k')
            time.sleep(0.1)

        #Cross Button ( front = north )
        if (0,1)==joystick.get_hat(0): # North
            ser.write(b'w')
            time.sleep(0.1)
        # if (1,1)==joystick.get_hat(0): # Northeast
        #     ser.write(b'z')
        #     time.sleep(0.1)
        if (1,0)==joystick.get_hat(0): # East
            ser.write(b'd')
            time.sleep(0.1)
        # if (1,-1)==joystick.get_hat(0): # Southeast
        #     ser.write(b'x')
        #     time.sleep(0.1)
        if (0,-1)==joystick.get_hat(0): # South
            ser.write(b's')
            time.sleep(0.1)
        # if (-1,-1)==joystick.get_hat(0): # Southwest
        #     ser.write(b'c')
        #     time.sleep(0.1)
        if (-1,0)==joystick.get_hat(0): # West
            ser.write(b'a')
            time.sleep(0.1)
        # if (-1,1)==joystick.get_hat(0): # Northwest
        #     ser.write(b'v')
        #     time.sleep(0.1)

#ser.write(b'0')
time.sleep(10)
#ser.write(b'1')

#ser.close()