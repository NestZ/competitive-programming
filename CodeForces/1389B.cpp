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
    int n, k, z;cin >> n >> k >> z;
    vector<int> arr(n), pre(n + 1);
    for(int i = 0;i < n;i++)cin >> arr[i];
    for(int i = 0;i < n;i++){
      pre[i] = arr[i];
      if(i > 0)pre[i] += pre[i - 1];
    }
    int ans = 0;
    int sum = arr[0];
    for(int i = 1;i <= k;i++){
      sum += arr[i];
      int rem_w = k - i;
      int rep_cnt = min(z, rem_w / 2);
      int rem_q = z - rep_cnt;
      rem_w -= rep_cnt * 2;
      int cur_get = sum + rep_cnt * (arr[i] + arr[i - 1]);
      if(rem_q && rem_w){
        rem_w--; rem_q--;
        cur_get += arr[i - 1];
        if(rem_w)
          cur_get += pre[i + rem_w - 1] - pre[i - 1];
      }
      else if(rem_w){
        cur_get += pre[i + rem_w] - pre[i];
      }
      ans = max(cur_get, ans);
    }
    cout << ans << endl;
  }
}
