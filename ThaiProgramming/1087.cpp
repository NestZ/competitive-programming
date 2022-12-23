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

  int r, c, k;cin >> r >> c >> k;
  vector<vector<int>> b(r + 10, vector<int>(c + 10));
  vector<vector<vector<int>>> pref_r(r + 10, vector<vector<int>>(c + 10, vector<int>(3)));
  vector<vector<vector<int>>> pref_c(r + 10, vector<vector<int>>(c + 10, vector<int>(3)));
  for (int i = 0;i < r;i++) {
    for (int j = 0;j < c;j++) {
      cin >> b[i][j];
    }
  }
  for (int i = 0;i < r;i++) {
    for (int j = 0;j < c;j++) {
      if (j & 1) {
        pref_r[i][j][1] = b[i][j] + ((j - 2 >= 0) ? pref_r[i][j - 2][1] : 0);
        pref_r[i][j][0] = (j - 1 >= 0) ? pref_r[i][j - 1][0] : 0;
      } else {
        pref_r[i][j][0] = b[i][j] + ((j - 2 >= 0) ? pref_r[i][j - 2][0] : 0);
        pref_r[i][j][1] = (j - 1 >= 0) ? pref_r[i][j - 1][1] : 0;
      }

      if (i & 1) {
        pref_c[i][j][1] = b[i][j] + ((i - 2 >= 0) ? pref_c[i - 2][j][1] : 0);
        pref_c[i][j][0] = (i - 1 >= 0) ? pref_c[i - 1][j][0] : 0;
      } else {
        pref_c[i][j][0] = b[i][j] + ((i - 2 >= 0) ? pref_c[i - 2][j][0] : 0);
        pref_c[i][j][1] = (i - 1 >= 0) ? pref_c[i - 1][j][1] : 0;
      }
    }
  }
  int ans = 0;
  for (int i = 0;i < r;i++) {
    for (int j = 0;j < c;j++) {
      int u = max(0, i - k);
      int d = min(r - 1, i + k);
      int l = max(0, j - k);
      int r = min(c - 1, j + k);
      int cur = 0;
      if (j & 1) {
        int inc = pref_r[i][r][1] - ((l - 1 >= 0) ? pref_r[i][l - 1][1] : 0);
        int dec = pref_r[i][r][0] - ((l - 1 >= 0) ? pref_r[i][l - 1][0] : 0);
        cur += inc - dec;
      } else {
        int dec = pref_r[i][r][1] - ((l - 1 >= 0) ? pref_r[i][l - 1][1] : 0);
        int inc = pref_r[i][r][0] - ((l - 1 >= 0) ? pref_r[i][l - 1][0] : 0);
        cur += inc - dec;
      }

      if (i & 1) {
        int inc = pref_c[d][j][1] - ((u - 1 >= 0) ? pref_c[u - 1][j][1] : 0);
        int dec = pref_c[d][j][0] - ((u - 1 >= 0) ? pref_c[u - 1][j][0] : 0);
        cur += inc - dec;
      } else {
        int dec = pref_c[d][j][1] - ((u - 1 >= 0) ? pref_c[u - 1][j][1] : 0);
        int inc = pref_c[d][j][0] - ((u - 1 >= 0) ? pref_c[u - 1][j][0] : 0);
        cur += inc - dec;
      }
      ans = max(ans, cur - b[i][j]);
    }
  }
  cout << ans << endl;
}
