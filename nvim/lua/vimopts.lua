vim.cmd("set expandtab")
vim.cmd("set tabstop=4")
vim.cmd("set softtabstop=4")
vim.cmd("set shiftwidth=4")
vim.cmd("set clipboard+=unnamedplus")

vim.opt.swapfile = false
vim.opt.relativenumber = true
vim.opt.number = true
vim.opt.wrap = false
vim.opt.cursorline = false
vim.opt.scrolloff = 50
--vim.opt.sidescrolloff = 5
--vim.opt.ignorecase = true
--vim.opt.smartcase = true
vim.opt.showmode = false
vim.opt.cmdheight = 0
vim.opt.background = "dark"
vim.opt.termguicolors = true
vim.opt.fillchars:append { vert = " " }
vim.opt.fillchars:append { eob = " " }
vim.o.statuscolumn = [[%!v:lua.StatusColumn()]]


function _G.StatusColumn()
    local relnum = vim.v.relnum
    local linenum = vim.v.lnum
    if relnum == 0 then
        --return string.format(" %d", linenum) --left-align absolute num
        return "%#LineNrAbsolute#"..string.format(" %d", linenum) --left-align absolute num
    else
        return "%#LineNrRelative#"..string.format("  %d", relnum)   --right-align relative num
        --return "%#LineNrRelative#"..string.format(" %-3d", relnum)   --right-align relative num
    end
end
--vim.o.signcolumn = "yes"
--vim.o.laststatus = 3

vim.g.mapleader = " "
vim.keymap.set('i', 'jk', '<ESC>', { desc = "exit insert mode" })

-- tabs --
vim.keymap.set('n', '<leader>to', '<cmd>tabnew<CR>', {})
vim.keymap.set('n', '<leader>tx', '<cmd>tabclose<CR>', {})
vim.keymap.set('n', '<leader>tn', '<cmd>tabn<CR>', {})
vim.keymap.set('n', '<leader>tp', '<cmd>tabp<CR>', {})
vim.keymap.set('n', '<leader>tf', '<cmd>tabnew %<CR>', {})

-- panes --
vim.keymap.set('n', '<c-k>', ':wincmd k<CR>')
vim.keymap.set('n', '<c-j>', ':wincmd j<CR>')
vim.keymap.set('n', '<c-h>', ':wincmd h<CR>')
vim.keymap.set('n', '<c-l>', ':wincmd l<CR>')
--vim.api.nvim_set_hl(0, "LineNrAbsolute", { fg = "#C0C8D0", bg = "#242933" })
--vim.api.nvim_set_hl(0, "LineNrRelative", { fg = "#BBC3D4", bg = "#242933" })
--vim.api.nvim_set_hl(0, "WinSeparator", { fg = "#303446", bg = "NONE" })
