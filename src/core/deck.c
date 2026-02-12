#include "deck.h"

#define APPEND_SET(SET, MAX_VALUE) \
  for (uint8_t i = 2; i <= MAX_VALUE; i++) { \
    strcpy(tmp_card.set, SET); \
    tmp_card.value = i; \
    tmp_deck[counter] = tmp_card; \
    counter++; \
  }

card_t *create_deck(bool_t include_jokers)
{
  card_t *deck;
  deck = NULL;

  uint8_t counter = 0;
  card_t tmp_deck[46]; /* 44 w/o jokers */
  card_t tmp_card;

  APPEND_SET("CLUBS", 14);
  APPEND_SET("SPADES", 14);
  APPEND_SET("HEARTS", 10);
  APPEND_SET("DIAMONDS", 10);

  if (include_jokers) {
    APPEND_SET("JOKERS", 3);
  }

  shuffle_pile(tmp_deck, counter, &deck);

  return deck;
}
