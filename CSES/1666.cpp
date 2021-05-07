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

vector<int> parent(100010);
vector<int> sz(100010, 1);

int find(int x){
  int ox = x;
  while(ox != parent[ox])
    ox = parent[ox];
  return parent[x] = ox;
}

bool same(int a, int b){
  return find(a) == find(b);
}

void unite(int a, int b){
  a = find(a);
  b = find(b);
  if(sz[a] < sz[b])swap(a, b);
  sz[a] += sz[b];
  sz[b] = 0;
  parent[b] = a;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;cin >> n >> m;
  for(int i = 1;i <= n;i++)
    parent[i] = i;
  vector<int> each;
  vector<pair<int, int>> edge;
  for(int i = 0;i < m;i++){
    int a, b;cin >> a >> b;
    if(!same(a, b))unite(a, b);
  }
  for(int i = 1;i <= n;i++){
    if(parent[i] == i)each.push_back(i);
  }
  cout << each.size() - 1 << endl;
  for(int i = 1;i < (int)each.size();i++){
    cout << each[i] << ' ' << each[i - 1] << endl;
  }
}
