return {
  {
    "neovim/nvim-lspconfig",
    opts = function(_, opts)
      local notion_root = "/Users/mschoening/Developer/makenotion/notion-next"

      opts.servers = opts.servers or {}
      opts.servers.vtsls = opts.servers.vtsls or {}

      local server = opts.servers.vtsls
      local old_before_init = server.before_init
      local old_on_init = server.on_init

      server.before_init = function(initialize_params, config)
        local root = config.root_dir

        if root == notion_root then
          config.settings = vim.tbl_deep_extend("force", config.settings or {}, {
            vtsls = {
              autoUseWorkspaceTsdk = true,
            },
            typescript = {
              experimental = {
                useTsgo = false,
              },
              tsdk = notion_root .. "/node_modules/typescript/lib",
              tsserver = {
                maxTsServerMemory = 35840,
                nodePath = notion_root .. "/src/cli/tsserverNode",
                pluginPaths = { notion_root .. "/node_modules" },
                useSyntaxServer = "never",
              },
            },
            javascript = {
              tsdk = notion_root .. "/node_modules/typescript/lib",
            },
          })
        end

        if old_before_init then
          return old_before_init(initialize_params, config)
        end
      end

      server.on_init = function(client, initialize_result)
        if client.config.root_dir == notion_root then
          client:notify("workspace/didChangeConfiguration", {
            settings = client.config.settings,
          })
        end

        if old_on_init then
          return old_on_init(client, initialize_result)
        end
      end
    end,
  },
}
