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

  ll b, c;cin >> b >> c;
  if(b > 0){
    ll rs = b - (c / 2);
    ll ls = -b - ((c - 1) / 2);
    ll re = -ls - ((c - 1) % 2 == 0 && (c - 1) > 0 ? 1 : 0);
    ll le = -rs - (c % 2 == 0 ? 1 : 0);
    ll rlen = re - rs + 1;
    ll llen = le - ls + 1;
    ll overlap = max(0ll, le - rs + 1);
    cout << rlen + llen - overlap << endl;
  }
  else{
    ll ls = b - (c / 2);
    ll rs = -b - ((c - 1) / 2);
    ll le = -rs - ((c - 1) % 2 == 0 && (c - 1) > 0 ? 1 : 0);
    ll re = -ls - (c % 2 == 0 ? 1 : 0);
    ll rlen = re - rs + 1;
    ll llen = le - ls + 1;
    ll overlap = max(0ll, le - rs + 1);
    cout << rlen + llen - overlap << endl;
  }
}
