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

  int n, t;cin >> n >> t;
  vector<int> arr(n);
  vector<int> pre(n + 1);
  for(int i = 0;i < n;i++)cin >> arr[i];
  for(int i = n - 1;i >= 0;i--){
    pre[i] = max(arr[i], pre[i + 1]);
  }
  int mx = 0;
  int cnt = 0;
  for(int i = 0;i < n - 1;i++){
    if(pre[i + 1] - arr[i] > mx){
      mx = pre[i + 1] - arr[i];
      cnt = 1;
    }
    else if(pre[i + 1] - arr[i] == mx)cnt++;
  }
  cout << cnt << endl;
}
