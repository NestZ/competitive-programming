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
  string v = "AEIOU";
  for(int q = 0;q < t;q++){
    string s;cin >> s;
    int n = s.length();
    int ans = INT_MAX;
    for(char c = 'A';c <= 'Z';c++){
      int cnt = 0;
      for(int i = 0;i < n;i++){
        if(s[i] == c)continue;
        if(v.find(c) != string::npos){
          if(v.find(s[i]) != string::npos)cnt += 2;
          else cnt++;
        }
        else{
          if(v.find(s[i]) == string::npos)cnt += 2;
          else cnt++;
        }
      }
      ans = min(ans, cnt);
    }
    cout << "Case #" << q + 1 << ": " << ans << endl;
  }
}
