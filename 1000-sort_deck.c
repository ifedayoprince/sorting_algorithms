#include <stdlib.h>
#include "deck.h"


/**
 * cmp_card - Compare two cards in the deck
 * @a: Pointer to the first card
 * @b: Pointer to the second card
 *
 * Return: A negative value if @a should be placed before @b,
 *         a positive value if @a should be placed after @b,
 *         zero if @a and @b are equal.
 */
int cmp_card(const void *a, const void *b)
{
    const card_t *card_a = *(const card_t **)a;
    const card_t *card_b = *(const card_t **)b;
    int val_cmp = strcmp(card_a->value, card_b->value);

    if (val_cmp != 0)
        return (val_cmp);
    return (card_a->kind - card_b->kind);
}

/**
 * sort_deck - Sort the deck of cards
 * @deck: Double pointer to the head of the deck
 */
void sort_deck(deck_node_t **deck)
{
    deck_node_t *node, *next;
    card_t **cards;
    size_t i, n;

    if (!deck || !*deck)
        return;

    for (node = *deck, n = 0; node; node = node->next, n++)
        ;

    cards = malloc(n * sizeof(*cards));
    if (!cards)
        return;

    for (node = *deck, i = 0; node; node = next)
    {
        next = node->next;
        cards[i++] = (card_t *)node->card;
        free(node);
    }

    qsort(cards, n, sizeof(*cards), cmp_card);

    *deck = NULL;
    for (i = 0; i < n; i++)
    {
        node = malloc(sizeof(*node));
        if (!node)
        {
            while (*deck)
            {
                next = (*deck)->next;
                free(*deck);
                *deck = next;
            }
            free(cards);
            return;
        }
        node->card = cards[i];
        node->next = *deck;
        if (*deck)
            (*deck)->prev = node;
        node->prev = NULL;
        *deck = node;
    }
    free(cards);
}
