#import cv2
import os
from datetime import datetime
import smtplib
from email.mime.multipart import MIMEMultipart
from email.mime.text import MIMEText
from email.mime.base import MIMEBase
from email import encoders
fromadder = "RDJ3001@gmail.com"
toadder = "mtpranshu2001@gmail.com"
password = "PranshuRocks"
msg = MIMEMultipart()
msg['From'] = "Laptop Alert - Lenovo (Pranshu)"
msg['To'] = "Pranshu Tripathi And himanshu Mani Tripathi"
cv2.namedWindow("Scanning")
vc = cv2.VideoCapture(0)
now = datetime.now()
current_time = now.strftime("%m/%d/%Y, %H:%M:%S")
# msg['Text'] = " Sir Your laptop was booted by this person at " + current_time
if vc.isOpened():  # try to get the first frame
    rval, frame = vc.read()
else:
    rval = False
flag = 0
while rval:
    # rval, frame = vc.read()
    # key = cv2.waitKey(20)
    # if key == 27: # exit on ESC
    #     i = 0;
    #     break
    cv2.imshow("Scanning", frame)
    cv2.imwrite(filename='image.jpg', img=frame)
    cv2.destroyWindow("Scanning")
    print("Image cliked and saved!")
    vc.release()
    filename1 = "image.jpg"
    attachment = open("image.jpg", "rb")
    part = MIMEBase('application', 'octet-stream')
    part.set_payload((attachment).read())
    encoders.encode_base64(part)
    part.add_header('Content-Disposition',"attachment; filename = %s" % filename1)
    msg.attach(part)
    print("Message Prepared to Dispatch")
    server = smtplib.SMTP('smtp.gmail.com', 587)
    server.starttls()
    print("Server login start")
    server.login(fromadder, password)
    print("Boss server logged in")
    text = msg.as_string()
    server.sendmail(fromadder, toadder, text)
    print("Sent to You boss!")
    print('Attachment Dispatched')
    server.quit()
    print("Losing connection")
    os.remove("image.jpg")
    print("Saved data is cleared")
    flag = 1
    break
if flag == 1:
    print("jobDone")
else:
    server = smtplib.SMTP('smtp.gmail.com', '587')
    server.starttls()
    print("The Part 2 has been initiated")
    server.login(fromadder, password)
    msg = "The P.C was Booted But the webcam couldn't Sent any pic"
    server.sendmail(fromadder, toadder, msg)
    print("Error mail sent")
    server.quit()
    print("Lost connection")
