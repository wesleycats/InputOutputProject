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

	float jumpHeight;
	float minJumpHeight;
	float maxJumpHeight;
	float walkJumpHeight;
	float rightSpeed;
	float leftSpeed;
	float minHorizontalSpeed;
	float maxHorizontalSpeed;
};