Project = {
  name = "spider",
  kind = "StaticLib",
  language = "C++",
  dialect = "23",

  pch = "src/spch.h",

  files = {
    "src/**.cpp",
  },

  includedirs = {
    "src",
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
}
