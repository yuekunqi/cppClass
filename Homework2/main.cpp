#include<iostream>
using namespace std;
float c2f(float);
float f2c(float);

int main(){
	float c,rec,f,ref;
	cout<<"�����������¶ȣ�";
	cin>>c;
	rec = c2f(c);
	cout<<c<<"��="<<rec<<"�H"<<endl;
	cout<<"�����뻪���¶ȣ�";
	cin>>f ;
	ref = f2c(c);
	cout<<f<<"�H="<<ref<<"��"<<endl;
}

float f2c(float f){
	float c;
	c = 5.0/9.0*(f - 32);
	return c;
}

float c2f(float c){
	float f;
	f = 9.0*c/5.0+32;
	return f;
}