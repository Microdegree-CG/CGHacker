project "02-Arithmatic_operation"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++17"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")
    
    files
    {
        "matrix_operation.cpp"
    }

    includedirs
    {
        "%{IncludeDir.eigen}",
        "%{wks.location}/CGHacker/vendor/spdlog/include",
		"%{wks.location}/CGHacker/src",
    }

    links
    {
        "CGHacker"
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
