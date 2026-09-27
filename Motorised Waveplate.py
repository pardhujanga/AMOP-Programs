import sys
import serial

motor = serial.Serial(port = 'COM3', baudrate = 9600, parity = serial.PARITY_NONE)
reply = ''
# 1 degree is 398 pulses. We find the number of pulses we need to send based on the 
# number of degrees we want to turn it. 

try:
    message = int(input())
    if message < 0:
        message = 16**8 + message

    Hex = hex(message).lstrip('0x').rstrip('L').upper()

    while len(Hex)<8:
        Hex = '0' + Hex
        
    final = '0mr' + Hex    
    motor.write(final.encode())

    reply = motor.readline()
    print(reply.decode())

    motor.close()
    print(motor.is_open)

except:
    print("Oops!", sys.exc_info()[0], "occurred.")
    motor.close()
    print(motor.is_open)
