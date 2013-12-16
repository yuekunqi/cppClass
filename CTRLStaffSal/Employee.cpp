#include "Staff.h"

vector <CTempStaff> temp;
vector <CAdministrator> admin;
vector <CTeacher> teacher;

CStaff::CStaff(char* n, char *na, Sex_Choose s, unsigned int ser){
	strcpy(No, n);
	strcpy(Name, na);
	sex = s;
	ServiceYears = ser;
}

void CStaff::SetNo(char* n){
	strcpy(No, n);
}

char* CStaff::GetNo(){
	return No;
}

void CStaff::SetName(char* na){
	strcpy(Name, na);
}

char* CStaff::GetName(){
	return Name;
}

void CStaff::SetSex(Sex_Choose se){
	sex = se;
}

Sex_Choose CStaff::GetSex(){
	return sex;
}

void CStaff::SetServiceYears(unsigned int ser){
	ServiceYears = ser;
}

unsigned int CStaff::GetServiceYears(){
	return ServiceYears;
}

float CTempStaff::GetSalary(){
		return (float)TempSalary;
}

float CAdministrator::GetSalary(){
		if( post == Section_Member ){
			return (float)(Base_Salary + this->GetServiceYears() * Base_ServiceYears);
		}
		else if (post == Section_Chief){
			return (float)(Base_Salary + this->GetServiceYears() * Base_ServiceYears + Post_Salary_Section_Chief);
		}
		else{
			return (float)(Base_Salary + this->GetServiceYears() * Base_ServiceYears + Post_Salary_Division_Chief);
		}
}

Post_Choose  CAdministrator::GetPost(){
	return post;
}

void CAdministrator::SetPost(Post_Choose p){
	post = p;
}

float CTeacher::GetSalary(){
	if(rank == Lecturer){
		return (float)(Base_Salary + this->GetServiceYears() * Base_ServiceYears + hour * Class_Salary_Lecturer); 
	}
	else if(rank == Associate_Professor || rank == Professor){
		return (float)(Base_Salary + this->GetServiceYears() * Base_ServiceYears + hour * Class_Salary_Professor_A + master * Subsidy_Master); 
	}
	else{
		return (float)(Base_Salary + this->GetServiceYears() * Base_ServiceYears + hour * Class_Salary_Tutor_PHD + master * Subsidy_Master + doctor * Subsidy_Doctor); 
	}
}

Rank_Choose CTeacher::GetRank(){
	return rank;
}
unsigned int CTeacher::GetHour(){
	return hour;
}
unsigned int CTeacher::GetMaster(){
	return master;
}
unsigned int CTeacher::GetDoctor(){
	return doctor;
}
void CTeacher::SetRank(Rank_Choose r){
	rank = r;
}
void CTeacher::SetHour(unsigned int h){
	hour = h;
}
void CTeacher::SetMaster(unsigned int m){
	master = m;
}
void CTeacher::SetDoctor(unsigned int d){
	doctor = d;
}

void Show_List(){
	system("cls");
	cout<<"**********Welcome to Staff Salary Management System**********"<<endl;
	cout<<"\tA. Show Staff(s) Salary List"<<endl;
	cout<<"\tB. Add A Staff"<<endl;
	cout<<"\tC. Delete A Staff"<<endl;
	cout<<"\tD. Edit A Staff"<<endl;
	cout<<"\tE. Output Staff(s) Salary List & Exit"<<endl;
	cout<<"\tF. Exit"<<endl;
	cout<<"Please Enter Your Choice: ";
}

void Choose_Show(){
	cout<<"**********Details of the Deployment**********"<<endl;
	cout<<"\tA. Show Temp Staff Salary List"<<endl;
	cout<<"\tB. Show Administrators Salary List"<<endl;
	cout<<"\tC. Show Teachers Salary List"<<endl;
	cout<<"Please Enter Your Choice: ";
	char c;
	cin>>c;
	switch (c) {
	case 'A':case 'a':
		if(temp.empty() == true){
			printf("There is no Temp Staff!");
			getch();
		}
		else{
			int ord;
			for(ord = 0; ord < temp.size(); ord++){
				cout<<temp[ord];
				cout<<"Salary: "<<temp[ord].GetSalary()<<endl;
			}
			getch();
		}
		break;
	case 'B':case 'b':
		if(admin.empty() == true){
			printf("There is no Administrator!");
			getch();
		}
		else{
			int ord;
			for(ord = 0; ord < admin.size(); ord++){
				cout<<admin[ord];
				cout<<"Salary: "<<admin[ord].GetSalary()<<endl;
			}
			getch();
		}
		break;
	case 'C':case 'c':
		if(teacher.empty() == true){
			printf("There is no Teacher!");
			getch();
		}
		else{
			int ord;
			for(ord = 0; ord < teacher.size(); ord++){
				cout<<teacher[ord];
				cout<<"Salary: "<<teacher[ord].GetSalary()<<endl;
			}
			getch();
		}
		break;
	default:
		cin.sync();
		printf("\rPlease Enter Correct Choice (From A To C): ");
		break;
	}
}

