return {
    "nvim-lualine/lualine.nvim",
    dependencies = { "echasnovski/mini.icons" },
    config = function()
        require("lualine").setup({
            options = {
                --theme = "moonfly",
                --theme = "auto",
                theme = "palenight",
                --global_status = true,
                section_separators = '',
                component_separators = '',
            },
        })
    end
}
