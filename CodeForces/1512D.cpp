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

  ll t;cin >> t;
  while(t--){
    ll n;cin >> n;
    ll sum_pre = 0;
    ll sum = 0;
    vector<ll> arr(n + 2);
    for(ll i = 0;i < n + 2;i++){
      cin >> arr[i];
      sum += arr[i];
    }
    sort(arr.begin(), arr.end());
    for(ll i = 0;i < n;i++)sum_pre += arr[i];
    //pre is sum
    if(sum_pre == arr[n]){
      for(ll i = 0;i < n;i++)cout << arr[i] << ' ';
    }
    //last is sum
    else{
      set<ll> s;
      for(int i = 0;i < n + 1;i++)s.insert(arr[i]);
      bool done = false;
      ll want = sum_pre + arr[n] - arr[n + 1];
      if(!s.count(want))cout << -1;
      else{
        for(ll i = 0;i < n + 1;i++){
          if(arr[i] == want && !done)done = true;
          else cout << arr[i] << ' ';
        }
      }
    }
    cout << endl;
  }
}
