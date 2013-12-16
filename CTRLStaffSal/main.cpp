#include"Staff.h"

int main(){
	char c;
	while(1) {
		Show_List();
		cin>>c;
		switch (c) {
		case 'A':case 'a':
			cin.sync();cin.clear();
			Choose_Show();
			break;
		case 'B':case 'b': 
			cin.sync();cin.clear();
			Choose_Add();
			break;
		case 'C':case 'c': 
			cin.sync();cin.clear();
			Choose_Del();
			break;
		case 'D':case 'd':
			cin.sync();cin.clear();
			Choose_Edit();
			break;
		case 'E':case 'e':
			cin.sync();cin.clear();
			Choose_Save();
			break;
		case 'F':case 'f':
			cin.sync();
			Choose_Exit();
			break;
		default:
			cin.sync();
			printf("\rPlease Enter Correct Choice (From A To F): ");
			getch();
			break;
		}
	}
}