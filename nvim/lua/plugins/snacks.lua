return {
    {
        "folke/snacks.nvim",
        priority = 1000,
        lazy = false,
        opts = {
            image = {
                enabled = true,
                doc = { enabled = true, },
            },
            explorer = {
                enabled = false,
                layout = { cycle = true, }
            },
            quickfile = {
                enabled = true,
                exclude = { "latex" },
            },
            picker = {
                enabled = true,
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
                    { section = "header" },
                },
            },
        },
        keys = {

        }
    }
}
