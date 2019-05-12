// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class LostDark : ModuleRules
{
    public LostDark(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(new string[] {
            "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay","UMG", "NavigationSystem", "AIModule", "GamePlayTasks" });
        PrivateDependencyModuleNames.AddRange(new string[] { "LostDarkSetting" });
    }
}
