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

  int n, m, q;cin >> n >> m >> q;
  set<int> s;
  s.insert(1); s.insert(n + 1);
  for(int i = 0;i < m;i++){
    int a, k;cin >> a >> k;
    int l = a;
    int r = a + k;
    if(s.count(l))s.erase(l);
    else s.insert(l);
    if(s.count(r))s.erase(r);
    else s.insert(r);
  }
  for(int i = 0;i < q;i++){
    int x;cin >> x;
    int fst = 1, lst = n + 1;
    auto e = s.upper_bound(x);
    if(e == s.end())lst = n + 1;
    else lst = *e;
    if(e == s.begin())fst = 1;
    else fst = *(--e);
    cout << lst - fst << endl;
  }
}
