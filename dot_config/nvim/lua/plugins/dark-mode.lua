-- Automatic dark mode switching based on system appearance
return {
  {
    "cormacrelf/dark-notify",
    config = function()
      require("dark_notify").run()
    end,
  },
}
