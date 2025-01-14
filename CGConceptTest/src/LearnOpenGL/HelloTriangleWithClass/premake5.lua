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
        "%{IncludeDir.GLFW}",
        "%{IncludeDir.GLM}",
        "%{IncludeDir.GLAD}",
		"%{IncludeDir.IMGUI}",
		"%{wks.location}/CGHacker/src",
		"%{wks.location}/CGHacker/vendor/spdlog/include",
    }

    links
    {
        "CGHacker",
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
