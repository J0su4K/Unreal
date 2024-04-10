// Fill out your copyright notice in the Description page of Project Settings.


#include "MaterialInteract/ColorSwitchMeshActor.h"
#include <Utils/Util.h>

void AColorSwitchMeshActor::BeginPlay()
{
	Super::BeginPlay();
	InitMaterial();
	//SwitchRandomColor();
}

void AColorSwitchMeshActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	LOG("OK");
}

//void AColorSwitchMeshActor::Tick(float DeltaTime)
//{
//	Super::Tick(DeltaTime);
//	SwitchRandomColor();
//	LOG("OK");
//	
//	
//	
//	DELTATIME;
//}

void AColorSwitchMeshActor::InitMaterial()
{
	if (!otherActor)
	return;

	TObjectPtr<UStaticMeshComponent> _staticMesh = otherActor->GetComponentByClass<UStaticMeshComponent>();

	if (!_staticMesh)
	return;
	LOG_COLOR_TIME("Okay" , Red , 20);

	dynamicMaterial = _staticMesh->CreateDynamicMaterialInstance(0);
}

void AColorSwitchMeshActor::SwitchRandomColor()
{
	if(!dynamicMaterial)
	return;

	dynamicMaterial->SetVectorParameterValue("BaseColor", FLinearColor::MakeRandomColor());
}
