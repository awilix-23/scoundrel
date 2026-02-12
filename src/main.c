#include "core/common.h"
#include "core/deck.h"
#include "core/room.h"

int32_t main(void)
{
  uint32_t seed = time(NULL); /* better seeding methods ? */
  srand(seed);

  card_t *deck = create_deck(false);

  room_t room = init_room(4);
  populate_room(&room, &deck);

  pile_print(room.cards);

  destroy_pile(&deck);
  destroy_pile(&(room.cards));

  return 0;
}
