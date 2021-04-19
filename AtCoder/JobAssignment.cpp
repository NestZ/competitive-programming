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
  int both = INT_MAX;
  vector<pair<int, int>> arr1;
  vector<pair<int, int>> arr2;
  for(int i = 0;i < n;i++){
    int a, b;cin >> a >> b;
    arr1.push_back({a, b});
    arr2.push_back({b, a});
    both = min(both, a + b);
  }
  int one = INT_MAX, two = INT_MAX;
  sort(arr1.begin(), arr1.end());
  sort(arr2.begin(), arr2.end());
  for(int i = 1;i < n;i++){
    one = min(one, arr1[i].second);
    two = min(two, arr2[i].second);
  }
  one = max(one, arr1[0].first);
  two = max(two, arr2[0].first);
  cout << min({both, one, two}) << endl;
}
