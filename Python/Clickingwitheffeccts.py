from picamera import PiCamera
from time import sleep

camera = PiCamera()

i = 1
for effect in camera.IMAGE_EFFECTS:
    camera.start_preview()
    camera.image_effect = effect
    camera.annotate_text = "Effect: %s" % effect
    camera.capture('/home/pi/Practicals/image%s.jpg' % i)
    print(i)
    i = i + 1
    sleep(0.1)
    camera.stop_preview()
camera.close()
