// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "ShooterCharacter.generated.h"

UCLASS()
class SHOOTER1_API AShooterCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AShooterCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called for forward/backward input
	void MoveForward(float Value);

	// Called for left/right input
	void MoveRight(float Value);

	/* Called via input to turn at a given rate.
	@param		Rate this is a normalized rate, i.e. 1.0 means 100% of desired turn rate*/
	void TurnAtRate(float Rate);

	/* Called via input to look up/down at a given rate
	@param Rate		this is a normalized rate, i.e. 1.0 means 100% of desired rate*/
	void LookUpAtRate(float Rate);

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
private:
	// Camera boom posititioning the camera behind the character
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera", meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;

	// Camera that follows the characetr
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera", meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* FollowCamera;

	// Base turn rate, in deg/sec. Other scaling may affect final turn rate
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera", meta = (AllowPrivateAccess = "true"))
	float BaseTurnRate;

	// Base look up/down rate, in deg/sec. Other scaling may affect final turn rate
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera", meta = (AllowPrivateAccess = "true"))
	float BaseLookUpRate;

public:
	// Creates a USpringArmComponent that returns CameraBoom
	FORCEINLINE USpringArmComponent* GetCameraBoom() const { return CameraBoom; };
	// Creates a UCameraComponent that returns FollowCamera
	FORCEINLINE UCameraComponent* GetFollowCamera() const { return FollowCamera; };
};
