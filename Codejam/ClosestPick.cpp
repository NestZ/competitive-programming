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
  for(int q = 0;q < t;q++){
    int n, k;cin >> n >> k;
    vector<int> arr(n);
    vector<int> cnt_same;
    vector<int> cnt;
    for(int i = 0;i < n;i++)cin >> arr[i];
    arr.push_back(0);
    arr.push_back(k + 1);
    sort(arr.begin(), arr.end());
    for(int i = 1;i <= n + 1;i++){
      int diff = max(0, arr[i] - arr[i - 1] - 1);
      if(i == 1 || i == n + 1)cnt.push_back(diff);
      else cnt.push_back((diff + 1) / 2);
      cnt_same.push_back(diff);
    }
    sort(cnt.rbegin(), cnt.rend());
    sort(cnt_same.rbegin(), cnt_same.rend());
    double ans = double(cnt[0] + cnt[1]) / double(k);
    double ans_same = double(cnt_same[0]) / double(k);
    printf("Case #%d: %.9lf\n", q + 1, max(ans, ans_same));
  }
}

