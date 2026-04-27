#!/usr/bin/env bash
set -euo pipefail

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
VIAL_QMK_HOME="${VIAL_QMK_HOME:-$HOME/vial-qmk}"
FIRMWARE="${VIAL_QMK_HOME}/crkbd_rev1_vial.hex"

dfu-programmer atmega32u4 erase --force
dfu-programmer atmega32u4 flash "${FIRMWARE}"
dfu-programmer atmega32u4 reset
