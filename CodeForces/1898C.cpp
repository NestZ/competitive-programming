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
    int n, m, k;cin >> n >> m >> k;
    if (k < n + m - 2) {
      cout << "NO" << endl;
    } else if ((k - (n + m - 2)) % 2 != 0) {
      cout << "NO" << endl;
    } else {
      string fst = "R ";
      string snd = "B ";
      cout << "YES" << endl;
      for (int i = 0;i < n;i++) {
        for (int j = 0;j < m - 1;j++) {
          if (i == 0) {
            if (j % 2 == 0) cout << fst;
            else cout << snd;
          } else if (i == 1 && j == 0) {
            cout << snd;
          } else if(i == n - 1 && j == m - 2) {
            if (m % 2 == 0) {
              if (i % 2 == 0) cout << snd;
              else cout << fst;
            } else {
              if (i % 2 == 0) cout << fst;
              else cout << snd;
            }
          } else if (i == n - 2 && j == m - 2) {
            if (m % 2 == 0) {
              if (i % 2 == 0) cout << fst;
              else cout << snd;
            } else {
              if (i % 2 == 0) cout << snd;
              else cout << fst;
            }
          } else {
            cout << "R ";
          }
        }
        cout << endl;
      }
      for (int i = 0;i < n - 1;i++) {
        for (int j = 0;j < m;j++) {
          if (j == m - 1) {
            if (m % 2 == 0) {
              if (i % 2 == 0) cout << snd;
              else cout << fst;
            } else {
              if (i % 2 == 0) cout << fst;
              else cout << snd;
            }
          } else if (i == 0 && j == 0) {
            cout << fst;
          } else if (i == 0 && j == 1) {
            cout << fst;
          } else if (i == n - 2 && j == m - 2) {
            if (m % 2 == 0) {
              if (i % 2 == 0) cout << snd;
              else cout << fst;
            } else {
              if (i % 2 == 0) cout << fst;
              else cout << snd;
            }
          } else {
            cout << "R ";
          }
        }
        cout << endl;
      }
    }
  }
}
