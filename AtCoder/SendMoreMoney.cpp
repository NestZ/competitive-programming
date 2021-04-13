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

  set<char> all;
  string s1, s2, s3;cin >> s1 >> s2 >> s3;
  int n1 = s1.length(), n2 = s2.length(), n3 = s3.length();
  ll ans1 = -1, ans2 = -1, ans3 = -1;
  for(int i = 0;i < n1;i++)all.insert(s1[i]);
  for(int i = 0;i < n2;i++)all.insert(s2[i]);
  for(int i = 0;i < n3;i++)all.insert(s3[i]);
  if(all.size() > 10)cout << "UNSOLVABLE";
  else{
    int n = all.size();
    vector<char> c;
    vector<int> perm(10);
    map<char, int> m;
    for(int i = 0;i < 10;i++)perm[i] = i;
    for(char ch : all)c.push_back(ch);
    do{
      for(int i = 0;i < n;i++)m[c[i]] = perm[i];
      string ns1 = s1, ns2 = s2, ns3 = s3;
      for(char &ch : ns1)ch = '0' + m[ch];
      for(char &ch : ns2)ch = '0' + m[ch];
      for(char &ch : ns3)ch = '0' + m[ch];
      if(ns1[0] == '0' || ns2[0] == '0' || ns3[0] == '0')
        continue;
      ll num1 = stoll(ns1);
      ll num2 = stoll(ns2);
      ll num3 = stoll(ns3);
      if(num1 + num2 != num3)continue;
      ans1 = num1; ans2 = num2; ans3 = num3;
      break;
    }while(next_permutation(perm.begin(), perm.end()));
    if(ans1 == -1)cout << "UNSOLVABLE";
    else cout << ans1 << endl << ans2 << endl << ans3;
  }
  cout << endl;
}
