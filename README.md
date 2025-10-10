# dotfiles

Personal dotfiles managed by [chezmoi](https://chezmoi.io) for a consistent development environment across machines.

## Overview

This repository contains configuration files for my development workflow, featuring:
- **Fish shell** with intelligent history and directory navigation
- **Neovim** with a fully-configured LazyVim setup
- **Ghostty** terminal with automatic Zellij multiplexing
- **Git** with GPG commit signing via 1Password

All configurations use the **Gruvbox Dark Hard** color scheme for visual consistency.

## Prerequisites

Before installation, ensure you have:

- **macOS** (primary target; Linux support via templating)
- **Homebrew** package manager: [brew.sh](https://brew.sh)
- **1Password** with SSH agent enabled (for GPG signing)
- **Berkeley Mono** font (for Ghostty): [berkeleygraphics.com](https://berkeleygraphics.com/typefaces/berkeley-mono/)

### Recommended Tools

These tools are configured but need to be installed separately:

```bash
brew install fish neovim git bat btop atuin zoxide ghostty
brew install --cask 1password
```

## Quick Start

### Initial Setup

Install chezmoi and apply dotfiles in one command:

```bash
sh -c "$(curl -fsLS get.chezmoi.io)" -- init --apply mschoening
```

During setup, you'll be prompted for:

- **Name**: Your full name (for Git commits)
- **Email**: Your email address (for Git commits)
- **GPG Key ID**: Optional, for commit signing via 1Password

### Update Existing Installation

Pull and apply the latest changes:

```bash
chezmoi update
```

## What's Included

### Shell Environment

- **fish** ([fishshell.com](https://fishshell.com))
  - **atuin**: Encrypted shell history sync
  - **zoxide**: Smart directory jumping (`z` command)
  - Custom PATH: Homebrew, Bun, local bins

### Editor

- **nvim** ([neovim.io](https://neovim.io))
  - **LazyVim** distribution with sensible defaults
  - **Gruvbox Hard** colorscheme
  - Custom keymap: `kj` in insert mode → `<Esc>`
  - Plugins configured in `lua/plugins/`

### Terminal

- **ghostty** ([ghostty.org](https://ghostty.org))
  - **Berkeley Mono Variable** font
  - Auto-launches Zellij session "main"
  - Gruvbox Dark Hard theme

- **zellij** ([zellij.dev](https://zellij.dev))
  - Compact layout
  - Gruvbox Dark theme

### Version Control

- **git**
  - GPG commit signing via 1Password (macOS)
  - Templated configuration using chezmoi variables
  - User info populated from setup prompts

### CLI Utilities

- **bat**: Syntax-highlighted `cat` replacement
- **btop**: Modern system monitor

## Customization

### Modifying Configurations

**Important**: Never edit files in `~/.config` directly. Always edit the source files in this repository.

```bash
# Edit a file (opens source in $EDITOR)
chezmoi edit ~/.config/nvim/init.lua

# Preview changes before applying
chezmoi diff

# Apply changes
chezmoi apply
```

### Adding New Dotfiles

```bash
# Add an existing config file to chezmoi
chezmoi add ~/.config/newapp/config.toml

# Commit and push
chezmoi cd
git add .
git commit -m "Add newapp configuration"
git push
```

### Template Variables

Templates use Go's `text/template` syntax and can access variables from `.chezmoi.toml.tmpl`:

- `{{ .user.name }}`: Your name
- `{{ .user.email }}`: Your email
- `{{ .gpg.keyid }}`: GPG key ID
- `{{ .chezmoi.os }}`: Operating system (darwin, linux, etc.)

Example OS-specific configuration:

```
{{ if eq .chezmoi.os "darwin" }}
# macOS-specific settings
{{ end }}
```

## Repository Structure

```
~/.local/share/chezmoi/          # Source directory
├── .chezmoi.toml.tmpl           # Template prompts
├── dot_config/                  # Maps to ~/.config/
│   ├── fish/
│   ├── nvim/
│   ├── ghostty/
│   ├── zellij/
│   └── git/
└── README.md
```

## Troubleshooting

### Check What Would Change

```bash
chezmoi diff
```

### View Rendered Template

```bash
chezmoi cat ~/.config/git/config
```

### Re-run Setup Prompts

```bash
chezmoi init
```

## Resources

- [chezmoi Documentation](https://www.chezmoi.io/user-guide/command-overview/)
- [LazyVim Documentation](https://www.lazyvim.org)
- [Fish Shell Tutorial](https://fishshell.com/docs/current/tutorial.html)
