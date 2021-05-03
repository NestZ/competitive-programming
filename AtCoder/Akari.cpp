#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int ll;

#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef LOCAL
~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  *this << "[";
  for(auto it = d.b;it != d.e;++it)
    *this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int h, w;cin >> h >> w;
  int n, m;cin >> n >> m;
  //0 nothing 1 rock 2 light
  vector<vector<int>> arr(h + 1, vector<int>(w + 1));
  vector<vector<int>> l(h + 1, vector<int>(w + 1));
  vector<vector<int>> r(h + 1, vector<int>(w + 1));
  vector<vector<int>> u(h + 1, vector<int>(w + 1));
  vector<vector<int>> d(h + 1, vector<int>(w + 1));
  for(int i = 0;i < n;i++){
    int a, b;cin >> a >> b;
    arr[a][b] = 2;
  }
  for(int i = 0;i < m;i++){
    int a, b;cin >> a >> b;
    arr[a][b] = 1;
  }
  for(int i = 1;i <= h;i++){
    int lst = 0;
    for(int j = 1;j <= w;j++){
      if(arr[i][j] != 0)lst = arr[i][j];
      l[i][j] = lst;
    }
    lst = 0;
    for(int j = w;j >= 1;j--){
      if(arr[i][j] != 0)lst = arr[i][j];
      r[i][j] = lst;
    }
  }
  for(int i = 1;i <= w;i++){
    int lst = 0;
    for(int j = 1;j <= h;j++){
      if(arr[j][i] != 0)lst = arr[j][i];
      u[j][i] = lst;
    }
    lst = 0;
    for(int j = h;j >= 1;j--){
      if(arr[j][i] != 0)lst = arr[j][i];
      d[j][i] = lst;
    }
  }
  int ans = 0;
  for(int i = 1;i <= h;i++){
    for(int j = 1;j <= w;j++){
      if(l[i][j] == 2 || r[i][j] == 2 ||
          u[i][j] == 2 || d[i][j] == 2)ans++;
    }
  }
  cout << ans << endl;
}
