#include "courses.h"
#include <iostream>
using namespace std;

int main(){
	courses *list;
	/*list = Create_ClassInfor("Java");
	Add_Student(list, "Java", "6090014", "Colin.H");
	Add_Student(list, "Java", "0690014", "º«·ÉÓî");
	Show_Course(list, "Java");
	Input_Grades(list, "Java", "6090014", 90.0);*/
	printf("****Course Information Control Center****\n");
	printf("Please Input First Class Name:");
	char fn[20];
	scanf("%s",fn);
	list = Create_ClassInfor(fn);
	char choose;
	while(1){
		Show_List();
		cin>>choose;
		switch (choose)	{
		case '1':
			Show_Courses_name(list);
			break;
		case '2':
			printf("Please Input Class Name:");
			char cna[20];
			scanf("%s",cna);
			Add_Course(list,cna);
			break;
		case '3':
			printf("Please Input Class Name:");
			char cns[20];
			scanf("%s",cns);
			Show_Course(list, cns);
			break;
		case '4':
			printf("Please Input Class Name:");
			char cnac[20];
			scanf("%s",cnac);
			printf("Please Input Student Name:");
			char cnas[20];
			scanf("%s",cnas);
			printf("Please Input Student Number:");
			char cnan[20];
			scanf("%s",cnan);
			Add_Student(list, cnac, cnan, cnas);
			break;
		case '5':
			printf("Please Input Class Name:");
			char cndc[20];
			scanf("%s",cndc);
			printf("Please Input Student Name:");
			char cnds[20];
			scanf("%s",cnds);
			Delete_Student(list, cndc, cnds);
			break;
		case '6':
			printf("Please Input Class Name:");
			char cnic[20];
			scanf("%s",cnic);
			printf("Please Input Student Name:");
			char cnin[20];
			scanf("%s",cnin);
			printf("Please Input Student Grade:");
			float grade;
			scanf("%f",&grade);			
			Input_Grades(list, cnic, cnin, grade);
			break;
		case '7':
			return 0;
			break;
		default:
			cin.sync();
			printf("Error Input!!!\n");
			break;
		}
	}
}
