return {
    "nvim-tree/nvim-tree.lua",
    version = "*",
    lazy = false,
    dependencies = { "nvim-tree/nvim-web-devicons", },
    config = function()
        require("nvim-tree").setup({
            filters = {
                dotfiles = true,
            },
        })
        vim.keymap.set('n', '<leader>ee', ':NvimTreeFocus<CR>')
        vim.keymap.set('n', '<leader>ex', ':NvimTreeToggle<CR>')
    end
}
