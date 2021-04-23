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

  ll x;cin >> x;
  map<ll, ll> m;
  set<ll> s;
  ll lst = 0;
  for(ll i = 0;;i++){
    ll p = pow(i, 5);
    s.insert(p);
    m[p] = i;
    if(p - lst > x)break;
    lst = p;
  }
  for(ll i : s){
    if(i > x){
      ll rem = i - x;
      if(s.count(rem)){
        cout << m[i] << ' ' << m[rem];
        break;
      }
    }
    else{
      ll rem = x - i;
      if(s.count(rem)){
        cout << m[i] << ' ' << -m[rem];
        break;
      }
    }
  }
  cout << endl;
}
