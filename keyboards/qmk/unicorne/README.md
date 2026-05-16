# Boardsource Unicorne QMK Layouts

This directory stores the source of truth for my Boardsource Unicorne QMK layouts.

Current assumptions:

- QMK target: `boardsource/unicorne`
- Layout macro: `LAYOUT_split_3x6_3`
- Controller/bootloader: RP2040 UF2

These files are versioned source only. Generated firmware artifacts are intentionally not committed.

## Layouts

- `shared/`: mirrors the wired Corne `shared` layout, including home-row mods

## Workflow

1. Install the QMK toolchain from the Brewfile:

   `chezmoi apply ~/.Brewfile`

   `brew bundle --global`

2. Set up or update the local QMK checkout:

   `qmk setup -H ~/qmk_firmware`

3. Build the Unicorne firmware with the repo-local wrapper:

   `./keyboards/scripts/build-unicorne.sh`

4. Put the Unicorne into bootloader mode, then copy the generated UF2 from `~/qmk_firmware` to the mounted RP2040 bootloader volume.

## Notes

- This is QMK firmware for the Unicorne target, not the generic `crkbd/rev1` Corne target.
- The `QK_BOOT` key is on the left home-row pinky position in the `ADJUST` layer.
