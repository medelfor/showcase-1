/*
 * Copyright © 2022, Medelfor, Limited. All rights reserved.
 * For any additional information refer to https://medelfor.com
 */

using UnrealBuildTool;

/**
 * This module provides core functionality of a jetpack, such as replicated movement,
 * fuel system and extension of jetpack with additional modules.
 *
 * @since 1.0.0
 */
public class Jetpack : ModuleRules
{
	public Jetpack(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[]
		{
			"Core", "CoreUObject", "Engine", "InputCore"
		});

		PrivateDependencyModuleNames.AddRange(new string[] {  });
	}
}
