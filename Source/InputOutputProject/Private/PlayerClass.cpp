// Fill out your copyright notice in the Description page of Project Settings.

#include "PlayerClass.h"
#include "Components/InputComponent.h"
#include "GameFramework/MovementComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/NavMovementComponent.h"

APlayerClass::APlayerClass()
{
	PrimaryActorTick.bCanEverTick = true;
	JumpHeight = 0;
	MinJumpHeight = 0;
	MaxJumpHeight = 750;
	WalkJumpHeight = 300;
	RightSpeed = 0;
	LeftSpeed = 0;
	MinHorizontalSpeed = 0;
	MaxHorizontalSpeed = 5;

	GetCharacterMovement()->JumpZVelocity = JumpHeight;
}

void APlayerClass::BeginPlay()
{
	Super::BeginPlay();
}

void APlayerClass::Tick(float deltaTime)
{
	Super::Tick(deltaTime);
	UE_LOG(LogTemp, Warning, TEXT("left speed: %f"), LeftSpeed);
	UE_LOG(LogTemp, Warning, TEXT("right speed: %f"), RightSpeed);
	UE_LOG(LogTemp, Warning, TEXT("jump height: %f"), JumpHeight);

	GetCharacterMovement()->JumpZVelocity = JumpHeight;

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
}

void APlayerClass::IncreaseRightSpeed(float amount)
{
	if (amount != 0) RightSpeed += 1;
	if (RightSpeed >= MaxHorizontalSpeed) RightSpeed = MaxHorizontalSpeed;
}

void APlayerClass::IncreaseLeftSpeed(float amount)
{
	if (amount != 0) LeftSpeed += 1;
	if (LeftSpeed >= MaxHorizontalSpeed) LeftSpeed = MaxHorizontalSpeed;
}

void APlayerClass::IncreaseJumpHeight(float amount)
{
	if (amount != 0) JumpHeight += 100;
	if (JumpHeight >= MaxJumpHeight) JumpHeight = MaxJumpHeight;
}

void APlayerClass::DecreaseRightSpeed(float amount)
{
	if (amount != 0) RightSpeed -= 1;
	if (RightSpeed <= MinHorizontalSpeed)
	{
		RightSpeed = MinHorizontalSpeed;
	}
}

void APlayerClass::DecreaseLeftSpeed(float amount)
{
	if (amount != 0) LeftSpeed -= 1;
	if (LeftSpeed <= MinHorizontalSpeed) LeftSpeed = MinHorizontalSpeed;
}

void APlayerClass::DecreaseJumpHeight(float amount)
{
	if (amount != 0)
	{
		JumpHeight -= 100;
	}

	if (JumpHeight <= MinJumpHeight) JumpHeight = MinJumpHeight;
}

void APlayerClass::Move()
{
	if (RightSpeed == 0 && LeftSpeed == 0 && JumpHeight == 0)
	{
		return;
	}

	AddMovementInput(GetActorForwardVector(), RightSpeed);
	AddMovementInput(GetActorForwardVector(), -LeftSpeed);
	Jump();

	if ((RightSpeed > 0 || LeftSpeed > 0) && JumpHeight == 0)
	{
		GetCharacterMovement()->JumpZVelocity = WalkJumpHeight;
		Jump();
	}
}