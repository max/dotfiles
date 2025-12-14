return {
  {
    "folke/snacks.nvim",
    opts = {
      scroll = { enabled = false },
      indent = {
        animate = { enabled = false },
        scope = {
          hl = "SnacksIndentScopeSubtle",
        },
      },
    },
    config = function(_, opts)
      -- Set up snacks with options
      require("snacks").setup(opts)

      -- Use a more subtle gray for indent guides (works well with Tokyo Night)
      vim.api.nvim_set_hl(0, "SnacksIndentScopeSubtle", { fg = "#3b4261" })
    end,
  },
}
