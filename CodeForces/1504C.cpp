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
    int n;cin >> n;
    string s;cin >> s;
    int cnto = count(s.begin(), s.end(), '0');
    bool valid = true;
    bool turn_a = true;
    int cnt1 = 0;
    if(cnto % 2 != 0 || s[0] == '0' || s[n - 1] == '0')
      valid = false;
    vector<char> a, b;
    for(int i = 0;i < n;i++){
      if(s[i] == '1'){
        if(cnt1 < (n - cnto) / 2){
          a.push_back('(');
          b.push_back('(');
        }
        else{
          a.push_back(')');
          b.push_back(')');
        }
        cnt1++;
      }
      else{
        if(turn_a){
          a.push_back('(');
          b.push_back(')');
        }
        else{
          a.push_back(')');
          b.push_back('(');
        }
        turn_a = !turn_a;
      }
    }
    if(valid){
      cout << "YES\n";
      for(char c : a)cout << c;
      cout << endl;
      for(char c : b)cout << c;
      cout << endl;
    }
    else cout << "NO\n";
  }
}
