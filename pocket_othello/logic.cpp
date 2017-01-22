#include "logic.h"
#include <stdlib.h>

static Vec2i LEVEL0[] = {
  Vec2i(0, 0), Vec2i(7, 0), Vec2i(7, 7), Vec2i(0, 7)
};

static Vec2i LEVEL1[] = {
  Vec2i(2, 2), Vec2i(3, 2), Vec2i(4, 2),
  Vec2i(5, 2), Vec2i(5, 3), Vec2i(5, 4),
  Vec2i(5, 5), Vec2i(4, 5), Vec2i(3, 5),
  Vec2i(2, 5), Vec2i(2, 4), Vec2i(2, 3)
};

static Vec2i LEVEL2[] = {
  Vec2i(3, 1), Vec2i(4, 1),
  Vec2i(6, 3), Vec2i(6, 4),
  Vec2i(4, 6), Vec2i(3, 6),
  Vec2i(1, 4), Vec2i(1, 3)
};

static Vec2i LEVEL3[] = {
  Vec2i(2, 1), Vec2i(5, 1),
  Vec2i(6, 2), Vec2i(6, 5),
  Vec2i(5, 6), Vec2i(2, 6),
  Vec2i(1, 5), Vec2i(1, 2)
};

static Vec2i LEVEL4[] = {
  Vec2i(1, 0), Vec2i(2, 0), Vec2i(3, 0), Vec2i(4, 0), Vec2i(5, 0), Vec2i(6, 0),
  Vec2i(7, 1), Vec2i(7, 2), Vec2i(7, 3), Vec2i(7, 4), Vec2i(7, 5), Vec2i(7, 6),
  Vec2i(6, 7), Vec2i(5, 7), Vec2i(4, 7), Vec2i(3, 7), Vec2i(2, 7), Vec2i(1, 7),
  Vec2i(0, 6), Vec2i(0, 5), Vec2i(0, 4), Vec2i(0, 3), Vec2i(0, 2), Vec2i(0, 1)
};

static Vec2i LEVEL5[] = {
  Vec2i(1, 1), Vec2i(6, 1), Vec2i(6, 6), Vec2i(1, 6)
};

static void swap(Vec2i &l, Vec2i &r) {
  Vec2i t = l;
  l = r;
  r = t;
}

static bool valid(unsigned char x, unsigned char y) {
  return x <= 7 && y <= 7;
}

static bool valid(char x, char y) {
  return x >= 0 && y >= 0 && x <= 7 && y <= 7;
}

unsigned char place(Board* b, Operation* o, GridStates s, unsigned char x, unsigned char y, bool p) {
  char tx, ty;
  char result = 0;
  if (b->get(x, y) != GS_EMPTY) return result;
  for (char j = -1; j <= 1; ++j) {
    for (char i = -1; i <= 1; ++i) {
      if (i == 0 && j == 0) continue;
      char t = 0;
      tx = x; ty = y;
      do {
        tx += i; ty += j;
        if (!valid(tx, ty))
          break;
        if ((t == 0 || t == 1) && b->get(tx, ty) == GS_EMPTY) {
          break;
        } else if (t == 0 && b->get(tx, ty) == o->currentSide()) {
          break;
        } else if (t == 0 && b->get(tx, ty) == o->opponentSide()) {
          ++t;
        } else if (t == 1 && b->get(tx, ty) == o->currentSide()) {
          ++t;
          break;
        }
      } while (true);
      if (t == 2) {
        ++result;
        if (p) {
          while (tx != x || ty != y) {
            tx -= i; ty -= j;
            b->set(tx, ty, o->currentSide());
          }
        }
      }
    }
  }
  return result;
}

bool placeable(Board* b, Operation* o, GridStates s) {
  for (unsigned char i = 0; i < 8; ++i) {
    for (unsigned char j = 0; j < 8; ++j) {
      if (place(b, o, s, i, j, false))
        return true;
    }
  }
  return false;
}

