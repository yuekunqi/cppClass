#include <malloc.h>
#include <iostream>
#include "Classinfor.h"

using namespace std;


int main(){
	courses *list;
	list = (courses*) malloc(sizeof(courses));
	list -> next = (courses*) malloc(sizeof(courses));
	strcpy(list -> next -> cname, "C++");
	list -> next -> next = NULL;
	list = Add_Course(list, "Java");
	list = Add_Course(list, "PHP");
	list = Add_Course(list, "PHP");
	list = Add_Course(list, "PHP");
	Show_Courses_name(list);
	//Add_Student(list, "C++", "90014", "º«·ÉÓî");
	//Add_Student(list, "C++", "690014", "Colin.H");
	//Show_Course(list, "C++");
}