#include <stdio.h>
#include <stdbool.h>
#include "poker.h"

int min(struct karta talia[], int talia_size, int i){
    int min = talia[i].w;
    int min_index = i;
    for (int j = i + 1; j < talia_size; j++) {
        if (min > talia[j].w) {
            min = talia[j].w;
            min_index = j;
        }
    }
    return min_index;
}

void swap(struct karta* karta1, struct karta* karta2){
    struct karta temp;
    temp = *karta1;
    *karta1 = *karta2;
    *karta2 = temp;
}

void giveCards(struct karta *maintalia, struct karta *playertalia, int liczba_elementow){
    srand(time(NULL));
    for (int i = 0; i < liczba_elementow; i++) {
        bool Confirmed = false;
        while (!Confirmed) {
        int randomnumber = rand() % 52;
            if (maintalia[randomnumber].w != 0) {
                swap(&maintalia[randomnumber], &playertalia[i]);
                Confirmed = true;
            }
        }
    }
}

void sort(struct karta talia[], int talia_size) {
    for (int i = 0; i < talia_size; i++) {
        int min_index = min(talia, talia_size, i);
        swap(&talia[i], &talia[min_index]);
    }
}

bool isHavePair(struct karta *talia, int liczba_elementow){
    int counter = 0;
    int tempkarta = talia[0].w;
    for (int i = 0; i < liczba_elementow; i++) {
        if (talia[i].w == tempkarta) counter++;
        else {
            tempkarta = talia[i].w;
            counter = 1;
        }
        if (counter == 2) return true;
    }
    return false;
}

bool isHaveTwoPairs(struct karta *talia, int liczba_elementow){
    int pair = 0;
    int temppair = -1;
    for (int i = 0; i < liczba_elementow; i++){
        for (int j = i + 1; j < liczba_elementow; j++){
            if (talia[i].w == talia[j].w && i != j && talia[i].w != temppair) {
                pair++;
                temppair = talia[i].w;
            }
            if (pair == 2) return true;
        }
    }
    return false;
}

bool isHaveSet(struct karta *talia, int liczba_elementow){
    int counter = 0;
    int tempkarta = talia[0].w;
    for (int i = 0; i < liczba_elementow; i++) {
        if (talia[i].w == tempkarta) counter++;
        else {
            tempkarta = talia[i].w;
            counter = 1;
        }
        if (counter == 3) return true;
    }
    return false;
}

bool isHaveStreet(struct karta *talia, int liczba_elementow){
    int counter = 0;
    for (int i = 0; i < liczba_elementow - 1; i++){
        if(talia[i].w == talia[i+1].w-1) counter++;
    } 
    if (counter == 4){
        return true;
    }
    return false;
}

bool isHaveFlash(struct karta *talia, int liczba_elementow){
    int counter = 0;
    for (int i = 0; i < liczba_elementow - 1; i++){
        if(talia[i].k == talia[i+1].k) counter++;
    }
    if(counter == 4){
        return true;
    }
    return false;
}

bool isHaveFullHouse(struct karta *talia, int liczba_elementow){
    if(isHaveSet(talia, liczba_elementow) && isHaveTwoPairs(talia, liczba_elementow)) return true;
    return false;
}

bool isHaveKare(struct karta *talia, int liczba_elementow){
    int counter = 0;
    int tempkarta = talia[0].w;
    for (int i = 0; i < liczba_elementow; i++) {
        if (talia[i].w == tempkarta) counter++;
        else {
            tempkarta = talia[i].w;
            counter = 1;
        }
        if (counter == 4) return true;
    }
    return false;
}

bool isHaveStreetFlash(struct karta *talia, int liczba_elementow){
    if(isHaveFlash(talia, liczba_elementow) && isHaveStreet(talia, liczba_elementow)) return true;
    return false;
}

bool isHaveFlashRoyal(struct karta *talia, int liczba_elementow){
    enum kolor tempkolor = talia[0].k;
    int temp = 10;
    for (int i = 0; i < liczba_elementow; i++) if (talia[i].k != tempkolor || talia[i].w != temp + i) return false;
    return true;
}

int GetCombinationValue(struct karta* talia, int liczba_elementow){
    if (isHaveFlashRoyal(talia, liczba_elementow)) return 23;
    if (isHaveStreetFlash(talia, liczba_elementow)) return 22;
    if (isHaveKare(talia, liczba_elementow)) return 21;
    if (isHaveFullHouse(talia, liczba_elementow)) return 20;
    if (isHaveFlash(talia, liczba_elementow)) return 19;
    if (isHaveStreet(talia, liczba_elementow)) return 18;
    if (isHaveSet(talia, liczba_elementow)) return 17;
    if (isHaveTwoPairs(talia, liczba_elementow)) return 16;
    if (isHavePair(talia, liczba_elementow)) return 15;
    return talia[4].w;
}

void printPlayerCards(struct karta* talia, int liczba_elementow) {
    printf("Player hand:\n");
    for (int i = 0; i < liczba_elementow; i++) printf("Karta: %d Typ: %d\n", talia[i].w, talia[i].k);
    printf("Combination value: %d\n", GetCombinationValue(talia, liczba_elementow));
    printf("\n");
}