#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>

using namespace std;
class Solution{
public:
	int uniquePaths(int m,int n){
		int **dp = new int*[m+1];
		for(int i=0;i<m+1;i++) dp[i] = new int[n+1];
		for(int i=0;i<m+1;i++) dp[i][1] = 0;
		for(int i=0;i<n+1;i++) dp[1][i] = 0;
		for(int i=2;i<=m;i++){
			for(int j=2;j<=n;j++){
				dp[i][j] = dp[i-1][j] + dp[i][j-1];
			}
		}
		return dp[m][n];
	}
};
int main()
{
  Solution test;
  cout<<test.uniquePaths(3,3)<<endl;
  return 0;
}

