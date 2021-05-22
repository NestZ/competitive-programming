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

  int n, m, d;cin >> n >> m >> d;
  vector<int> river(n + 1), c(m), suf(m + 1), pos(m);
  for(int i = 0;i < m;i++)cin >> c[i];
  for(int i = m - 1;i >= 0;i--){
    suf[i] = c[i];
    if(i < n - 1)
      suf[i] += suf[i + 1]; 
  }
  for(int i = 0;i < m;i++){
    //tail must not exceed n - suf[i + 1]
    ll tail = n - suf[i + 1];
    pos[i] = tail - c[i] + 1;
  }
  int cur = 0;
  for(int i = 0;i < m;i++){
    if(cur + d > n)break;
    if(cur + d < pos[i]){
      pos[i] -= pos[i] - (cur + d);
    }
    cur = pos[i] + c[i] - 1;
  }
  if(cur + d > n){
    cout << "YES\n";
    for(int i = 0;i < m;i++){
      for(int j = pos[i];j < pos[i] + c[i];j++){
        river[j] = i + 1;
      }
    }
    for(int i = 1;i <= n;i++)cout << river[i] << ' ';
    cout << endl;
  }
  else cout << "NO\n";
}
