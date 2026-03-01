#include "pch.h"

void SetScalableFloatValue(FScalableFloat& Float, float Value) {
    Float.Value = Value;
    Float.Curve.CurveTable = nullptr;
    Float.Curve.RowName = FName();
}

void Main() {
    if (Configuration::bConsole) {
        AllocConsole();
        FILE* Console;
        freopen_s(&Console, "conout$", "w", stdout);
    } 

    UFortEngine::GetEngine()->GameViewport->ViewportConsole = (UFortConsole*)UGameplayStatics::SpawnObject(UFortConsole::StaticClass(), UFortEngine::GetEngine()->GameViewport);

    auto Playlist = UObject::FindObject<UFortPlaylistAthena>("FortPlaylistAthena Playlist_ShowdownAlt_Solo.Playlist_ShowdownAlt_Solo");
    while (!Playlist) 
        Playlist = UObject::FindObject<UFortPlaylistAthena>("FortPlaylistAthena Playlist_ShowdownAlt_Solo.Playlist_ShowdownAlt_Solo");

    auto Playlist2 = UObject::FindObject<UFortPlaylistAthena>("FortPlaylistAthena Playlist_ShowdownTournament_Solo.Playlist_ShowdownTournament_Solo");
    while (!Playlist2)
        Playlist2 = UObject::FindObject<UFortPlaylistAthena>("FortPlaylistAthena Playlist_ShowdownTournament_Solo.Playlist_ShowdownTournament_Solo");

    FUIExtension Extension{};
    Extension.Slot = EUIExtensionSlot::Primary;
    Extension.WidgetClass.ObjectID.AssetPath.AssetName = UKismetStringLibrary::Conv_StringToName(TEXT("ArenaScoringHUD_C"));
    Extension.WidgetClass.ObjectID.AssetPath.PackageName = UKismetStringLibrary::Conv_StringToName(TEXT("/Game/UI/Competitive/Arena/ArenaScoringHUD"));

    FUIExtension Extension2{};
    Extension2.Slot = EUIExtensionSlot::Primary;
    Extension2.WidgetClass.ObjectID.AssetPath.AssetName = UKismetStringLibrary::Conv_StringToName(TEXT("ShowdownScoringHUD_C"));
    Extension2.WidgetClass.ObjectID.AssetPath.PackageName = UKismetStringLibrary::Conv_StringToName(TEXT("/Game/UI/Frontend/Showdown/ShowdownScoringHUD"));

    Playlist->UIExtensions.Add(Extension);
    Playlist2->UIExtensions.Add(Extension2);

    if (Configuration::bRespawn) {
        Playlist->bAllowJoinInProgress = true;
        Playlist->bForceCameraFadeOnRespawn = true;
        Playlist->bForceRespawnLocationInsideOfVolume = true;
        Playlist->bRespawnInAir = true;
        Playlist->RespawnType = EAthenaRespawnType::InfiniteRespawn;
        SetScalableFloatValue(Playlist->RespawnHeight, 20000);
        SetScalableFloatValue(Playlist->RespawnTime, 3);
    }
}

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        std::thread(Main).detach();
        break;
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}


