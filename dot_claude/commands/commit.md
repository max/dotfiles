---
auto_approve_tools:
  - Bash(git:*)
---

# Claude Command: Commit

Quick git commit with minimal ceremony.

## Usage

```
/commit
```

## What This Command Does

1. Check git status
2. If nothing staged, add all changes with `git add .`
3. Create a simple commit with a basic message based on the changes
4. Commit the changes
