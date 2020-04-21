workspace "Solis"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Solis"
	location "Solis"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

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
		systemversion "10.0.18362.0"

		defines
		{
		
			"SL_PLATFORM_WINDOWS",
			"SL_BUILD_DLL",
			"_WINDLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/SandBox")
		}
		
	filter "configurations:Debug"
		defines "SL_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "SL_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "SL_DIST"
		optimize "On"


project "SandBox"
	location "SandBox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs 
	{
		"Solis/vendor/spdlog/include",
		"Solis/src"
	}

	links
	{
		"Solis"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "10.0.18362.0"

		defines
		{
		
			"SL_PLATFORM_WINDOWS",
			"_WINDLL"
		}

		
	filter "configurations:Debug"
		defines "SL_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "SL_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "SL_DIST"
		optimize "On"