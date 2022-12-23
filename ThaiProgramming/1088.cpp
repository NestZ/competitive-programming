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

  ll n, m;cin >> n >> m;
  map<ll, ll> cnt;
  cnt[n + 1] = 0;
  ll to0 = 0, to1 = 0, to2 = 0;
  for (ll i = 0;i < m;i++) {
    ll s, e;cin >> s >> e;
    cnt[s]++;
    cnt[e + 1]--;
  }
  ll cur = 0;
  ll lst_i = 1;
  ll lst = 0;
  for (auto it = cnt.begin(); it != cnt.end(); ++it) {
    ll fst = it -> first;
    ll snd = it -> second;
    cur = (cur + snd) % 3;

    ll len = fst - lst_i;
    to0 += len * ((3 - lst) % 3);
    to1 += len * ((4 - lst) % 3);
    to2 += len * ((5 - lst) % 3);
    lst_i = fst;
    lst = cur;
  }
  char to;cin >> to;
  if (to == 'R') {
    cout << to0;
  } else if (to == 'G') {
    cout << to1;
  } else {
    cout << to2;
  }
  cout << endl;
}
