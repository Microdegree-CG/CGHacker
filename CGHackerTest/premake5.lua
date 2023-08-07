project "CGHackerTest"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"

	targetdir ("..bin/" .. outputdir .. "/%{prj.name}")
	objdir ("..bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
	    "src/**.h",
	    "src/**.cpp"
    }
    
    includedirs
	{
        "%{wks.location}/CGHacker/vendor/spdlog/include",
        "%{wks.location}/CGHacker/vendor/eigen",
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
        runtime "Debug"
        symbols "on"
        staticruntime "off"

    filter "configurations:Release"
        defines "CG_RELEASE"
        runtime "Release"
        optimize "on"
        staticruntime "on"

    filter "configurations:Dist"
        defines "CG_DIST"
        runtime "Release"
        optimize "on"
        staticruntime "on"
