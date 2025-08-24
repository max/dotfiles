set -U fish_greeting

fish_add_path /opt/homebrew/bin
fish_add_path $HOME/.bun/bin
fish_add_path $HOME/.local/bin

if status is-interactive
  atuin init fish | source
  zoxide init fish | source
end
