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
vector<ll> cnt, p, sz, rp;

int find(ll x){
  while(x != p[x])x = p[x];
  return x;
}

bool same(ll a, ll b){
  return find(a) == find(b);
}

void unite(ll a, ll b){
  a = find(a);
  b = find(b);
  if(sz[a] < sz[b])swap(a, b);
  sz[a] += sz[b];
  sz[b] = 0;
  p[b] = a;
}

bool is_a_win(ll a, ll b){
  ll pa = rp[find(a)];
  ll pb = rp[find(b)];
  ll cnta = cnt[pa];
  ll cntb = cnt[pb];
  if(cnta == cntb)return pa < pb;
  return cnta > cntb;
}

void a_win(ll a, ll b) {
  ll pa = rp[find(a)];
  ll pb = rp[find(b)];
  cnt[pa] += cnt[pb] / 2;
  rp[find(b)] = rp[find(a)];
}

//use dsu for ask if two is the same set

//need to know the current leader of any commander
//only fight one by one, so we know for easily (set by p)

//need to know the current sold's size of any commander
//only fight one by one, so we know for easily (set by p)

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> m;
  cnt = vector<ll>(n + 10);
  p = vector<ll>(n + 10);
  sz = vector<ll>(n + 10);
  rp = vector<ll>(n + 10);
  for(ll i = 1;i <= n;i++){
    cin >> cnt[i];
    p[i] = i;
    rp[i] = i;
    sz[i] = 1;
  }
  for(ll i = 1;i <= m;i++){
    ll a, b;cin >> a >> b;
    if(same(a, b)){
      cout << -1;
    } else {
      if(is_a_win(a, b)) {
        a_win(a, b);
        cout << rp[find(a)];
      } else {
        a_win(b, a);
        cout << rp[find(b)];
      }
      unite(a, b);
    }
    cout << endl;
  }
}
