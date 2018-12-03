#!/bin/bash

rm outback_trail
rm *.gch
rm *.o

OPTIONS=-std=c++11

g++ $OPTIONS Calendar.h Common.h Game.h Milestone.h \
             Photo.h Player.h Servo.h Supply.h Tests.h \
             UI.h Van.h VanMisfortune.h Game.cpp Main.cpp \
             Milestone.cpp Player.cpp Servo.cpp Tests.cpp UI.cpp

mv a.out outback_trail
