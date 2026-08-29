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
    {
      name = "configurations:Debug",
      flags = {
        "-O0",
        "-g"
      },
    },
    {
      name = "configurations:Release",
      flags = {
        "-O2",
      },
    },
  }
}
