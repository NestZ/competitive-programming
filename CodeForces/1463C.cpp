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
    vector<pair<ll, ll>> arr;
    for(ll i = 0;i < n;i++){
      ll a, b;cin >> a >> b;
      arr.push_back({a, b});
    }
    arr.push_back({1e18, arr[n - 1].second});
    ll start = 0;
    ll end = 0;
    ll ans = 0;
    for(ll i = 0;i < n;i++){
      if(i == 0){
        end = arr[i].second;
        //check if success
        if(arr[i + 1].first - arr[i].first >= abs(start - end)){
          ans++;
        }
      }
      else{
        //success
        if(arr[i].first - arr[i - 1].first >= abs(start - end)){
          start = end;
          end = arr[i].second;
          //check
          if(arr[i + 1].first - arr[i].first >= abs(start - end)){
            ans++;
          }
        }
        //nsuccess
        else{
          //update
          if(start < end){
            start += arr[i].first - arr[i - 1].first;
            assert(start < end);
          }
          else{
            start -= arr[i].first - arr[i - 1].first;
            assert(end < start);
          }
          //check
          if(start < end){
            if(arr[i].second >= start && arr[i].second <= end && abs(arr[i + 1].first - arr[i].first) >= abs(start - arr[i].second)){
              ans++;
            }
          }
          else{
            if(arr[i].second >= end && arr[i].second <= start && abs(arr[i + 1].first - arr[i].first) >= abs(start - arr[i].second)){
              ans++;
            }
          }
        }
      }
      debug() << imie(i) imie(start) imie(end);
    }
    cout << ans << endl;
  }
}
