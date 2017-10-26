#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
inline long long max(long long a,long long b){return (a>b?a:b);}
inline long long min(long long a,long long b){return (a>b?b:a);}
int main()
{
  int n,K,d;
  scanf("%d", &n);
  vector<long long int> vec;
  vec.resize(n+1);
  for(int i=0;i<n;i++) scanf("%lld", &vec[i]);
  scanf("%d %d",&K, &d);
  long long int ans = -1;
  long long maxdp[11][51];
  long long mindp[11][51];
  for(int i=1;i<=K;i++)
    for(int j=0;j<n;j++ ) maxdp[i][j]=mindp[i][j]=0;
  for(int i=0;i<n;i++){
    maxdp[1][i] = mindp[1][i] = vec[i];
    for(int k=2;k<=K;k++){
       for(int j=i-1; j>=0 && i-j<d; j--){
         maxdp[k][i] = max(max(maxdp[k-1][j]*vec[i],mindp[k-1][j]*vec[i]),maxdp[k][i]);
         mindp[k][i] = min(min(mindp[k-1][j]*vec[i],maxdp[k-1][j]*vec[i]),mindp[k][i]);
       }
    }
    ans = max(maxdp[K][i],ans);
  }
  printf("%lld\n",ans);
  return 0;
}
