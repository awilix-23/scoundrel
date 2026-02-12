#ifndef TYPE_H
#define TYPE_H

#include "CommonInterface.h"

typedef enum { false, true } bool_t;

typedef enum { JACK = 11, QUEEN , KING, ACE } faces_t;

typedef struct card { uint8_t value; char set[8]; struct card *link; } card_t;

#endif
