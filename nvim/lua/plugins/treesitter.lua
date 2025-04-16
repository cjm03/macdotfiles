return {
    "nvim-treesitter/nvim-treesitter",
    build = ":TSUpdate",
    config = function()
        local configs = require("nvim-treesitter.configs")

        configs.setup({
            ensure_installed = { "c", "bash", "lua", "vim", "vimdoc", "python", "markdown", "markdown_inline", "css", "regex", },
            highlight = { enable = true },
            indent = { enable = true },
        })
    end
}
