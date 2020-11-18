import cv2

body_cascade = cv2.CascadeClassifier('/home/pi/Haarcascade/haarcascade_eye.xml')
body_cas = cv2.CascadeClassifier('/home/pi/Haarcascade/haarcascade_frontalface_default.xml')
cap = cv2.VideoCapture(0)
while True:
    ret , frame = cap.read()
    gray = cv2.cvtColor(frame , cv2.COLOR_BGR2GRAY)
    eye = body_cascade.detectMultiScale(gray,1.3,5)
    body = body_cas.detectMultiScale(gray,1.3,5)
    for (x,y,w,h)  in body:
        cv2.rectangle(frame,(x,y),(x+w,y+h),(255,0,0),2)
    for (a,b,c,d) in eye:
        cv2.rectangle(frame,(a,b),(a+c,b+d),(255,0,0),2)
    cv2.imshow('frame' , frame)
    print(len(body))
    if cv2.waitKey(1) & 0xFF == ord('q'):
        break
cap.release()
cv2.destroyAllWindows()
                                    
