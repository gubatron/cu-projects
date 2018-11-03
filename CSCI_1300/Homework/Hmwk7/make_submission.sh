#!/bin/bash

file="hmwk7.zip"

if [ -f $file ] ; then
    rm $file
fi

zip hmwk7.zip Book.cpp Book.h User.cpp User.h Hmwk7.cpp