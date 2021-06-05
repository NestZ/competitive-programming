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

pair<int, int> simulate(pair<int, int> obs, string &s){
  int n = s.length();
  int cx = 0, cy = 0;
  for(int i = 0;i < n;i++){
    if(s[i] == 'L'){
      if(make_pair(cx - 1, cy) != obs)cx--;
    }
    else if(s[i] == 'R'){
      if(make_pair(cx + 1, cy) != obs)cx++;
    }
    else if(s[i] == 'U'){
      if(make_pair(cx, cy + 1) != obs)cy++;
    }
    else{
      if(make_pair(cx, cy - 1) != obs)cy--;
    }
  }
  return {cx, cy};
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  
  int t;cin >> t;
  while(t--){
    string s;cin >> s;
    int n = s.length();
    int cx = 0, cy = 0;
    vector<pair<int, int>> path;
    for(int i = 0;i < n;i++){
      if(s[i] == 'L')cx--;
      else if(s[i] == 'R')cx++;
      else if(s[i] == 'U')cy++;
      else cy--;
      if(cx != 0 || cy != 0)
        path.push_back({cx, cy});
    }
    pair<int, int> ans = make_pair(0, 0);
    for(auto p : path){
      auto d = simulate(p, s);
      if(d.first == 0 && d.second == 0){
        ans = p;
        break;
      }
    }
    cout << ans.first << ' ' << ans.second << endl;
  }
}
