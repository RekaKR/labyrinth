#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../common.h"
#include "labyrinth.h"

#define MIN_SIZE 5
#define MAX_SIZE 10

void initialize_labyrinth(Labyrinth* labyrinth) {
  reset_labyrinth(labyrinth);

  int n = 0;
  int m = 0;

  while (n < MIN_SIZE || n > MAX_SIZE) {
    printf("Enter the number of rows (between 5 and 10): ");
    scanf("%d", &n);
  
    if (n < MIN_SIZE || n > MAX_SIZE) {
      printf("Invalid value. ");
    }
  };

  while (m < MIN_SIZE || m > MAX_SIZE) {
    printf("Enter the number of columns (between 5 and 10): ");
    scanf("%d", &m);
  
    if (m < MIN_SIZE || m > MAX_SIZE) {
      printf("Invalid value. ");
    }
  };

  (*labyrinth).width = n;
  (*labyrinth).height = m;
  (*labyrinth).board = (char**) malloc((*labyrinth).height * sizeof(char*));

  for (int i = 0; i < (*labyrinth).height; i++) {
    (*labyrinth).board[i] = (char*) malloc((*labyrinth).width * sizeof(char));
  }
}

void create_labyrinth(Labyrinth* labyrinth) {
  initialize_labyrinth(labyrinth);

  printf("Enter the structure of the board row by row, %d characters per row without spaces, in one line. Use 'x' for walls and 'l' for labyrinth paths.\n", (*labyrinth).width);

  for (int i = 0; i < (*labyrinth).height; i++) {
    scanf("%s", (*labyrinth).board[i]);
  }
};

void load_labyrinth(Labyrinth* labyrinth) {
  reset_labyrinth(labyrinth);

  char fileName[50];
  
  printf("Enter the name of the txt file (start with ./files/, but without .txt extension): ");
  scanf("%s", fileName);

  strcat(fileName, ".txt");

  FILE* file = fopen(fileName, "r");
  
  fscanf(file, "%d %d\n", &(*labyrinth).width, &(*labyrinth).height);
  
  (*labyrinth).board = (char**) malloc((*labyrinth).height * sizeof(char*));
  
  for (int i = 0; i < (*labyrinth).height; i++) {
    (*labyrinth).board[i] = (char*) malloc((*labyrinth).width * sizeof(char));
  }
  
  for (int i = 0; i < (*labyrinth).height; i++) {
    fscanf(file, "%s\n", (*labyrinth).board[i]);
  }

  fclose(file);
};

int save_labyrinth(Labyrinth* labyrinth) {
  if ((*labyrinth).board == NULL) {
    printf("There is nothing to save. Please provide a labyrinth first.\n");
    return 1;
  }

  char fileName[50];

  printf("Enter the file name (start with ./files/, but without .txt extension): ");
  scanf("%s", fileName);

  strcat(fileName, ".txt");

  FILE* file = fopen(fileName, "w");

  fprintf(file, "%d %d\n", (*labyrinth).width, (*labyrinth).height);
  
  for (int i = 0; i < (*labyrinth).height; i++) {
    for (int j = 0; j < (*labyrinth).width; j++) {
      fprintf(file, "%c", (*labyrinth).board[i][j]);
    }

    fprintf(file, "\n");
  }
  
  fclose(file);

  return 0;
};