set -U fish_greeting

fish_add_path /opt/homebrew/bin

if status is-interactive
  atuin init fish | source
  zoxide init fish | source
end
