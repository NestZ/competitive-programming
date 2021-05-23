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
    string s;cin >> s;
    int n = s.length();
    vector<char> ans;
    queue<char> even, odd;
    for(int i = 0;i < n;i++){
      int num = s[i] - '0';
      if(num & 1)odd.push(s[i]);
      else even.push(s[i]);
    }
    while(!even.empty() || !odd.empty()){
      if(even.empty()){
        ans.push_back(odd.front());
        odd.pop();
      }
      else if(odd.empty()){
        ans.push_back(even.front());
        even.pop();
      }
      else{
        int e = even.front();
        int o = odd.front();
        if(e < o){
          ans.push_back(even.front());
          even.pop();
        }
        else{
          ans.push_back(odd.front());
          odd.pop();
        }
      }
    }
    for(char c : ans)cout << c;
    cout << endl;
  }
}
