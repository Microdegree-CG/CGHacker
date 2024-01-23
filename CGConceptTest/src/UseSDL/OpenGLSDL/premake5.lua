project "OpenGLSDL"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++17"

    targetdir ("../bin/" .. outputdir .. "/%{prj.name}")
    objdir ("../bin-int/" .. outputdir .. "/%{prj.name}")
    
    files
    {
        "src/main.cpp"
    }

    includedirs
    {
        "%{IncludeDir.GLFW}",
        "%{IncludeDir.GLM}",
        "%{IncludeDir.GLAD}",
		"%{IncludeDir.IMGUI}",
        "%{IncludeDir.SDL2}",
		"%{wks.location}/CGHacker/src",
		"%{wks.location}/CGHacker/vendor/spdlog/include",
    }
    libdirs
    {
        "%{LinkDir.SDL2}",
    }

    links
    {
        "SDL2",
        "SDL2main",
        "CGHacker"
    }

    debugenvs
    {
      "path=" .. os.getenv("path") .. ";" .. "%{DLLDir.SDL2}"
    }

    filter "system:windows"
        systemversion "latest"

	filter "configurations:Debug"
        systemversion "latest"
		runtime "Debug"
        symbols "on"
        staticruntime "off"

	filter "configurations:Release"
        systemversion "latest"
		runtime "Release"
        optimize "on"
        staticruntime "On"
