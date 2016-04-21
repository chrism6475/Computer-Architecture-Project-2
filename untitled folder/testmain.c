#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int* loadgrid(void){
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
    char* onegrid;

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
      //now copy the inside of the board into the grid. placeholder below
      //accidentally prints out extra C
      for(int m=0;m<4;m++){
        for(int r=0;r<4;r++){
          if(board[m+1][m+1]!=NULL){
            grid[m][r]=board[m+1][m+1];
          }
        }
      }
      // printing out board
        /*    for(int m=0;m<=5;m++){
              for(int l=0; l<=5; l++){

                if(board[l][m]==NULL && l!=5){
                  printf("%s" , " " );
                } else if(board[l][m]==NULL && l==5){
                  printf("%s\n" , " " );
                } else {
                printf("%c", board[l][m]);
                i++;
              }
            }
          }*/
      //print out grid.
      for(int m=0;m<=3;m++){
        for(int l=0; l<=3; l++){
          if(grid[l][m]==NULL){
            printf(" ");
          }else {
      printf("%c", grid[l][m]);
        }
      }
      printf("\n ");
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
