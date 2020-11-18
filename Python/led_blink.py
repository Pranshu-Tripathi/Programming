import RPi.GPIO as GPIO
#import gpio
from time import sleep
# sleep is for the delay
GPIO.setwarnings(False)
#screen will not be filled by warnings
GPIO.setmode(GPIO.BOARD)
#naming conventions BCM and BOARD
GPIO.setup(10,GPIO.IN)  #Y
GPIO.setup(5,GPIO.IN)  #G
GPIO.setup(8,GPIO.IN)  #R
GPIO.setup(13, GPIO.OUT, initial = GPIO.LOW)  # RED
GPIO.setup(15, GPIO.OUT, initial = GPIO.LOW)    #Green
GPIO.setup(16, GPIO.OUT, initial = GPIO.LOW)    #YELLOW
GPIO.setup(18, GPIO.OUT, initial = GPIO.LOW)
while True:
    if GPIO.input(13) == False and GPIO.input(8) == False:
        GPIO.output(13,GPIO.HIGH)
        GPIO.output(15,GPIO.LOW)  
        GPIO.output(16,GPIO.LOW)
    elif GPIO.input(13) == True and GPIO.input(8) == False:
        GPIO.output(13,GPIO.HIGH)
        GPIO.output(15,GPIO.LOW)  
        GPIO.output(16,GPIO.LOW)
        GPIO.output(18,GPIO.HIGH)
        sleep(2)
        GPIO.output(18,GPIO.LOW)
    if GPIO.input(15) == False and GPIO.input(5) == False:
        GPIO.output(13,GPIO.LOW)
        GPIO.output(15,GPIO.HIGH)  
        GPIO.output(16,GPIO.LOW)
    elif GPIO.input(15) == True and GPIO.input(5) == False:
        GPIO.output(13,GPIO.LOW)
        GPIO.output(15,GPIO.HIGH)  
        GPIO.output(16,GPIO.LOW)
        GPIO.output(18,GPIO.HIGH)
        sleep(2)
        GPIO.output(18,GPIO.LOW)
    if GPIO.input(16) == False and GPIO.input(10) == False:
        GPIO.output(13,GPIO.LOW)
        GPIO.output(15,GPIO.LOW)  
        GPIO.output(16,GPIO.HIGH)
    elif GPIO.input(16) == True and GPIO.input(10) == False:
        GPIO.output(13,GPIO.LOW)
        GPIO.output(15,GPIO.LOW)  
        GPIO.output(16,GPIO.HIGH)
        GPIO.output(18,GPIO.HIGH)
        sleep(2)
        GPIO.output(18,GPIO.LOW)
         
