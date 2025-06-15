return {
    {
        "folke/snacks.nvim",
        priority = 1000,
        lazy = false,
        opts = {
            indent = {
                priority = 1,
                enabled = true,
                char = "│",
                only_scope = false,
                only_current = false,
                hl = "SnacksIndent",
            },
            animate = { enabled = false },
            image = {
                enabled = true,
                doc = { enabled = true, },
            },
            explorer = { enabled = false, layout = { cycle = true, } },
            quickfile = { enabled = true, exclude = { "latex" }, },
            picker = {
                enabled = false,
                formatters = {
                    file = {
                        filename_first = false,
                        filename_only = false,
                        icon_width = 2,
                    },
                },
                layout = {
                    preset = "ivy",
                    cycle = false,
                },
                layouts = {
                    ivy = {
                        layout = {
                            box = "vertical",
                            backdrop = false,
                            width = 0,
                            height = 0.4,
                            position = "bottom",
                            border = "top",
                            title = " {title} {live} {flags}",
                            title_pos = "left",
                            { win = "input", height = 1, border = "bottom" },
                            {
                                box = "horizontal",
                                { win = "list", border = "none" },
                                { win = "preview", title = "{preview}", width = 0.5, border = "left" },
                            },
                        },
                    },
                }
            },
            dashboard = {
                enabled = true,
                sections = {
                    { section = "header" }
--                     {
--                         title = [[
--  ██████╗██╗      █████╗ ███╗   ██╗ ██████╗ 
-- ██╔════╝██║     ██╔══██╗████╗  ██║██╔════╝ 
-- ██║     ██║     ███████║██╔██╗ ██║██║  ███╗
-- ██║     ██║     ██╔══██║██║╚██╗██║██║   ██║
-- ╚██████╗███████╗██║  ██║██║ ╚████║╚██████╔╝
--  ╚═════╝╚══════╝╚═╝  ╚═╝╚═╝  ╚═══╝ ╚═════╝ ]], 
--                     },
                    -- {
                    --     { title = " " }, --, gap = 1 },
                    --     { section = "header" },
                    --     { title = " " },
                    --     {
                    --         section = "terminal",
                    --         cmd = "chafa ~/Pictures/locals/wallpapers/dimlandscape.jpg --format symbols --symbols wedge --size 64x16 --stretch",
                    --         height = 16,
                    --     },
                    -- },
                    -- {
                    --     { title = " ", pane = 2 },
                    --     { section = "startup", pane = 2 },
                    --     { title = " ", pane = 2 },
                    --     {
                    --         section = "terminal",
                    --         pane = 2,
                    --         cmd = "chafa ~/Pictures/locals/wallpapers/rain-cartoony.png --format symbols --symbols wedge --size 64x16 --stretch",
                    --         height = 16
                    --     },
                    --     { title = " ", pane = 2, gap = 1 },
                    --     { section = "keys", pane = 2 },
                    -- },
                },
            },
        },
        keys = {

        }
    }
}
