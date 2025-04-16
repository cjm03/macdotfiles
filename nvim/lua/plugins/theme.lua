--+ Vesper Theme +--

--return {
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
--}

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

--+ Github Theme +--

--return {
--    "projekt0n/github-nvim-theme",
--    name = 'github-theme',
--    lazy = false,
--    priority = 1000,
--    config = function()
--        require("github-theme").setup({
--            -- ...
--        })
--        vim.cmd("colorscheme github_dark_high_contrast")
--    end
--}


