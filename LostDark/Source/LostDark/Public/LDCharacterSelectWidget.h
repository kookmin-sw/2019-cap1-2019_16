// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "LostDark.h"
#include "Blueprint/UserWidget.h"
#include "LDCharacterSelectWidget.generated.h"

/**
	Select 맵에서 좌우 버튼을 눌렀을때, 메시를 바꿔주는 기능을 구현하는 클래스.

 	현재 레벨에 있는 스켈레탈 메시 액터의 목록을 가져오고
	버튼을 누를때마다 스켈레탈 메시 컴포넌트에 지정한 스켈레탈 메시를 변경하는 기능을 구현
	현재 월드에 있는 특정 타입을 상속받은 액터의 목록은 TActorIterator<액터타입> 구문으로 가져온다
 */
UCLASS()
class LOSTDARK_API ULDCharacterSelectWidget : public UUserWidget
{
	GENERATED_BODY()
	
protected:
	// 블루프린트에서 이 함수를 사용하기 위해서.
	UFUNCTION(BlueprintCallable)
		void NextCharacter(bool bForward = true);

	virtual void NativeConstruct() override;

protected:
	// 메시 인덱스
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Character)
		int32 CurrentIndex;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Character)
		int32 MaxIndex;

	// 레벨에 배치된 유일한 스켈레탈 매쉬 컴포넌트를 갖고있는 액터를 담을 변수
	TWeakObjectPtr<USkeletalMeshComponent> TargetComponent;

	UPROPERTY()
		class UButton* PrevButton;
	UPROPERTY()
		class UButton* NextButton;
	UPROPERTY()
		class UEditableTextBox* TextBox;
	UPROPERTY()
		class UButton* ConfirmButton;

private:
	UFUNCTION()
		void OnPrevClicked();
	UFUNCTION()
		void OnNextClicked();
	UFUNCTION()
		void OnConfirmClicked();
};
