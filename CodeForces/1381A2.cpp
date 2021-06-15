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

void Flip(char &a){
  if(a == '0')a = '1';
  else a = '0';
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;cin >> t;
  while(t--){
    int n;cin >> n;
    string a, b;cin >> a >> b;
    deque<char> q;
    vector<int> ans;
    bool rev = false, flip = false;
    for(char c : a)q.push_back(c);
    while(!q.empty()){
      char back_a = (rev ? q.front() : q.back());
      char back_b = b.back();
      char front_a = (rev ? q.back() : q.front());
      if(flip){
        Flip(back_a);
        Flip(front_a);
      }
      if(back_a != back_b){
        if(front_a == back_b)
          ans.push_back(1);
        ans.push_back(q.size());
        rev = !rev;
        flip = !flip;
      }
      b.pop_back();
      if(rev)q.pop_front();
      else q.pop_back();
    }
    cout << ans.size() << ' ';
    for(int i : ans)cout << i << ' ';
    cout << endl;
  }
}
