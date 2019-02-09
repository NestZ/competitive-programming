#include<iostream>
using namespace std;

int main(){
  int line;
  int column;
  int midline;
  int underline;

  cin >> line;

  if(line % 2 == 0){
    column = line - 1;
    midline = line / 2;
    underline = line / 2;
  }
  else{
    column = line;
    midline = (line + 1) / 2;
    underline = midline - 1;
  }

  for(int i = 0;i < midline;i++){
    for(int j = 0;j < column;j++){
      if(j == (column / 2) - i || j == (column / 2) + i)cout << "*";
      else cout << "-";
    }
    cout << "\n";
  }
  
  for(int k = underline;k > 0;k--){
    for(int l = 0;l < column;l++){
      if(l == (column / 2) - k + 1 || l == (column / 2) + k - 1)cout << "*";
      else cout << "-";
    }
    cout << "\n";
  }
  return 0;
}
