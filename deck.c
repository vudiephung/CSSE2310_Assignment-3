#include "deck.h"
#include "stdlib.h"

void handle_deck(FILE* deckFile, Deck *myDeck) {
    int next = 0;
    int numberOfCards;
    fscanf(deckFile, "%d", &numberOfCards);
    if (numberOfCards < 4) {
        myDeck->valid = false;
        return;
    } 
    char* cards = malloc(sizeof(char) * (numberOfCards + 1));
    for (int i = 0; i < numberOfCards + 1; i++) {
        next = fgetc(deckFile);
        if ((next >= 'A' && next <= 'E') || next == '\n') {
            cards[i] = (char)next;
            //printf("%d %c\n", i, (char)next);
        } else {
            break;
        }
    }
    bool valid = (cards[numberOfCards] == '\n');
    if (valid) {
        myDeck->numberOfCards = numberOfCards;
        myDeck->cards = cards;
    }
    myDeck->valid = valid;
}

bool is_valid_deck_file(char* deck, Deck* myDeck) {
    FILE* deckFile = fopen(deck, "r");
    if (deckFile == NULL) {
        return false;
    }
    handle_deck(deckFile, myDeck);
    fclose(deckFile);
    return myDeck->valid;
}