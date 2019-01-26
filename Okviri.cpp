#include<iostream>

using namespace std;

void centerline(string type){
  int i;
  cout << "#.";
  for(i=0;i<type.size();i++){
    cout << type[i];
    if(i+1 != type.size() && (i+1) % 3 == 0)cout << ".*.";
    else if(i+1 != type.size() && (i+2) % 3 == 0)cout << ".*.";
    else if(i+1 != type.size() && (i+1) % 3 != 0)cout << ".#.";
    else if(i+1 == type.size() && (i+1) % 3 != 0)cout << ".#";
    else if(i+1 == type.size() && (i+1) % 3 == 0)cout << ".*";
  }
  cout << "\n";
}

void line24(string type){
  int i;

  for(i=1;i<=type.size();i++){
    if(i % 3 == 0)cout << ".*.*";
    else cout << ".#.#";
  }
  cout << "." << "\n";
}

void line15(string type){
  int i;

  for(i=1;i<=type.size();i++){
    if(i % 3 ==0)cout << "..*.";
    else cout << "..#.";
  }
  cout << ".";
}

void print(string type){
  line15(type);
  cout << "\n";
  line24(type);
  centerline(type);
  line24(type);
  line15(type);
}

int main(){
  string type;

  cin >> type;
  print(type);

  return 0;
}
