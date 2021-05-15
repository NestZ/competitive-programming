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
    int n, m;cin >> n >> m;
    bool valid = true;
    vector<int> a(n), b(n), c(m), ans(m);
    vector<vector<int>> want(n + 1);
    vector<int> same(n + 1, -1);
    for(int i = 0;i < n;i++)cin >> a[i];
    for(int i = 0;i < n;i++)cin >> b[i];
    for(int i = 0;i < m;i++)cin >> c[i];
    for(int i = 0;i < n;i++){
      if(a[i] != b[i]){
        want[b[i]].push_back(i);
      }
      else same[b[i]] = i;
    }
    for(int i = m - 1;i >= 0;i--){
      if((int)want[c[i]].size() == 0){
        if(same[c[i]] == -1){
          if(i == m - 1)valid = false;
          else ans[i] = ans[i + 1];
        }
        else ans[i] = same[c[i]];
      }
      else{
        ans[i] = want[c[i]].back();
        b[want[c[i]].back()] = a[want[c[i]].back()];
        want[c[i]].pop_back();
      }
    }
    for(int i = 0;i < n;i++){
      if(a[i] != b[i])valid = false;
    }
    if(!valid)cout << "NO\n";
    else{
      cout << "YES\n";
      for(int i : ans)cout << i + 1 << ' ';
      cout << endl;
    }
  }
}
