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

  int t;cin >> t;
  while(t--){
    int n;cin >> n;
    int mn_x = 1e5, mn_y = 1e5;
    int mx_x = -1e5, mx_y = -1e5;
    for(int i = 0;i < n;i++){
      int x, y;cin >> x >> y;
      int l;cin >> l;
      if(l == 0)mx_x = max(mx_x, x);
      int u;cin >> u;
      if(u == 0)mn_y = min(mn_y, y);
      int r;cin >> r;
      if(r == 0)mn_x = min(mn_x, x);
      int d;cin >> d;
      if(d == 0)mx_y = max(mx_y, y);
    }
    if(mn_x < mx_x || mn_y < mx_y)cout << 0;
    else{
      cout << 1 << ' ';
      cout << mn_x << ' ' << mn_y;
    }
    cout << endl;
  }
}
