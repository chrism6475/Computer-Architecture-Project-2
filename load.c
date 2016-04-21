#include <stdio.h>
#include <string.h>
#include <stdlib.h>


char ** load(){


  FILE *infile;
  infile = fopen("Text.txt", "r");
  char buffer[256];
  char *indices=NULL;
  char board[6][6];
  char alpha[5];
  char *ptr;
  int i=0;
  int ret[256];
  int x,y,j,k=0; //x is the column, y is the row
  int f=0;
  char grid[4][4];
  for(int i=0;i<=6; i++){
    for (int j=0;j<=6;j++){
      board[i][j]=NULL;
    }
  }
  if(infile==NULL) perror ("Error opening file");
    else{
      while (fgets(buffer, 256, infile)!=NULL){
      //  printf("This is the buffer %s\n", buffer);
        indices=strtok(buffer,",");
        while(indices!=NULL){
    //    printf("The indices are %s ,", indices);
        //alpha[i]='a';
          if(*indices=='A'){
            alpha[f]='A';
            f++;
          } else if(*indices=='B'){
            alpha[f]='B';
            f++;
          } else if(*indices=='C'){
            alpha[f]='C';
            f++;
          }
        *(ret+i)=strtol(indices, &ptr, 10);
      //  printf("The ret integers are %d\n , ", ret[i]);
        indices=strtok(NULL,",");
        i++;
      }
      fclose(infile);
      }
    }
    for(i=0; i<=3; i++){
      if(ret[i]>=6){
        x=ret[i]%6;
        y=ret[i]/6;
        if(x==0){
          y-=1;
          x=5;
        }else{
          x-=1;
        }
        board[x][y]='X';
      }else{
        x=ret[i]-1;
        board[x][0]='X';
      }
    }
      for(k=0;k<ret[4];k++){
        x=(ret[6+(2*k)]%6);
        y=(ret[6+(2*k)]/6);
          if(x==0){
            y-=1;
            x=5;
          }else{
            x-=1;
          }
        board[x][y]=alpha[k];
      }

    return **board;
  }
