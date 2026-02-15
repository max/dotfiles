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
      -- Fix transparency and color issues with picker and explorer
      picker = {
        win = {
          input = {
            wo = {
              winblend = 0,
              winhighlight = "Normal:Normal,FloatBorder:FloatBorder",
            },
          },
          list = {
            wo = {
              winblend = 0,
              winhighlight = "Normal:Normal,FloatBorder:FloatBorder",
            },
          },
          preview = {
            wo = {
              winblend = 0,
              winhighlight = "Normal:Normal,FloatBorder:FloatBorder",
            },
          },
        },
      },
      explorer = {
        win = {
          position = "left",
          wo = {
            winblend = 0,
            winhighlight = "Normal:Normal,NormalNC:Normal",
          },
          bo = {
            buftype = "nofile",
          },
        },
      },
    },
    config = function(_, opts)
      -- Set up snacks with options
      require("snacks").setup(opts)

      -- Use a more subtle gray for indent guides (works well with Gruvbox)
      vim.api.nvim_set_hl(0, "SnacksIndentScopeSubtle", { fg = "#3c3836" })

      -- Ensure proper background colors for floating windows with Gruvbox Hard
      vim.api.nvim_set_hl(0, "FloatBorder", { fg = "#928374", bg = "#1d2021" })
      vim.api.nvim_set_hl(0, "NormalFloat", { bg = "#1d2021" })
    end,
  },
}
