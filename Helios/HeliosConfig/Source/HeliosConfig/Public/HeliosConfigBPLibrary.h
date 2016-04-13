// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Engine.h"
#include "HeliosConfigBPLibrary.generated.h"

/* 
*	Helios Config Class
*
*	Automaticlly creates a config for your current project. The config will be named: HeliosConfig_GameName.json
*
*	Supports:
*	String
*	Int
*	Color
*	Bool
*	Vector
*	Vecor2D
*/

UCLASS()
class HELIOSCONFIG_API UHeliosConfigBPLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

private:
	// True if intialized, otherwise false
	static bool bInitialized;
	// Local Json
	static TSharedPtr<FJsonObject> JsonObject;

public:
	// STRING
	/* Get a string value from the HeliosConfig.json -- if the VariableName cannot be found it is created and set to DefaultValue */
		static FString GetString(const FString& VariableName, FString DefaultValue = "None");
	/* Set a string value to the HeliosConfig.json */
		static void SetString(const FString & VariableName, const FString & Value);

	// Int
	/* Get a int value from the HeliosConfig.json -- if the VariableName cannot be found it is created and set to DefaultValue */
		static int32 GetInt(const FString& VariableName, int32 DefaultValue = 0);
	/* Set a int value to the HeliosConfig.json */
		static void SetInt(const FString & VariableName, const int32 Value);

	// FLOAT
	/* Get a float value from the HeliosConfig.json -- if the VariableName cannot be found it is created and set to DefaultValue */
		static float GetFloat(const FString& VariableName, float DefaultValue = 1.0);
	/* Set a float value to the HeliosConfig.json */
		static void SetFloat(const FString & VariableName, const float Value);

	// COLOR
	/* Get a color value from the HeliosConfig.json -- if the VariableName cannot be found it is created set to the DefaultValue */
		static FLinearColor GetColor(const FString& VariableName, FLinearColor DefaultValue = FLinearColor::Black);
	/* Set a float value to the HeliosConfig.json */
		static void SetColor(const FString & VariableName, FLinearColor Value);

	// BOOL
	/* Get a bool value from the HeliosConfig.json -- if the VariableName cannot be found it is created and set to DefaultValue */
		static bool GetBool(const FString& VariableName, bool DefaultValue = true);
	/* Set a bool value to the HeliosConfig.json */
		static void SetBool(const FString & VariableName, bool Value);

	// VECTOR
	/* Get a bool value from the HeliosConfig.json -- if the VariableName cannot be found it is created and set to DefaultValue */
		static FVector GetVector(const FString& VariableName, FVector DefaultValue = FVector(0, 0, 0));
	/* Set a bool value to the HeliosConfig.json */
		static void SetVector(const FString & VariableName, FVector Value);

	// VECTOR2D
	/* Get a bool value from the HeliosConfig.json -- if the VariableName cannot be found it is created and set to DefaultValue */
		static FVector2D GetVector2D(const FString & VariableName, FVector2D DefaultValue = FVector2D(0, 0));
	/* Set a bool value to the HeliosConfig.json */
		static void SetVector2D(const FString & VariableName, FVector2D Value);

	/*=====================================================================
	BLUEPRINT
	=====================================================================*/
	
	// STRING
	/* Get a string value from the HeliosConfig.json -- if the VariableName cannot be found it is created and set to DefaultValue */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Get String", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject", Keywords = "helios config get string"), Category = "Helios|Config")
		static FString BP_GetString(UObject* WorldContextObject, const FString& VariableName, FString DefaultValue = "None");
	/* Set a string value to the HeliosConfig.json */
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Set String", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject", Keywords = "helios config get int"), Category = "Helios|Config")
		static void BP_SetString(UObject * WorldContextObject, const FString & VariableName, const FString & Value);

	// Int
	/* Get a int value from the HeliosConfig.json -- if the VariableName cannot be found it is created and set to DefaultValue */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Get Int", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject", Keywords = "helios config get int"), Category = "Helios|Config")
		static int32 BP_GetInt(UObject* WorldContextObject, const FString& VariableName, int32 DefaultValue = 0);
	/* Set a int value to the HeliosConfig.json */
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Set Int", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject", Keywords = "helios config get int"), Category = "Helios|Config")
		static void BP_SetInt(UObject * WorldContextObject, const FString & VariableName, const int32 Value);

	// FLOAT
	/* Get a float value from the HeliosConfig.json -- if the VariableName cannot be found it is created and set to DefaultValue */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Get Float", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject", Keywords = "helios config get float"), Category = "Helios|Config")
		static float BP_GetFloat(UObject* WorldContextObject, const FString& VariableName, float DefaultValue = 1.0);
	/* Set a float value to the HeliosConfig.json */
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Set Float", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject", Keywords = "helios config get int"), Category = "Helios|Config")
		static void BP_SetFloat(UObject * WorldContextObject, const FString & VariableName, const float Value);

	// COLOR
	/* Get a color value from the HeliosConfig.json -- if the VariableName cannot be found it is created set to the DefaultValue */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Get Color", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject", Keywords = "helios config get color"), Category = "Helios|Config")
		static FLinearColor BP_GetColor(UObject* WorldContextObject, const FString& VariableName, FLinearColor DefaultValue = FLinearColor::Black);
	/* Set a float value to the HeliosConfig.json */
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Set Color", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject", Keywords = "helios config get int"), Category = "Helios|Config")
		static void BP_SetColor (UObject * WorldContextObject, const FString & VariableName, FLinearColor Value);

	// BOOL
	/* Get a bool value from the HeliosConfig.json -- if the VariableName cannot be found it is created and set to DefaultValue */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Get Bool", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject", Keywords = "helios config get bool"), Category = "Helios|Config")
		static bool BP_GetBool(UObject* WorldContextObject, const FString& VariableName, bool DefaultValue = true);
	/* Set a bool value to the HeliosConfig.json */
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Set Bool", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject", Keywords = "helios config get int"), Category = "Helios|Config")
		static void BP_SetBool(UObject * WorldContextObject, const FString & VariableName, bool Value);

	// VECTOR
	/* Get a bool value from the HeliosConfig.json -- if the VariableName cannot be found it is created and set to DefaultValue */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Get Vector", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject", Keywords = "helios config get bool"), Category = "Helios|Config")
		static FVector BP_GetVector(UObject* WorldContextObject, const FString& VariableName, FVector DefaultValue = FVector(0, 0, 0));
	/* Set a bool value to the HeliosConfig.json */
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Set Vector", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject", Keywords = "helios config get int"), Category = "Helios|Config")
		static void BP_SetVector(UObject * WorldContextObject, const FString & VariableName, FVector Value);

	// VECTOR2D
	/* Get a bool value from the HeliosConfig.json -- if the VariableName cannot be found it is created and set to DefaultValue */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Get Vector2D", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject", Keywords = "helios config get bool"), Category = "Helios|Config")
		static FVector2D BP_GetVector2D(UObject * WorldContextObject, const FString & VariableName, FVector2D DefaultValue = FVector2D(0, 0));
	/* Set a bool value to the HeliosConfig.json */
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Set Vector2D", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject", Keywords = "helios config get int"), Category = "Helios|Config")
		static void BP_SetVector2D(UObject * WorldContextObject, const FString & VariableName, FVector2D Value);

	virtual void BeginDestroy() override;

private:
	// To be called with every set or get, to insure the jsonobject is initialized
	static void Initialize();
	// Deserializes JsonObject for reading
	static void DeserializeJson(TSharedPtr<FJsonObject> &JsonObject);
	// Serializes JsonObject for writing
	static void SerializeJson(TSharedPtr<FJsonObject>& JsonObject);
	// Returns the complete Path and FileName of the HeliosConfig.json
	static FString GetConfigPath();
};
