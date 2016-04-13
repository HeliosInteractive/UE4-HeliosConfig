// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.

#include "HeliosConfigPrivatePCH.h"
#include "HeliosConfigBPLibrary.h"

bool UHeliosConfigBPLibrary::bInitialized = false;
TSharedPtr<FJsonObject> UHeliosConfigBPLibrary::JsonObject = MakeShareable(new FJsonObject);

FString UHeliosConfigBPLibrary::GetString(const FString& VariableName, FString DefaultValue)
{
#if WITH_EDITOR
	return DefaultValue;
#endif // With_EDITOR

	Initialize();

	FString TheValue = DefaultValue;
	if (!JsonObject->TryGetStringField(VariableName, TheValue))
	{
		SetString(VariableName, DefaultValue);
	}
	return TheValue;
}

void UHeliosConfigBPLibrary::SetString(const FString& VariableName, const FString& Value)
{
#if WITH_EDITOR
	return;
#endif // With_EDITOR

	Initialize();

	JsonObject->SetStringField(VariableName, Value);
}

int32 UHeliosConfigBPLibrary::GetInt(const FString& VariableName, int32 DefaultValue)
{
#if WITH_EDITOR
	return DefaultValue;
#endif // With_EDITOR

	Initialize();

	int32 TheValue = DefaultValue;
	if (!JsonObject->TryGetNumberField(VariableName, TheValue))
	{
		SetInt(VariableName, DefaultValue);
	}
	return TheValue;
}

void UHeliosConfigBPLibrary::SetInt(const FString& VariableName, const int32 Value)
{
#if WITH_EDITOR
	return;
#endif // With_EDITOR

	Initialize();

	JsonObject->SetNumberField(VariableName, Value);
}

float UHeliosConfigBPLibrary::GetFloat(const FString& VariableName, float DefaultValue)
{
#if WITH_EDITOR
	return DefaultValue;
#endif // With_EDITOR

	Initialize();

	double TheValue = DefaultValue;
	if (!JsonObject->TryGetNumberField(VariableName, TheValue))
	{
		SetFloat(VariableName, DefaultValue);
	}
	return (float)TheValue;
}

void UHeliosConfigBPLibrary::SetFloat(const FString& VariableName, const float Value)
{
#if WITH_EDITOR
	return;
#endif // With_EDITOR

	Initialize();

	JsonObject->SetNumberField(VariableName, Value);
}

FLinearColor UHeliosConfigBPLibrary::GetColor(const FString& VariableName, FLinearColor DefaultValue)
{
#if WITH_EDITOR
	return DefaultValue;
#endif // With_EDITOR

	Initialize();

	const TArray<TSharedPtr<FJsonValue>>* rgb;
	if (!JsonObject->TryGetArrayField(VariableName, rgb))
	{
		SetColor(VariableName, DefaultValue);
		return DefaultValue;
	}

	bool bHasAlpha = (rgb->Num() > 3); // if rgb contains more than three variables it has an alpha value set.
	FLinearColor color;

	if (bHasAlpha)
	{
		color = FLinearColor((float)rgb[0][0].Get()->AsNumber(), (float)rgb[0][1].Get()->AsNumber(), (float)rgb[0][2].Get()->AsNumber(), (float)rgb[0][3].Get()->AsNumber());
	}
	else
	{
		color = FLinearColor((float)rgb[0][0].Get()->AsNumber(), (float)rgb[0][1].Get()->AsNumber(), (float)rgb[0][2].Get()->AsNumber(), 1);
	}
	return color;
}

void UHeliosConfigBPLibrary::SetColor(const FString & VariableName, FLinearColor Value)
{

#if WITH_EDITOR
	return;
#endif // With_EDITOR

	Initialize();

	TArray<TSharedPtr<FJsonValue>> ColorValues;
	ColorValues.Add(MakeShareable(new FJsonValueNumber(Value.R)));
	ColorValues.Add(MakeShareable(new FJsonValueNumber(Value.G)));
	ColorValues.Add(MakeShareable(new FJsonValueNumber(Value.B)));
	if (Value.A < 1)
	{
		// alpha defaults to one on GetColor, so only write out alpha if the value is != 1
		ColorValues.Add(MakeShareable(new FJsonValueNumber(Value.A)));
	}

	JsonObject->SetArrayField(VariableName, ColorValues);
}

