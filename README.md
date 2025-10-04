# dotfiles

Personal dotfiles managed by [chezmoi](https://chezmoi.io).

## Usage

### Install

Install chezmoi and apply dotfiles:

```
sh -c "$(curl -fsLS get.chezmoi.io)" -- init --apply mschoening
```

This will prompt for:

- Name
- Email
- GPG Key ID (optional, for commit signing)

### Update

```
chezmoi update
```

## What's Included

- **fish**: Shell with atuin and zoxide integration
- **nvim**: LazyVim-based Neovim setup with Gruvbox Hard theme
- **ghostty**: Terminal emulator with Berkeley Mono font
- **zellij**: Terminal multiplexer
- **git**: Git configuration with 1Password SSH signing (macOS)
- **bat**, **btop**: CLI utilities
