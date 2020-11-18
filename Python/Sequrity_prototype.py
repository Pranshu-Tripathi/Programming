import smtplib,os,time
import RPi.GPIO as GPIO
GPIO.setwarnings(False)
GPIO.setmode(GPIO.BCM)
GPIO.setup(17,GPIO.OUT,initial = GPIO.LOW) #buzzer
GPIO.setup(27,GPIO.IN) #ir
GPIO.setup(23,GPIO.IN) #switch 1 - Entry Switch
GPIO.setup(24,GPIO.IN) #switch 2 - Exit Switch
count = 2
while(True):
    if GPIO.input(24) == True:
        for i in range(0,1):
            GPIO.output(17,GPIO.HIGH)
            time.sleep(0.1)
            GPIO.output(17,GPIO.LOW)
        time.sleep(20)
        continue 
    if GPIO.input(27) == True:
        time.sleep(5)
        #First Checking Entry
        if(GPIO.input(23) == True): 
            for i in range(0,2):
                GPIO.output(17,GPIO.HIGH)
                time.sleep(0.1)
                GPIO.output(17,GPIO.LOW)
            # server = smtplib.SMTP('smtp.gmail.com',587)
            # server.starttls()
            # server.login("raspberry@gmail.com","taphmt33")
            # msg = "One Of the Room-mates have entered the Room at "
            # server.sendmail("raspberry@gmail.com","iec2019002@iiita.ac.in",msg + time+ "time")
            # print("MAIL sent to Tejas Agrawal College id")
            # server.sendmail("raspberry@gmail.com","iec2019001@iiita.ac.in",msg + time)
            # print("MAIL sent to Pranshu Tripathi At college id")
            # server.quit()
            # time.sleep(300)  
        else:
            for i in range (0,5):
                GPIO.output(17,GPIO.HIGH)
                time.sleep(0.1)
                GPIO.output(17,GPIO.LOW)    
            # server = smtplib.SMTP('smtp.gmail.com',587)
            # server.starttls()
            # server.login("raspberry@gmail.com","taphmt33")
            # msg = "One3 of the room - mate Exited the room at "
            # server.sendmail("raspberry@gmail.com","iec2019002@iiita.ac.in",msg + time+ "time")
            # print("MAIL sent to Tejas Agrawal College id")
            # server.sendmail("raspberry@gmail.com","iec2019001@iiita.ac.in",msg + time)
            # print("MAIL sent to Pranshu Tripathi At college id")
            # server.quit()
            # time.sleep(300)