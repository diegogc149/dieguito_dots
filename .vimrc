set number
set mouse=a
syntax on
set termguicolors
colorscheme torte
set ruler
set showcmd
"========Plugins=========

nnoremap <C-n> :NERDTreeToggle<CR>
let g:netrw_list_hide = ''
let g:netrw_liststyle = 3
let g:netrw_hide = 0
call plug#begin('~/.vim/plugged')
Plug 'francoiscabrol/ranger.vim'
Plug 'rbgrouleff/bclose.vim'
Plug 'neoclide/coc.nvim', {'branch':'release'}
Plug 'honza/vim-snippets'
Plug 'SirVer/ultisnips'
call plug#end()

inoremap ( ()<left>
inoremap < <><left>
inoremap ' ''<left>
inoremap " ""<left>
inoremap { {}<left>
inoremap [ []<left>
inoremap ¿ ¿?<left>
inoremap ¡ ¡!<left>
inoremap ===== ====================()====================<left><left><left><left><left><left><left><left><left><left><left><left><left><left><left><left><left><left><left><left><left>
inoremap <C-s> <Esc>:w<Enter>i<right>
" Activar autocompletado con <Tab> y <Enter>
inoremap <silent><expr> <TAB> pumvisible() ? "\<C-n>" : "\<TAB>"
inoremap <silent><expr> <S-TAB> pumvisible() ? "\<C-p>" : "\<S-TAB>"
inoremap <silent><expr> <CR> pumvisible() ? coc#_select_confirm() : "\<CR>"

" Mostrar sugerencias automáticas
set updatetime=300
set shortmess+=c
set signcolumn=auto


" Snippets (para usar ultisnips)
let g:coc_snippet_next = '<tab>'

