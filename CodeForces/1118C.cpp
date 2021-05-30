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
  map<int, int> m;
  vector<vector<int>> ans(n, vector<int>(n));
  for(int i = 0;i < n * n;i++){
    int t;cin >> t;
    m[t]++;
  }
  if(n % 2 == 0){
    vector<pair<int, int>> arr;
    for(auto p : m){
      if(p.second % 4){
        cout << "NO\n";
        return 0;
      }
      arr.push_back(p);
    }
    int ptr = 0;
    for(int i = 0;i < n / 2;i++){
      for(int j = 0;j < n / 2;j++){
        if(ptr == (int)arr.size() || arr[ptr].second == 0){
          cout << "NO\n";
          return 0;
        }
        ans[i][j] = arr[ptr].first;
        ans[n - i - 1][j] = arr[ptr].first;
        ans[i][n - j - 1] = arr[ptr].first;
        ans[n - i - 1][n - j - 1] = arr[ptr].first;
        arr[ptr].second -= 4;
        if(ptr < (int)arr.size() && arr[ptr].second == 0)ptr++;
      }
    }
  }
  else{
    vector<pair<int, int>> arr;
    int center = -1;
    for(auto p : m){
      if(p.second & 1){
        if(center == -1){
          center = p.first;
          m[p.first]--;
        }
        else{
          cout << "NO\n";
          return 0;
        }
      }
      arr.push_back({p.first, m[p.first]});
    }
    int ptr = 0;
    while(ptr < (int)arr.size() && arr[ptr].second < 4)ptr++;
    for(int i = 0;i < n / 2;i++){
      for(int j = 0;j < n / 2;j++){
        if(ptr == (int)arr.size() || arr[ptr].second < 4){
          cout << "NO\n";
          return 0;
        }
        ans[i][j] = arr[ptr].first;
        ans[n - i - 1][j] = arr[ptr].first;
        ans[i][n - j - 1] = arr[ptr].first;
        ans[n - i - 1][n - j - 1] = arr[ptr].first;
        arr[ptr].second -= 4;
        while(ptr < (int)arr.size() && arr[ptr].second < 4)ptr++;
      }
    }
    ans[n / 2][n / 2] = center;
    ptr = 0;
    while(arr[ptr].second == 0)ptr++;
    for(int i = 0;i < n / 2;i++){
      if(ptr == (int)arr.size() || arr[ptr].second == 0){
        cout << "NO\n";
        return 0;
      }
      ans[i][n / 2] = arr[ptr].first;
      ans[n - i - 1][n / 2] = arr[ptr].first;
      arr[ptr].second -= 2;
      while(ptr < (int)arr.size() && arr[ptr].second == 0)ptr++;
    }
    for(int i = 0;i < n / 2;i++){
      if(ptr == (int)arr.size() || arr[ptr].second == 0){
        cout << "NO\n";
        return 0;
      }
      ans[n / 2][i] = arr[ptr].first;
      ans[n / 2][n - i - 1] = arr[ptr].first;
      arr[ptr].second -= 2;
      while(ptr < (int)arr.size() && arr[ptr].second == 0)ptr++;
    }
  }
  cout << "YES\n";
  for(int i = 0;i < n;i++){
    for(int j = 0;j < n;j++){
      cout << ans[i][j] << ' ';
    }
    cout << endl;
  }
}
