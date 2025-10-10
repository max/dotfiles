---
auto_approve_tools:
  - mcp__notion
---

# Claude Command: Implement

A command that fetches a task from Notion and in the current directory implements the task for the repository.

## Usage

```
/implement $ARGUMENTS
```

## What This Command Does

1. Fetch the task based on the provided URL in $ARGUMENTS.
2. Plan the best course of action.
3. Thoroughly implement the task.
4. Mark the task with a status of `Waiting`.
