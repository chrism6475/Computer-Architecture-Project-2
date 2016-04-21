#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

//this function creates the inner grid based on the game board and returns
// the grid for use elsewhere.  grid will need to be free'd 
char* creategrid(char board[][]){
  char* onegrid;
  char grid[4][4];
  //char onegrid [36];
  int x,y=0;
  for(int i=0;i<5;i++){
    //move letters in outer, top layer into the 4x4 grid
    if(board[i+1][0]!=NULL && grid[i][0]!=NULL){
      grid[i][1]=board[i+1][0];
    } else if(board[i+1][0]!=NULL && grid[i][0]==NULL){
      grid[i][0]=board[i+1][0];
    }
    //move letters in outer,left layer into the 4x4 grid
    if(board[0][i+1]!=NULL && grid[0][i]!=NULL){
      grid[1][i]=board[0][i+1];
    } else if(board[i][1]!=NULL && grid[i][0]==NULL){
      grid[0][i]=board[0][i+1];
    }
    //move letters in outer, bottom layer into the 4x4 grid
    if(board[i+1][5]!=NULL && grid[i][3]!=NULL){
      grid[i][3]=board[i+1][5];
    } else if(board[i+1][5]!=NULL && grid[i][3]==NULL){
      grid[i][3]=board[i+1][5];
    }
    //move letters in outer,right layer into the 4x4 grid
    if(board[5][i+1]!=NULL && grid[3][i]!=NULL){
      grid[2][i]=board[4][i+1];
    } else if(board[5][i+1]!=NULL && grid[3][i]==NULL){
      grid[3][i]=board[5][i+1];
    }

  }

  onegrid=(char*) malloc(sizeof(char)*36);
  assert(onegrid != NULL);

  for(y=0; y<4;x++){
    for(x=0;x<4;y++){
      //*(onegrid + 4y+x)=grid[x][y];
      onegrid[4y+x]=grid[x][y];
    }
  }
  return onegrid;
}
