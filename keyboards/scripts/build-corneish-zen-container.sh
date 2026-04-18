#!/usr/bin/env bash
set -euo pipefail

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
REPO_ROOT="$(cd "${SCRIPT_DIR}/../.." && pwd)"
ZEN_ROOT="${REPO_ROOT}/keyboards/zmk/corneish-zen"
WORKSPACE_ROOT="${ZEN_ROOT}/.build/workspace"
CONFIG_DIR="${WORKSPACE_ROOT}/config"
LEFT_BUILD_DIR="${WORKSPACE_ROOT}/build/left"
RIGHT_BUILD_DIR="${WORKSPACE_ROOT}/build/right"
IMAGE="${ZMK_DOCKER_IMAGE:-docker.io/zmkfirmware/zmk-dev-arm:4.1-branch}"

if ! command -v docker >/dev/null 2>&1; then
  echo "Missing required command: docker" >&2
  exit 1
fi

mkdir -p "${WORKSPACE_ROOT}"
rsync -a --delete "${ZEN_ROOT}/config/" "${CONFIG_DIR}/"
rm -rf "${LEFT_BUILD_DIR}" "${RIGHT_BUILD_DIR}"

docker run --rm \
  --platform linux/arm64 \
  --user "$(id -u):$(id -g)" \
  -e HOME=/tmp \
  -v "${WORKSPACE_ROOT}:/workspaces/zmk" \
  -w /workspaces/zmk \
  "${IMAGE}" \
  bash -lc '
    set -euo pipefail

    if [ ! -d .west ]; then
      west init -l config
    fi

    west update
    west zephyr-export
    west build -p -s zmk/app -d /workspaces/zmk/build/left -b corneish_zen_left -- \
      -DZMK_CONFIG=/workspaces/zmk/config \
      -DCONFIG_ZMK_STUDIO=y

    west build -p -s zmk/app -d /workspaces/zmk/build/right -b corneish_zen_right -- \
      -DZMK_CONFIG=/workspaces/zmk/config
  '

echo
echo "Left firmware:"
find "${LEFT_BUILD_DIR}/zephyr" -maxdepth 1 \( -name '*.uf2' -o -name '*.bin' -o -name '*.hex' \) -print
echo
echo "Right firmware:"
find "${RIGHT_BUILD_DIR}/zephyr" -maxdepth 1 \( -name '*.uf2' -o -name '*.bin' -o -name '*.hex' \) -print
