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
    int p, f;cin >> p >> f;
    int cnts, cntw;cin >> cnts >> cntw;
    int s, w;cin >> s >> w;
    if(w < s){
      swap(s, w);
      swap(cnts, cntw);
    }
    int ans = 0;
    for(int i = 0;i <= cnts && s * i <= p;i++){
      int my_cnt = i;
      int my_rem = p - i * s;
      my_cnt += min(cntw, my_rem / w);
      int rem_s = cnts - i;
      int rem_w = cntw - min(cntw, my_rem / w);
      int f_cnt = 0;
      int f_rem = f;
      f_cnt += min(rem_s, f_rem / s);
      f_rem -= f_cnt * s;
      f_cnt += min(rem_w, f_rem / w);
      ans = max(ans, f_cnt + my_cnt);
    }
    cout << ans << endl;
  }
}
