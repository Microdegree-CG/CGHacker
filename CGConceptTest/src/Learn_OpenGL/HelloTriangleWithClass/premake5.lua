project "03-HelloTriangleWithClass"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++17"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files
    {
        "src/**.h",
        "src/**.cpp",
        "res/**"
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
        systemversion "latest"
        defines "CG_DEBUG"
	    runtime "Debug"
        symbols "on"
        staticruntime "off"

	filter "configurations:Release" 
        systemversion "latest"
        defines "CG_RELEASE"
	    runtime "Release"
        optimize "on"
        staticruntime "On"
