using UnrealBuildTool;

public class CoreAIModule : ModuleRules
{
	public CoreAIModule(ReadOnlyTargetRules Target) : base(Target)
	{
		PrivateDependencyModuleNames.AddRange(new string[] {"Core", "CoreUObject", "Engine", "AIModule", "GameplayTasks"});
	}
}