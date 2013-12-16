#include <iostream>
#include <sstream>

using namespace std;

int main(){
	char s[20];
	freopen("w.txt","w",stdout);
	cin>>s;
	cout<<s;
	freopen("CON","w",stdout);
	cout<<s;
}

