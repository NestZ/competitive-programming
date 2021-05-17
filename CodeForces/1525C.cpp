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

void fuck(vector<pair<ll, ll>> &arr, vector<char> &dir,
    vector<ll> &ans, ll m){
  stack<pair<ll, ll>> s;
  ll n = arr.size();
  for(ll i = 0;i < n;i++){
    if(s.empty())s.push(arr[i]);
    else{
      ll c_idx = arr[i].second;
      ll c_pos = arr[i].first;
      char c_dir = dir[c_idx];
      if(c_dir == 'L'){
        ll l_idx = s.top().second;
        ll l_pos = s.top().first;
        char l_dir = dir[l_idx];
        s.pop();
        if(l_dir == 'R'){
          ans[c_idx] = ans[l_idx] = (c_pos - l_pos) / 2;
        }
        else{
          ans[c_idx] = ans[l_idx] = (c_pos + l_pos) / 2;
        }
      }
      else s.push(arr[i]);
    }
  }
  while(s.size() >= 2){
    auto cur = s.top(); s.pop();
    auto lst = s.top(); s.pop();
    ll c_idx = cur.second;
    ll c_pos = cur.first;
    char c_dir = dir[c_idx];
    ll l_idx = lst.second;
    ll l_pos = lst.first;
    char l_dir = dir[l_idx];
    assert(c_dir == 'R');
    if(l_dir == 'R'){
      ans[c_idx] = ans[l_idx] = ((m - c_pos) + (m - l_pos)) / 2;
    }
    else{
      ans[c_idx] = ans[l_idx] = (m + (m - c_pos) + l_pos) / 2;
    }
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll t;cin >> t;
  while(t--){
    ll n, m;cin >> n >> m;
    vector<char> dir(n);
    vector<ll> ans(n, -1);
    vector<pair<ll, ll>> arr(n), even, odd;
    for(ll i = 0;i < n;i++){
      cin >> arr[i].first;
      arr[i].second = i;
    }
    for(ll i = 0;i < n;i++)cin >> dir[i];
    sort(arr.begin(), arr.end());
    for(auto p : arr){
      if(p.first % 2 == 0)even.push_back(p);
      else odd.push_back(p);
    }
    fuck(even, dir, ans, m);
    fuck(odd, dir, ans, m);
    for(ll i : ans)
      cout << i << ' ';
    cout << endl;
  }
}
