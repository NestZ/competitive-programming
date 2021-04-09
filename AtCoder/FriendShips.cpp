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

  int n, k;cin >> n >> k;
  int mx = (n - 2) * (n - 1) / 2;
  if(k > mx)cout << -1 << endl;
  else{
    int one = n * (n - 1) / 2 - k;
    if(one < n - 1)cout << -1 << endl;
    else{
      cout << one << endl;
      for(int i = 1;i < n;i++){
        cout << i << ' ' << n << endl;
      }
      int cur = n - 1;
      for(int i = 1;i <= n;i++){
        for(int j = i + 1;j < n;j++, cur++){
          if(cur == one)return 0;
          else cout << i << ' ' << j << endl;
        }
      }
    }
  }
}
