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
    vector<int> cnt(n + 1), ans(m);
    vector<tuple<int, vector<int>, int>> arr(m);
    for(int i = 0;i < m;i++){
      cin >> get<0>(arr[i]);
      get<2>(arr[i]) = i;
      for(int j = 0;j < get<0>(arr[i]);j++){
        int f;cin >> f;
        get<1>(arr[i]).push_back(f);
      }
    }
    sort(arr.begin(), arr.end());
    for(int i = 0;i < m;i++){
      int sz = get<0>(arr[i]);
      int mn = INT_MAX;
      int ind = -1;
      for(int j = 0;j < sz;j++){
        if(cnt[get<1>(arr[i])[j]] < mn){
          mn = cnt[get<1>(arr[i])[j]];
          ind = get<1>(arr[i])[j];
        }
      }
      if(mn + 1 > (m + 1) / 2){
        valid = false;
        break;
      }
      else{
        cnt[ind]++;
        ans[get<2>(arr[i])] = ind;
      }
    }
    if(valid){
      cout << "YES\n";
      for(int i : ans)cout << i << ' ';
      cout << endl;
    }
    else cout << "NO\n";
  }
}
