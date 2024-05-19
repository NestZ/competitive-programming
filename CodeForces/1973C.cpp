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
  while(t--) {
    int n;cin >> n;
    vector<int> arr(n);
    vector<int> peak;
    vector<int> non_peak;
    bool start_zero = false;
    for (int i = 0;i < n;i++) {
      cin >> arr[i];
      if (arr[i] == 1 && i > 0 && i < n - 1) {
        start_zero = i % 2 == 1;
      }
    }
    for (int i = 0;i < n;i++) {
      bool is_peak = false;
      if (i > 0 && i < n - 1 && (start_zero && (i % 2 == 0) || !start_zero && (i % 2 == 1))) {
        is_peak = true;
      }
      if (is_peak) peak.push_back(arr[i]);
      else non_peak.push_back(arr[i]);
    }

    sort(peak.begin(), peak.end());
    sort(non_peak.begin(), non_peak.end());

    vector<int> ans(n + 1, 0);
    for (int i = 0;i < peak.size();i++) {
      ans[peak[i]] = n - i;
    }
    for (int i = 0;i < non_peak.size();i++) {
      ans[non_peak[i]] = non_peak.size() - i;
    }

    for (int i = 0;i < n;i++) {
      cout << ans[arr[i]] << ' ';
    }
    cout << endl;
  }
}
