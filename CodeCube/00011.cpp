#include<bits/stdc++.h>
using namespace std;

int main(){
      int n,m,k;cin >> n >> m >> k;
      int **s = new int*[n + 10];
      for(int i = 0;i < n;i++)s[i] = new int[m + 10];
      int e = 0;
      for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++){
                  cin >> s[i][j];
            }
      }
      int curr_e = 0;
      for(int i = n - 1;i >= 0;i--){
            queue<int> q;
            int curr_e = 0;
            int q_e = 0;
            for(int j = 0;j < m;j++){
                  if(q.size() == k){
                        if(q.front() == 0)q_e--;
                        q.pop();
                  }
                  q.push(s[i][j]);
                  if(s[i][j] == 0){
                        q_e++;
                        curr_e++;
                  }
                  if(q_e + e >= k)return cout << i + 1, 0;
            }
            e += curr_e;
            if(e >= k)return cout << i, 0;
            curr_e = 0;
      }
}