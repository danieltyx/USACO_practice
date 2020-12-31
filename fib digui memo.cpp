#include <bits/stdc++.h>
using namespace std;
int memo[1001];
int fib(int x)
{
	
	if(x <= 1) return 1;
	if(memo[x]!=0) return memo[x];
	return memo[x] = fib(x-1) + fib (x-2);
	
}
int main()
{
	int n = 5;
	cout<<fib(n-1);
}