bool turn(Board* b, Operation* o) {
  unsigned char c0, c1;
  b->count(c0, c1);
  o->c0 = c0;
  o->c1 = c1;
  if (placeable(b, o, o->opponentSide())) {
    o->playing = o->playing == 0 ? 1 : 0;
    return false;
  }
  if (placeable(b, o, o->currentSide())) {
    return false;
  }
  return true; /* Game over. */
}

void shuffle(void) {
  for (unsigned char i = 0; i < 24; ++i) {
    swap(LEVEL0[rand() % countof(LEVEL0)], LEVEL0[rand() % countof(LEVEL0)]);
    swap(LEVEL1[rand() % countof(LEVEL1)], LEVEL1[rand() % countof(LEVEL1)]);
    swap(LEVEL2[rand() % countof(LEVEL2)], LEVEL2[rand() % countof(LEVEL2)]);
    swap(LEVEL3[rand() % countof(LEVEL3)], LEVEL3[rand() % countof(LEVEL3)]);
  }
}

void think(Stack* s, Operation* o) {
  Board* b = &s->bottom();
  for (unsigned char i = 0; i < countof(LEVEL0); ++i) {
    if (place(b, o, o->currentSide(), LEVEL0[i].x, LEVEL0[i].y, true))
      return;
  }
  for (unsigned char i = 0; i < countof(LEVEL1); ++i) {
    if (place(b, o, o->currentSide(), LEVEL1[i].x, LEVEL1[i].y, true))
      return;
  }
  for (unsigned char i = 0; i < countof(LEVEL2); ++i) {
    if (place(b, o, o->currentSide(), LEVEL2[i].x, LEVEL2[i].y, true))
      return;
  }
  for (unsigned char i = 0; i < countof(LEVEL3); ++i) {
    if (place(b, o, o->currentSide(), LEVEL3[i].x, LEVEL3[i].y, true))
      return;
  }
  for (unsigned char i = 0; i < countof(LEVEL4); ++i) {
    if (place(b, o, o->currentSide(), LEVEL4[i].x, LEVEL4[i].y, false)) {
      char dx = (LEVEL4[i].x == 0 || LEVEL4[i].x == 7) ? 0 : 1;
      char dy = (LEVEL4[i].y == 0 || LEVEL4[i].y == 7) ? 0 : 1;
      unsigned char s = 0;
      char tx = LEVEL4[i].x, ty = LEVEL4[i].y;
      do {
        tx += dx; ty += dy;
        if (b->get(tx, ty) == o->opponentSide()) {
          s |= 0x01;
        } else if (b->get(tx, ty) == o->currentSide()) {
          s |= 0x02;
        } else if (b->get(tx, ty) == GS_EMPTY) {
          s |= 0x04;
          break;
        }
      } while (valid(tx, ty));
      dx = -dx; dy = -dy;
      tx = LEVEL4[i].x, ty = LEVEL4[i].y;
      do {
        tx += dx; ty += dy;
        if (b->get(tx, ty) == o->opponentSide()) {
          s |= 0x10;
        } else if (b->get(tx, ty) == o->currentSide()) {
          s |= 0x20;
        } else if (b->get(tx, ty) == GS_EMPTY) {
          s |= 0x40;
          break;
        }
      } while (valid(tx, ty));
      if ((s & 0x01) != 0 && (s & 0x40) != 0) {
        place(b, o, o->currentSide(), LEVEL4[i].x, LEVEL4[i].y, true);
        return;
      } else if ((s & 0x10) != 0 && (s & 0x04) != 0) {
        place(b, o, o->currentSide(), LEVEL4[i].x, LEVEL4[i].y, true);
        return;
      }
    }
  }
  for (unsigned char i = 0; i < countof(LEVEL5); ++i) {
    if (place(b, o, o->currentSide(), LEVEL3[i].x, LEVEL3[i].y, true))
      return;
  }
  for (unsigned char i = 0; i < 8; ++i) {
    for (unsigned char j = 0; j < 8; ++j) {
      if (place(b, o, o->currentSide(), i, j, true))
        return;
    }
  }
}
