return {
    
---------------mason.nvim--------------------------------------------------------

    {
        "williamboman/mason.nvim",
        lazy = false,
        config = function()
            require("mason").setup()
        end,
    },
    
---------------mason-lspconfig.nvim----------------------------------------------

    {
        "williamboman/mason-lspconfig.nvim",
        lazy = false,
        --opts = { auto_install = true, },
        config = function()
            require("mason-lspconfig").setup({
                ensure_installed = { "pylsp", 
                    "clangd",
                    "lua_ls",
                    "intelephense",
                    "bashls",
                    "html"
                },
            })
        end,
    },
    
---------------nvim-lspconfig----------------------------------------------------

    {
        "neovim/nvim-lspconfig",
        lazy = false,
        config = function()
            local cmp_nvim_lsp = require("cmp_nvim_lsp")
            local capabilities = vim.tbl_deep_extend(
                "force",
                {},
                vim.lsp.protocol.make_client_capabilities(),
                cmp_nvim_lsp.default_capabilities()
            )

            local lspconfig = require("lspconfig")

            lspconfig.pylsp.setup({
                capabilities = capabilities,
            })

            lspconfig.lua_ls.setup({
                capabilities = capabilities,
            })

            lspconfig.html.setup({
                capabilities = capabilities,
                filetypes = { "html", "php", "css", "javascript", "typescript", "jsx", "tsx", },
            })

            lspconfig.bashls.setup({
                capabilities = capabilities,
            })
            
            lspconfig.intelephense.setup({
                capabilities = capabilities,
            })

            require("lspconfig").clangd.setup({
                cmd = {
                    "clangd",
                    "--compile-commands-dir=build",
                    "--background-index",
                    "--clang-tidy",
                    "--log=verbose",
                    "--header-insertion=iwyu",
                    "--completion-style=detailed",
                    "--function-arg-placeholders",
                    "--fallback-style=llvm",
                },
                init_options = {
                    usePlaceholders = true,
                    completeUnimported = true,
                    clangdFileStatus = true,
                },
                filetypes = { "c", "objc", "h", "cpp" },
                capabilities = capabilities,
            })

            vim.keymap.set("n", "K", vim.lsp.buf.hover, {})
            vim.keymap.set("n", "<leader>gd", vim.lsp.buf.definition, { desc = "definition" })
            vim.keymap.set("n", "<leader>gr", vim.lsp.buf.references, { desc = "references" })
            vim.keymap.set("n", "<leader>ca", vim.lsp.buf.code_action, { desc = "codeaction" })
            vim.keymap.set("n", "<leader>go", vim.diagnostic.open_float, { desc = "open diagnostic float" })
            --vim.keymap.set("n", "<leader>g", vim.lsp.buf.rename, {})
        end,
    },
}
