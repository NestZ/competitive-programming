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
    vector<char> arr(1000, '$');
    map<char, int> m;
    bool valid = true;
    int cur = 500;
    for(int i = 0;i < n;i++){
      if(i == 0){
        m[s[i]] = cur;
        arr[cur] = s[i];
      }
      else{
        if(s[i] == arr[cur - 1])cur--;
        else if(s[i] == arr[cur + 1])cur++;
        else if(arr[cur - 1] == '$'){
          if(m[s[i]] != 0)valid = false;
          else{
            cur--;
            arr[cur] = s[i];
            m[s[i]] = cur;
          }
        }
        else if(arr[cur + 1] == '$'){
          if(m[s[i]] != 0)valid = false;
          else{
            cur++;
            arr[cur] = s[i];
            m[s[i]] = cur;
          }
        }
        else valid = false;
      }
    }
    if(!valid)cout << "NO";
    else{
      cout << "YES\n";
      for(char c : arr){
        if(c != '$')cout << c;
      }
      for(char c = 'a';c <= 'z';c++){
        if(!m.count(c))cout << c;
      }
    }
    cout << endl;
  }
}
