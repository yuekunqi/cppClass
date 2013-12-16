#include<iostream>
using namespace std;

int power(int, int);

int main(){
	int x,y,ans;
	cout<<"请依次输入底数和指数：";
	cin>>x>>y;
	ans = power(x,y);
	cout<<"以"<<x<<"为底数、"<<y<<"为指数的幂是"<<ans<<endl;
}