void Choose_Add(){
	char c;
	cout<<"**********Details of the Deployment**********"<<endl;
	cout<<"\tA. Add A Temp Staff"<<endl;
	cout<<"\tB. Add A Administrator"<<endl;
	cout<<"\tC. Add A Teacher"<<endl;
	cout<<"Please Enter Your Choice: ";
	cin>>c;
	switch (c) {
	case 'A':case 'a': {
		cin.sync();cin.clear();
		char Num[20];
		char Name[40];
		int s;
		Sex_Choose sex;
		unsigned int ServiceYears;
		cout<<"You Will Input the Information of Temporary Staff\nPlease Input the Information According To Prompts:"<<endl;
		cout<<"No. ";
		gets(Num);
		cout<<"Name: ";
		gets(Name);
		cout<<"Sex(1. Male  2.Female): ";
		cin>>s; sex = (s==1)? Male : Female;
		cout<<"Service Year(s): ";
		cin>>ServiceYears;
		CTempStaff sctemp(Num, Name, sex, ServiceYears);
		cout<<"The Following Information Will Be Save!\n"<<sctemp<<"\nDone!"<<endl;
		temp.push_back(sctemp);
		getch();
		break;
	}
	case 'B':case 'b':{
		cin.sync();cin.clear();
		char No[20];
		char Name[40];
		int s;
		Sex_Choose sex;
		unsigned int ServiceYears;
		Post_Choose post;
		cout<<"You Will Input the Information of Administrator\nPlease Input the Information According To Prompts:"<<endl;
		cout<<"No. ";
		gets(No);
		cout<<"Name: ";
		gets(Name);
		cout<<"Sex(1. Male  2.Female): ";
		cin>>s; sex = (s==1)? Male : Female;
		cout<<"Service Year(s): ";
		cin>>ServiceYears;
		cout<<"Post(1.Section Member 2.Section Chief 3.Division_Chief ): ";
		cin>>s;
		switch(s){
		case 1:post = Section_Member;break;
		case 2:post = Section_Chief;break;
		case 3:post = Division_Chief;break;
		default: exit(1);break;
		}
		CAdministrator scadmin(No, Name, sex, ServiceYears, post);
		cout<<"The Following Information Will Be Save!\n"<<scadmin<<"\nDone!"<<endl;
		admin.push_back(scadmin);
		getch();
		break;
	}
	case 'C':case 'c':{
		cin.sync();cin.clear();
		char No[20];
		char Name[40];
		int s;
		Sex_Choose sex;
		unsigned int ServiceYears;
		Rank_Choose rank;
		unsigned int hour, master, doctor;
		cout<<"You Will Input the Information of Teacher\nPlease Input the Information According To Prompts:"<<endl;
		cout<<"No. ";
		gets(No);
		cout<<"Name: ";
		gets(Name);
		cout<<"Sex(1. Male  2.Female): ";
		cin>>s; sex = (s==1)? Male : Female;
		cout<<"Service Year(s): ";
		cin>>ServiceYears;
		cout<<"Rank(1.Lecturer 2.Associate Professor 3.Professor 4.Tutor_PHD): ";
		cin>>s;
		switch(s){
		case 1:rank = Lecturer;break;
		case 2:rank = Associate_Professor;break;
		case 3:rank = Professor;break;
		case 4:rank = Tutor_PHD;break;
		default: exit(1);break;
		}
		cout<<"Teaching Hours: ";
		cin>>hour;
		cout<<"Numbers of Master(s): ";
		cin>>master;
		cout<<"Numbers of Doctor(s): ";
		cin>>doctor;
		CTeacher scteacher(No, Name, sex, ServiceYears, rank, hour, master, doctor);
		cout<<"The Following Information Will Be Save!\n"<<scteacher<<"\nDone!"<<endl;
		teacher.push_back(scteacher);
		getch();
		break;
    	}
	default:
		cin.sync();
		printf("\rPlease Enter Correct Choice (From A To C): ");
		break;
	}
}

