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
    int n;cin >> n;
    vector<int> ans(n);
    priority_queue<tuple<int, int, int>> q;
    q.push({n, 0, n - 1});
    int cnt = 1;
    while(!q.empty()){
      auto cur = q.top(); q.pop();
      int l = -get<1>(cur);
      int r = get<2>(cur);
      int mid = ((r - l + 1) % 2 ? (l + r) / 2 : (l + r - 1) / 2);
      ans[mid] = cnt++;
      if(mid - 1 >= l)
        q.push({mid - l, -l, mid - 1});
      if(r >= mid + 1)
        q.push({r - mid, -(mid + 1), r});
    }
    for(int i : ans)
      cout << i << ' ';
    cout << endl;
  }
}
