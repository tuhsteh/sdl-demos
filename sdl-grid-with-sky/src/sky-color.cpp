#include "sky-color.h"

#include <time.h>

#include <iostream>

color skies[HOURS] = {
    {0x00, 0x00, 0x22, 0xFF},  // #000028;  0000
    {0x00, 0x00, 0x30, 0xFF},  // #000030;  0100
    {0x00, 0x00, 0x38, 0xFF},  // #000038;  0200
    {0x00, 0x00, 0x40, 0xFF},  // #000040;  0300
    {0x00, 0x00, 0x48, 0xFF},  // #000048;  0400
    {0x00, 0x00, 0x50, 0xFF},  // #000050;  0500
    {0x00, 0x00, 0x60, 0xFF},  // #000060;  0600
    {0x00, 0x20, 0x80, 0xFF},  // #002080;  0700
    {0x00, 0x40, 0xAF, 0xFF},  // #0040AF;  0800
    {0x00, 0x60, 0xB0, 0xFF},  // #0060B0;  0900
    {0x00, 0x68, 0xB8, 0xFF},  // #0068B8;  1000
    {0x00, 0x70, 0xC0, 0xFF},  // #0070C0;  1100
    {0x00, 0x78, 0xD0, 0xFF},  // #0078D0;  1200
    {0x00, 0x80, 0xE0, 0xFF},  // #0080E0;  1300
    {0x00, 0xA0, 0xF0, 0xFF},  // #00A0F0;  1400
    {0x00, 0xB0, 0xFF, 0xFF},  // #00B0FF;  1500
    {0x20, 0xB8, 0xFF, 0xFF},  // #20B8FF;  1600
    {0x40, 0xB0, 0xFF, 0xFF},  // #40B0FF;  1700
    {0x60, 0xA0, 0xFF, 0xFF},  // #60A0FF;  1800
    {0x80, 0x70, 0xE0, 0xFF},  // #8070E0;  1900
    {0x60, 0x40, 0xD8, 0xFF},  // #6040D8;  2000
    {0x40, 0x10, 0xAF, 0xFF},  // #4010AF;  2100
    {0x20, 0x00, 0x80, 0xFF},  // #200080;  2200
    {0x00, 0x00, 0x40, 0xFF},  // #000040;  2300
};

color pickHighContrast() {
  time_t now = time(NULL);
  struct tm *tm_struct = localtime(&now);
  int hour = tm_struct->tm_hour;
  std::cout << "Hour:  " << hour << std::endl;
  return skies[(hour + HOURS / 2) % HOURS];
};

color pickNextColor() {
  time_t now = time(NULL);
  struct tm *tm_struct = localtime(&now);
  int hour = tm_struct->tm_hour;
  std::cout << "Hour:  " << hour << std::endl;
  return skies[hour];
}