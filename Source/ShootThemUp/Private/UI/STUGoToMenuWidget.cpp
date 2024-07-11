// Shot Them Up. All Rights Reserved

#include "UI/STUGoToMenuWidget.h"
#include "Components/Button.h"
#include "Kismet/GameplayStatics.h"
#include "STUGameInstance.h"

DEFINE_LOG_CATEGORY_STATIC(LogSTUGoToMenuWidget, All, All);

void USTUGoToMenuWidget::NativeOnInitialized()
{
    Super::NativeOnInitialized();

    if (ToMenuButton)
    {
        ToMenuButton->OnClicked.AddDynamic(this, &USTUGoToMenuWidget::OnExitToMenu);
    }
}

void USTUGoToMenuWidget::OnExitToMenu()
{
    if (!GetWorld()) return;

    const auto STUGameInstance = GetWorld()->GetGameInstance<USTUGameInstance>();
    if (!STUGameInstance) return;

    if (STUGameInstance->GetMenuLevelName().IsNone())
    {
        UE_LOG(LogSTUGoToMenuWidget, Error, TEXT("Level name is NONE"))
        return;
    }
    
    UGameplayStatics::OpenLevel(this, STUGameInstance->GetMenuLevelName());
}