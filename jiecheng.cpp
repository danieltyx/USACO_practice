#include "bits/stdc++.h"
using namespace std;
int r[1000010];
int dj[1000010];
int sj[1000010];
int tj[1000010];
int main()
{
	int sum = 0;
	int n,m;
	int hmd = 0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&r[i]);
	}
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&dj[i],&sj[i],&tj[i]);
	}
	for(int i=1;i<=m;i++)
	{
		hmd = tj[i]-sj[i];
		for(int j=0;j<=hmd;j++)
		{
			if(r[sj[i]+j] >= dj[i])
			{
				sum++;
			}
		}
		if(sum==hmd+1)
		{
			for(int j=0;j<=hmd;j++)
			{
				r[sj[i]+j] = r[sj[i]+j] - dj[i];
			}
		}
		else
		{
			//printf("hmd:%d\n",hmd);
			//printf("sum:%d\n",sum);
			printf("-1\n");
			printf("%d",i);
			return 0;
		}
		sum =0;
	}
	
	for(int i=1;i<=m;i++)
	{
		cout<<dj[i]<<"  "<<sj[i]<<"  "<<tj[i]<<endl;
	}
	
	
	printf("0");
	return 0;
}
