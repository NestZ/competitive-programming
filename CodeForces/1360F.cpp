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

bool check(string cur, vector<string> &arr){
  int n = arr.size();
  int m = cur.length();
  for(int i = 0;i < n;i++){
    int cnt = 0;
    for(int j = 0;j < m;j++){
      if(cur[j] != arr[i][j])cnt++;
    }
    if(cnt > 1)return false;
  }
  return true;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;cin >> t;
  while(t--){
    int n, m;cin >> n >> m;
    vector<string> arr(n);
    vector<set<char>> choice(m);
    for(int i = 0;i < n;i++)cin >> arr[i];
    for(int i = 0;i < n;i++){
      for(int j = 0;j < m;j++){
        choice[j].insert(arr[i][j]);
      }
    }
    string ans = "-1";
    string cur = arr[0];
    if(check(cur, arr))ans = cur;
    for(int i = 0;i < m;i++){
      if(choice[i].size() == 1)continue;
      for(char c : choice[i]){
        cur[i] = c;
        if(check(cur, arr))ans = cur;
      }
      cur[i] = arr[0][i];
    }
    cout << ans << endl;
  }
}
