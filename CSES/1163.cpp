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

  int x, n;cin >> x >> n;
  vector<int> arr, q, ans;
  set<int> s;
  arr.push_back(0); arr.push_back(x);
  s.insert(0); s.insert(x);
  for(int i = 0;i < n;i++){
    int t;cin >> t;
    q.push_back(t);
    arr.push_back(t);
    s.insert(t);
  }
  sort(arr.begin(), arr.end());
  int mx = 0;
  for(int i = 1;i < (int)arr.size();i++){
    mx = max(mx, arr[i] - arr[i - 1]);
  }
  ans.push_back(mx);
  for(int i = n - 1;i >= 1;i--){
    s.erase(q[i]);
    auto up = s.upper_bound(q[i]);
    auto down = --(s.upper_bound(q[i]));
    mx = max(mx, *up - *down);
    ans.push_back(mx);
  }
  reverse(ans.begin(), ans.end());
  for(int i : ans)cout << i << ' ';
  cout << endl;
}
