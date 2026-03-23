-- Hammerspoon configuration
local hyper = { "cmd", "alt", "ctrl" }

-- Hide default Hammerspoon menubar icon
hs.menuIcon(false)

-- Menubar utilities dropdown
local menu = hs.menubar.new()
if menu then
  menu:setTitle("⋯")

  local function buildMenu()
    local caffeineState = hs.caffeinate.get("displayIdle")
    return {
      {
        title = caffeineState and "Caffeine: ON" or "Caffeine: OFF",
        fn = function()
          hs.caffeinate.toggle("displayIdle")
        end,
      },
      { title = "-" },
      {
        title = "Reload Config",
        fn = function()
          hs.reload()
        end,
      },
    }
  end

  menu:setMenu(buildMenu)
end

-- Reload config
hs.hotkey.bind(hyper, "r", function()
  hs.reload()
end)

hs.alert.show("Hammerspoon loaded")
