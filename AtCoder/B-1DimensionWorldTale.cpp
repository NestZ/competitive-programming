#include<bits/stdc++.h>
using namespace std;

int main(){
      int n,m,x,y;cin >> n >> m >> x >> y;
      int arrn[n + 10];for(int i = 0;i < n;i++)cin >> arrn[i];
      int arrm[m + 10];for(int i = 0;i < m;i++)cin >> arrm[i];
      sort(arrn, arrn + n);
      sort(arrm, arrm + m);
      if(arrm[0] > arrn[n - 1] && arrm[0] > x && arrm[0] <= y)cout << "No War";
      else cout << "War";
}