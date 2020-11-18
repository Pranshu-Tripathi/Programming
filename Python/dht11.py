import Adafruit_DHT
import time
import RPi.GPIO as GPIO
GPIO.setmode(GPIO.BOARD)
GPIO.setwarnings(False)
GPIO.setup(8,GPIO.OUT , initial = GPIO.LOW)
sensor = Adafruit_DHT.DHT11
pin = 17


while 1:
    humidity , temperature = Adafruit_DHT.read_retry(sensor , pin)
    if humidity is not None and temperature is not None:
        print("Temp = {0:0.1f}* humidity = {1:0.1f}%".format(temperature , humidity))
    else:
        print("Failed Boi!")
    if (temperature >=20):
        GPIO.output(8, GPIO.HIGH)
        time.sleep(0.1)
        GPIO.output(8,GPIO.LOW)
        
        
