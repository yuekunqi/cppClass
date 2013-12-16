#include<iostream>
using namespace std;

int power(int x,int y){
	int ans;
	if(y==1) ans=x;
	else ans = x*power(x,y-1);
	return ans;
}