void Choose_Del(){
	char c;
	cout<<"**********Details of the Deployment**********"<<endl;
	cout<<"\tA. Delete A Temp Staff"<<endl;
	cout<<"\tB. Delete A Administrator"<<endl;
	cout<<"\tC. Delete A Teacher"<<endl;
	cout<<"Please Enter Your Choice: ";
	cin>>c;
	switch(c){
	case 'A':case 'a':{
		cin.sync();cin.clear();
		char inNo[20];
		bool flag = false;
		cout<<"Please Enter Staff's No.:";
		cin>>inNo;
		if(temp.empty() == true){
			printf("There is no Temp Staff!");
			getch();
		}
		else{
			int ord;
			for(ord = 0; ord < temp.size(); ord++){
				if(strcmp(temp[ord].GetNo(),inNo)==0){
					temp.erase(temp.begin()+ord, temp.begin()+ord+1);
					flag = true;
				}
			}
		}
		if(flag == false){
			cout<<"There is not the staff that you describe!"<<endl;
		}
		else{
			cout<<"Done!"<<endl;
		}
		getch();
		break;
	}
	case 'B':case 'b':{
		cin.sync();cin.clear();
		char inNo[20];
		bool flag = false;
		cout<<"Please Enter Staff's No.:";
		cin>>inNo;
		if(admin.empty() == true){
			printf("There is no Administrator!");
			getch();
		}
		else{
			int ord;
			for(ord = 0; ord < admin.size(); ord++){
				if(strcmp(admin[ord].GetNo(),inNo)==0){
					admin.erase(admin.begin()+ord, admin.begin()+ord+1);
					flag = true;
				}
			}
		}
		if(flag == false){
			cout<<"There is not the staff that you describe!"<<endl;
		}
		else{
			cout<<"Done!"<<endl;
		}
		getch();
		break;
	}
	case 'C':case 'c':{
		cin.sync();cin.clear();
		char inNo[20];
		bool flag = false;
		cout<<"Please Enter Staff's No.:";
		cin>>inNo;
		if(teacher.empty() == true){
			printf("There is no Teacher!");
			getch();
		}
		else{
			int ord;
			for(ord = 0; ord < teacher.size(); ord++){
				if(strcmp(teacher[ord].GetNo(),inNo)==0){
					teacher.erase(teacher.begin()+ord, teacher.begin()+ord+1);
					flag = true;
				}
			}
		}
		if(flag == false){
			cout<<"There is not the staff that you describe!"<<endl;
		}
		else{
			cout<<"Done!"<<endl;
		}
		getch();
		break;
	}
	default:
		cin.sync();
		printf("\rPlease Enter Correct Choice (From A To C): ");
		break;
	}
}

