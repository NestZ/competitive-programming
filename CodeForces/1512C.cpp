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
  while(t--){
    //a = 0
    int a, b;cin >> a >> b;
    string s;cin >> s;
    int n = s.length();
    bool valid = true;
    a -= count(s.begin(), s.end(), '0');
    b -= count(s.begin(), s.end(), '1');
    for(int i = 0;i < n / 2;i++){
      if(s[i] == '?' && s[n - i - 1] == '?'){}
      else if(s[i] == '?'){
        if(s[n - i - 1] == '1')b--;
        else a--;
        s[i] = s[n - i - 1];
      }
      else if(s[n - i - 1] == '?'){
        if(s[i] == '1')b--;
        else a--;
        s[n - i - 1] = s[i];
      }
      if(a < 0 || b < 0)valid = false;
    }
    for(int i = 0;i < n / 2;i++){
      if(s[i] == '?' && s[n - i - 1] == '?'){
        if(a >= 2){
          s[i] = s[n - i - 1] = '0';
          a -= 2;
        }
        else if(b >= 2){
          s[i] = s[n - i - 1] = '1';
          b -= 2;
        }
        else valid = false;
      }
    }
    if((n & 1) && s[n / 2] == '?'){
      int i = n / 2;
      if(a > 0){
        s[i] = '0';
        a--;
      }
      else if(b > 0){
        s[i] = '1';
        b--;
      }
      else valid = false;
    }
    for(int i = 0;i < n / 2;i++){
      if(s[i] != s[n - i - 1])valid = false;
    }
    if(b > 0 || a > 0)valid = false;
    if(valid)cout << s;
    else cout << -1;
    cout << endl;
  }
}
