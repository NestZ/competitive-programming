#include<iostream>
using namespace std;

int main(){
  int n;
  cin >> n;
  int list[n];
  int temp;
  int Num = 1;
  int status = 1;

  for(int i = 0;i < n;i++)
    cin >> list[i];

  //Bubble sort
  while(status == 1){
    status = 0;
    for(int i = 0;i < n - 1;i++){
      if(list[i] > list[i+1]){
        temp = list[i];
        list[i] = list[i+1];
        list[i+1] = temp;
        status = 1;
      }
    }
  }

  //Check how many different number
  for(int i = 1;i < n;i++){
    if(list[i] != list[i-1])Num += 1;
  }

  int number[2][Num];

  //set number's array to 0
  for(int i = 0;i < 2;i++){
    for(int j = 0;j < Num;j++){
      number[i][j] = 0;
    }
  }

  int j = 0;

  //Count each different number
  for(int i = 0;i < n;i++){
    if(list[i] == list[i+1]){
      number[1][j]++;
      number[0][j] = list[i];
    }
    else if(list[i] != list[i+1]){
      number[1][j]++;
      number[0][j] = list[i];
      j++;
    }
  }

  //find the most frequency number
  int max = 0;
  for(int i = 0;i < Num;i++){
    if(number[1][i] > max)max = number[1][i];
  }

  //Check if it has many number equal to max
  for(int i = 0;i < Num;i++){
    if(number[1][i] == max){
      cout << number[0][i] << " ";
    }
  }

  return 0;
}
