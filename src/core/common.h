#ifndef CORE_COMMON_H
#define CORE_COMMON_H

#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

typedef enum { false, true } bool_t;

typedef struct card { uint8_t value; char set[8]; struct card *link; } card_t;

typedef struct { uint8_t max_cards; card_t *cards; } room_t;

#endif
