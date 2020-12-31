#include"bits/stdc++.h"
using namespace std;
bool vis[20];
int sum = 0;
int checkprime(int x,int y)
{
	int xysum = x + y;
	for(int i=2;i*i<=xysum;i++)
	{
		if(xysum%i==0)
		{
			return 1;
		}
	}
	return 2;
}
int main()
{
	for(int i=1;i<=20;i++)
	{
		if(vis[i])continue;
		vis[i]=true;
		for(int j=1;j<=20;j++)
		{
			if(vis[j])continue;
			vis[j]=true;
			for(int k=1;k<=20;k++)
			{
				if(vis[k])continue;
				vis[i]=true;
				if(checkprime(i,j)==1&&checkprime(j,k)==1&&checkprime(i,k)==1)
				{
					sum++;
				}
				vis[i] = false;
			}
			vis[j] = false;
		}
		vis[i]=  false;
	}
	cout<<sum;
	return 0;
}
