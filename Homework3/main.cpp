#include<iostream>
using namespace std;

int  combinatories(int, int);

int main(){
	int m,n;
	int c;
	cout<<"�������������������m,n,����m��n:";
	cin>>m>>n;
	c = combinatories(m,n);
	cout<<"��"<<m<<","<<n<<"Ϊ�������������"<<c<<endl;
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