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

  int n, m, k;cin >> n >> m >> k;
  int l = 0, r = 0;
  vector<int> w(n), a(m);
  for(int i = 0;i < n;i++)cin >> w[i];
  for(int i = 0;i < m;i++)cin >> a[i];
  sort(w.begin(), w.end());
  sort(a.begin(), a.end());
  int ans = 0;
  while(l < n && r < m){
    if(abs(w[l] - a[r]) <= k){
      ans++;
      l++; r++;
    }
    else if(w[l] < a[r]){
      l++;
    }
    else if(w[l] > a[r]){
      r++;
    }
  }
  cout << ans << endl;
}
