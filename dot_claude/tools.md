# Tools Reference

CLI tools available on this machine. Prefer these over MCPs.

## Core Development

**gh** — GitHub CLI for PRs, issues, workflows, releases.
```bash
gh pr view 123
gh pr create --title "..." --body "..."
gh issue list
gh api repos/owner/repo/...
```

**chezmoi** — Dotfiles manager. Source: `~/.local/share/chezmoi`
```bash
chezmoi diff          # Preview changes
chezmoi apply         # Apply changes
chezmoi add ~/.file   # Add file to management
chezmoi git status    # Git ops in source dir
```

**nvim** — Neovim with LazyVim config. Gruvbox theme, `kj` = Esc.

## Shell & Navigation

**fish** — Primary shell. Config at `~/.config/fish/`

**atuin** — Shell history with fuzzy search. `Ctrl+R` to search.

**zoxide** — Smart cd. Use `z <partial>` to jump to frequent dirs.

**bat** — Better cat with syntax highlighting.

**btop** — System monitor.

## Project Tools

**committer** — Safe git commit helper
```bash
~/.claude/scripts/committer "feat: add feature" file1.ts file2.ts
```
Prevents `git add .`, validates files exist, handles lock files.

## Container & Infra

**docker** — Container runtime (if installed)

**terraform** — Infrastructure as code (in `~/Developer/max/terraform/`)

## Notes
<!-- Add new tools here as they're installed -->
