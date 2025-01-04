#include <stdio.h>
#include <stdlib.h>
#include "common.h"
#include "print.h"

int print_board(Labyrinth* labyrinth) {
  if ((*labyrinth).board == NULL) {
    printf("No content to display. Please select a valid menu option.\n");
    return 1;
  }

  printf("-----------------\n");
  for (int i = 0; i < (*labyrinth).height; i++) {
    for (int j = 0; j < (*labyrinth).width; j++) {
      if ((*labyrinth).board[i][j] == 'l') {
        printf("  ");
      } else {
        printf("%c ", (*labyrinth).board[i][j]);
      }
    }

    printf("\n");
  }
  
  return 0;
};