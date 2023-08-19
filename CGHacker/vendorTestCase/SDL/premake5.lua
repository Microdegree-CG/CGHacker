project "TestCaseSDL"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++17"

    targetdir ("../bin/" .. outputdir .. "/%{prj.name}")
    objdir ("../bin-int/" .. outputdir .. "/%{prj.name}")
    
    files
    {
        "src/HelloSDL.cpp"
    }

    includedirs
    {
        "%{IncludeDir.SDL2}",
    }
    libdirs
    {
        "%{LinkDir.SDL2}",
    }

    links
    {
        "SDL2",
        "SDL2main",
    }

    debugenvs
    {
      "path=" .. os.getenv("path") .. ";" .. "%{DLLDirs.SDL2}"
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
