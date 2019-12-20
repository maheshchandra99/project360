import numpy as np
import cv2
import  _thread
from tkinter import *

from time import sleep
import serial

ser = serial.Serial('COM3', 9600)

image = np.zeros((600,350,3),np.uint8)
image[:,:] = [0,255,0]
cv2.putText(image,"360_CS",(96,100),cv2.FONT_HERSHEY_COMPLEX_SMALL, 1.5, 255)

image[150:450,100:250]=[255,255,255]
height, width, _ = image.shape

#global value
global valueN
global valueE
global valueW
global valueS

valueN, valueE, valueS, valueW = 150,0,0,0


def shrink(n,e,w,s,image):

	top    = max(150 - n,0)
	bottom = max(450 + s,0)
	right  = max(250 + e,0)
	left   = max(100 - w,0)
	color  = [0, 0, 255]

	copy = image.copy()
	copy[0:top,:]   = color
	copy[bottom:,:] = color
	copy[:,right:]  = color
	copy[:,:left]   = color

	return copy

def update():
        arduino_data_list = list( map(int, str(ser.readline().decode("utf-8")).strip().split() ) )

        print(arduino_data_list)
        
        global valueW
        global valueE
        global valueS
        
        valueW = arduino_data_list[0] 
        valueE = arduino_data_list[1]
        valueS = arduino_data_list[2]

while True:

        update()

        to_show = shrink( int(valueN),int(valueE),int(valueW),int(valueS),image )
        cv2.imshow("Color Image",to_show)
        if cv2.waitKey(10) == ord("q"):
                break

cv2.destroyAllWindows()


