#include <stdio.h>
#include <string.h>
#include <time.h>
#include "TypeInterface.h"

#define APPEND_SET(SET, MAX_VALUE) \
  for (int i = 2; i <= MAX_VALUE; i++) { \
    strcpy(tmp_card.set, SET); \
    tmp_card.value = i; \
    tmp_deck[counter] = tmp_card; \
    counter++; \
  }
/******************************************************************************/
void append_top_card(card_t, card_t **);
void append_bottom_card(card_t, card_t **);
void print_pile(card_t *);
void draw_card(card_t **, card_t **);
card_t *create_deck(bool_t);
card_t *create_hand(void);
void destroy_pile(card_t **);
/******************************************************************************/
int32_t main(void)
{
  uint32_t seed = time(NULL); /* better seeding methods ? */
  srand(seed);

  card_t *deck = create_deck(false);
  card_t *hand = create_hand();

  draw_card(&deck, &hand);

  destroy_pile(&deck);
  destroy_pile(&hand);

  return 0;
}
/******************************************************************************/
void append_top_card(card_t card, card_t **pile)
{
  card_t *new_card;
  new_card = (card_t *)malloc(sizeof(card_t));

  new_card->value = card.value;
  strcpy(new_card->set, card.set);

  new_card->link = *pile;
  *pile = new_card;
}

void draw_card(card_t **source, card_t **destination)
{
  card_t *top_card;
  if (*source != NULL) {
    append_top_card(**source, destination);

    top_card = *source;
    *source = (*source)->link;

    free(top_card);
  }
}

void print_pile(card_t *pile)
{
  card_t *top_card;
  top_card = pile;

  while (top_card != NULL) {
    printf("%s %d\n", top_card->set, top_card->value);

    top_card = top_card->link;
  }
}

void shuffle_pile(card_t *avail_cards, uint8_t length, card_t **pile)
{
  uint8_t index;

  while (length >= 2) {
    length--;
    index = rand() % (length);

    append_top_card(avail_cards[index], pile);
    avail_cards[index] = avail_cards[length];
  }

  append_top_card(avail_cards[0], pile);
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

card_t *create_hand(void)
{
  card_t *hand;
  hand = NULL;

  return hand;
}

void destroy_pile(card_t **pile)
{
  card_t *previous_card, *current_card;

  if (*pile != NULL) {
    previous_card = *pile;
    current_card = (*pile)->link;

    while (current_card != NULL) {
      free(previous_card);
      previous_card = current_card;
      current_card = current_card->link;
    }

    free(previous_card);
    *pile = NULL;
  }
}
