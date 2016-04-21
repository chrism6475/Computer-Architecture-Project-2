#include <stdio.h>
#include <string.h>
#include "load.h"
#include "creategrid.h"


int main(){
  char *board;

    board =load("Text.txt");

  /*  for(int i=0;i<10;i++){
    printf("*(test+ %d) : %d\n",i,*(test+i));
  }*/

  char *grid[4][4];
  grid=creategrid(&board);
    return 0;

}
