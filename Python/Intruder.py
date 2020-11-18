from picamera import PiCamera
import RPi.GPIO as GPIO
from time import sleep
import smtplib
import datetime
from email.mime.multipart import MIMEMultipart
from email.mime.text import MIMEText
from email.mime.base import MIMEBase
from email import encoders

GPIO.setmode(GPIO.BCM)
GPIO.setup(2,GPIO.IN)
camera = PiCamera()

fromaddr = "RDJ3001@gmail.com"
toaddr = "iec2019071@iiita.ac.in"
msg = MIMEMultipart() 
msg['From'] = "RDJ"
msg['To'] = "Anurag"
msg['Subject'] = "ALERT! We have an intruder"

print ("The Intruder Detection system has started. A mail would be sent to %s on detecting any presence." %toaddr )
while True:
    if(GPIO.input(2)==False):
        body = "We have an intruder check! Image attached here with. The Temperature:" 
        msg.attach(MIMEText(body, 'plain'))
        camera.start_preview()
        camera.annotate_text = "Time: %s" % datetime.datetime.now()
        camera.capture('/home/pi/Practicals/image.jpg')
        sleep(0.1)
        camera.stop_preview()

        filename = "/home/pi/Practicals/image.jpg"
        attachment = open("/home/pi/Practicals/image.jpg", "rb")
 
        part = MIMEBase('application', 'octet-stream')
        part.set_payload((attachment).read())
        encoders.encode_base64(part)
        part.add_header('Content-Disposition', "attachment; filename= %s" % filename)
 
        msg.attach(part)
 
        server = smtplib.SMTP('smtp.gmail.com', 587)
        server.starttls()
        
        server.login(fromaddr, "PranshuRocks")
        text = msg.as_string()
        server.sendmail(fromaddr, toaddr, text)
        server.quit()
        sleep(5)
        print("Mail Sent")
        
