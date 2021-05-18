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

double fuck(ll cnt, ll h, ll c, ll t){
  double avg = double(cnt * h + cnt * c + h) / (2 * cnt + 1);
  return avg;
}

double diff(ll cnt, ll h, ll c, ll t){
  return fabs(fuck(cnt, h, c, t) - double(t));
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll q;cin >> q;
  while(q--){
    ll h, c, t;cin >> h >> c >> t;
    double avg = (h + c) / 2.0;
    if(double(t) <= avg)cout << 2;
    else{
      ll l = 0, r = 1e6;
      ll best = 0;
      while(l <= r){
        ll mid = l + (r - l) / 2;
        debug() << imie(mid) imie(diff(mid, h, c, t));
        if(diff(mid, h, c, t) <= diff(mid + 1, h, c, t)){
          best = mid;
          r = mid - 1;
        }
        else l = mid + 1;
      }
      cout << best * 2 + 1;
    }
    cout << endl;
  }
}
