#include<iostream>

using namespace std;

int main(){
  int num,n,i = 2,j = 1,a = 0,check;
  cin >> num;
  cin >> n;

  int count[num-1],checker[num+1];

  for(i=0;i<num+2;i++){
    checker[i] = i;
  }

  for(i=0;i<num;i++)count[i] = 0;

  for(i=2;i<=num;i++){
    for(j=1;i*j<=num;j++){
      if(checker[i*j] != 0){
        count[a] = i*j;
        checker[i*j] = 0;
        a++;
      }
    }
  }

  cout << count[n-1];

  return 0;
}
