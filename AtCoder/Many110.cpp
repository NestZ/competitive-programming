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

const ll mx = 1e10;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n;cin >> n;
  string s;cin >> s;
  if(s == "1"){
    cout << mx * 2;
  } else if(s == "0") {
    cout << mx;
  } else {
    string t = string(2 * n, '1');
    for(ll i = 1;i <= 2 * n;i++){
      if(i % 3 == 0)t[i - 1] = '0';
    }
    string fst = t.substr(0, n);
    string snd = t.substr(1, n);
    string trd = t.substr(2, n);
    if(fst == s){
      ll len = (n + 2) / 3;
      cout << mx - len + 1;
    } else if(snd == s) {
      ll len = (n + 3) / 3;
      cout << mx - len + 1;
    } else if(trd == s) {
      ll len = (n + 4) / 3;
      cout << mx - len + 1;
    } else {
      cout << 0;
    }
  }
  cout << endl;
}
