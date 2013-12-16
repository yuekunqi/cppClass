#include "courses.h"
#include <iostream>
using namespace std;

courses* Create_ClassInfor(char cname[]){
	courses *h, *f;
	course *cp;
	h = (courses *) malloc (sizeof(courses));
	f = (courses *) malloc (sizeof(courses));
	cp = (course *) malloc (sizeof(course));
	strcpy(f -> cname, cname);
	cp -> next = NULL;
	f -> next = NULL;
	h -> c = NULL;
	f -> c = cp;
	h -> next = f;
	printf("Create Courses Information Successfully!!!\nCourse: %s Added Successfully!!!\n",cname);
	return h;
}

void Add_Course(courses *cs,char cname[]){
	courses *csp, *s;
	course *cp;
	s = (courses *) malloc (sizeof(courses));
	cp = (course *) malloc (sizeof(course));
	cp -> next = NULL;
	csp = cs;
	while(csp -> next != NULL){
		csp = csp -> next;
	}
	strcpy(s -> cname, cname);
	s -> c = cp;
	s -> next = NULL;
	csp -> next = s;
	printf("Course: %s Added Successfully!!!\n",cname);
}

void Show_Courses_name(courses *cs){
	courses *csp;
	csp = cs -> next;
	printf("****Existed Course(s) List****\n");
	while(csp != NULL){
		printf("             %s\n",csp -> cname);
		csp = csp -> next;
	}
	printf("****End of Existed Course(s) List****\n\n");
}

void Add_Student(courses *cs, char cname[], char sno[], char sname[]){
	courses *csp;
	course *cp, *s;
	csp = cs -> next;
	s = (course *) malloc (sizeof(course));
	s -> grade = 0.0;
	strcpy(s -> sno, sno);
	strcpy(s -> sname, sname);
	while (strcmp(csp -> cname, cname)!=0 && csp->next!= NULL) {
		csp = csp -> next;
	}
	if(csp == NULL){
		printf("Course: %s Does NOT Exist!!!\n", cname);
		return;
	}
	cp = csp -> c;
	while(cp->next != NULL) {
		cp = cp -> next;
	}
	s -> next = NULL;
	cp -> next = s;
	printf("Student: %s Added Successfully!!!\n",sname);
}

void Show_Course(courses *cs, char cname[]){
	courses *csp;
	course *cp;
	csp = cs -> next;
	while (strcmp(csp -> cname, cname)!=0&&csp->next!=NULL) {
		csp = csp -> next;
	}
	if(csp == NULL){
		printf("Course: %s Does NOT Exist!!!\n", cname);
		return;
	}
	cp = csp -> c -> next;
	printf("****Student(s) List Of %s****\n", cname);
	printf("NO.\t\tName\t\tGrade\n");
	while(cp != NULL){
		printf("%s\t\t%s\t\t%f\n", cp -> sno, cp -> sname, cp -> grade);
		cp = cp -> next;
	}
	printf("****End Of Student(s) List Of %s****\n", cname);
}

void Delete_Student(courses *cs, char cname[], char sname[]){
	courses *csp;
	course *cp;
	csp = cs -> next;
	while (strcmp(csp -> cname, cname)!=0 && csp != NULL) {
		csp = csp -> next;
	}
	if(csp == NULL){
		printf("Course: %s Does NOT Exist!!!\n", cname);
		return;
	}
	cp = csp -> c;
	while(strcmp(cp -> next -> sname, sname)!=0 && cp != NULL) {
		cp = cp -> next;
	}
	if(cp == NULL){
		printf("Student: %s Does NOT Exist!!!\n", sname);
		return;
	}
	cp->next=cp->next->next;
	printf("Student %s has been deleted!!!\n",sname);
}

course* Input_Grades(courses *cs, char cname[], char sno[], float grade){
	courses *csp;
	course *cp;
	csp = cs -> next;
	while (strcmp(csp -> cname, cname)!=0 && csp != NULL) {
		csp = csp -> next;
	}
	if(csp == NULL){
		printf("Course: %s Does NOT Exist!!!\n", cname);
		return NULL;
	}
	cp = csp -> c;
	while(strcmp(cp -> sno, sno)!=0 && cp != NULL) {
		cp = cp -> next;
	}
	if(cp == NULL){
		printf("Student: %s Does NOT Exist!!!\n", sno);
		return NULL;
	}
	cp->grade = grade;
	return cp;
}

void Show_List(){
	printf("****Course Information Control Center****\n");
	printf("<1>. Show Course Name(s)\n");
	printf("<2>. Add A Course\n");
	printf("<3>. Show Course Information\n");
	printf("<4>. Add A Student\n");
	printf("<5>. Delete A Student\n");
	printf("<6>. Input Grade(s)\n");
	printf("<7>. Exit\n");
	printf("Please Select An Option:");
}
