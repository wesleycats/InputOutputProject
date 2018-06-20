// Fill out your copyright notice in the Description page of Project Settings.

#include "PlayerClass.h"
#include "Components/InputComponent.h"
#include "GameFramework/MovementComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/NavMovementComponent.h"

APlayerClass::APlayerClass()
{
	PrimaryActorTick.bCanEverTick = true;
	jumpHeight = 0;
	minJumpHeight = 0;
	maxJumpHeight = 750;
	walkJumpHeight = 300;
	rightSpeed = 0;
	leftSpeed = 0;
	minHorizontalSpeed = 0;
	maxHorizontalSpeed = 5;

	GetCharacterMovement()->JumpZVelocity = jumpHeight;
}

void APlayerClass::BeginPlay()
{
	Super::BeginPlay();
}

void APlayerClass::Tick(float deltaTime)
{
	Super::Tick(deltaTime);
	UE_LOG(LogTemp, Warning, TEXT("left speed: %f"), leftSpeed);
	UE_LOG(LogTemp, Warning, TEXT("right speed: %f"), rightSpeed);
	UE_LOG(LogTemp, Warning, TEXT("jump height: %f"), jumpHeight);

	GetCharacterMovement()->JumpZVelocity = jumpHeight;

	Move();
}

void APlayerClass::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("IncreaseRightSpeed", this, &APlayerClass::IncreaseRightSpeed);
	PlayerInputComponent->BindAxis("IncreaseLeftSpeed", this, &APlayerClass::IncreaseLeftSpeed);
	PlayerInputComponent->BindAxis("IncreaseJumpHeight", this, &APlayerClass::IncreaseJumpHeight);
	PlayerInputComponent->BindAxis("DecreaseRightSpeed", this, &APlayerClass::DecreaseRightSpeed);
	PlayerInputComponent->BindAxis("DecreaseLeftSpeed", this, &APlayerClass::DecreaseLeftSpeed);
	PlayerInputComponent->BindAxis("DecreaseJumpHeight", this, &APlayerClass::DecreaseJumpHeight);
	//PlayerInputComponent->BindAxis("MoveUp", this, &APlayerClass::MoveUp);
}

void APlayerClass::IncreaseRightSpeed(float amount)
{
	if (amount != 0) rightSpeed += 1;
	if (rightSpeed >= maxHorizontalSpeed) rightSpeed = maxHorizontalSpeed;

	//UE_LOG(LogTemp, Warning, TEXT("Amount: %f"), amount);
}

void APlayerClass::IncreaseLeftSpeed(float amount)
{
	if (amount != 0) leftSpeed += 1;
	if (leftSpeed >= maxHorizontalSpeed) leftSpeed = maxHorizontalSpeed;

}

void APlayerClass::IncreaseJumpHeight(float amount)
{
	if (amount != 0) jumpHeight += 100;
	if (jumpHeight >= maxJumpHeight) jumpHeight = maxJumpHeight;
}

void APlayerClass::DecreaseRightSpeed(float amount)
{
	if (amount != 0) rightSpeed -= 1;
	if (rightSpeed <= minHorizontalSpeed)
	{
		rightSpeed = minHorizontalSpeed;
	}
}

void APlayerClass::DecreaseLeftSpeed(float amount)
{
	if (amount != 0) leftSpeed -= 1;
	if (leftSpeed <= minHorizontalSpeed) leftSpeed = minHorizontalSpeed;
}

void APlayerClass::DecreaseJumpHeight(float amount)
{
	if (amount != 0)
	{
		jumpHeight -= 100;
	}

	if (jumpHeight <= minJumpHeight) jumpHeight = minJumpHeight;
}

void APlayerClass::Move()
{
	if (rightSpeed == 0 && leftSpeed == 0 && jumpHeight == 0)
	{
		return;
	}

	AddMovementInput(GetActorForwardVector(), rightSpeed);
	AddMovementInput(GetActorForwardVector(), -leftSpeed);
	Jump();

	if ((rightSpeed > 0 || leftSpeed > 0) && jumpHeight == 0)
	{
		GetCharacterMovement()->JumpZVelocity = walkJumpHeight;
		Jump();
	}
}