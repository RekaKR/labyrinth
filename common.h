#ifndef COMMON_H
#define COMMON_H

typedef struct Labyrinth {
  int width;
  int height;
  char** board;
} Labyrinth;

void reset_labyrinth(Labyrinth* labyrinth);

#endif