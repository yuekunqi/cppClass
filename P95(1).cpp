#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<cctype>
#include<numeric>
#include<cstdlib>
#include <iomanip>
#include<sstream>
#define mod 1000000007
#define INT 2147483647
#define pi acos(-1.0)
#define eps 1e-3
#define lll __int64
#define ll long long
//freopen("1.txt","r",stdin);
using namespace std;

double F_to_C(double f)
{
	double c=(double)5/(double)9*(f-32);
	return c;
}

int main()
{
	double f;
	cin>>f;
	cout<<fixed<<setprecision(1)<<F_to_C(f)<<endl;
    return 0;
}
