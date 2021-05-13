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

  int t;cin >> t;
  while(t--){
    int n, m, x;cin >> n >> m >> x;
    vector<pair<int, int>> arr;
    vector<int> ans(n);
    for(int i = 0;i < n;i++){
      int num;cin >> num;
      arr.push_back({num, i});
    }
    sort(arr.begin(), arr.end());
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    for(int i = 0;i < m;i++){
      q.push({0, i});
    }
    for(auto p : arr){
      auto cur = q.top(); q.pop();
      auto np = make_pair(cur.first + p.first, cur.second);
      ans[p.second] = cur.second + 1;
      q.push(np);
    }
    vector<int> check;
    bool valid = true;
    while(!q.empty()){
      check.push_back(q.top().first);
      q.pop();
    }
    int mx = *max_element(check.begin(), check.end());
    int mn = *min_element(check.begin(), check.end());
    if(mx - mn > x)valid = false;
    if(valid){
      cout << "YES\n";
      for(int i : ans)cout << i << ' ';
      cout << endl;
    }
    else cout << "NO\n";
  }
}
