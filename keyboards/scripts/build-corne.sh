#!/bin/sh
set -eu

SCRIPT_DIR="$(CDPATH= cd -- "$(dirname "$0")" && pwd)"
REPO_ROOT="$(CDPATH= cd -- "$SCRIPT_DIR/../.." && pwd)"

. "$SCRIPT_DIR/qmk-env.sh"

if [ ! -d "$QMK_HOME/.git" ]; then
  echo "Missing qmk_firmware checkout at $QMK_HOME" >&2
  echo "Run: qmk setup -H \"$QMK_HOME\"" >&2
  exit 1
fi

mkdir -p "$QMK_HOME/keyboards/crkbd/keymaps/shared"
cp "$REPO_ROOT/keyboards/qmk/corne/shared/"* "$QMK_HOME/keyboards/crkbd/keymaps/shared/"

cd "$QMK_HOME"
qmk compile -kb crkbd/rev1 -km shared