bool UHeliosConfigBPLibrary::GetBool(const FString& VariableName, bool DefaultValue)
{
#if WITH_EDITOR
	return DefaultValue;
#endif // With_EDITOR

	Initialize();

	bool TheValue = DefaultValue;
	if (!JsonObject->TryGetBoolField(VariableName, TheValue))
	{
		SetBool(VariableName, DefaultValue);
	}
	return TheValue;
}

void UHeliosConfigBPLibrary::SetBool(const FString& VariableName, bool Value)
{
#if WITH_EDITOR
	return;
#endif // With_EDITOR

	Initialize();

	JsonObject->SetBoolField(VariableName, Value);
}

FVector UHeliosConfigBPLibrary::GetVector(const FString & VariableName, FVector DefaultValue)
{
#if WITH_EDITOR
	return DefaultValue;
#endif // With_EDITOR

	Initialize();

	FVector Vector = DefaultValue;
	const TArray<TSharedPtr<FJsonValue>> *VectorValues;
	if (!JsonObject->TryGetArrayField(VariableName, VectorValues))
	{
		SetVector(VariableName, DefaultValue);
		return DefaultValue;
	}
	return FVector((float)(*VectorValues)[0]->AsNumber(), (float)(*VectorValues)[1]->AsNumber(), (float)(*VectorValues)[2]->AsNumber());
}

void UHeliosConfigBPLibrary::SetVector(const FString & VariableName, FVector Value)
{
#if WITH_EDITOR
	return;
#endif // With_EDITOR

	Initialize();

	TArray<TSharedPtr<FJsonValue>> VectorValues;
	VectorValues.Add(MakeShareable(new FJsonValueNumber(Value.X)));
	VectorValues.Add(MakeShareable(new FJsonValueNumber(Value.Y)));
	VectorValues.Add(MakeShareable(new FJsonValueNumber(Value.Z)));

	JsonObject->SetArrayField(VariableName, VectorValues);
}

FVector2D UHeliosConfigBPLibrary::GetVector2D(const FString & VariableName, FVector2D DefaultValue)
{
#if WITH_EDITOR
	return DefaultValue;
#endif // With_EDITOR

	Initialize();

	FVector2D Vector = DefaultValue;
	const TArray<TSharedPtr<FJsonValue>> *VectorValues;
	if (!JsonObject->TryGetArrayField(VariableName, VectorValues))
	{
		SetVector2D(VariableName, DefaultValue);
		return DefaultValue;
	}
	return FVector2D((float)(*VectorValues)[0]->AsNumber(), (float)(*VectorValues)[1]->AsNumber());
}

void UHeliosConfigBPLibrary::SetVector2D(const FString & VariableName, FVector2D Value)
{
#if WITH_EDITOR
	return;
#endif // With_EDITOR

	Initialize();

	TArray<TSharedPtr<FJsonValue>> VectorValues;
	VectorValues.Add(MakeShareable(new FJsonValueNumber(Value.X)));
	VectorValues.Add(MakeShareable(new FJsonValueNumber(Value.Y)));

	JsonObject->SetArrayField(VariableName, VectorValues);
}

/*=====================================================================
BLUEPRINT
=====================================================================*/

FString UHeliosConfigBPLibrary::BP_GetString(UObject* WorldContextObject, const FString& VariableName, FString DefaultValue)
{
#if WITH_EDITOR
	return DefaultValue;
#endif // With_EDITOR

	Initialize();

	return GetString(VariableName, DefaultValue);
}

void UHeliosConfigBPLibrary::BP_SetString(UObject* WorldContextObject, const FString& VariableName, const FString& Value)
{
#if WITH_EDITOR
	return;
#endif // With_EDITOR

	Initialize();

	SetString(VariableName, Value);
}

int32 UHeliosConfigBPLibrary::BP_GetInt(UObject* WorldContextObject, const FString& VariableName, int32 DefaultValue)
{
#if WITH_EDITOR
	return DefaultValue;
#endif // With_EDITOR

	Initialize();

	return GetInt(VariableName, DefaultValue);
}

void UHeliosConfigBPLibrary::BP_SetInt(UObject* WorldContextObject, const FString& VariableName, const int32 Value)
{
#if WITH_EDITOR
	return;
#endif // With_EDITOR

	Initialize();

	SetInt(VariableName, Value);
}

float UHeliosConfigBPLibrary::BP_GetFloat(UObject* WorldContextObject, const FString& VariableName, float DefaultValue)
{
#if WITH_EDITOR
	return DefaultValue;
#endif // With_EDITOR

	Initialize();

	return GetFloat(VariableName, DefaultValue);
}

