// Fill out your copyright notice in the Description page of Project Settings.

using System.IO;
using UnrealBuildTool;

public class AssetImport : ModuleRules
{
    //TODO : CAUTION !!!!!!!
    // 현재 이 모듈은 Win64에 대해서만 완벽한 개발 및 릴리즈 환경을 내포하고 있으며,
    // WIN32는 모듈 정보만 기입되어 있습니다.
    // 따라서 Gear VR 및 기타 플랫폼에서의 동작을 위해서는 각각의 타겟 플랫폼 환경에
    // 알맞는 라이브러리 및 모듈 설정을 필요로 합니다. 

	public AssetImport(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        // 컴파일 타임 감소를 위한 추가
        MinFilesUsingPrecompiledHeaderOverride = 1;
        bFasterWithoutUnity = true;

        PublicDependencyModuleNames.AddRange(
            new string[] 
            {
                "Core", "CoreUObject", "Engine",
                "ProceduralMeshComponent"
            });

		PrivateDependencyModuleNames.AddRange(new string[] {  });

        // Uncomment if you are using Slate UI
        // PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

        // Uncomment if you are using online features
        // PrivateDependencyModuleNames.Add("OnlineSubsystem");

        // To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true


         
        // See as https://wiki.unrealengine.com/Assimp_for_Unreal
        if ((Target.Platform == UnrealTargetPlatform.Win64) || (Target.Platform == UnrealTargetPlatform.Win32))
        {
            string PathToProject = "C:\\Users\\Utsuho\\Desktop\\General\\Project\\Prototype\\UEPrototype";
            PublicIncludePaths.Add(Path.Combine(PathToProject, "Source\\ThirdParty"));
            string PlatformString = (Target.Platform == UnrealTargetPlatform.Win64) ? "Win64" : "Win32";
            string LibrariesPath = Path.Combine(PathToProject, "Binaries", PlatformString);

            PublicAdditionalLibraries.Add(Path.Combine(LibrariesPath, "assimp-vc140-mt.lib"));
        }
    }
}
