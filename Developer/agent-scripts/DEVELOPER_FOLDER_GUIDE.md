# Developer Folder Organization Guide

## Base Directory
`~/Developer/`

## Top-Level Structure

```
Developer/
├── max/           # Personal projects & personal open source (GitHub: max)
├── oss/           # Cloned repositories from other people/organizations
└── makenotion/    # Notion-related projects (notion-next codebase, etc.)
```

## Folder Details

### `max/`
- Your personal GitHub username
- All personal projects
- Your personal open source contributions

### `oss/`
- Cloned repositories from other developers/organizations
- **Organized by GitHub organization name**
- Derive org name from the git remote URL

Example structure:
```
oss/
├── google/
│   └── gmail-sdk/
├── facebook/
│   └── react/
├── microsoft/
│   └── vscode/
└── anthropics/
    └── claude-code/
```

### `makenotion/`
- Notion-related projects
- Contains `notion-next` codebase
- Currently exists with: notion-next, tmp-ajax-tail, tmp-plot

## Notes
- All folder names are lowercase
- For `oss/`: extract org from remote URL (e.g., `github.com/google/repo` → `oss/google/repo`)
