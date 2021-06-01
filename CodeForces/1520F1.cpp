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

int q(int l, int r){
  cout << "? " << l << ' ' << r << endl;
  int res;cin >> res;
  return res;
}

void ans(int x){
  cout << "! " << x << endl;
}

int main(){
  int n, t;cin >> n >> t;
  while(t--){
    int k;cin >> k;
    int l = 1, r = n;
    int best = n;
    while(l <= r){
      int mid = l + (r - l) / 2;
      int res = q(1, mid);
      int z = mid - res;
      if(z >= k){
        r = mid - 1;
        best = mid;
      }
      else l = mid + 1;
    }
    ans(best);
  }
}
