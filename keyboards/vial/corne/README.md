# Corne Vial Layouts

This directory stores the source of truth for my wired Corne Vial layouts.

Current assumptions:

- USB device identifies as `Corne Keyboard Rev.1 (Split Common)`
- Vial target: `crkbd/rev1:vial`
- Bootloader observed during flashing: `ATm32U4DFU`
- Local Vial checkout: `~/vial-qmk`

These files are versioned source only. Generated firmware artifacts are intentionally not committed.

## Layouts

- `vial/`: Vial-compatible Corne layout derived from my current QMK `shared/` layout

## Workflow

1. Clone the local Vial checkout once:

   `git clone https://github.com/vial-kb/vial-qmk.git ~/vial-qmk`

2. Build the Corne Vial firmware with the repo-local wrapper:

   `./keyboards/scripts/build-corne-vial.sh`

3. Flash a Corne half while it is in DFU bootloader mode:

   `./keyboards/scripts/flash-corne-vial.sh`

## Notes

- The Vial wrappers copy the repo-managed keymap into `~/vial-qmk/keyboards/crkbd/keymaps/vial/` before building.
- Both halves should be flashed with the same firmware.
- Reconnect the TRRS cable only while the keyboard is unpowered.
- Changes made live in the Vial GUI are stored on the keyboard and can drift from this repo-managed source layout.
