# If you come from bash you might have to change your $PATH.
# export PATH=$HOME/bin:/usr/local/bin:$PATH

export ZSH="$HOME/.oh-my-zsh"

ZSH_THEME="agnosterzak"

plugins=( 
    git
    zsh-autosuggestions
    zsh-syntax-highlighting
)

source $ZSH/oh-my-zsh.sh


# Display Pokemon-colorscripts
# Project page: https://gitlab.com/phoneybadger/pokemon-colorscripts#on-other-distros-and-macos
#pokemon-colorscripts 

# fastfetch. Will be disabled if above colorscript was chosen to install
fastfetch -c $HOME/.config/fastfetch/config.jsonc

# Set-up icons for files/directories in terminal using lsd
alias ls='lsd'
alias l='ls -l'
alias la='ls -a'
alias lla='ls -la'
alias lt='ls --tree'
alias hidamari='flatpak run io.github.jeffshee.Hidamari'

alias drivel4='brave-browser https://bit.ly/Drive_L4'
alias drivecct='brave-browser https://bit.ly/DriveFIEE-CCT'
alias ccpp='brave-browser https://sites.google.com/view/ccppuni/'
alias whatsdesk='/opt/whatsdesk/whatsdesk --enable-features=UseOzonePlatform --ozone-platform=wayland --disable-smooth-scrolling'
export SAL_USE_VCLPLUGIN=gtk3

alias minecraft='flatpak run org.prismlauncher.PrismLauncher'
alias discord='discord --enable-features=UseOzonePlatform --ozone-platform-hint=auto'
alias ytm='youtube-music --enable-features=UseOzonePlatform --ozone-platform=wayland' 

export NVM_DIR="$HOME/.nvm"
[ -s "$NVM_DIR/nvm.sh" ] && \. "$NVM_DIR/nvm.sh"  # This loads nvm
[ -s "$NVM_DIR/bash_completion" ] && \. "$NVM_DIR/bash_completion"  # This loads nvm bash_completion

if [ -z "$SSH_AUTH_SOCK" ]; then
    eval "$(ssh-agent -s)" > /dev/null
    ssh-add ~/.ssh/github 2>/dev/null
fi
