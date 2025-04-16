vim.g.loaded_netrw = 1
vim.g.loaded_netrwPlugin = 1

local lazypath = vim.fn.stdpath("data") .. "/lazy/lazy.nvim"
if not vim.loop.fs_stat(lazypath) then
	vim.fn.system({
		"git",
		"clone",
		"--filter=blob:none",
		"https://github.com/folke/lazy.nvim.git",
		"--branch=stable",
		lazypath
	})
end
vim.opt.rtp:prepend(lazypath)

require("vimopts")
require("lazy").setup("plugins")
vim.api.nvim_set_hl(0, "LineNrAbsolute", { fg = "#BBC3D4", bg = "#080C10", bold = true })
vim.api.nvim_set_hl(0, "LineNrRelative", { fg = "#656D87", bg = "#080C10" })
--vim.api.nvim_set_hl(0, "LineNrAbsolute", { fg = "#BBC3D4", bg = "#242933", bold = true })
--vim.api.nvim_set_hl(0, "LineNrRelative", { fg = "#656D87", bg = "#242933" })
