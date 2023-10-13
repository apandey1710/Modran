using UnrealBuildTool;

public class PlayerCharacterModule : ModuleRules
{
	public PlayerCharacterModule(ReadOnlyTargetRules Target) : base(Target)
	{
		PrivateDependencyModuleNames.AddRange(new string[] {"Core", "CoreUObject", "Engine"});
	}
}