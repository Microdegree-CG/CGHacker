project "CGHackerSandbox"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"

	targetdir ("../../bin/" .. outputdir .. "/%{prj.name}")
	objdir ("../../bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"src/**.h",
		"src/**.cpp"
	}

	includedirs
	{
		"%{IncludeDir.GLM}",
		"%{IncludeDir.GLAD}",
		"%{IncludeDir.IMGUI}",
		"%{wks.location}/CGHacker/vendor/spdlog/include",
		"%{wks.location}/CGHacker/src",
		"%{wks.location}/CGHacker/vendor",
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
