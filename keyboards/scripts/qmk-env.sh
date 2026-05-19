#!/bin/sh
set -eu

QMK_HOME="${QMK_HOME:-$HOME/qmk_firmware}"

export PATH="/opt/homebrew/bin:$PATH"
export PATH="/opt/homebrew/opt/arm-none-eabi-binutils/bin:$PATH"
export PATH="/opt/homebrew/opt/arm-none-eabi-gcc@8/bin:$PATH"
export PATH="/opt/homebrew/opt/avr-binutils/bin:$PATH"
export PATH="/opt/homebrew/opt/avr-gcc@8/bin:$PATH"

export QMK_HOME
