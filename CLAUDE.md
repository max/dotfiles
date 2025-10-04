# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/claude-code) when working with code in this repository.

## Repository Overview

This is a **chezmoi-managed dotfiles repository**. Chezmoi manages configuration files across multiple machines securely using a source directory (`~/.local/share/chezmoi`) that is separate from the target location (`~` by default).

**Critical**: Never directly edit files in `~/.config` or other target locations. Always edit files in this repository and use `chezmoi apply` to sync changes.

## Chezmoi Naming Conventions

Chezmoi uses special prefixes to map source files to their target locations:

- `dot_` prefix → `.` (e.g., `dot_config/` → `~/.config/`)
- `.tmpl` suffix → File is a template that uses Go's `text/template` syntax
- Templates can access data from `.chezmoi.toml.tmpl` via variables like `{{ .user.name }}`, `{{ .gpg.keyid }}`, `{{ .chezmoi.os }}`

## Essential Commands

### Testing Changes
```bash
# Preview what would change (always run before apply)
chezmoi diff

# See what target state would be for a file
chezmoi cat ~/.config/git/config
```

### Applying Changes
```bash
# Apply all changes
chezmoi apply

# Apply specific file
chezmoi apply ~/.config/fish/config.fish
```

### Adding New Dotfiles
```bash
# Add an existing file to chezmoi
chezmoi add ~/.config/newapp/config

# Edit a file through chezmoi (opens source file)
chezmoi edit ~/.config/fish/config.fish
```

### Git Operations
```bash
# Git commands run in source directory
chezmoi git status
chezmoi git add .
chezmoi git commit -m "message"
chezmoi git push
```

## Repository Structure

### Configuration Applications

- **nvim/**: LazyVim-based Neovim setup
  - `init.lua`: Entry point that loads config.lazy
  - `lua/config/`: Core configuration (keymaps, options, autocmds)
  - `lua/plugins/`: Plugin configurations
  - Uses Gruvbox Hard colorscheme
  - Custom keymap: `kj` in insert mode → `<Esc>`

- **fish/**: Fish shell configuration
  - Integrates with: atuin (shell history), zoxide (directory jumping)
  - PATH additions: `/opt/homebrew/bin`, `~/.bun/bin`, `~/.local/bin`

- **git/**: Git configuration (templated)
  - Uses GPG signing with 1Password on macOS
  - Template variables: user.name, user.email, gpg.keyid

- **ghostty/**: Terminal emulator
  - Font: Berkeley Mono Variable
  - Theme: Gruvbox Dark Hard
  - Auto-launches zellij session "main" on startup

- **zellij/**: Terminal multiplexer
  - Layout: compact
  - Theme: gruvbox-dark

- **bat/**, **btop/**: Additional CLI tools

### Template System

`.chezmoi.toml.tmpl` prompts for:
- `user.name` / `user.email`: Used in git config
- `gpg.keyid`: Used for commit signing (optional)

OS-specific blocks use `{{ if (eq .chezmoi.os "darwin") }}` for macOS-specific config.

## Custom Claude Command

`/commit` - Quick git commit with minimal ceremony (see `dot_claude/commands/commit.md`)
