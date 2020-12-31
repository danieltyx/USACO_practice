#include"bits/stdc++.h"
using namespace std;
int main()
{
	set<int> myset;
	set<int>::iterator it;
	int a[5] = {0,5,3,546,345};
	for(int i=1;i<=4;i++)
	{
		myset.insert(a[i]);
	} 
	myset.insert(a,a+4);
	myset.insert(77);
	it = myset.end();
	myset.erase(--it);

	it = myset.begin();
	myset.erase(it);

	int aa;
	for(it=myset.begin();it!=myset.end();++it)
	{
		aa = *it;
		cout<<aa<<" ";
	}
	cout<<myset.size();
	return 0;
}