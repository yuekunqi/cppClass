#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>

using namespace std;

int fac(int n)
{
	int p=1;
	for(int i=n;i>=1;i--)
	{
		p*=i;
	}
	return p;
}

int Comb(int m,int n)
{
	int p=1;
	int k=0;
	while(k<=n-1)
	{
		p*=(m-k);
		k++;
	}
	p/=fac(n);
	return p;
}

int main()
{
	int m,n;
	cin>>m>>n;
	cout<<Comb(m,n)<<endl;
	return 0;
}
