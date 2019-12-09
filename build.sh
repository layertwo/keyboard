#!/bin/bash

cd ~/qmk_firmware/
make clean
git pull
make gh60/satan:layertwo
make atreus62:layertwo
make lily58:layertwo
