#include<bits/stdc++.h>
using namespace std;

int main(){
      int n;cin >> n;
      int a = 0;
      int b = 0;
      char ch[n + 10];
      int counter = 0;
      for(int i = 0;i < n;i++){
            cin >> ch[i];
            if(i % 2 != 0){
                  if(ch[i] == ch[i - 1]){
                        ch[i] == 'a' ? ch[i] = 'b':ch[i] = 'a';
                        counter++;
                  }
            }
      }
      cout << counter << "\n";
      for(int i = 0;i < n;i++)cout << ch[i];
      return 0;
}