import RPi.GPIO as GPIO
from time import sleep
GPIO.setwarnings(False)
GPIO.setmode(GPIO.BOARD)
GPIO.setup(8,GPIO.IN)
GPIO.setup(10,GPIO.OUT , initial=GPIO.LOW)
GPIO.setup(5,GPIO.OUT , initial=GPIO.LOW)
while 1:
    if(GPIO.input(8)==True):
        GPIO.output(10, GPIO.HIGH)
        sleep(0.1)
        GPIO.output(10, GPIO.LOW)
        sleep(0.1)
    elif(GPIO.input(8)==False):
        GPIO.output(5 , GPIO.HIGH)
        sleep(0.1)
        GPIO.output(5 , GPIO.LOW)
        sleep(0.1)
        
