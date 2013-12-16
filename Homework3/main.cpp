#include<iostream>
using namespace std;

int  combinatories(int, int);

int main(){
	int m,n;
	int c;
	cout<<"请依次输入组合数参数m,n,其中m≥n:";
	cin>>m>>n;
	c = combinatories(m,n);
	cout<<"以"<<m<<","<<n<<"为参数的组合数是"<<c<<endl;
}

int combinatories (int m,int n){
	int c;
	long x=1,y=1,z=1;
	for(int i=1;i<=m;i++){
		x *= i;
	}
	for(int i=1;i<=n;i++){
		y *= i;
	}
	for(int i=1;i<=(m-n);i++){
		z *= i;
	}
	c = x/(y*z);
	return (int)c;
}