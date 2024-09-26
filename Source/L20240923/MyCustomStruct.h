#pragma once

#include "CoreMinimal.h"
#include "MyCustomStruct.generated.h"

USTRUCT(BlueprintType)
struct FMyLevelStruct
{
    GENERATED_BODY()

    UPROPERTY(BlueprintReadWrite, Category = "Node Data")
    FString DisplayName;

    UPROPERTY(BlueprintReadWrite, Category = "Node Data")
    FString DataType;

    UPROPERTY(BlueprintReadWrite, Category = "Node Data")
    double ValueDouble;

};
USTRUCT(BlueprintType)
struct FMySwitchStruct
{
    GENERATED_BODY()

    UPROPERTY(BlueprintReadWrite, Category = "Node Data")
    FString DisplayName;

    UPROPERTY(BlueprintReadWrite, Category = "Node Data")
    FString DataType;

    UPROPERTY(BlueprintReadWrite, Category = "Node Data")
    bool ValueBool;

};
USTRUCT(BlueprintType)
struct FEventIdStruct
{
    GENERATED_BODY()

    UPROPERTY(BlueprintReadWrite, Category = "Node Data")
    FString DisplayName;

    UPROPERTY(BlueprintReadWrite, Category = "Node Data")
    FString DataType;

    UPROPERTY(BlueprintReadWrite, Category = "Node Data")
    TArray<uint8> ValueByteString;

};

USTRUCT(BlueprintType)
struct FReciveTimeStruct
{
    GENERATED_BODY()

    UPROPERTY(BlueprintReadWrite, Category = "Node Data")
    FString DisplayName;

    UPROPERTY(BlueprintReadWrite, Category = "Node Data")
    FString DataType;

    UPROPERTY(BlueprintReadWrite, Category = "Node Data")
    FDateTime ValueDateTime;

};
USTRUCT(BlueprintType)
struct FSeverityStruct
{
    GENERATED_BODY()

    UPROPERTY(BlueprintReadWrite, Category = "Node Data")
    FString DisplayName;

    UPROPERTY(BlueprintReadWrite, Category = "Node Data")
    FString DataType;

    UPROPERTY(BlueprintReadWrite, Category = "Node Data")
    int32 ValueInt32; // uint16 대신 int32 사용
};

USTRUCT(BlueprintType)
struct FMyCustomStruct
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "information")
    FMyLevelStruct MyLevelStruct;  // 중첩된 구조체

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "information")
    FMySwitchStruct MySwitchStruct;  // 중첩된 구조체

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "information")
    FEventIdStruct EventIdStruct;  // 중첩된 구조체

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "information")
    FReciveTimeStruct ReciveTimeStruct;  // 중첩된 구조체

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "information")
    FSeverityStruct SeverityStruct;  // 중첩된 구조체
};