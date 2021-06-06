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

int mxN;

int sum(int k, vector<int> &tree){
  int s = 0;
  while(k > 0){
    s += tree[k];
    k -= k & -k;
  }
  return s;
}

int range_sum(int l, int r, vector<int> &tree){
  return sum(r, tree) - sum(l - 1, tree);
}

void add(int k, int x, vector<int> &tree){
  while(k < mxN){
    tree[k] += x;
    k += k & -k;
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;cin >> t;
  while(t--){
    int n;cin >> n;
    int ans = 0;
    vector<pair<int, int>> arr;
    map<int, int> ind;
    mxN = 2 * n + 10;
    vector<int> cnt(n + 1), start(mxN), end(mxN);
    for(int i = 0;i < n;i++){
      int l, r;cin >> l >> r;
      arr.push_back({r, l});
      ind[l] = 0;
      ind[r] = 0;
    }
    int tmp = 1;
    for(auto &p : ind)p.second = tmp++; 
    for(int i = 0;i < n;i++)
      add(ind[arr[i].second], 1, start);
    sort(arr.begin(), arr.end());
    for(int i = 0;i < n;i++){
      cnt[i] += range_sum(1, ind[arr[i].first], start) - 1;
      cnt[i] += range_sum(ind[arr[i].second], ind[arr[i].first], end);
      add(ind[arr[i].second], -1, start);
      add(ind[arr[i].first], 1, end);
      ans = max(ans, cnt[i] + 1);
    }
    cout << n - ans << endl;
  }
}
