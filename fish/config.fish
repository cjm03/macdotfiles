if status is-interactive
    # Commands to run in interactive sessions can go here
end
eval "$(/opt/homebrew/bin/brew shellenv)"
# ❱  best version
# ❯  U+276F
# ❮  U+276E
# set --global hydro_symbol_prompt '❱❱'
# set --global hydro_color_pwd C48DFF
set fish_greeting
set -Ux XDG_CONFIG_HOME $HOME/.config
set -gx EDITOR nvim
set -gx LANG en_US.UTF-8

set -g alt a7ab93 
set -g constant b0b58a 
set -g comment 696969 
set -g fg adacac 
set -g func 808796 
set -g keyword a18b7f 
set -g number b5ae84 
set -g operator 856b6c 
set -g property 9c797d 
set -g str 8a968f 
set -g type 8a879c 
# Syntax Highlighting Colors
set -g fish_color_normal adacac
set -g fish_color_command 808796
set -g fish_color_keyword a18b7f
set -g fish_color_quote 8a968f
set -g fish_color_redirection b0b58a
set -g fish_color_end 856b6c
set -g fish_color_error 9e5560
set -g fish_color_param adacac
set -g fish_color_valid_path 8a879c
set -g fish_color_option a7ab93
set -g fish_color_comment 696969
set -g fish_color_selection --background=1b1c1d
set -g fish_color_operator 856b6c
set -g fish_color_escape a18b7f
set -g fish_color_autosuggestion 696969
set -g fish_color_cwd 8a968f
set -g fish_color_hostname b5ae84
set -g fish_color_status 9e5560
set -g fish_color_cancel b5ae84
set -g fish_color_search_match --background=1b1c1d
# Completion Pager Colors
set -g fish_pager_color_progress a7ab93
set -g fish_pager_color_prefix 8a879c
set -g fish_pager_color_completion adacac
set -g fish_pager_color_description 696969
set -g fish_pager_color_selected_prefix a7ab93
set -g fish_pager_color_selected_completion a7ab93
set -g fish_pager_color_selected_background --background=1b1c1d

# -- alias -- #
alias cat="bat -p"                              # BAT: like cat but colorful   
alias ls="eza"                                  # EZA: better ls
alias la="eza --long --header --icons --all"    # EZA: alias for ls -alnh7ggggggggggqfgasiduft7
alias tree="eza --tree"                         # EZA: better tree
alias fd="fd -HI"                               # FD: IDEK WHAT THIS DOES
alias cd="z"                                    # ZOXIDE: TESTING
alias ystart="yabai --start-service"            # YABAI: start yabai so focus follows mouse
alias ystop="yabai --stop-service"              # YABAI: stop yabai bc its lowkey weird

zoxide init fish | source
