#!/bin/bash

cd ~/qmk_firmware/
make clean
git pull
make satan:layertwo
make atreus62:layertwo
