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
    int32 ValueInt32; // uint16 ��� int32 ���
};

USTRUCT(BlueprintType)
struct FMyCustomStruct
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "information")
    FMyLevelStruct MyLevelStruct;  // ��ø�� ����ü

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "information")
    FMySwitchStruct MySwitchStruct;  // ��ø�� ����ü

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "information")
    FEventIdStruct EventIdStruct;  // ��ø�� ����ü

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "information")
    FReciveTimeStruct ReciveTimeStruct;  // ��ø�� ����ü

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "information")
    FSeverityStruct SeverityStruct;  // ��ø�� ����ü
};