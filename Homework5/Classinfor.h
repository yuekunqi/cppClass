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

void Show_Courses_name(courses *cs);
courses* Add_Course(courses *cs,char cname[]);
void Show_Course(courses *cs, char cname[]);
void Add_Student(courses *cs, char cname[], char sno[], char sname[]);
void Delete_Student(courses *cs, char cname[], char sname[]);
void Input_Grades(course *cs, char cname[], char sno[]);
void Show_List();
