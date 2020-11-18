from picamera import PiCamera
from time import sleep

camera = PiCamera()
sleep(1)
camera.start_preview()
print("Clicking Picture!")
camera.capture('/home/pi/Practicals/group5.jpg')
sleep(0.1)  ## prevent camera damage
camera.stop_preview()
camera.close() ## important line when using in loop
