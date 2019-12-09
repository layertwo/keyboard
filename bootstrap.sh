#!/bin/bash

mkdir -p ~/qmk_firmware/keyboards/atreus62/keymaps/layertwo
mkdir -p ~/qmk_firmware/keyboards/satan/keymaps/layertwo
mkdir -p ~/qmk_firmware/keyboards/lily58/keymaps/layertwo
ln -fs ~/keyboard/atreus62/* ... ~/qmk_firmware/keyboards/atreus62/keymaps/layertwo
ln -fs ~/keyboard/mod_j/* ... ~/qmk_firmware/keyboards/satan/keymaps/layertwo
ln -fs ~/keyboard/lily58/* ... ~/qmk_firmware/keyboards/lily58/keymaps/layertwo
