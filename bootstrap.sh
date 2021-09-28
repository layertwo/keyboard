#!/bin/bash
python3 -m pip install --user qmk
mkdir -p ~/qmk_firmware/keyboards/atreus62/keymaps/layertwo
mkdir -p ~/qmk_firmware/keyboards/gh60/satan/keymaps/layertwo
mkdir -p ~/qmk_firmware/keyboards/lily58/keymaps/layertwo
ln -fs ~/keyboard/atreus62/* ... ~/qmk_firmware/keyboards/atreus62/keymaps/layertwo
ln -fs ~/keyboard/mod_j/* ... ~/qmk_firmware/keyboards/gh60/satan/keymaps/layertwo
ln -fs ~/keyboard/lily58/* ... ~/qmk_firmware/keyboards/lily58/keymaps/layertwo
