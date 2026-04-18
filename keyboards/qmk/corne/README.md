# Corne QMK Layouts

This directory stores the source of truth for my wired Corne QMK layouts.

Current assumptions:

- USB device identifies as `Corne Keyboard Rev.1 (Split Common)`
- QMK target: `crkbd/rev1`
- Bootloader observed during flashing: `ATm32U4DFU`

These files are versioned source only. Generated firmware artifacts are intentionally not committed.

## Layouts

- `shared/`: first-pass layout intended to mirror the Corne-ish Zen homerow mods and layer model

## Workflow

1. Install the QMK toolchain from the Brewfile:

   `chezmoi apply ~/.Brewfile`

   `brew bundle --global`

2. Set up the local QMK checkout once:

   `qmk setup -H ~/qmk_firmware`

3. Build the Corne firmware with the repo-local wrapper:

   `./keyboards/scripts/build-corne.sh`

4. Flash a Corne half while it is in DFU bootloader mode:

   `./keyboards/scripts/flash-corne.sh`

## Notes

- The wrapper scripts set the required QMK compiler toolchain PATH explicitly, so normal shell startup files do not need QMK-specific path entries.
- Both halves should be flashed with the same firmware.
- Reconnect the TRRS cable only while the keyboard is unpowered.
