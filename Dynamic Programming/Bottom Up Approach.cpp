#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
						//0  1  1  2  3  5  8 
int dp[N];
//Bottom Up Approach
int fib(int n){
	int count = 0;
	dp[0] = 0;
	dp[1] = 1;
	for(int i = 2; i<=n; i++){
		dp[i] = dp[i-1] + dp[i-2];
	}
	return dp[n];
}

int main()
{
	int n;
	cin>>n;
	cout<<fib(n);
}