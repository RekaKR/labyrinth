#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "common.h"
#include "play.h"
#include "print.h"

int movement(Labyrinth* labyrinth, int vertic, int horiz) {
  for (int i = 0; i < (*labyrinth).height; i++) {
    for (int j = 0; j < (*labyrinth).width; j++) {
      if ((*labyrinth).board[i][j] == 'P') {
        if ((*labyrinth).board[i+vertic][j+horiz] == 'l') {
          (*labyrinth).board[i+vertic][j+horiz] = 'P';
          (*labyrinth).board[i][j] = 'l';

          print_board(labyrinth);
          return 0;
        }
      }
    }
  }
  
  return 1;
}

int start_labyrinth(Labyrinth* labyrinth) {
  int emptySpaces = 0;

  if ((*labyrinth).board == NULL) {
    printf("No board. Please provide one to play.\n");
    return 1;
  }

  for (int i = 1; i < (*labyrinth).height - 1; i++) {
    for (int j = 1; j < (*labyrinth).width - 1; j++) {
      if ((*labyrinth).board[i][j] == 'l') {
        emptySpaces++;
      }
    }
  }
  
  int targetInd = rand() % emptySpaces;
  int currentInd = 0;

  for (int i = 1; i < (*labyrinth).height - 1; i++) {
    for (int j = 1; j < (*labyrinth).width - 1; j++) {
      if ((*labyrinth).board[i][j] == 'l') {
        if (currentInd == targetInd) {
          (*labyrinth).board[i][j] = 'P';
        }

        currentInd++;
      }
    }
  }

  return 0;
}

int win(Labyrinth* labyrinth) {
  for (int i = 0; i < (*labyrinth).height; i++) {
    for (int j = 0; j < (*labyrinth).width; j++) {
      if ((*labyrinth).board[0][j] == 'P' ||
      (*labyrinth).board[(*labyrinth).height - 1][j] == 'P' ||
      (*labyrinth).board[i][0] == 'P' ||
      (*labyrinth).board[i][(*labyrinth).width - 1] == 'P') {
        return 0;
      }
    }
  }

  return 1;
}

int play_labyrinth(Labyrinth* labyrinth) {
  char direction;

  if (start_labyrinth(labyrinth)) return 1;
  print_board(labyrinth);

  printf("To play the game, enter a direction (w, s, a, d), or enter q to quit: ");

  while (win(labyrinth) != 0) {
    scanf("%c", &direction);
  
    if (direction == 'q') {
      printf("See you soon.\n");
      return 0;
    } else if (direction == 'w') {   
      movement(labyrinth, -1, 0);
    } else if (direction == 's') {
      movement(labyrinth, 1, 0);
    } else if (direction == 'a') {
      movement(labyrinth, 0, -1);
    } else if (direction == 'd') {
      movement(labyrinth, 0, 1);
    }
  }

  printf("You won!!\n");

  return 0;
};