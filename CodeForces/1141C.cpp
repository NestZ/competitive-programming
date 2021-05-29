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

  int n;cin >> n;
  vector<int> arr(n - 1), ans(n);
  for(int i = 0;i < n - 1;i++)cin >> arr[i];
  ans[0] = 1;
  int mn = 1;
  for(int i = 1;i < n;i++){
    ans[i] = ans[i - 1] + arr[i - 1];
    mn = min(mn, ans[i]);
  }
  if(mn < 1){
    int add = 1 - mn;
    for(int &i : ans)i += add;
  }
  map<int, int> cnt;
  bool valid = true;
  for(int i : ans){
    cnt[i]++;
    if(cnt[i] > 1)valid = false;
    if(i < 1 || i > n)valid = false;
  }
  if(valid){
    for(int i : ans)cout << i << ' ';
  }
  else cout << -1;
  cout << endl;
}
