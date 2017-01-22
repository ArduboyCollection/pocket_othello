#include "visual.h"
#include <avr/pgmspace.h>

PROGMEM const unsigned char SPRITE_BOARD[] = {
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x90, 0xaa, 0xbc, 0x80, 0x80, 0x80, 0x80,
  0xbe, 0xa4, 0x98, 0x80, 0x80, 0x80, 0x80, 0x98, 0xa4, 0xa4, 0x80, 0x80, 0x80, 0x80, 0x98, 0xa4,
  0xbe, 0x80, 0x80, 0x80, 0x80, 0x9c, 0xaa, 0x8c, 0x80, 0x80, 0x80, 0x80, 0x88, 0xbc, 0x8a, 0x80,
  0x80, 0x80, 0x80, 0xa4, 0xaa, 0x94, 0x80, 0x80, 0x80, 0x80, 0xbe, 0x88, 0xb0, 0x80, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x3e, 0x00, 0x00, 0x00, 0xfe, 0x41, 0x40, 0x40, 0x40, 0x40, 0x40, 0xff, 0x40,
  0x40, 0x40, 0x40, 0x40, 0x40, 0xff, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0xff, 0x40, 0x40, 0x40,
  0x40, 0x40, 0x40, 0xff, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0xff, 0x40, 0x40, 0x40, 0x40, 0x40,
  0x40, 0xff, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0xff, 0x40, 0x40, 0x40, 0x40, 0x40, 0x41, 0xfe,
  0x00, 0x00, 0x99, 0x95, 0x12, 0x00, 0x00, 0xff, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0xff, 0x20,
  0x20, 0x20, 0x20, 0x20, 0x20, 0xff, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0xff, 0x20, 0x20, 0x20,
  0x20, 0x20, 0x20, 0xff, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0xff, 0x20, 0x20, 0x20, 0x20, 0x20,
  0x20, 0xff, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0xff, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0xff,
  0x00, 0x00, 0x88, 0x0a, 0xc5, 0x00, 0x00, 0xff, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0xff, 0x10,
  0x10, 0x10, 0x10, 0x10, 0x10, 0xff, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0xff, 0x10, 0x10, 0x10,
  0x10, 0x10, 0x10, 0xff, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0xff, 0x10, 0x10, 0x10, 0x10, 0x10,
  0x10, 0xff, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0xff, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0xff,
  0x00, 0x00, 0xe3, 0xa2, 0x27, 0x00, 0x00, 0xff, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0xff, 0x08,
  0x08, 0x08, 0x08, 0x08, 0x08, 0xff, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0xff, 0x08, 0x08, 0x08,
  0x08, 0x08, 0x08, 0xff, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0xff, 0x08, 0x08, 0x08, 0x08, 0x08,
  0x08, 0xff, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0xff, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0xff,
  0x00, 0x00, 0xe2, 0x52, 0x81, 0x00, 0x00, 0xff, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0xff, 0x04,
  0x04, 0x04, 0x04, 0x04, 0x04, 0xff, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0xff, 0x04, 0x04, 0x04,
  0x04, 0x04, 0x04, 0xff, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0xff, 0x04, 0x04, 0x04, 0x04, 0x04,
  0x04, 0xff, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0xff, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0xff,
  0x00, 0x00, 0x08, 0xe9, 0x18, 0x00, 0x00, 0xff, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0xff, 0x02,
  0x02, 0x02, 0x02, 0x02, 0x02, 0xff, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0xff, 0x02, 0x02, 0x02,
  0x02, 0x02, 0x02, 0xff, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0xff, 0x02, 0x02, 0x02, 0x02, 0x02,
  0x02, 0xff, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0xff, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0xff,
  0x00, 0x00, 0x28, 0x54, 0x28, 0x00, 0x00, 0x3f, 0x41, 0x81, 0x81, 0x81, 0x81, 0x81, 0xff, 0x81,
  0x81, 0x81, 0x81, 0x81, 0x81, 0xff, 0x81, 0x81, 0x81, 0x81, 0x81, 0x81, 0xff, 0x81, 0x81, 0x81,
  0x81, 0x81, 0x81, 0xff, 0x81, 0x81, 0x81, 0x81, 0x81, 0x81, 0xff, 0x81, 0x81, 0x81, 0x81, 0x81,
  0x81, 0xff, 0x81, 0x81, 0x81, 0x81, 0x81, 0x81, 0xff, 0x81, 0x81, 0x81, 0x81, 0x81, 0x41, 0x3f
};

PROGMEM const unsigned char SPRITE_WHITE[] = {
  0x00, 0x00, 0x18, 0x3c, 0x3c, 0x18, 0x00, 0x00
};

PROGMEM const unsigned char SPRITE_BLACK[] = {
  0x00, 0x00, 0x18, 0x24, 0x24, 0x18, 0x00, 0x00
};

PROGMEM const unsigned char SPRITE_CURSOR[] = {
  0x00, 0x3c, 0x42, 0x42, 0x42, 0x42, 0x3c, 0x00
};