void UHeliosConfigBPLibrary::BP_SetFloat(UObject* WorldContextObject, const FString& VariableName, const float Value)
{
#if WITH_EDITOR
	return;
#endif // With_EDITOR

	Initialize();

	SetInt(VariableName, Value);
}

FLinearColor UHeliosConfigBPLibrary::BP_GetColor(UObject* WorldContextObject, const FString& VariableName, FLinearColor DefaultValue)
{
#if WITH_EDITOR
	return DefaultValue;
#endif // With_EDITOR

	Initialize();

	return GetColor(VariableName, DefaultValue);
}

void UHeliosConfigBPLibrary::BP_SetColor(UObject * WorldContextObject, const FString & VariableName, FLinearColor Value)
{

#if WITH_EDITOR
	return;
#endif // With_EDITOR

	Initialize();

	SetColor(VariableName, Value);
}

bool UHeliosConfigBPLibrary::BP_GetBool(UObject* WorldContextObject, const FString& VariableName, bool DefaultValue)
{
#if WITH_EDITOR
	return DefaultValue;
#endif // With_EDITOR

	Initialize();

	return GetBool(VariableName, DefaultValue);
}

void UHeliosConfigBPLibrary::BP_SetBool(UObject* WorldContextObject, const FString& VariableName, bool Value)
{
#if WITH_EDITOR
	return;
#endif // With_EDITOR

	Initialize();

	SetBool(VariableName, Value);
}

FVector UHeliosConfigBPLibrary::BP_GetVector(UObject * WorldContextObject, const FString & VariableName, FVector DefaultValue)
{
#if WITH_EDITOR
	return DefaultValue;
#endif // With_EDITOR

	Initialize();

	return GetVector(VariableName, DefaultValue);
}

void UHeliosConfigBPLibrary::BP_SetVector(UObject * WorldContextObject, const FString & VariableName, FVector Value)
{
#if WITH_EDITOR
	return;
#endif // With_EDITOR

	Initialize();

	SetVector(VariableName, Value);
}

FVector2D UHeliosConfigBPLibrary::BP_GetVector2D(UObject * WorldContextObject, const FString & VariableName, FVector2D DefaultValue)
{
#if WITH_EDITOR
	return DefaultValue;
#endif // With_EDITOR

	Initialize();

	return GetVector2D(VariableName, DefaultValue);
}

void UHeliosConfigBPLibrary::BP_SetVector2D(UObject * WorldContextObject, const FString & VariableName, FVector2D Value)
{
#if WITH_EDITOR
	return;
#endif // With_EDITOR

	Initialize();

	SetVector2D(VariableName, Value);
}

void UHeliosConfigBPLibrary::BeginDestroy()
{
	SerializeJson(JsonObject);
	Super::BeginDestroy();
}

void UHeliosConfigBPLibrary::Initialize()
{
	if (!bInitialized)
	{
		DeserializeJson(JsonObject);
		bInitialized = true;
	}
}

void UHeliosConfigBPLibrary::DeserializeJson(TSharedPtr<FJsonObject> &JsonObject)
{
	FString JsonText;
	FFileHelper::LoadFileToString(JsonText, *GetConfigPath());
	TSharedRef<TJsonReader<>> Reader = TJsonReaderFactory<>::Create(JsonText);
	FJsonSerializer::Deserialize(Reader, JsonObject);
}

void UHeliosConfigBPLibrary::SerializeJson(TSharedPtr<FJsonObject> &JsonObject)
{
	FString OutputString;
	TSharedRef<TJsonWriter<>> Writer = TJsonWriterFactory<>::Create(&OutputString);
	FJsonSerializer::Serialize(JsonObject.ToSharedRef(), Writer);
	FFileHelper::SaveStringToFile(OutputString, *GetConfigPath());
}

FString UHeliosConfigBPLibrary::GetConfigPath()
{
	// Get Game Directory
	// Editor: GameDirectory of .uproject on disk
	// Runtime: InstallDir/WindowsNoEditor/GameName


	FString GameName = FApp::GetGameName();
	UE_LOG(LogTemp, Error, TEXT("%s"), *GameName);

	FString ThePath = FPaths::ConvertRelativePathToFull(FPaths::GameDir());
	ThePath += "HeliosConfig_" + GameName + ".json";
	return ThePath;
}

