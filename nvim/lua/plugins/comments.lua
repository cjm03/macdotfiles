return {
    "numToStr/Comment.nvim",
    opts = {},
    config = function()
        require("Comment").setup({
        })
    end
}
-- NORMAL MODE
-- 'gcc'         :   Toggles current line using linewise comment
-- 'gbc'         :   Toggles current line using blockwise comment
-- '[count]gcc'  :   Toggles number of lines as a prefix-count using linewise
-- '[count]gbc'  :   Toggles number of lines as a prefix-count using blockwise
--
-- VISUAL MODE
-- 'gc'          :   Toggles the region using linewise comment
-- 'gb'          :   Toggles the region using blockwise comment
