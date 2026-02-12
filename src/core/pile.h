#ifndef PILE_H
#define PILE_H

#include "common.h"

void append_top_card(card_t, card_t **);

void append_bottom_card(card_t, card_t **);

void draw_card(card_t **, card_t **);

void shuffle_pile(card_t *, uint8_t, card_t **);

void destroy_pile(card_t **);

void pile_print(card_t *);

uint8_t pile_length(card_t *);

#endif
