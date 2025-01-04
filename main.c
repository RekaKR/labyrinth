#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include "common.h"
#include "./labyrinth/labyrinth.h"
#include "print.h"
#include "play.h"

void menu(Labyrinth* labyrinth) {
  int menuNum;
  bool istrue = true;  

  while (istrue) {
    printf(
      "________________\n\n"
      "      MENU\n"
      "________________\n"
      "Please choose from the menu:\n"
      "-----------------\n"
    );

    printf("1. Draw\n"
      "2. Create\n"
      "3. Save\n"
      "4. Load\n"
      "5. Play\n"
      "6. Exit\n"
      "Enter a number: "
    );

    scanf("%d", &menuNum);

    printf("-----------------\n");

    switch (menuNum) {
      case 1:
        print_board(labyrinth);
        break;
      case 2:
        create_labyrinth(labyrinth);
        break;
      case 3:
        save_labyrinth(labyrinth);
        break;
      case 4:
        load_labyrinth(labyrinth);
        break;
      case 5:
        play_labyrinth(labyrinth);
        break;
      case 6:
        printf("Byyyyyyye!\n");
        istrue = false;
        break;
      default:
        printf("INVALID NUMBER\n");
        break;
    }
  }
}

int main() {
  srand(time(NULL));

  Labyrinth labyrinth;
  
  labyrinth.board = NULL;

  printf(
    "Hello player. Nice to have you here.\n"
    "This is a labyrinth game: \n"
    "You have to get from the inside of the labyrinth to the exit. The possible directions are up, down, left, right.\n"
    "You win by stepping on the exit tile!\n"
    "Have fun!\n"
  );
  
  menu(&labyrinth);
  reset_labyrinth(&labyrinth);

  return 0;
}