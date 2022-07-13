project "01-GLFWConf"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++17"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")
    
    files
    {
        "**.h",
        "**.cpp"
    }

    includedirs
    {
		"%{wks.location}/CGHacker/vendor/spdlog/include",
		"%{wks.location}/CGHacker/src",
        "%{IncludeDir.GLFW}",
    }

    links
    {
        "CGHacker",
        "GLFW",
        "opengl32.lib"
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
