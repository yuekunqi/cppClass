#include "Card.h"

string Card::getName(){
	return name;
}
void Card::setName(string p){
	name = p;
}
float Card::getCash(){
	return cash;
}
void Card::setCash(float c){
	cash = c;
}
Card::Card(string p, float c){
	name = p;
	cash = c;
}
void Card::recharge0(float re){
	cash += re;
}


void CardManager::add(string n, float ca){
	Card sc(n, ca);
	cards.push_back(sc);
}
void CardManager::del(string n){
	vector <Card>::iterator itr = cards.begin();
	int ord = 0;
	while(itr != cards.end()){
		if(cards[ord].getName() == n){
			cards.erase(itr);
			return;
		}
		else{
			ord++;
			itr++;
		}
	}
}
void CardManager::query(string n){
	vector <Card>::iterator itr = cards.begin();
	int ord = 0;
	while(itr != cards.end()){
		if(cards[ord].getName() == n){
			cout<<"Name: "<<cards[ord].getName()<<"\tCash: "<<cards[ord].getCash()<<endl;
			return;
		}
		else{
			ord++;
			itr++;
		}
	}
	cout<<"This Person Does NOT Exist!!!\n";
}
void CardManager::recharge(string n, float re){
	vector <Card>::iterator itr = cards.begin();
	int ord = 0;
	while(itr != cards.end()){
		if(cards[ord].getName() == n){
			cards[ord].recharge0(re);
			cout<<"Recharge Successfully!!!"<<endl;
			return;
		}
		else{
			ord++;
			itr++;
		}
	}
	cout<<"This Person Does NOT Exist!!!\n";
}

void Show_List(){
	system("cls");
	cout<<"******Welcome to Card Control Center******"<<endl;
	cout<<"\t1. Add A Card"<<endl;
	cout<<"\t2. Delete A Card"<<endl;
	cout<<"\t3. Auery A Card"<<endl;
	cout<<"\t4. Recharge A Card"<<endl;
	cout<<"\t5. Exit"<<endl;
	cout<<"Enter your choice: ";
}