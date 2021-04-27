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

  int n, k;cin >> n >> k;
  vector<pair<int, int>> arr;
  for(int i = 0;i < n;i++){
    int a, b;cin >> a >> b;
    arr.push_back({-b, a});
  }
  sort(arr.rbegin(), arr.rend());
  set<pair<int, int>> s;
  int ans = 0;
  for(int i = 0;i < n;i++){
    if(s.empty()){
      s.insert({-arr[i].first, arr[i].second});
      ans++;
    }
    else{
      auto w = make_pair(arr[i].second, INT_MAX);
      auto ptr = s.upper_bound(w);
      if(ptr != s.begin()){
        ptr--;
        s.erase(ptr);
      }
      else if((int)s.size() == k)continue;
      s.insert({-arr[i].first, arr[i].second});
      ans++;
    }
  }
  cout << ans << endl;
}
