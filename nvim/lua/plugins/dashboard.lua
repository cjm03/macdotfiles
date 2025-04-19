return {
    "nvimdev/dashboard-nvim",
    enabled = false,
    event = "VimEnter",
    config = function()
        require("dashboard").setup({
            -- theme = 'hyper'
            theme = 'doom'
        })
    end,
    dependencies = { {"nvim-tree/nvim-web-devicons"} }
}
