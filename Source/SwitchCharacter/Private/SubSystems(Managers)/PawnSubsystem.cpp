#include "SubSystems(Managers)/PawnSubsystem.h"
#include <Utils/Util.h>

//void UPawnSubsystem::AddNewPawn(TObjectPtr<APawn> _pawns)
//{
//	pawns.Add(_pawns);
//	LOG("Add");
//}

void UPawnSubsystem::AddPawn(const FString& _key, TObjectPtr<APawn> _pawn)
{

	if (allControllablePawns.Contains(_key)) return;
	allControllablePawns.Add(_key, _pawn);
}

void UPawnSubsystem::SwitchTo(const FString& _key)
{
	if (!allControllablePawns.Contains(_key)) return;

	TObjectPtr<APawn> _pawn  = allControllablePawns[_key];
	if (!_pawn) return;
	UE_LOG(LogTemp, Warning, TEXT("%s"), *_pawn->GetName());
	GetWorld()->GetFirstPlayerController()->Possess(_pawn);
}

void UPawnSubsystem::RemoveAll()
{
	pawns.Empty();
}

//void UPawnSubsystem::SwitchPawn()
//{
//	indexPawn++;
//	indexPawn %= pawns.Num();
//	GetWorld()->GetFirstPlayerController()->Possess(pawns[indexPawn]);
//	LOG("Changement de joueur ");
//}
