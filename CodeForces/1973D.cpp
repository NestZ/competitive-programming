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
  while(t--) {
    int n, k;cin >> n >> k;
    int mx = 0;

    // max = n * n
    int r = n + 1;
    int m = 0;
    while(r != n) {
      m += n;
      cout << "? 1 " << m << endl << flush;
      cin >> r;
    }
    mx = m / n;

    // candidate for ans = [mx, n * mx] = n possible answer
    // number of query = n + n * k
    // but with number of segment => k * (ans / mx) <= n
    // ans <= n/k * mx
    // ans = [mx, n/k * mx] => n/k possible answer
    // so, total number of query is O(2n)
    int ans = -1;
    for (int i = 0;i < n / k && ans == -1;i++) {
      int cur_pos = 0;
      for (int j = 0;j < k && cur_pos < n;j++) {
        cout << "? " << cur_pos + 1 << " " << mx * (i + 1) << endl << flush;
        cin >> cur_pos;
        if (cur_pos == n && j == k - 1) {
          ans = mx * (i + 1);
          break;
        }
      }
    }

    cout << "! " << ans << endl << flush;

    int verd;cin >> verd;
    if (verd != 1) break;
  }
}
