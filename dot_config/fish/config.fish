set -U fish_greeting

set -gx EDITOR nvim
set -gx VISUAL nvim

fish_add_path $HOME/.bun/bin
fish_add_path $HOME/.cargo/bin
fish_add_path $HOME/.local/bin
fish_add_path /opt/homebrew/bin

if status is-interactive
    atuin init fish | source
    zoxide init fish | source
end

direnv hook fish | source
