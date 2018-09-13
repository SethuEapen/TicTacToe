#include <iostream>
#include <cstring>

using namespace std;

void clearBoard(char* Ptr[3][3]);
void drawBoard(char* Ptr[3][3]);

int main()
{

  char board[3][3];
  char* boardPtr[3][3];
  for(int x = 0; x < 3; x++){
    for(int y = 0; y < 3; y++){
      boardPtr[x][y] = &board[x][y];
    }
  }
  clearBoard(boardPtr);
  drawBoard(boardPtr);
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
