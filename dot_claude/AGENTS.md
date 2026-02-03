# Agent Protocol

Personal agent guardrails for max. Read fully before any task.

## Contact & Identity
- GitHub: max
- Workspace: `~/Developer/` (personal: `max/`, oss: `oss/<org>/`, work: `makenotion/`)
- Dotfiles: `~/.local/share/chezmoi/` (managed by chezmoi)

## File & Workspace Rules
- Never edit files outside the current project without explicit permission
- Prefer editing existing files over creating new ones
- No new markdown/doc files unless explicitly requested
- Keep files under ~500 LOC; split when it improves clarity

## Git Safety (Critical)
- NEVER run destructive commands without explicit consent: `push --force`, `reset --hard`, `clean -f`, `branch -D`
- NEVER skip hooks (`--no-verify`) unless explicitly requested
- NEVER amend commits unless explicitly requested (create NEW commits after hook failures)
- Prefer staging specific files over `git add .` or `git add -A`
- Use `~/.claude/scripts/committer` when available for safer commits

## Commit Style
- Follow Conventional Commits: `type(scope): message`
- Types: feat, fix, refactor, docs, test, chore, style
- Keep messages concise, imperative mood ("add" not "added")
- Include `Co-Authored-By: Claude <noreply@anthropic.com>` when Claude contributes

## PR Workflow
- Use `gh` CLI for all GitHub operations (not web UI)
- Review: `gh pr view`, `gh pr diff` — do NOT switch branches during review
- Create: `gh pr create --title "..." --body "..."`
- Always include test plan in PR body

## Development Preferences
- Languages: TypeScript, Go, Swift, Rust, Fish shell
- Editor: Neovim (LazyVim config)
- Terminal: Ghostty + Zellij
- Shell: Fish with atuin (history) and zoxide (cd)
- Prefer CLIs over MCPs when available

## Code Style
- No over-engineering; minimal changes for the task at hand
- No speculative features or premature abstractions
- Comments only for non-obvious logic
- No emojis in code/docs unless explicitly requested

## Testing
- Run tests before committing when touching logic
- Verify changes work before marking complete

## Multi-Agent Safety
- Do NOT create/apply/drop git stash unless explicitly requested
- Do NOT switch branches unless explicitly requested
- Do NOT create/modify git worktrees unless explicitly requested
- Keep changes scoped; don't touch unrelated files
- When multiple agents active, focus on your assigned task only

## Critical Thinking
- Fix root cause, not symptoms
- Verify in code before answering; don't guess
- Escalate blockers rather than working around them
- Leave breadcrumb notes in code for tricky decisions

## Shorthand Commands
- `sync`: commit changes (sensible message), pull --rebase, push
- `gate`: run lint + build + test before committing

## Tools Reference
See `~/.claude/tools.md` for available CLI tools.

## Notes
<!-- Add notes here when issues occur. Let the agent update this section. -->
