#include <stdio.h>
#include <stdlib.h>
#include "list.h"

struct Student
{
	int num;
	int english;
	int math;
	struct list_head list;
};
struct list_head stu_list;
struct Student stu1,stu2,stu3;
struct list_head *pos;
struct Student *tmp;

int main(int argc, const char *argv[])
{
	INIT_LIST_HEAD(&stu_list);

	stu1.num = 1;
	stu1.english = 90;
	stu1.math = 98;
	list_add_tail(&(stu1.list),&stu_list);

	stu2.num = 2;
	stu2.english = 92;
	stu2.math = 91;
	list_add_tail(&(stu2.list),&stu_list);

	stu3.num = 3;
	stu3.english = 94;
	stu3.math = 95;
	list_add_tail(&(stu3.list),&stu_list);

	list_for_each(pos,&stu_list)
	{
		tmp = list_entry(pos, struct Student,list);
		printf("NO: %d, english: %d, math: %d \n", tmp->num, tmp->english, tmp->math);
	}
	
	return 0;
}
