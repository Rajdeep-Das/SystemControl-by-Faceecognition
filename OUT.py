import cv2
import numpy as np
import time
import serial

ser = serial.Serial('COM4', 9600, timeout=1)

recognizer = cv2.face.createLBPHFaceRecognizer()
recognizer.load('trainner/trainner.yml')
cascadePath = "haarcascade_frontalface_default.xml"
faceCascade = cv2.CascadeClassifier(cascadePath);


cam = cv2.VideoCapture(1)
#cam.set(3,320)
#cam.set(4,240)
#time.sleep(2)
#cam.set(15,-8.0)
#font = cv2.InitFont(cv2.CV_FONT_HERSHEY_SIMPLEX, 1, 1, 0, 1, 1)
font = cv2.FONT_HERSHEY_SIMPLEX
while True:
    ret, im =cam.read()
    gray=cv2.cvtColor(im,cv2.COLOR_BGR2GRAY)
    faces=faceCascade.detectMultiScale(gray, 1.2,5)
    for(x,y,w,h) in faces:
        cv2.rectangle(im,(x,y),(x+w,y+h),(0,255,0),2)
        Id, conf = recognizer.predict(gray[y:y+h,x:x+w])
        #for testing
        print(conf)
        if(conf<105):
            if(Id==1):
                Id="Rajdeep"
                ser.write(b'0')
        else:
            Id="Unknown"
            #ser.write(b'0')
        #cv2.putText(im,str(Id), (x,y+h),font, 255)
        cv2.putText(im,str(Id),(x,y+h), font, 1,(255,255,255),2,cv2.LINE_AA)
    cv2.imshow('OUT Cam',im) 
    if cv2.waitKey(10) & 0xFF==ord('q'):
        break
cam.release()
ser.close()
cv2.destroyAllWindows()
