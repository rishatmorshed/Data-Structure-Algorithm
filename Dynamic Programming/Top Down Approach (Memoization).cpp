#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
				//0  1  1  2  3  5  8 
int dp[N];
//Top down Approach
int fib(int n){
	if(n == 0) return 0;	//Base condition
	if(n == 1) return 1;
	if(dp[n] != -1) return dp[n];		
	dp[n] = fib(n-1) + fib(n-2); // This is called memoization
	return dp[n];
}

int main()
{
	memset(dp, -1, sizeof(dp)); /* we can use for loop also
				       to initialize array index as -1*/
	int n;
	cin>>n;
	cout<<fib(n);
}
