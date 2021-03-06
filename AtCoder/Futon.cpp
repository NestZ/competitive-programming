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
  vector<vector<char>> arr(h, vector<char>(w));
  for(int i = 0;i < h;i++)
    for(int j = 0;j < w;j++)
      cin >> arr[i][j];
  int ans = 0;
  for(int i = 0;i < h;i++){
    for(int j = 0;j < w;j++){
      if(i + 1 < h && arr[i][j] == '.' && arr[i + 1][j] == '.')ans++;
      if(j + 1 < w && arr[i][j] == '.' && arr[i][j + 1] == '.')ans++;
    }
  }
  cout << ans << endl;
}
