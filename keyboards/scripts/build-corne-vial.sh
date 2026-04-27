#!/usr/bin/env bash
set -euo pipefail

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
REPO_ROOT="$(cd "${SCRIPT_DIR}/../.." && pwd)"

# shellcheck source=keyboards/scripts/qmk-env.sh
source "${SCRIPT_DIR}/qmk-env.sh"

VIAL_QMK_HOME="${VIAL_QMK_HOME:-$HOME/vial-qmk}"
SOURCE_DIR="${REPO_ROOT}/keyboards/vial/corne/vial"
TARGET_DIR="${VIAL_QMK_HOME}/keyboards/crkbd/keymaps/vial"

mkdir -p "${TARGET_DIR}"
cp "${SOURCE_DIR}/keymap.c" "${TARGET_DIR}/keymap.c"
cp "${SOURCE_DIR}/config.h" "${TARGET_DIR}/config.h"
cp "${SOURCE_DIR}/rules.mk" "${TARGET_DIR}/rules.mk"
cp "${SOURCE_DIR}/vial.json" "${TARGET_DIR}/vial.json"

make -C "${VIAL_QMK_HOME}" crkbd/rev1:vial
