// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PaperCharacter.h"
#include "PaperFlipbookComponent.h"
#include "PlayerClass.generated.h"

/**
*
*/
UCLASS()
class INPUTOUTPUTPROJECT_API APlayerClass : public APaperCharacter
{
	GENERATED_BODY()

public:
	APlayerClass();

protected:

	virtual void BeginPlay() override;

public:

	virtual void Tick(float deltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void IncreaseRightSpeed(float amount);

	void DecreaseRightSpeed(float amount);

	void IncreaseLeftSpeed(float amount);

	void DecreaseLeftSpeed(float amount);

	void IncreaseJumpHeight(float amount);

	void DecreaseJumpHeight(float amount);

	void Move();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = PlayerJumpHeight)
	float JumpHeight;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = PlayerMinJumpHeight)
	float MinJumpHeight;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = PlayerMaxJumpHeight)
	float MaxJumpHeight;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = PlayerWalkJumpHeight)
	float WalkJumpHeight;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = PlayerRightSpeed)
	float RightSpeed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = PlayerLeftSpeed)
	float LeftSpeed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = PlayerMinHorizontalSpeed)
	float MinHorizontalSpeed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = PlayerMaxHorizontalSpeed)
	float MaxHorizontalSpeed;
};