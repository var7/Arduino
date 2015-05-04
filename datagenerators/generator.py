__author__ = 'var'
import sys
from random import randint

filename = 'Switch.csv'

day = ['Monday', 'Tuesday', 'Wednesday', 'Thursday', 'Friday', 'Saturday', 'Sunday']
time = ['Morning', 'Afternoon', 'Night']
temp = ['cool', 'hot', 'cold']
light = ['bright', 'dim', 'moderate', 'dark']
# switch = ['YES','NO']
attributes = [day, time, temp, light]# switch]

lines = 10
file = open(filename, 'w+')
# file.write("day,time,temp,light,switch\n")
for i in range(lines):
    for j in  range(len(attributes)):
        length = (len(attributes[j]))-1
        random = randint(0, length)
        file.write('{}'.format(attributes[j][random]))
        if j < (len(attributes)-1):
            file.write(",")
    file.write(',\n')
file.close()
