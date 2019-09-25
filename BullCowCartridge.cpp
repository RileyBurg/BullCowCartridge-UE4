// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();
    PrintLine(TEXT("Welcome to Bull Cows!"));
    PrintLine(TEXT("Guess the word!"));
    PrintLine(TEXT("Press tab to continue..."));
    HiddenWord = TEXT("cake");
    currentLives = 5;
}

void UBullCowCartridge::OnInput(const FString& Input) // When the player hits enter
{
    bool isWord{};
    ClearScreen();
    PrintLine(TEXT("You have " + currentLives + " left."));
    if (Input == HiddenWord)
    {
        isWord = true;
        PrintLine(TEXT("This is the word!"));
    } 
    else
    {
        isWord = false;
        PrintLine(TEXT("This is not the word. You've lost a life."));
        currentLives = LooseLife(currentLives);
    }
    if (LooseLife()==0)
    {   
        PrintLine(TEXT("YOU HAVE DIED."));
    }
}

int LooseLife(int currentLives)
{
    return (currentLives-1);
}