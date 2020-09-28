#include <stdio.h>

typedef struct studentTag{
	char name[20];
	int age;
	double gpa;
} student;

typedef struct studentTag2{
	char name[20];
	int age;
	double gpa;
} student2;

int main (){
	student s={"kim", 20, 4.3};
	printf("%s\t%d\t%f\n", s.name , s.age, s.gpa);
	student2 ss={"dl", 34, 4.3};
	printf("%d", ss.age);
}
