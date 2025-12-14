return {
  -- Configure Tokyo Night
  {
    "folke/tokyonight.nvim",
    opts = {
      style = "night", -- storm, night, moon, or day
    },
  },

  -- Configure LazyVim to load Tokyo Night
  {
    "LazyVim/LazyVim",
    opts = {
      colorscheme = "tokyonight",
    },
  },
}
