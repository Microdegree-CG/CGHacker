project "TestCaseSFML"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++17"

    targetdir ("../bin/" .. outputdir .. "/%{prj.name}")
    objdir ("../bin-int/" .. outputdir .. "/%{prj.name}")
    
    files
    {
        "src/HelloSFML.cpp"
    }

    includedirs
    {
        "%{IncludeDir.SFML}",
    }
    libdirs
    {
        "%{LinkDir.SFML}",
    }

    links
    {
        "sfml-window",
        "sfml-system",
        "opengl32"
    }

    debugenvs
    {
      "path=" .. os.getenv("path") .. ";" .. "%{DLLDir.SFML}"
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
