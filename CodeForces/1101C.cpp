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

ll find(ll x, vector<int> &parent){
  ll nx = x;
  while(nx != parent[nx])nx = parent[nx];
  return parent[x] = nx;
}

void unite(ll a, ll b, vector<int> &parent,
    vector<int> &sz){
  a = find(a, parent);
  b = find(b, parent);
  if(sz[a] < sz[b])swap(a, b);
  sz[a] += sz[b];
  sz[b] = 0;
  parent[b] = a;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;cin >> t;
  while(t--){
    int n;cin >> n;
    vector<tuple<int, int, int>> arr;
    vector<int> parent(n), sz(n), ans(n);
    for(int i = 0;i < n;i++){
      parent[i] = i;
      sz[i] = 1;
    }
    for(int i = 0;i < n;i++){
      int a, b;cin >> a >> b;
      arr.push_back({a, b, i});
    }
    sort(arr.begin(), arr.end());
    priority_queue<pair<int, int>> q;
    for(int i = 0;i < n;i++){
      if(q.empty())q.push({-get<1>(arr[i]), get<2>(arr[i])});
      else{
        while(!q.empty() && get<0>(arr[i]) > -q.top().first)
          q.pop();
        if(!q.empty())
          unite(q.top().second, get<2>(arr[i]), parent, sz);
        q.push({-get<1>(arr[i]), get<2>(arr[i])});
      }
    }
    int cnt = 0, fst = 0;
    for(int i = 0;i < n;i++){
      if(sz[i] > 0){
        cnt++;
        fst = i;
      }
    }
    for(int i = 0;i < n;i++){
      if(find(i, parent) == fst)ans[i] = 1;
      else ans[i] = 2;
    }
    if(cnt == 1)cout << -1;
    else{
      for(int i = 0;i < n;i++)
        cout << ans[i] << ' ';
    }
    cout << endl;
  }
}
