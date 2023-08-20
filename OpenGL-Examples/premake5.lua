project "OpenGL-Examples"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("../bin/" .. outputdir .. "/%{prj.name}")
	objdir ("../bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"src/**.h",
		"src/**.cpp"
	}

	includedirs
	{
		"../CGHacker/vendor/spdlog/include",
		"../CGHacker/src",
		"../CGHacker/vendor",
		"../CGHacker/%{IncludeDir.GLM}",
		"../CGHacker/%{IncludeDir.GLAD}",
		"../CGHacker/%{IncludeDir.IMGUI}"
	}

	links
	{
		"CGHacker"
	}

	filter "system:windows"
		systemversion "latest"

		defines
		{
			"GLCORE_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "GLCORE_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "GLCORE_RELEASE"
		runtime "Release"
        optimize "on"
