return {
    "mikavilpas/yazi.nvim",
    event = "VeryLazy",
    dependencies = { "folke/snacks.nvim" },
    keys = {
        {
            "<leader>yo",
            "<cmd>Yazi<cr>",
            desc = "Open yazi at the current file",
        },
        {
            "<leader>yw",
            "<cmd>Yazi cwd<cr>",
            desc = "Open yazi in nvim's working directory",
        },
        {
            "<leader>ye",
            "<cmd>Yazi toggle<cr>",
            desc = "Resume last yazi session",
        },
    },
    opts = {
        open_for_directories = false,
        keymaps = { show_help = "<f1>", },
    },
}
