#include<iostream>

using namespace std;

int main(){
  int i,j,n[10],ans[10],answer = 0;
  int num;

  for(i=0;i<10;i++){
    cin >> n[i];
  }

  for(i=0;i<10;i++){
    ans[i] = n[i] % 42;
    if(i==0)answer++;
    else{
      for(j=1;j<=i;j++){
        if(ans[i] == ans[i-j])break;
        else if(j == i)answer++;
      }
    }
  }

  cout << answer;

  return 0;
}
