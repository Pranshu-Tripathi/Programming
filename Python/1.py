import RPi.GPIO as GPIO
from time import sleep
import cv2
from email.mime.multipart import MIMEMultipart
from email.mime.text import MIMEText
from email.mime.base import MIMEBase
from email import encoders
import smtplib
from PIL import Image
GPIO.setwarnings(False)
GPIO.setmode(GPIO.BCM) 
GPIO.setup(17, GPIO.OUT, initial=GPIO.LOW)
body_cascade = cv2.CascadeClassifier('/home/pi/Haarcascade/haarcascade_eye.xml')
body_cas = cv2.CascadeClassifier('/home/pi/Haarcascade/haarcascade_frontalface_default.xml')
upper_cas = cv2.CascadeClassifier('/home/pi/Haarcascade/haarcascade_upperbody.xml')
cap = cv2.VideoCapture(0)
msg = MIMEMultipart() 
msg['From'] = "RDJ"
msg['To'] = "Anurag"
msg['Subject'] = "ALERT! We have an intruder"
body = "We have an intruder check! Image attached here with" 
msg.attach(MIMEText(body, 'plain'))
while True:
    ret , frame = cap.read()
    gray = cv2.cvtColor(frame , cv2.COLOR_BGR2GRAY)
    eye = body_cascade.detectMultiScale(gray,1.3,5)
    face = body_cas.detectMultiScale(gray,1.3,5)
    upper = upper_cas.detectMultiScale(gray,1.3,5)
    
    for (x,y,w,h)  in face:
        cv2.rectangle(frame,(x,y),(x+w,y+h),(255,0,0),2)
        cv2.imshow('frame' , frame)
        
        if cv2.waitKey(1) & 0xFF == ord('q'):
            break
            crop_image = frame[ y:y+h , x: x+w]
            cv2.imwrite("face.jpg",crop_image)
            image.save("face.jpg")
            server = smtplib.SMTP('smtp.gmail.com', 587)
            server.starttls()
            fromaddr = "RDJ3001@gmail.com"
            toaddr = "iec2019071@iiita.ac.in"
            attachment = open("/home/pi/Practicals/face.jpg", "rb")
            part = MIMEBase('application', 'octet-stream')
            part.set_payload((attachment).read())
            encoders.encode_base64(part)
            part.add_header('Content-Disposition', "attachment; filename = /home/pi/Practicals/face.jpg")
            msg.attach(part)
            server.login(fromaddr, "PranshuRocks")
            text = msg.as_string()
            server.sendmail(fromaddr, toaddr, text)
            server.quit()
            sleep(5)
            print("Mail Sent")
    
cap.release()
cv2.destroyAllWindows()
                             
