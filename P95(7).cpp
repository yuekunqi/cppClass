#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;

int cal_pow(int x,int y)
{
	if(y==0)
		return 1;
	return x*cal_pow(x,y-1);
}

int main()
{
	int x,y;
	cin>>x>>y;
	cout<<cal_pow(x,y)<<endl;
	return 0;
}
