include "./vendor/premake_customization/solution_items.lua"

workspace "CGHacker"
    architecture "x64"
    startproject "OpenGL-Sandbox"

    configurations
    {
        "Debug",
        "Release",
        "Dist"
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
IncludeDir["IMGUI"]    = "%{wks.location}/CGHacker/vendor/imgui"
IncludeDir["STB"]     = "%{wks.location}/CGHacker/vendor/stb"
IncludeDir["GLM"]     = "%{wks.location}/CGHacker/vendor/glm"


-- projects
group "Dependencies"
    include "vendor"
    include "CGHacker/vendor/glfw"
    include "CGHacker/vendor/Glad"
    include "CGHacker/vendor/imgui"
group ""


include "CGHacker"
include "OpenGL-Sandbox"
include "OpenGL-Examples"

include "premakes/learn_opengl.lua"
include "premakes/learn_eigen.lua"
