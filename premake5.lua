workspace "CMSim"
	architecture "x64"
	startproject "FreeTest"
	
	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "CMSim"
	location "CMSim"
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
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "10.0.19041.0"

		defines
		{	
			"CMS_PLATFORM_WINDOWS",
			"CMS_BUILD_DLL"
		}

		postbuildcommands
		{
			--("{COPY}%{cfg.buildtarget.relpath}../bin/"  ..outputdir..  "/FreeTest")
			("{COPY} %{cfg.buildtarget.relpath} \"../bin/" .. outputdir .. "/FreeTest/\"")
		}
		--postbuildcommands{("{COPY} %{cfg.buildtarget.relpath} \"../bin/" .. outputdir .. "Sandbox/\"")}

	filter "configurations:Debug"
		defines "CMS_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "CMS_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "CMS_DIST"
		optimize "On"

project "FreeTest"
	location "FreeTest"
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
		"CMSim/vendor/spdlog/include",
		"CMSim/src"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "10.0.19041.0"

		defines
		{	
			"CMS_PLATFORM_WINDOWS"
		}

	links 
	{
		"CMSim"
	}

	filter "configurations:Debug"
		defines "CMS_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "CMS_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "CMS_DIST"
		optimize "On"