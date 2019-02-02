#!/bin/bash

mkdir -p ~/qmk_firmware/keyboards/atreus62/keymaps/layertwo
mkdir -p ~/qmk_firmware/keyboards/satan/keymaps/layertwo
ln -fs ~/keyboard/atreus62/* ... ~/qmk_firmware/keyboards/atreus62/keymaps/layertwo
ln -fs ~/keyboard/mod_j/* ... ~/qmk_firmware/keyboards/satan/keymaps/layertwo
