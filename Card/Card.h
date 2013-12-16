#include <iostream>
#include <conio.h>
#include <vector>
#include <sstream>
using namespace std;
class Card{
private:
	string name;
	float cash;
public:
	string getName();
	void setName(string p);
	float getCash();
	void setCash(float c);
	Card(string p, float c=0);
	void recharge0(float re);
};
class CardManager{
private:
	vector <Card> cards;
public:
	void add(string n, float ca = 0);
	void del(string n);
	void query(string n);
	void recharge(string n, float re);
};
void Show_List();