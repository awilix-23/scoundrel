#ifndef ROOM_H
#define ROOM_H

#include "common.h"
#include "pile.h"

room_t init_room(uint8_t);
void populate_room(room_t *, card_t **);

#endif
