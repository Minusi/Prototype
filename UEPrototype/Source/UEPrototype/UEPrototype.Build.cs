// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;

public class UEPrototype : ModuleRules
{
	public UEPrototype(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        // 컴파일 타임 감소를 위한 추가
        MinFilesUsingPrecompiledHeaderOverride = 1;
        bFasterWithoutUnity = true;

        PublicDependencyModuleNames.AddRange(
            new string[] 
            {
                "Core", "CoreUObject", "Engine", "InputCore",
                "ProceduralMeshComponent", "HeadMountedDisplay",
                "UMG", "AssetImport", "AssetRegistry", "ImageWrapper"
            });

		PrivateDependencyModuleNames.AddRange(new string[] {  });

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });
		
		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
