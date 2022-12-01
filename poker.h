#ifndef TEST_HEADER
#define TEST_HEADER

enum kolor {TREF = 1, PIK = 2, KARO = 3, KIER = 4};
enum wartosc {WALET = 11, DAMA = 12, KROL = 13, AS = 14};
struct karta {
    enum wartosc w;
    enum kolor k;
};

void sort(struct karta talia[], int talia_size);
void giveCards(struct karta *maintalia, struct karta *playertalia, int liczba_elementow);
bool isHavePair(struct karta *talia, int liczba_elementow);
bool isHaveTwoPairs(struct karta *talia, int liczba_elementow);
bool isHaveSet(struct karta *talia, int liczba_elementow);
bool isHaveStreet(struct karta *talia, int liczba_elementow);
bool isHaveFlash(struct karta *talia, int liczba_elementow);
bool isHaveFullHouse(struct karta *talia, int liczba_elementow);
bool isHaveKare(struct karta *talia, int liczba_elementow);
bool isHaveStreetFlash(struct karta *talia, int liczba_elementow);
bool isHaveFlashRoyal(struct karta *talia, int liczba_elementow);
int GetCombinationValue(struct karta* talia, int liczba_elementow);
void printPlayerCards(struct karta* talia, int liczba_elementow);

#endif