void Choose_Edit(){
	char c;
	cout<<"**********Details of the Deployment**********"<<endl;
	cout<<"\tA. Edit A Temp Staff"<<endl;
	cout<<"\tB. Edit A Administrator"<<endl;
	cout<<"\tC. Edit A Teacher"<<endl;
	cout<<"Please Enter Your Choice: ";
	cin>>c;
	switch(c){
	case 'A':case 'a':{
		cin.sync();cin.clear();
		char inNo[20];
		bool flag = false;
		cout<<"Please Enter Staff's No.:";
		cin>>inNo;
		if(temp.empty() == true){
			printf("There is no Temp Staff!");
			getch();
		}
		else{
			int ord;
			for(ord = 0; ord < temp.size(); ord++){
				if(strcmp(temp[ord].GetNo(),inNo)==0){
					cin.sync();cin.clear();
					char Name[40];
					int s;
					Sex_Choose sex;
					unsigned int ServiceYears;
					cout<<"You Will Input the Information of Temporary Staff\nPlease Input the Information According To Prompts:"<<endl;
					cout<<"Name: ";
					gets(Name);
					cout<<"Sex(1. Male  2.Female): ";
					cin>>s; sex = (s==1)? Male : Female;
					cout<<"Service Year(s): ";
					cin>>ServiceYears;
					temp[ord].SetName(Name);temp[ord].SetSex(sex);temp[ord].SetServiceYears(ServiceYears);
					cout<<"The Following Information Will Be Save!\n"<<temp[ord]<<"\nDone!"<<endl;
					getch();
					flag = true;
				}
			}
		}
		if(flag == false){
			cout<<"There is not the staff that you describe!"<<endl;
		}
		else{
			cout<<"Done!"<<endl;
		}
		getch();
		break;
	}
	case 'B':case 'b':{
		cin.sync();cin.clear();
		char inNo[20];
		bool flag = false;
		cout<<"Please Enter Staff's No.:";
		cin>>inNo;
		if(admin.empty() == true){
			printf("There is no Administrator!");
			getch();
		}
		else{
			int ord;
			for(ord = 0; ord < admin.size(); ord++){
				if(strcmp(admin[ord].GetNo(),inNo)==0){
					cin.sync();cin.clear();
					char Name[40];
					int s;
					Sex_Choose sex;
					unsigned int ServiceYears;
					Post_Choose post;
					cout<<"You Will Input the Information of Administrator\nPlease Input the Information According To Prompts:"<<endl;
					cout<<"Name: ";
					gets(Name);
					cout<<"Sex(1. Male  2.Female): ";
					cin>>s; sex = (s==1)? Male : Female;
					cout<<"Service Year(s): ";
					cin>>ServiceYears;
					cout<<"Post(1.Section Member 2.Section Chief 3.Division_Chief ): ";
					cin>>s;
					switch(s){
					case 1:post = Section_Member;break;
					case 2:post = Section_Chief;break;
					case 3:post = Division_Chief;break;
					default: exit(1);break;
					}
					admin[ord].SetName(Name);admin[ord].SetServiceYears(ServiceYears);admin[ord].SetSex(sex);admin[ord].SetPost(post);
					cout<<"The Following Information Will Be Save!\n"<<admin[ord]<<"\nDone!"<<endl;
					getch();
					flag = true;
				}
			}
		}
		if(flag == false){
			cout<<"There is not the staff that you describe!"<<endl;
		}
		else{
			cout<<"Done!"<<endl;
		}
		getch();
		break;
	}
	case 'C':case 'c':{
		cin.sync();cin.clear();
		char inNo[20];
		bool flag = false;
		cout<<"Please Enter Staff's No.:";
		cin>>inNo;
		if(teacher.empty() == true){
			printf("There is no Teacher!");
			getch();
		}
		else{
			int ord;
			for(ord = 0; ord < teacher.size(); ord++){
				if(strcmp(teacher[ord].GetNo(),inNo)==0){
					cin.sync();cin.clear();
					char Name[40];
					int s;
					Sex_Choose sex;
					unsigned int ServiceYears;
					Rank_Choose rank;
					unsigned int hour, master, doctor;
					cout<<"You Will Input the Information of Teacher\nPlease Input the Information According To Prompts:"<<endl;
					cout<<"Name: ";
					gets(Name);
					cout<<"Sex(1. Male  2.Female): ";
					cin>>s; sex = (s==1)? Male : Female;
					cout<<"Service Year(s): ";
					cin>>ServiceYears;
					cout<<"Rank(1.Lecturer 2.Associate Professor 3.Professor 4.Tutor_PHD): ";
					cin>>s;
					switch(s){
					case 1:rank = Lecturer;break;
					case 2:rank = Associate_Professor;break;
					case 3:rank = Professor;break;
					case 4:rank = Tutor_PHD;break;
					default: exit(1);break;
					}
					cout<<"Teaching Hours: ";
					cin>>hour;
					cout<<"Numbers of Master(s): ";
					cin>>master;
					cout<<"Numbers of Doctor(s): ";
					cin>>doctor;
					teacher[ord].SetName(Name);teacher[ord].SetSex(sex);teacher[ord].SetServiceYears(ServiceYears);
					teacher[ord].SetRank(rank);teacher[ord].SetHour(hour);teacher[ord].SetMaster(master);
					teacher[ord].SetDoctor(doctor);
					cout<<"The Following Information Will Be Save!\n"<<teacher[ord]<<"\nDone!"<<endl;
					getch();
					flag = true;
				}
			}
		}
		if(flag == false){
			cout<<"There is not the staff that you describe!"<<endl;
		}
		else{
			cout<<"Done!"<<endl;
		}
		getch();
		break;
	}
	default:
		cin.sync();
		printf("\rPlease Enter Correct Choice (From A To C): ");
		break;
	}
}

void Choose_Save(){
	if(temp.empty() == true){
			freopen("TempStaff_SalaryList.txt","w",stdout);
			printf("There is no Temp Staff!");
			freopen("CON","w",stdout);
		}
	else{
		int ord;
		freopen("TempStaff_SalaryList.txt","w",stdout);
		for(ord = 0; ord < temp.size(); ord++){
			cout<<temp[ord];
			cout<<"\tSalary: "<<temp[ord].GetSalary()<<endl;
		}
		freopen("CON","w",stdout);
	}
	freopen("Administrator_SalaryList.txt","w",stdout);
	if(admin.empty() == true){
		printf("There is no Administrator!");
	}
	else{
		int ord;
		for(ord = 0; ord < admin.size(); ord++){
			cout<<admin[ord];
			cout<<"\tSalary: "<<admin[ord].GetSalary()<<endl;
		}
	}
	freopen("CON", "w", stdout);
	freopen("Teacher_SalaryList.txt","w",stdout);
	if(teacher.empty() == true){
		printf("There is no Teacher!");
	}
	else{
		int ord;
		for(ord = 0; ord < teacher.size(); ord++){
			cout<<teacher[ord];
			cout<<"\tSalary: "<<teacher[ord].GetSalary()<<endl;
		}
	}
	freopen("CON", "w", stdout);
	cout<<"Done!!!"<<endl;
	Choose_Exit();
}

void Choose_Exit(){
	cout<<"Bye-Bye!!!"<<endl;
	getch();
	exit(0);
}
