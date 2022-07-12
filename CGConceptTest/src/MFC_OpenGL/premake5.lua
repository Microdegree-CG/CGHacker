project "MFC_OpenGL_Demo"
    kind "WindowedApp"
    language "C++"
    cppdialect "C++17"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")
    
    pchheader "pch.h"
    pchsource "%{wks.location}/CGConceptTest/src/MFC_OpenGL/src/pch.cpp"

    
    files
    {
        "%{wks.location}/CGConceptTest/src/MFC_OpenGL/src/MFC_OpenGL/**.h",
        "%{wks.location}/CGConceptTest/src/MFC_OpenGL/src/MFC_OpenGL/**.cpp",
        "%{wks.location}/CGConceptTest/src/MFC_OpenGL/src/MFC_OpenGL/**.rc",
        "%{wks.location}/CGConceptTest/src/MFC_OpenGL/src/pch.h",
        "%{wks.location}/CGConceptTest/src/MFC_OpenGL/src/pch.cpp",
        "%{wks.location}/CGConceptTest/src/MFC_OpenGL/src/framework.h",
        "%{wks.location}/CGConceptTest/src/MFC_OpenGL/src/targetver.h",
    }

    includedirs
    {
        "src",
        "%{IncludeDir.GLFW}",
        "%{IncludeDir.GLAD}"
    }

    links
    {
        "GLFW",
        "GLAD",
        "opengl32.lib"
    }

    flags
    {
      "MFC"
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
