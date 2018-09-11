#include <iostream>
#include <cstring>

using namespace std;

void clearBoard(int* Ptr[3][3]);
void drawBoard(int* Ptr[3][3]);

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
}

void clearBoard(int* Ptr[3][3]){
  for(int x = 0; x < 3; x++){
    for(int y = 0; y < 3; y++){
      Ptr[x][y] = 0;
    }
  }
}

void drawBoard(int* Ptr[3][3]){
  cout << "  1 2 3" << endl;
  cout << "a";
  for(int i = 0; i < 3; i++){
    cout << " " << 
  }
}
