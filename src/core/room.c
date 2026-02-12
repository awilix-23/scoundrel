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
