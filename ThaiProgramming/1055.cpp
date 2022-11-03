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

  // vector<int> t = {1, 2, 3};
  // auto tt = t.begin();
  // tt++;tt++;
  // t.erase(tt);
  // cout << (tt == t.end());
  // return 0;
  int n, k;cin >> n >> k;
  vector<int> a(n);
  vector<int> ans(k, 0);
  for (int i = 0;i < n;i++) cin >> a[i];

  int ptr = 0;
  for (int i = 0;i < n;i++) {
    int c;cin >> c;
    int cnt = 0;
    while (cnt < c) {
      if (a[ptr] != 0) cnt++;
      ptr++;
      if (ptr == n)ptr = 0;
    }
    while(a[ptr] == 0) {
      ptr++;
      if (ptr == n) ptr = 0;
    }
    ans[i % k] += a[ptr];
    a[ptr] = 0;
  }

  for (int i = 0;i < k;i++) cout << ans[i] << endl;
}
