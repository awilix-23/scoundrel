#include "pile.h"

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

void pile_print(card_t *pile)
{
  card_t *top_card;
  top_card = pile;

  while (top_card != NULL) {
    printf("%s %d\n", top_card->set, top_card->value);

    top_card = top_card->link;
  }
}

uint8_t pile_length(card_t *pile)
{
  uint8_t length = 0;

  card_t *crawler;
  crawler = pile;

  while (crawler != NULL) {
    crawler = crawler->link;
    length++;
  }

  return length;
}
