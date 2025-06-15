return {
    "nvim-telescope/telescope.nvim",
    branch = "0.1.x",
    dependencies = {
        "nvim-lua/plenary.nvim",
        { "nvim-telescope/telescope-fzf-native.nvim", build = "make" },
        "nvim-tree/nvim-web-devicons",
    },
    config = function()
        require("telescope").setup({
            extensions = {
                fzf = {
                    fuzzy = true,
                    override_generic_sorter = true,
                    override_file_sorter = true,
                    case_mode = "smart_case",
                },
            },
            pickers = {
                colorscheme = {
                    enable_preview = true,
                },
                find_files = {
                    hidden = true,
                },
            },
        })
        require("telescope").load_extension("fzf")
        local builtin = require("telescope.builtin")
        vim.keymap.set("n", "<leader>ff", ":Telescope find_files<CR>", {})
        vim.keymap.set("n", "<leader>fg", builtin.live_grep, { desc = "livegrep" })
        vim.keymap.set("n", "<leader>fd", builtin.diagnostics, { desc = "diagnostics" })
        vim.keymap.set("n", "<leader>fs", builtin.lsp_document_symbols, { desc = "lsp document symbols" })
    end,
}
