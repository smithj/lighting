#!/usr/bin/python

import Adafruit_BBIO.GPIO as GPIO
 

#GPIO.setup("GPIO0_26", GPIO.OUT)
#GPIO.output("GPIO0_26", GPIO.HIGH)

GPIO.setup("P9_12", GPIO.OUT)
GPIO.output("P9_12", GPIO.HIGH)

GPIO.cleanup()
