#include "Kismet/KismetSystemLibrary.h"
//#include <iostream>
//using namespace std;
//locale::global(locale(""));
//srand((time(nullptr)));
#pragma region LOG
#define LOG(msg)  UKismetSystemLibrary::PrintString(this , msg)
#define LOG_COLOR(msg , color)  UKismetSystemLibrary::PrintString(this , msg , true , true , FLinearColor::color)
#define LOG_COLOR_TIME(msg , color , time)  UKismetSystemLibrary::PrintString(this , msg , true , true , FLinearColor::color,time)
#pragma endregion 

#pragma region Component_Util
#define CREATE(T, name)  CreateDefaultSubobject<T>(name)
#pragma endregion



#pragma region To_STRING

#define TO_STRING(F) FString::SanitizeFloat(F)
#define INT_TO_STRING(I) FString::FromInt(I)

#pragma region DEBUG

#define USE_DEBUG 1

#define DEBUG_BOX(size , color)\
if(USE_DEBUG)\
DrawDebugBox(GetWorld() , GetActorLocation() , FVector(size), FColor::color)

#define DEBUG_LINE(fVector , color,lifetime ,dethPriority , thickness)\
if(USE_DEBUG)\
DrawDebugLine(GetWorld() ,GetActorLocation(), fVector , FColor::color , false , lifetime ,dethPriority , thickness)

#define DEBUG_LINE_COLOR( r , g , b) DrawDebugLine(GetWorld() ,GetActorLocation(), settings.GetTargetLocation() , FColor(r,g,b) , false , -1 ,0 , 3)



#define DEBUG_LINE_COLOR_V2(color) DrawDebugLine(GetWorld() ,GetActorLocation(), settings.GetTargetLocation() , FColor::color, false , -1 ,0 , 3)

#define DEBUG_SPHERE(radius ,segments ,color)\
if(USE_DEBUG)\
DrawDebugSphere(GetWorld() , settings.GetTargetLocation() , radius , segments , FColor::color);
#pragma endregion



#pragma region DEBUG CORRECTION



#define CREAT_CLASS

#define DRAW_LINE(from , to , color , size)\
	if(USE_DEBUG)\
	DrawDebugLine(GetWorld() , from , to , FColor::color , false , -1 , 0 , size)

#define DRAW_SPHERE(from , radius , color , size)\
	if(USE_DEBUG)\
DrawDebugSphere(GetWorld() ,from , radius , 10, color , false, -1,0,size)

#define DRAW_BOX(from , extent , color , size) DrawDebugBox(GetWorld() , from  )\
	if(USE_DEBUG)\
DrawDebugBox(GetWorld() , GetActorLocation() , FVector(extent) , FColor::color , false , -1 , 0 , size)
#pragma endregion
#define DELTATIME  GetWorld()->DeltaTimeSeconds 