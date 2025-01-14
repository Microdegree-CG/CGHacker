include "./vendor/premake_customization/solution_items.lua"
require("vendor/export-compile-commands/export-compile-commands")

workspace "CGHacker"
    architecture "x64"
    startproject "CGHackerSandbox"

    configurations
    {
        "Debug",
        "Release",
    }

    solution_items
    {
        ".editorconfig"
    }

    flags
    {
        "MultiProcessorCompile"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["EIGEN"]   = "%{wks.location}/CGHacker/vendor/eigen"
IncludeDir["GLFW"]    = "%{wks.location}/CGHacker/vendor/glfw/include"
IncludeDir["GLAD"]    = "%{wks.location}/CGHacker/vendor/Glad/include"
IncludeDir["IMGUI"]   = "%{wks.location}/CGHacker/vendor/imgui"
IncludeDir["STB"]     = "%{wks.location}/CGHacker/vendor/stb"
IncludeDir["GLM"]     = "%{wks.location}/CGHacker/vendor/glm"
IncludeDir["SDL2"]    = "%{wks.location}/vendor/SDL2/include"
IncludeDir["SFML"]    = "%{wks.location}/vendor/SFML/include"

LinkDir={}
LinkDir["SDL2"] = "%{wks.location}/vendor/SDL2/lib/x64/"
LinkDir["SFML"] = "%{wks.location}/vendor/SFML/lib/"

DLLDir = {}
DLLDir["SDL2"] = "%{wks.location}/vendor/SDL2/Lib/x64"
DLLDir["SFML"] = "%{wks.location}/vendor/SFML/bin/"

-- projects
group "Dependencies"
    include "vendor"
    include "CGHacker/vendor/glfw"
    include "CGHacker/vendor/Glad"
    include "CGHacker/vendor/imgui"
group ""

include "CGHacker"
include "CGHackerSandbox"
include "CGHackerExamples"
include "CGConceptTest"
