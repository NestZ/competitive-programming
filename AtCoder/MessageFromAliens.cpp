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

  string s;cin >> s;
  int n = s.length();
  bool r = false;
  deque<char> q;
  for(int i = 0;i < n;i++){
    if(s[i] == 'R')r = !r;
    else{
      if(r)q.push_front(s[i]);
      else q.push_back(s[i]);
    }
  }
  vector<char> c;
  stack<char> st;
  while(!q.empty()){
    if(r){
      c.push_back(q.front());
      q.pop_front();
    }
    else{
      c.push_back(q.back());
      q.pop_back();
    }
  }
  for(char ch : c){
    if(!st.empty() && ch == st.top())st.pop();
    else st.push(ch);
  }
  vector<char> ans;
  while(!st.empty()){
    ans.push_back(st.top());
    st.pop();
  }
  for(char ch : ans)cout << ch;
  cout << endl;
}
