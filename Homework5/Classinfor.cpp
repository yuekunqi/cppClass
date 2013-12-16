#include "Classinfor.h"
#include <iostream>

using namespace std;

void Show_Courses_name(courses *cs){
	courses *p;
	p = cs;
	cout<<"courses name is ";
	while( p != NULL ){
		cout<<p->cname<<" ";
		p = p -> next;
	}
	cout<<endl;
}

courses* Add_Course(courses *cs,char cname[]){
	courses *s, *csp;
	course *cp;
	csp = cs;
	s = (courses *) malloc (sizeof(courses));
	strcpy(s -> cname, cname);
	cp = (course *) malloc (sizeof (course));
	cp -> next = NULL;
	strcpy(cp -> sname, "Test");
	while(csp -> next != NULL) csp = csp -> next;
	s -> c = cp;
	s -> next = NULL;
	csp -> next = s;
	return s;
}

void Show_Course(courses *cs, char cname[]){
	courses *csp;
	course *cp;
	csp = cs;
	while( strcmp(csp -> cname, cname) != 0 ){
		csp = csp -> next;
	}
	cp = csp -> c -> next;
	printf("\t\t\tList of %s\n",csp -> cname);
	printf("NO.\t\tName\t\tGrade\n");
	while ( cp != NULL ){
		printf("%s\t\t%s\t\t%f\n", cp -> sno, cp -> sname, cp -> grade);
		cp = cp -> next;
	}
}

void Add_Student(courses *cs, char cname[], char sno[], char sname[]){
	courses *csp;
	course *s;
	csp = cs;
	while ( strcmp(csp -> cname, cname) != 0 ){
		csp = csp -> next;
	}
	s = (course *) malloc ( sizeof (course));
	strcpy( s -> sname, sname );
	strcpy(s -> sno , sno);
	s -> grade = 0.0;
	//printf("%s",csp->c->sname);
	//s -> next = csp -> c;
	csp -> c = s;
}

void Delete_Student(courses *cs, char cname[], char sname[]){
	courses *csp;
	course *c;
	csp = cs;
	while ( strcmp(csp -> cname, cname) != 0 ){
		csp = csp -> next;
	}
	c = csp -> c;
	while ( strcmp(c -> next -> sname , sname) != 0 ){
		c = c -> next;
	}
	c -> next = c -> next -> next;
}

void Input_Grades(course *cs, char cname[], char sno[]){

}

void Show_List(){

}
