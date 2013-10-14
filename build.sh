#!/bin/bash

# just a simple script to automate the qmake process

qmake -project
qmake *.pro

cd converterWidget
qmake -project
qmake *.pro
make

cd ..
make
