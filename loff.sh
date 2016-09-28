#!/bin/bash


if ! [ -e /sys/class/gpio/gpio60 ]; then

   echo 60 > /sys/class/gpio/export

fi;


echo out >  /sys/class/gpio/gpio60/direction
echo 0 > /sys/class/gpio/gpio60/value 
