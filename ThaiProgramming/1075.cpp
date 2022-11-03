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

  ll n;cin >> n;
  vector<pair<ll, ll>> arr;
  for (ll i = 0;i < n;i++) {
    ll d, c;cin >> d >> c;
    arr.push_back({c, d});
  }
  sort(arr.begin(), arr.end());

//ans_data/ans_cost = cur_data/cur_cost
//ans_data*cur_cost < cur_data*ans_cost
  ll cur_data = arr[0].second, cur_cost = arr[0].first;
  ll ans_data = arr[0].second, ans_cost = arr[0].first;
  for (ll i = 1;i < n;i++) {
    cur_data += arr[i].second;
    cur_cost = arr[i].first;
    if (ans_data * cur_cost < cur_data * ans_cost) {
      ans_data = cur_data;
      ans_cost = cur_cost;
    }
  }
  cout << ans_data << ' ' << ans_cost << endl;
}
