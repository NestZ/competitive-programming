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
  vector<pair<ll, ll>> point(n + 1);
  vector<pair<ll, ll>> op;
  vector<vector<pair<ll, ll>>> query(200010);
  vector<pair<ll, ll>> ans(200010);
  for(ll i = 1;i <= n;i++){
    ll x, y;cin >> x >> y;
    point[i] = {x, y};
  }
  ll m;cin >> m;
  for(ll i = 0;i < m;i++){
    ll opn;cin >> opn;
    if(opn == 1 || opn == 2)
      op.push_back({opn, -1});
    else if(opn == 3 || opn == 4){
      ll d;cin >> d;
      op.push_back({opn, d});
    }
  }
  ll q;cin >> q;
  for(ll i = 0;i < q;i++){
    ll a, b;cin >> a >> b;
    query[a].push_back({b, i});
  }
  bool sw = false;
  ll sx = 1, sy = 1, cx = 0, cy = 0;
  for(ll i = 0;i <= m;i++){
    for(auto j : query[i]){
      ll fst = point[j.first].first;
      ll snd = point[j.first].second;
      if(sw)swap(fst, snd);
      ans[j.second] = {fst * sx + cx, snd * sy + cy};
    }
    if(i < m){
      auto cur = op[i];
      if(cur.first == 1){
        sw = !sw;
        sx = -sx;
        cx = -cx;
        swap(sx, sy);
        swap(cx, cy);
      }
      else if(cur.first == 2){
        sw = !sw;
        sy = -sy;
        cy = -cy;
        swap(sx, sy);
        swap(cx, cy);
      }
      else if(cur.first == 3){
        sx = -sx;
        cx = 2 * cur.second - cx;
      }
      else{
        sy = -sy;
        cy = 2 * cur.second - cy;
      }
    }
  }
  for(int i = 0;i < q;i++){
    cout << ans[i].first << ' ' << ans[i].second << endl;
  }
}
