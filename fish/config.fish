if status is-interactive
    # Commands to run in interactive sessions can go here
end

eval "$(/opt/homebrew/bin/brew shellenv)"
set fish_greeting
set -Ux XDG_CONFIG_HOME $HOME/.config
set -gx EDITOR nvim
set -gx LANG en_US.UTF-8

# -- alias -- #
alias cat="bat -p"                              # BAT: like cat but colorful   
alias ls="eza"                                  # EZA: better ls
alias la="eza --long --header --icons --all"    # EZA: alias for ls -alnh7ggggggggggqfgasiduft7
alias tree="eza --tree"                         # EZA: better tree
alias fd="fd -HI"                               # FD: IDEK WHAT THIS DOES
alias cd="z"                                    # ZOXIDE: TESTING

zoxide init fish | source
