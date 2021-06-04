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
    int n, m;cin >> n >> m;
    string s;cin >> s;
    vector<int> arr(n + 2), suf_mx(n + 2), pre_mx(n + 2), suf_mn(n + 2), pre_mn(n + 2);
    for(int i = 1;i <= n;i++){
      if(s[i - 1] == '+')arr[i] = arr[i - 1] + 1;
      else arr[i] = arr[i - 1] - 1;
    }
    pre_mx[0] = 0;
    pre_mn[0] = 0;
    suf_mx[n + 1] = arr[n];
    suf_mn[n + 1] = arr[n];
    for(int i = 1;i <= n;i++){
      pre_mx[i] = max(pre_mx[i - 1], arr[i]);
      pre_mn[i] = min(pre_mn[i - 1], arr[i]);
    }
    for(int i = n;i >= 1;i--){
      suf_mx[i] = max(suf_mx[i + 1], arr[i]);
      suf_mn[i] = min(suf_mn[i + 1], arr[i]);
    }
    for(int i = 0;i < m;i++){
      int l, r;cin >> l >> r;
      int cur_num = arr[l - 1];
      int cur_mx = pre_mx[l - 1];
      int cur_mn = pre_mn[l - 1];
      int r_num = arr[r];
      int r_mx = suf_mx[r + 1];
      int r_mn = suf_mn[r + 1];
      int inc = max(0, r_mx - r_num);
      int dec = max(0, r_num - r_mn);
      int nmx = max(cur_mx, cur_num + inc);
      int nmn = min(cur_mn, cur_num - dec);
      cout << nmx - nmn + 1 << endl;
    }
  }
}
