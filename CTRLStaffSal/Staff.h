#include <string.h>
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <vector>
#include <conio.h>
#define TempSalary 400//define the salary of CTempStaff
#define Base_Salary 1250//define the base Salary
#define Base_ServiceYears 5.5//define the base number of ServiceYears
#define Post_Salary_Section_Chief 350//define the post Salary of Section_Chief
#define Post_Salary_Division_Chief 550//define the post Salary of Division_Chief
#define Class_Salary_Lecturer 45
#define Class_Salary_Professor_A 150
#define Class_Salary_Tutor_PHD 200
#define Subsidy_Master 320
#define Subsidy_Doctor 750
using namespace std;
enum Sex_Choose {
	Male, Female
};
enum Post_Choose{
	Section_Member, Section_Chief, Division_Chief
};
enum Rank_Choose{
	Lecturer, Associate_Professor, Professor, Tutor_PHD
};

void Show_List();
void Choose_Show();
void Choose_Add();
void Choose_Del();
void Choose_Edit();
void Choose_Save();
void Choose_Exit();

class CStaff {
private:
	char No[20];
	char Name[20];
	Sex_Choose sex;
	unsigned int ServiceYears;
public:
	CStaff(char* n, char *na, Sex_Choose s,unsigned int ser);
	void SetNo(char* n);
	char* GetNo();
	void SetName(char* na);
	char* GetName();
	void SetSex(Sex_Choose se);
	Sex_Choose GetSex();
	void SetServiceYears(unsigned int ser);
	unsigned int GetServiceYears();
	float GetSalary();
};

class CTempStaff :public CStaff{
	
public:
	CTempStaff(char* n, char *na, Sex_Choose s,unsigned int ser):CStaff(n,na, s, ser){

	}
	float GetSalary();
	friend ostream& operator <<(ostream& out, CTempStaff& ct){
		cout<<"No."<<ct.GetNo()<<"\tName: "<<ct.GetName()<<"\tSex: "<<ct.GetSex()<<"\tServiceYears: "<<ct.GetServiceYears()<<"\tPerson Type: Temp Staff";
		return out;
	}
};

class CAdministrator :public CStaff{
private:
	Post_Choose post;
public:
	CAdministrator(char* n, char *na, Sex_Choose s,unsigned int ser, Post_Choose po):CStaff(n,na, s, ser){
		post = po;
	}
	float GetSalary();
	Post_Choose GetPost();
	void SetPost(Post_Choose p);
	friend ostream& operator <<(ostream& out, CAdministrator& ca){
		cout<<"No."<<ca.GetNo()<<"\tName: "<<ca.GetName()<<"\tSex: "<<ca.GetSex()<<"\tService Years: "<<ca.GetServiceYears()<<"\nPost: "<<ca.GetPost()<<"\tPerson Type:Administrator";
		return out;
	}
};

class CTeacher :public CStaff{
private:
	Rank_Choose rank;
	unsigned int hour;
	unsigned int master;
	unsigned int doctor;
public:
	CTeacher(char* n, char *na, Sex_Choose s,unsigned int ser, Rank_Choose ra, unsigned int h, unsigned int ma = 0, unsigned int doc = 0):CStaff(n,na, s, ser){
		rank = ra;
		hour = h;
		master = ma;
		doctor = doc;
	}
	float GetSalary();
	Rank_Choose GetRank();
	unsigned int GetHour();
	unsigned int GetMaster();
	unsigned int GetDoctor();
	void SetRank(Rank_Choose r);
	void SetHour(unsigned int h);
	void SetMaster(unsigned int m);
	void SetDoctor(unsigned int d);
	friend ostream& operator <<(ostream& out, CTeacher& ct){
		cout<<"No."<<ct.GetNo()<<"\tName: "<<ct.GetName()<<"\tSex: "<<ct.GetSex()<<"\tService Years: "<<ct.GetServiceYears()<<"\nRank: "<<ct.GetRank()<<"\tTeaching Hours: "<<ct.GetHour()<<"\nNumbers of Master(s): "<<ct.GetMaster()<<"\tNumbers of Doctor(s): "<<ct.GetDoctor()<<"\tPerson Type: Teacher";
		return out;
	}
};

