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

  ll q;cin >> q;
  while(q--){
    ll u, v;cin >> u >> v;
    bool valid = true;
    if(u > v)valid = false;
    string su, sv;
    for(ll i = 0;i < 32;i++){
      su += '0';
      sv += '0';
    }
    for(ll i = 0;i < 32;i++){
      if((u >> i) & 1)su[i] = '1';
      if((v >> i) & 1)sv[i] = '1';
    }
    ll cntu = 0, cntv = 0;
    for(ll i = 0;i < 32;i++){
      if(su[i] == '1')cntu++;
      if(sv[i] == '1')cntv++;
      if(cntu < cntv)valid = false;
    }
    if(valid)cout << "yEs";
    else cout << "nO";
    cout << endl;
  }
}
