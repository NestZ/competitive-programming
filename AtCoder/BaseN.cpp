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

ll n, m;
string s;

bool valid(ll num){
  ll e = n - 1;
  ll tmp = num;
  if(tmp > m)return false;
  for(int i = 2;i <= e;i++){
    if(m / tmp >= num){
      tmp *= num;
    }
    else return false;
  }
  return true;
}

bool check(ll num){
  ll res = 0;
  for(int i = n - 1;i >= 0 && res <= m;i--){
    ll p = pow(num, n - i - 1) * (s[i] - '0');
    if(p > m)return false;
    res += p;
  }
  return res <= m;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> s;
  cin >> m;
  n = s.length();
  ll mx = *max_element(s.begin(), s.end()) - '0';
  if(n == 1){
    if(mx > m)cout << 0;
    else cout << 1;
  }
  else{
    ll l = mx + 1;
    ll r = m;
    ll ans = 0;
    while(l <= r){
      ll mid = l + (r - l) / 2;
      if(!valid(mid))r = mid - 1;
      else if(!check(mid))r = mid - 1;
      else {
        ans = mid;
        l = mid + 1;
      }
    }
    cout << max(0ll, ans - mx);
  }
  cout << endl;
}
