--+ Vesper Theme +--
-- return {
--    "datsfilipe/vesper.nvim",
--    lazy = false,
--    priority = 1000,
--    config = function()
--        require("vesper").setup({
--            italics = {
--                comments = false,
--                keywords = false,
--                functions = false,
--                strings = false,
--                variables = false,
--            },
--        })
--        vim.cmd("colorscheme vesper")
--    end
-- }

--+ Nordic Theme +--
--return {
--    "AlexvZyl/nordic.nvim",
--    lazy = false,
--    priority = 1000,
--    config = function()
--        require("nordic").load()
--        vim.cmd("colorscheme nordic")
--    end
--}

--+ Midnight Theme +---
return {
    "dasupradyumna/midnight.nvim",
    lazy = false,
    priority = 1000,
    config = function()
        require("midnight").setup({
            --optional setup here !
        })
        vim.cmd("colorscheme midnight")
    end
}

--+ E-Ink Theme +--
-- return {
--     "alexxGmZ/e-ink.nvim",
--     lazy = false,
--     priority = 1000,
--     config = function()
--         require("e-ink").setup()
--         vim.cmd("colorscheme e-ink")
--     end
-- }

