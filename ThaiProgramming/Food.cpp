#include<bits/stdc++.h>
using namespace std;

int main(){
      int n;cin >> n;
      int arr[n + 10];
      int m;cin >> m;
      set<int> s;
      set<int>::iterator it;
      for(int i = 0;i < m;i++){
            int t;cin >> t;
            s.insert(t);
      }
      for(int i = 0;i < n;i++)arr[i] = i + 1;
      do{
            it = s.find(arr[0]);
            if(it == s.end()){
                  for(int i = 0;i < n;i++)cout << arr[i] << " ";
                  cout << "\n";
            }
      }while(next_permutation(arr, arr + n));
      return 0;
}