#include "room.h"

room_t init_room(uint8_t max_cards)
{
  card_t *cards;
  cards = NULL;

  room_t room = { .max_cards = max_cards, .cards = cards };

  return room;
}

void populate_room(room_t *room, card_t **deck)
{
  for (uint8_t i = pile_length(room->cards); i <= room->max_cards - 1; i++) {
    draw_card(deck, &(room->cards));
  }
}

void get_room_card(card_t card, room_t *room, card_t **hand)
{
  card_t *previous_card, *current_card;
  current_card = room->cards;
  previous_card = NULL;

  while (current_card != NULL) {
    if (current_card->value != card.value
        || strcmp(current_card->set, card.set) != 0) {
      previous_card = current_card;
      current_card = current_card->link;
      continue;
    } else break;
  }

  if (current_card == NULL) return; /* Card not found... */

  if (previous_card == NULL) {
    draw_card(&(room->cards), hand);
  } else {
    previous_card->link = current_card->link;
    current_card->link = NULL;
    draw_card(&current_card, hand);
  }
}
