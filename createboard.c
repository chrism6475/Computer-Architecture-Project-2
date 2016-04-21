
  int x,y,j =0; //x is the column, y is the row
for(int i=0; i<=4; i++){

    x=indices[i]/6;
    y=indices[i]%6;
    if(y==0){
      x-=1;
      y=5;
    }else{
      y-=1;
    }
    board[x][y]='X';
  }else{
    x=indices[i]-1;
    board[x][0]='X'
  }
  for(i=0;i<=indices[5];i++){
    x=(indices[7+j]/6);
    y=(indices[7+j]%6);
      x-=1;
      y=5;
    }else{
      y-=1;
    }
    board[x][y]=alpha[i];
    j+=2;
  }
}
//move outer layers into board[4][4]. then, add in all fills
//end write condition to search for and return last element of the last index in indices

return board;

}
