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

  int n, x;cin >> n >> x;
  vector<pair<int, int>> arr;
  for(int i = 0;i < n;i++){
    int t;cin >> t;
    arr.push_back({t, i});
  }
  sort(arr.begin(), arr.end());
  for(int i = 0;i < n - 2;i++){
    for(int j = i + 1;j < n - 1;j++){
      int sum = arr[i].first + arr[j].first;
      int want = x - sum;
      if(want <= 0)break;
      int l = j + 1;
      int r = n - 1;
      while(l <= r){
        int mid = l + (r - l) / 2;
        if(arr[mid].first == want){
          cout << arr[i].second + 1 << ' ' << arr[j].second + 1 << ' ' << arr[mid].second + 1 << endl;
          return 0;
        }
        else if(arr[mid].first < want)l = mid + 1;
        else r = mid - 1;
      }
    }
  }
  cout << "IMPOSSIBLE\n";
}
