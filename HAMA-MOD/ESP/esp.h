// HMOOD__TG@i_8_f
 

#pragma once

#include "../SDK.hpp"
#include <vector>

 
void Drawesp();
void DrawWorldEsp();
void CaptureWorldEsp(SDK::ASTExtraPlayerCharacter* player, SDK::ASTExtraPlayerController* controller);
const char* GetVehicleName(SDK::ASTExtraVehicleBase* vehicle);

 
SDK::UWorld* GetFullWorld();
SDK::FVector GetBoneLocationByName(SDK::ASTExtraPlayerCharacter* actor,const char* boneName);
SDK::ASTExtraPlayerCharacter* GetTargetByCrossDist();

using namespace SDK;

template <class T>
inline void GetAllActors(std::vector<T*>& outActors) {
    outActors.clear();
UKismetMathLibrary* UMC = (UKismetMathLibrary*)UKismetMathLibrary::StaticClass();
    auto GWorld = GetFullWorld();
    if (!GWorld || !GWorld->PersistentLevel) return;

    UGameplayStatics* gGameplayStatics = (UGameplayStatics*)UGameplayStatics::StaticClass();
    if (!gGameplayStatics) return;

    TArray<AActor*> found;
    gGameplayStatics->GetAllActorsOfClass((UObject*)GWorld, T::StaticClass(), &found);

    outActors.reserve(found.Num());
    for (int i = 0; i < found.Num(); i++) {
        AActor* a = found[i];
        if (!a) continue;
        if (!a->RootComponent) continue;
        if ((uintptr_t)a < 0x10000) continue;                
        if ((uintptr_t)a > 0xFFFFFFFFFFFF) continue;         
        if (a == nullptr) continue;
        outActors.push_back((T*)a);
    }
}
