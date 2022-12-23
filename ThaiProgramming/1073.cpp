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

  int l,t;cin >> l >> t;
  int n;cin >> n;
  vector<int> ans;
  for (int i = 0;i < n;i++) {
    int d;cin >> d;
    char dir;cin >> dir;
    if (dir == 'L') {
      if (t <= d) {
        ans.push_back(d - t);
      } else {
        int rem_t = t - d;
        int last = rem_t % l;
        if (rem_t / l % 2 == 0) {
          ans.push_back(last);
        } else {
          ans.push_back(l - last);
        }
      }
    } else {
      if (t <= l - d) {
        ans.push_back(d + t);
      } else {
        int rem_t = t - (l - d);
        int last = rem_t % l;
        if (rem_t / l % 2 == 0) {
          ans.push_back(l - last);
        } else {
          ans.push_back(last);
        }
      }
    }
  }
  sort(ans.begin(), ans.end());
  for (int i = 0;i < n;i++) {
    cout << ans[i] << ' ';
  }
  cout << endl;
}
