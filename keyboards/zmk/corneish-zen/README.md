# Corne-ish Zen ZMK Config

This directory stores the source of truth for my Corne-ish Zen ZMK config.

Current source:

- GitHub repo: <https://github.com/max/zmk-config-zen-2>
- Forked from `LOWPROKB/zmk-config-zen-2`

Files checked in here are the minimal config sources used to build firmware:

- `build.yaml`
- `config/corneish_zen.keymap`
- `config/corneish_zen.conf`
- `config/west.yml`

Generated firmware artifacts are intentionally not committed.

## Local builds

To keep the Zephyr workspace and generated artifacts out of the tracked config,
use the local wrapper script from the repo root:

```bash
./keyboards/scripts/build-corneish-zen.sh
```

This creates a temporary ZMK workspace under `keyboards/zmk/corneish-zen/.build/`,
syncs dependencies there, and emits separate left/right firmware artifacts.

## Container builds

If you prefer not to install the Zephyr SDK on the host, use the Docker wrapper:

```bash
./keyboards/scripts/build-corneish-zen-container.sh
```

This uses the official ARM ZMK dev image and writes the workspace and firmware
artifacts under `keyboards/zmk/corneish-zen/.build/`.
