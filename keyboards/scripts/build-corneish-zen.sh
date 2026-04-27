#!/usr/bin/env bash
set -euo pipefail

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
REPO_ROOT="$(cd "${SCRIPT_DIR}/../.." && pwd)"
ZEN_ROOT="${REPO_ROOT}/keyboards/zmk/corneish-zen"
WORKSPACE_ROOT="${ZEN_ROOT}/.build/workspace"
CONFIG_DIR="${WORKSPACE_ROOT}/config"
LEFT_BUILD_DIR="${WORKSPACE_ROOT}/build/left"
RIGHT_BUILD_DIR="${WORKSPACE_ROOT}/build/right"
VENV_DIR="${WORKSPACE_ROOT}/.venv"
WEST_BIN="${VENV_DIR}/bin/west"
PYTHON_BIN="${VENV_DIR}/bin/python"

if ! command -v uv >/dev/null 2>&1; then
  echo "Missing required command: uv" >&2
  echo "Install uv first, or provide west on PATH." >&2
  exit 1
fi

mkdir -p "${WORKSPACE_ROOT}"
rsync -a --delete "${ZEN_ROOT}/config/" "${CONFIG_DIR}/"

if [ ! -x "${WEST_BIN}" ] || ! "${PYTHON_BIN}" -m pip --version >/dev/null 2>&1; then
  uv venv --clear --seed "${VENV_DIR}"
  uv pip install --python "${PYTHON_BIN}" west
fi

if [ ! -d "${WORKSPACE_ROOT}/.west" ]; then
  (
    cd "${WORKSPACE_ROOT}"
    "${WEST_BIN}" init -l config
  )
fi

cd "${WORKSPACE_ROOT}"
"${WEST_BIN}" update
"${WEST_BIN}" zephyr-export
"${WEST_BIN}" packages pip --install

"${WEST_BIN}" build -p -s zmk/app -d "${LEFT_BUILD_DIR}" -b corneish_zen_left -- \
  -DZMK_CONFIG="${CONFIG_DIR}" \
  -DCONFIG_ZMK_STUDIO=y

"${WEST_BIN}" build -p -s zmk/app -d "${RIGHT_BUILD_DIR}" -b corneish_zen_right -- \
  -DZMK_CONFIG="${CONFIG_DIR}"

echo
echo "Left firmware:"
find "${LEFT_BUILD_DIR}/zephyr" -maxdepth 1 \( -name '*.uf2' -o -name '*.bin' -o -name '*.hex' \) -print
echo
echo "Right firmware:"
find "${RIGHT_BUILD_DIR}/zephyr" -maxdepth 1 \( -name '*.uf2' -o -name '*.bin' -o -name '*.hex' \) -print
