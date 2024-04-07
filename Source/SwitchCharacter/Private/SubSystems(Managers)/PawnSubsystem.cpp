#include "SubSystems(Managers)/PawnSubsystem.h"
#include <Utils/Util.h>

void UPawnSubsystem::AddNewPawn(TObjectPtr<APawn> _pawns)
{
	pawns.Add(_pawns);
	LOG("Add");
}

void UPawnSubsystem::RemoveAll()
{
	pawns.Empty();
}

void UPawnSubsystem::SwitchPawn()
{
	indexPawn++;
	indexPawn %= pawns.Num();
	GetWorld()->GetFirstPlayerController()->Possess(pawns[indexPawn]);
	LOG("Changement de joueur ");
}
