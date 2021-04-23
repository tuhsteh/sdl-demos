#ifndef SKYCOLOR_H
#define SKYCOLOR_H

#include <time.h>

const int HOURS = 24;

struct color {
  int r;
  int b;
  int g;
  int a;  // alpha
};

color pickHighContrast();
color pickNextColor();

#endif //  sky-color_h
