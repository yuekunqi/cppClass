typedef struct course {
	char sno[20];
	char sname[20];
	float grade;
	course *next;
};

typedef struct courses {
	char cname[40];
	course *c;
	courses *next;
};

courses* Create_ClassInfor(char cname[]);
void Add_Course(courses *cs,char cname[]);
void Show_Courses_name(courses *cs);
void Add_Student(courses *cs, char cname[], char sno[], char sname[]);
void Show_Course(courses *cs, char cname[]);
void Delete_Student(courses *cs, char cname[], char sname[]);
course* Input_Grades(courses *cs, char cname[], char sno[], float grade);
void Show_List();
