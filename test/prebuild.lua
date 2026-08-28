Project = {
  name = "c-test",
  kind = "ConsoleApp",
  language = "C++",
  dialect = "23",

  files = {
    "main.cpp",
  },

  includedirs = {
    "${WORKSPACEDIR}Spider/src",
  },

  flags = {
    "-Wall",
    "-Werror",
  },

  filters = {
    -- Debug Config
    {
      name = "configurations:Debug",
      flags = {
        "-O0",
        "-g"
      },
    },
    -- Release Config
    {
      name = "configurations:Release",
      flags = {
        "-O2",
      },
    },
  },

  links = {
    "spider"
  }
}
