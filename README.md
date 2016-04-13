# UE4-HeliosConfig

##Installation
####Engine
Engine installations show up as an engine plugin on the default list. This means they are avaiable to all projects! This is the ideal soultion for something standard like this.

1. Open C:\Program Files\Epic Games\4.XX\Engine\Plugins
2. Add the root Helios folder from this project
3. Open your project and use!

####Project
A project installation adds the plugin only to a single project.

1. Open your project directory and create a "Plugins" folder
2. Add the HeliosConfig folder found under the Helios root folder
3. Open your project and use!

##Usage
####Blueprint
Default usage with blueprints is easy. Once the plugin is enabled a new Helios category appears in the blueprint selection list. Here you will find all the functions, Get and Set for variables from the config file. All the functions are pure so they do not need an execution line, this makes using them easier!

####C++
To gain access to the HeliosConfigBPLibrary class in C++ you need to include the plugin in your in your Project.Build.cs
```C#
// Add "HeliosConfig" to PublicDependencyModuleNames
PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeliosConfig" });
// Add this line to insure the the headers are used in your project
PublicIncludePaths.AddRange(new string[] { "HeliosConfig/Public" });
```
Now just set up your class and
```C++
#include "HeliosConfigBPLibrary.h"

// now you have access to the class and functions

UE_LOG(LogTemp, Log, TEXT("Code: %s"), *UHeliosConfigBPLibrary::GetString("codeString", "This Code String"));
UE_LOG(LogTemp, Log, TEXT("Code: %d"), UHeliosConfigBPLibrary::GetInt("codeInt", 10));
UE_LOG(LogTemp, Log, TEXT("Code: %f"), UHeliosConfigBPLibrary::GetFloat("codeFloat", 11.12));
UE_LOG(LogTemp, Log, TEXT("Code: %f"), UHeliosConfigBPLibrary::GetColor("codeColor", FLinearColor::Red).R);
UE_LOG(LogTemp, Log, TEXT("Code: %s"), (UHeliosConfigBPLibrary::GetBool("codeBool", true)) ? "true" : "false");
UE_LOG(LogTemp, Log, TEXT("Code: %f"), UHeliosConfigBPLibrary::GetVector("codeVector", FVector(13, 14, 15)).X);
UE_LOG(LogTemp, Log, TEXT("Code: %f"), UHeliosConfigBPLibrary::GetVector2D("codeVector2D", FVector2D(16,17)).X);
```

##Notes
The config is saved to InstallDir/WindowsNoEditor/GameName. It will have the game name appeneded to the config file name. Example: "HeliosConfig_GameName.json" this prevents conflicts from other apps the may support the game itself but also require a config file of their own.
