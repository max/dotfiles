#!/bin/sh
set -eu

SCRIPT_DIR="$(CDPATH= cd -- "$(dirname "$0")" && pwd)"

. "$SCRIPT_DIR/qmk-env.sh"

"$SCRIPT_DIR/build-corne.sh"

HEX="$QMK_HOME/crkbd_rev1_shared.hex"

if [ ! -f "$HEX" ]; then
  echo "Missing firmware artifact: $HEX" >&2
  exit 1
fi

dfu-programmer atmega32u4 erase --force
dfu-programmer atmega32u4 flash "$HEX"
dfu-programmer atmega32u4 reset
