#include <iostream>
#include <string.h>

using namespace std;

void clearBoard(char* Ptr[3][3]);
void drawBoard(char* Ptr[3][3]);
bool checkWin(char* Ptr[3][3], char player);
bool checkTie(char* Ptr[3][3]);

int main()
{
  char board[3][3];
  char* boardPtr[3][3];
  char input[2];
  char player = 'O';
  char stillPlaying = 'y';
  for(int x = 0; x < 3; x++){
    for(int y = 0; y < 3; y++){
      boardPtr[x][y] = &board[x][y];
    }
  }
  while(stillPlaying == 'y'){
    clearBoard(boardPtr);
    drawBoard(boardPtr);
    player = 'O';
    while(!checkWin(boardPtr, player) && !checkTie(boardPtr)){
      if(player == 'X'){
	player = 'O';
      }
      else{
	player = 'X';
      }
      do
      {
	cin.get(input, 3);
	cin.clear();
	cin.ignore(100, '\n');
      }while(!(input[0] == '1' || input[0] == '2' || input[0] == '3')
	     && !(input[1] == 'a' || input[1] == 'b' || input[1] =='c'));
      if(board[(int)input[1] - 'a'][(int)input[0] - '1'] == ' '){
	board[(int)input[1] - 'a'][(int)input[0] - '1'] = player;
      }
      drawBoard(boardPtr);
    }
    if(checkTie(boardPtr)){
      cout << "Tie game!" << endl;
    }
    else{
      cout << "Congratulations! Player " << player << " won!" << endl;
    }
    cout << "Do you want to play again?(y or n)" << endl;
    cin >> stillPlaying;
    cin.clear();
    cin.ignore(100, '\n');
  }
}
void clearBoard(char* Ptr[3][3]){
  for(int x = 0; x < 3; x++){
    for(int y = 0; y < 3; y++){
      *Ptr[x][y] = ' ';
    }
  }
}

void drawBoard(char* Ptr[3][3]){
  cout << "  1 2 3" << endl;
  cout << 'a';
  for(int i = 0; i < 3; i++){
    cout << ' ' << *Ptr[0][i];
  }
  cout << endl;

  cout << 'b';
  for(int i = 0; i < 3; i++){
    cout << ' ' << *Ptr[1][i];
  }
  cout << endl;

  cout << 'c';
  for(int i = 0; i < 3; i++){
    cout << ' ' << *Ptr[2][i];
  }
  cout << endl;
  cout << endl;  
}

bool checkWin(char* Ptr[3][3], char player){
  for(int i = 0; i < 3; i++){
    if(*Ptr[0][i] == player && *Ptr[1][i] == player && *Ptr[2][i] == player){
      cout << "A" << endl;
      return true;
    }
    if(*Ptr[i][0] == player && *Ptr[i][1] == player && *Ptr[i][2] == player){
      cout << "B" << endl;
      return true;
    }
  }
  if(*Ptr[0][0] == player && *Ptr[1][1] == player && *Ptr[2][2] == player){
    cout << "C" << endl;
    return true;
  }
  if(*Ptr[2][0] == player && *Ptr[1][1] == player && *Ptr[0][2] == player){
    return true;
    cout << "D" << endl;
  }
  return false;
}

bool checkTie(char* Ptr[3][3]){
  for(int x = 0; x < 3; x++){
    for(int y = 0; y < 3; y++){
      if(*Ptr[x][y] == ' '){
	return false;
      }
    }
  }
  return true;
}
