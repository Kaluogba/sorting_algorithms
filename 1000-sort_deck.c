#include <stdlib.h>
#include <stdio.h>
#include "deck.h"

/**
 * bubble_sort_deck - Sorts a deck of cards using the Bubble Sort algorithm
 * @deck: Pointer to the head of the deck
 */
void bubble_sort_deck(deck_node_t **deck) {
    if (*deck == NULL || (*deck)->next == NULL)
        return;

    int swapped;
    deck_node_t *ptr1;
    deck_node_t *lptr = NULL;

    do {
        swapped = 0;
        ptr1 = *deck;

        while (ptr1->next != lptr) {
            const card_t *card1 = ptr1->card;
            const card_t *card2 = ptr1->next->card;

            // Compare card values and kinds
            if ((card1->kind > card2->kind) ||
                (card1->kind == card2->kind && strcmp(card1->value, card2->value) > 0)) {
                swap_cards(ptr1, ptr1->next);
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}

/**
 * swap_cards - Swaps two card nodes in a deck
 * @node1: First card node
 * @node2: Second card node
 */
void swap_cards(deck_node_t *node1, deck_node_t *node2) {
    const card_t *temp = node1->card;
    node1->card = node2->card;
    node2->card = temp;
}
