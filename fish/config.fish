if status is-interactive
    # Commands to run in interactive sessions can go here
end

eval "$(/opt/homebrew/bin/brew shellenv)"
set fish_greeting
set -Ux XDG_CONFIG_HOME $HOME/.config


# -- exa -- #
alias ls="eza"
alias la="ls --long --header --icons --all"
# -- fd -- #
alias fd="fd -HI"

set -gx EDITOR nvim
set -gx LANG en_US.UTF-8
