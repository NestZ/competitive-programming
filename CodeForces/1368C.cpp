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
  vector<pair<int, int>> ans;
  ans.push_back({0, 0});
  int start = 1, end = 0;
  for(int i = 0;i < n;i++, start += 2){
    for(int j = -1;j <= 1;j++){
      ans.push_back({start, j});
    }
    ans.push_back({start + 1, 0});
    end = max(end, start + 1);
  }
  if(n % 2 == 0){
    start = 1;
    for(int i = 0;i < n / 2;i++, start += 4){
      for(int j = 0;j <= 2;j++){
        ans.push_back({start + j, 2});
        ans.push_back({start + j, -2});
      }
    }
    for(int i = 0;i <= 4;i++){
      ans.push_back({-1, i});
      ans.push_back({end + 1, i});
    }
    for(int i = 0;i <= end;i++){
      ans.push_back({i, 4});
    }
  }
  else{
    start = 1;
    for(int i = 0;i < n / 2;i++, start += 4){
      for(int j = 0;j <= 2;j++){
        ans.push_back({start + j, 2});
        ans.push_back({start + j + 2, -2});
      }
    }
    for(int i = 0;i <= 2;i++){
      ans.push_back({-1, -i});
      ans.push_back({end + 1, i});
    }
    for(int i = 0;i <= 1;i++){
      ans.push_back({i, -2});
      ans.push_back({end - i, 2});
    }
  }
  cout << ans.size() << endl;
  for(auto p : ans)
    cout << p.first << ' ' << p.second << endl;
}
