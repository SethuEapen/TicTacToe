//inports
#include <iostream>
#include <string.h>

using namespace std;

//functions INIT
void clearBoard(char* Ptr[3][3]);
void drawBoard(char* Ptr[3][3]);
bool checkWin(char* Ptr[3][3], char player);
bool checkTie(char* Ptr[3][3]);
int xWins = 0, oWins = 0;

int main()//Main Loop
{
  //variables INIT
  char board[3][3];
  char* boardPtr[3][3];
  char input[2];
  char player = 'O';
  char stillPlaying = 'y';
  bool attemptNum = true;
  //sets an array to pointers of board
  for(int x = 0; x < 3; x++){
    for(int y = 0; y < 3; y++){
      boardPtr[x][y] = &board[x][y];
    }
  }
  //Game
  while(stillPlaying == 'y'){//default set to y
    cout << "Score: X wins - " << xWins << endl << "O wins - " << oWins << endl; //prints out o and x wins
    clearBoard(boardPtr);//clear and itit board
    drawBoard(boardPtr);//draw board to screen
    player = 'O';//set default to O so it will change to X
    while(!checkWin(boardPtr, player) && !checkTie(boardPtr)){
      //change player
      if(player == 'X'){
	player = 'O';
      }
      else{
	player = 'X';
      }
      do//read in value once and if it is invalid read in another value
      {
	if(attemptNum == true){
	  cout << "Enter a spot" << endl;
	}
	else{
	  cout << "That number is invalid" << endl;
	}
	cin.get(input, 3);//read in a value 3 charecters long and store it in input
	cin.clear();
	cin.ignore(1000000, '\n');//ignore 1000000 characters until reading in again
	attemptNum = false;// make attempt run false so if it runs again than it will print "that number is invalid"
      }while(!(input[0] == '1' || input[0] == '2' || input[0] == '3')//if first value is 1,2 or 3
	     || !(input[1] == 'a' || input[1] == 'b' || input[1] =='c')//if second value is a,b or c
	     || !(board[(int)input[1] - 'a'][(int)input[0] - '1'] == ' '));// if the spot is not already occupied
      attemptNum = true;//reset
      board[(int)input[1] - 'a'][(int)input[0] - '1'] = player;//place character at spot
      drawBoard(boardPtr);//draw the board
    }//check if the reason that the game loop broke was due to a tie
    if(checkTie(boardPtr)){
      cout << "Tie game!" << endl;
    }
    else{//else it must be that someone won
      cout << "Congratulations! Player " << player << " won!" << endl;
      if(player == 'X'){
	xWins++;
      }
      else{
	oWins++;
      }
    }
    cout << "Do you want to play again?(y or n)" << endl;
    cin >> stillPlaying;
    cin.clear();
    cin.ignore(1000000, '\n');
  }
}
void clearBoard(char* Ptr[3][3]){//clears the board each space becomes ' '
  for(int x = 0; x < 3; x++){
    for(int y = 0; y < 3; y++){
      *Ptr[x][y] = ' ';
    }
  }
}

void drawBoard(char* Ptr[3][3]){//draw a board
  cout << "  1 2 3" << endl;
  cout << 'a';
  for(int i = 0; i < 3; i++){//print first row
    cout << ' ' << *Ptr[0][i];
  }
  cout << endl;

  cout << 'b';
  for(int i = 0; i < 3; i++){//print second row
    cout << ' ' << *Ptr[1][i];
  }
  cout << endl;

  cout << 'c';
  for(int i = 0; i < 3; i++){//print third row
    cout << ' ' << *Ptr[2][i];
  }
  cout << endl;  
}

bool checkWin(char* Ptr[3][3], char player){//check if anyone won
  for(int i = 0; i < 3; i++){//rows
    if(*Ptr[0][i] == player && *Ptr[1][i] == player && *Ptr[2][i] == player){
      return true;
    }//columns
    if(*Ptr[i][0] == player && *Ptr[i][1] == player && *Ptr[i][2] == player){
      return true;
    }
  }//diagonals
  if(*Ptr[0][0] == player && *Ptr[1][1] == player && *Ptr[2][2] == player){
    return true;
  }
  if(*Ptr[2][0] == player && *Ptr[1][1] == player && *Ptr[0][2] == player){
    return true;
  }
  return false;
}

bool checkTie(char* Ptr[3][3]){//did they tie?
  for(int x = 0; x < 3; x++){
    for(int y = 0; y < 3; y++){
      if(*Ptr[x][y] == ' '){
	return false;
      }
    }
  }
  return true;
}
