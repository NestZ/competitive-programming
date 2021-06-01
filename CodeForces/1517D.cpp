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

int ans[11][505][505] = {};
vector<vector<int>> hor(505, vector<int>(505));
vector<vector<int>> ver(505, vector<int>(505));

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m, c;cin >> n >> m >> c;
  for(int i = 0;i < n;i++)
    for(int j = 0;j < m - 1;j++)
      cin >> hor[i][j];
  for(int i = 0;i < n - 1;i++)
    for(int j = 0;j < m;j++)
      cin >> ver[i][j];
  if(c & 1){
    for(int i = 0;i < n;i++){
      for(int j = 0;j < m;j++){
        cout << -1 << ' ';
      }
      cout << endl;
    }
    return 0;
  }
  c /= 2;
  for(int i = 1;i <= c;i++){
    for(int j = 0;j < n;j++){
      for(int k = 0;k < m;k++){
        ans[i][j][k] = 1 << 30;
        if(j > 0)ans[i][j][k] = min(ans[i][j][k], ans[i - 1][j - 1][k] + ver[j - 1][k]);
        if(j < n - 1)ans[i][j][k] = min(ans[i][j][k], ans[i - 1][j + 1][k] + ver[j][k]);
        if(k > 0)ans[i][j][k] = min(ans[i][j][k], ans[i - 1][j][k - 1] + hor[j][k - 1]);
        if(k < m - 1)ans[i][j][k] = min(ans[i][j][k], ans[i - 1][j][k + 1] + hor[j][k]);
      }
    }
  }
  for(int i = 0;i < n;i++){
    for(int j = 0;j < m;j++){
      cout << ans[c][i][j] * 2 << ' ';
    }
    cout << endl;
  }
}
