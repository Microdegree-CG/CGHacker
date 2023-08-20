project "04-Shaders"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++17"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")
    
    files
    {
        "src/**.h",
        "src/**.cpp",
        "asserts/**.fs",
        "asserts/**.vs",
    }

    includedirs
    {
        "%{wks.location}/CGHacker/vendor/spdlog/include",
        "%{wks.location}/CGHacker/src",
        "%{IncludeDir.GLFW}",
        "%{IncludeDir.GLAD}"
    }

    links
    {
        "CGHacker",
        "GLFW",
        "GLAD",
        "opengl32.lib"
    }

    filter "system:windows"
        systemversion "latest"

	filter "configurations:Debug"
        defines "CG_DEBUG"
        systemversion "latest" 
        runtime "Debug"
        symbols "on"
        staticruntime "off"

	filter "configurations:Release"
        systemversion "latest" 
        runtime "Release"
        optimize "on"
        staticruntime "On"
