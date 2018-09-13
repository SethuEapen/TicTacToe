#include <iostream>
#include <string.h>

using namespace std;

void clearBoard(char* Ptr[3][3]);
void drawBoard(char* Ptr[3][3]);
bool checkWin(char* Ptr[3][3], char player);

int main()
{
  char board[3][3];
  char* boardPtr[3][3];
  char input[2];
  char player = 'X';
  for(int x = 0; x < 3; x++){
    for(int y = 0; y < 3; y++){
      boardPtr[x][y] = &board[x][y];
    }
  }
  clearBoard(boardPtr);
  drawBoard(boardPtr);
  while(!checkWin(boardPtr, player)){
    cin.get(input, 3); // Do With do while
    cin.clear();
    cin.ignore(100, '\n');
    cout << input << endl;
    if(input[0] == '1' || input[0] == '2' || input[0] == '3'){
      if(input[1] == 'a' || input[1] == 'b' || input[1] == 'c'){
	if(board[(int)input[0] - '1'][(int)input[1] - 'a'] == ' '){
	  board[(int)input[0] - '1'][(int)input[1] - 'a'] = player;
	}
      }
    }
    else{
      cout << "Fskdfjhskdfh" << endl;
    }
    drawBoard(boardPtr);
    player == 'Y';
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
  cout << "a";
  for(int i = 0; i < 3; i++){
    cout << " " << *Ptr[0][i];
  }
  cout << endl;

  cout << "b";
  for(int i = 0; i < 3; i++){
    cout << " " << *Ptr[1][i];
  }
  cout << endl;

  cout << "c";
  for(int i = 0; i < 3; i++){
    cout << " " << *Ptr[2][i];
  }
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
