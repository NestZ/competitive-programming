__gcd(int, int);
lcm = a * b / __gcd(a, b);

int gcd(int a, int b){
	return b ? gcd(a % b) : a;
}

bool isPrime(int n){
   if(n <= 1)return false;
   if(n <= 3)return true;
   if(n % 2 == 0 || n % 3 == 0)return false;
   for(int i = 5;i * i <= n;i += 6){
		 if(n % i == 0 || n % (i + 2) == 0)return false;
   }
   return true;
}

int countSubString(string s, string temp){
   int ans = 0;
   size_t f = s.find(temp);
   while(f != string::npos){
		 ans++;
		 f = s.find(temp, f + 1);
   }
   return ans;
}

#Count leading & trailing zero of an integer bits
__builtin_clz(n);
__builtin_clzll(n);

#Count 1s bits of an integer
__builtin_popcount(n);
__builtin_popcountll(n);

#Error checking
assert(n == 3);

#Error Printing
cerr << "Some thing";

#binary exponentiation
long long binpow(long long a, long long b) {
 long long res = 1;
 while (b > 0) {
	 if (b & 1)
		 res = res * a;
	 a = a * a;
	 b >>= 1;
 }
 return res;
}
