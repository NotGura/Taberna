workspace "Taberna"
	architecture "x64"
	
	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}
	
outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Core"
	location "Core"
	kind "SharedLib"
	language "C++"
	
	targetdir ("bin/" ..outputdir.. "/%{prj.name}")
	objdir ("bin-int/" ..outputdir.. "/%{prj.name}")
	
	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}
	
	includedirs
	{
		"%{prj.name}/vendor/spdlog/include"
	}
	
	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"
	
		defines
		{
			"TB_PLATFORM_WINDOWS",
			"TB_BUILD_DLL"
		}
		
		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" ..outputdir.. "/Sandbox/")
		}
		
	filter "configurations:Debug"
		defines "TB_DEBUG"
		symbols "On"
		
	filter "configurations:Release"
		defines "TB_RELEASE"
		optimize "On"
		
	filter "configurations:Dist"
		defines "TB_DIST"
		optimize "On"
		
project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"
	
	targetdir ("bin/" ..outputdir.. "/%{prj.name}")
	objdir ("bin-int/" ..outputdir.. "/%{prj.name}")
	
	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}
	
	includedirs
	{
		"Core/vendor/spdlog/include",
		"Core/src"
	}
	
	links
	{
		"Core"
	}
	
	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"
	
		defines
		{
			"TB_PLATFORM_WINDOWS"
		}
		
	filter "configurations:Debug"
		defines "TB_DEBUG"
		symbols "On"
		
	filter "configurations:Release"
		defines "TB_RELEASE"
		optimize "On"
		
	filter "configurations:Dist"
		defines "TB_DIST"
		optimize "On"