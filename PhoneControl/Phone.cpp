#include <stdio.h>
class PhoneCard{
public:
	PhoneCard();
	~PhoneCard();
	virtual void performDial(){
		return;
	}
	double balance;

private:
	//NULL
};

PhoneCard::PhoneCard(){
	balance = 100.00f;
}

PhoneCard::~PhoneCard(){
	balance = 0.00f;
}

class Card_201: public PhoneCard
{
public:
	Card_201(long cn, int pw, double b):PhoneCard(){
		connectNumber = cn;
		password = pw;
		balance = b;
		additoryFee = 1.00;
		connected = false;
	}
	~Card_201(){
		connectNumber = 0;
		password = 0;
		balance = 0;
		connected = false;
	}
	void performConnect(long cn, int pw);
	double getBalance();
	void performDial();

private:
	long connectNumber;
	double additoryFee;
	long cardNumber;
	int password;
	bool connected;
};

void Card_201::performConnect(long cn, int pw){
	if(cn == connectNumber && pw == password){
		connected = true;
		printf("System Has Already Connected!!!\n");
	}
	else{
		connected = false;
		printf("Wrong Username or Password!!\n");
	}
}

void Card_201::performDial(){
	if(connected = true){
		balance -= (0.3+additoryFee);
		printf("Dial Over. Fee = %lf\n", (0.3+additoryFee));
	}
	else{
		printf("Doesn't Connect!!!\n");
	}
}

inline double Card_201::getBalance(){
	if(connected == true){
		printf("getBalance Success!!balance = %lf\n", balance);
		return balance;
	}
	else{
		printf("Doesn't Connect, GetBalance Failed!!\n");
		return -1.0;
	}
}

int main(){
	Card_201 phone(9014, 19930601, 100);
	phone.performConnect(9014, 19930602);
	phone.getBalance();
	phone.performConnect(9014, 19930601);
	phone.getBalance();
	phone.performDial();
	phone.getBalance();
}