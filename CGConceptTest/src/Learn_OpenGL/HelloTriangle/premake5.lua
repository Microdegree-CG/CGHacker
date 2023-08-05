project "03-Hello-Triangle"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++17"

    targetdir ("../bin/" .. outputdir .. "/%{prj.name}")
    objdir ("../bin-int/" .. outputdir .. "/%{prj.name}")

    files
    {
        "src/**.h",
        "src/**.cpp",
    }

    includedirs
    {
        "%{IncludeDir.GLFW}",
        "%{IncludeDir.GLAD}",
        "%{IncludeDir.EIGEN}",
        "%{wks.location}/CGHacker/vendor/eigen",
        "%{wks.location}/CGHacker/src",
        "%{wks.location}/CGHacker/vendor/spdlog/include",
    }

    links
    {
        "GLFW",
        "GLAD",
        "CGHacker",
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
