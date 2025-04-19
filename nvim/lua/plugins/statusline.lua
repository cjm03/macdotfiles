return {
    "nvim-lualine/lualine.nvim",
    dependencies = { "echasnovski/mini.icons" },
    config = function()
        require("lualine").setup({
            options = {
                --theme = "moonfly",
                -- theme = "auto",
                theme = "onedark",
                global_status = false,
                section_separators = '',
                component_separators = '',
            },
        })
    end
}
