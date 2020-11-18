import os, smtplib
import RPi.GPIO as GPIO
from time import sleep
GPIO.setwarnings(False)
GPIO.setmode(GPIO.BOARD)
GPIO.setup(8,GPIO.IN)
import Adafruit_DHT
sensor = Adafruit_DHT.DHT11
pin = 17


while 1:
    humidity , temperature = Adafruit_DHT.read_retry(sensor , pin)
    if humidity is not None and temperature is not None:
        print("Temp = {0:0.1f}* humidity = {1:0.1f}%".format(temperature , humidity))
    else:
        print("Failed Boi!")  
    if(GPIO.input(8) == False and temperature >=20):
        server = smtplib.SMTP('smtp.gmail.com', 587)
        server.starttls()
        
        msg = "LDR And Temperature"
        server.login("ritikasahusexy@gmail.com","MainhoonBevakoof")
        server.sendmail("ritikasahusexy@gmail.com", "iec2019071@iiita.ac.in",msg)
        server.quit()
        print("Send")
