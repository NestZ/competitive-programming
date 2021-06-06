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

  vector<string> all;

  for(char c = 'a';c <= 'z';c++){
    string s = "";
    s += c;
    all.push_back(s);
  }

  for(char c = 'a';c <= 'z';c++){
    for(char cc = 'a';cc <= 'z';cc++){
      string s1 = "";
      s1 += c;
      string s2 = "";
      s2 += cc;
      all.push_back(s1 + s2);
    }
  }

  for(char c = 'a';c <= 'z';c++){
    for(char cc = 'a';cc <= 'z';cc++){
      for(char ccc = 'a';ccc <= 'z';ccc++){
        string s1 = "";
        s1 += c;
        string s2 = "";
        s2 += cc;
        string s3 = "";
        s3 += ccc;
        all.push_back(s1 + s2 + s3);
      }
    }
  }

  int t;cin >> t;
  while(t--){
    int n;cin >> n;
    string s;cin >> s;
    for(string ss : all){
      //cout << ss << endl;
      if(s.find(ss) == string::npos){
        cout << ss << endl;
        break;
      }
    }
  }
}
