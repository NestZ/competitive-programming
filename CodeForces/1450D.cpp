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

vector<int> arr(300010), cnt(300010), ans(300010);

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;cin >> t;
  while(t--){
    int n;cin >> n;
    for(int i = 0;i <= n;i++){
      cnt[i] = 0;
      ans[i] = 0;
    }
    for(int i = 0;i < n;i++){
      cin >> arr[i];
      arr[i]--;
      cnt[arr[i]]++;
    }
    int tmp = -1;
    while(cnt[tmp + 1] == 1){
      tmp++;
    }
    ans[0] = tmp == n - 1;
    int l = 0, r = n - 1;
    ans[n - 1] = cnt[0] > 0;
    for(int i = n - 1;i > 0;i--){
      if(!ans[n - 1])break;
      ans[i] = true;
      int nxt = n - i - 1;
      if(--cnt[nxt] == 0 && (arr[l] == nxt || arr[r] == nxt) &&
          cnt[nxt + 1]){
        if(arr[l] == nxt)l++;
        if(arr[r] == nxt)r--;
        continue;
      }
      break;
    }
    for(int i = 0;i < n;i++)
      cout << ans[i];
    cout << endl;
  }
}
