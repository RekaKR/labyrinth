#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "common.h"

void reset_labyrinth(Labyrinth* labyrinth) {
  if ((*labyrinth).board != NULL) {
    for (int i = 0; i < (*labyrinth).height; i++) {
      free((*labyrinth).board[i]);
    }

    free((*labyrinth).board);
    (*labyrinth).board = NULL;
  }
  
  (*labyrinth).width = 0;
  (*labyrinth).height = 0;
}