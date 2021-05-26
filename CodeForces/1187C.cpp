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

  int n, m;cin >> n >> m;
  //0 not any
  //1 start
  //2 mid
  //3 end
  bool valid = true;
  vector<int> arr(n + 1), arr2(n + 1), ans(n + 1);
  vector<pair<int, int>> z;
  for(int i = 0;i < m;i++){
    int t, l, r;cin >> t >> l >> r;
    if(t){
      if(arr[l] == 0)arr[l] = 1;
      else if(arr[l] == 3)arr[l] = 2;
      if(arr[r] == 0)arr[r] = 3;
      else if(arr[r] == 1)arr[r] = 2;
      for(int j = l + 1;j <= r - 1;j++)
        arr[j] = 2;
    }
    else z.push_back({l, r});
  }
  for(auto p : z){
    int l = p.first;
    int r = p.second;
    int cnt1 = 0, cnt3 = 0, cnt0 = 0;
    for(int i = l;i <= r;i++){
      if(arr[i] == 1)cnt1++;
      else if(arr[i] == 3)cnt3++;
      else if(arr[i] == 0)cnt0++;
      if(i == l && arr2[i] == 0)arr2[i] = 1;
      else if(i == r && arr2[i] == 0)arr2[i] = 3;
      else arr2[i] = 2;
    }
    if(arr[l] == 1 && arr[r] == 3 && cnt1 == 1 && cnt3 == 1)valid = false;
    if(cnt0 > 0 || (cnt1 > 0 && cnt3 > 0)){}
    else valid = false;
  }
  int cur = 1000;
  for(int i = 1;i <= n;i++){
    ans[i] = cur;
    if((arr2[i] == 1 || arr2[i] == 2) &&
        (arr[i] == 3 || arr[i] == 0))cur--;
  }
  if(valid){
    cout << "YES\n";
    for(int i = 1;i <= n;i++)
      cout << ans[i] << ' ';
    cout << endl;
  }
  else cout << "NO\n";
}
