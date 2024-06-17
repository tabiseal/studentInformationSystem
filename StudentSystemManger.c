#include "StudentSystemManger.h"

int main()
{
	//create node
	Node* head = (Node*)malloc(sizeof(Node));
	head->next = NULL;
	loadStudent(head);

	while (1)
	{
		welcome();
		char c = _getch();
		switch (c)
		{
		case '1'://input
			inputStudent(head);
			break;
		case '2'://print
			printStudent(head);
			break;
		case '3'://count
			countStudent(head);
			break;
		case '4'://search
			searchStudent(head);
			break;
		case '5'://modify
			modifyStudent(head);
			break;
		case '6'://delete
			deleteStudent(head);
			break;
		case '7'://sort
			sortStudent(head);
			break;
		case '8'://exit
			system("cls");
			printf("Bye Bye\n");
			exit(0);
			break;
		default:
			printf("input again\n");
			break;
		}
	}


	return 0;
}

void welcome()
{
	printf("*****************************************\n");
	printf("*\tStudentSystemManger\t\t*\n");
	printf("*****************************************\n");
	printf("*\tSelectFeatureList\t\t*\n");
	printf("*****************************************\n");
	printf("*\t1.Input info of student\t\t*\n");
	printf("*\t2.Print info of student\t\t*\n");
	printf("*\t3.Count num of student\t\t*\n");
	printf("*\t4.Search for student info\t*\n");
	printf("*\t5.Modify student info\t\t*\n");
	printf("*\t6.Delete student info\t\t*\n");
	printf("*\t7.Sort by grade\t\t\t*\n");
	printf("*\t8.Exit\t\t\t\t*\n");
		
}

void inputStudent(Node* head)
{
	Node* fresh = (Node*)malloc(sizeof(Node));
	fresh->next = NULL;
	printf("input student number,name,score\n");
	scanf("%d%s%d", &fresh->student.stuNum, fresh->student.name, &fresh->student.score);
	Node* move = head;
	while (move->next != NULL)
	{
		move = move->next;
	}
	//put the stu Info in the back
	move->next = fresh;

	saveStudent(head);
	//pause the program
	system("pause");

	//clear console
	system("cls");
}


void printStudent(Node* head)
{
	Node* move = head->next;
	while (move != NULL)
	{
		printf("Student Number:%d Student Name:%s score%d\n", move->student.stuNum, move->student.name, move->student.score);
		move = move->next;
	}
	//pause the program
	system("pause");

	//clear console
	system("cls");

}

void countStudent(Node* head)
{
	int count = 0;
	Node* move = head->next;
	while (move != NULL)
	{
		count++;
		move = move->next;
	}
	printf("The number of Student is:%d\n", count);

	//pause the program
	system("pause");

	//clear console
	system("cls");
}

void searchStudent(Node* head)
{
	printf("input the Student ID to search for:");
	int stuNum=0;
	scanf("%d", &stuNum);
	Node* move = head->next;
	while (move != NULL)
	{
		if (stuNum == move->student.stuNum)
		{
			printf("Student Number:%d Student Name:%s score%d\n", move->student.stuNum, move->student.name, move->student.score);
			//pause the program
			system("pause");

			//clear console
			system("cls");
			return;
		}
		move = move->next;
	}
	printf("No such student found\n");

	//pause the program
	system("pause");

	//clear console
	system("cls");
}

void saveStudent(Node* head)
{
	FILE* file = fopen("./stu.info", "w");
	Node* move = head->next;
	while (move != NULL)
	{
		if (fwrite(&move->student, sizeof(Student), 1, file) != 1)
		{
			printf("input failure\n");
			return;
		}
		move = move->next;
	}
	fclose(file);
}

void loadStudent(Node* head)
{
	//open file
	FILE* file = fopen("./stu.info", "r");
	if (file == NULL)
	{
		printf("no stu info file\n");
		return;
	}
	//creat a node
	Node* fresh = malloc(sizeof(Node));
	fresh->next = NULL;
	Node* move = head;
	while (fread(&fresh->student, sizeof(Student), 1, file) == 1)
	{
		move->next = fresh;
		move = fresh;
		fresh = (Node*)malloc(sizeof(Node));
		fresh->next = NULL;
	}
	free(fresh);
	fclose(file);
	printf("read success\n");
}

void modifyStudent(Node* head)
{
	printf("input the student ID\n");
	int stuNum = 0;
	scanf("%d", &stuNum);
	Node* move = head->next;
	while (move != NULL)
	{
		if (move->student.stuNum == stuNum)
		{
			printf("input name,score\n");
			scanf("%s%d", move->student.name, &move->student.score);
			saveStudent(head);
			printf("modify successfully\n");
			//pause the program
			system("pause");

			//clear console
			system("cls");
		}
		move = move->next;
	}
	printf("no such stu\n");
	//pause the program
	system("pause");

	//clear console
	system("cls");
}

void deleteStudent(Node* head)
{
	printf("input delete stu ID\n");
	int stuNum = 0;
	scanf("%d", &stuNum);

	Node* move = head;
	while (move->next != NULL)
	{
		if (move->next->student.stuNum == stuNum)
		{
			Node* tmp = move->next;
			move->next = move->next->next;
			free(tmp);
			tmp = NULL;
			saveStudent(head);
			printf("delete successfully\n");
			//pause the program
			system("pause");

			//clear console
			system("cls");
			return;

		}
		move = move->next;
	}
	printf("no such stu\n");
	//pause the program
	system("pause");

	//clear console
	system("cls");
}

void sortStudent(Node* head)
{
	Node* save = NULL;
	Node* move = NULL;
	
	for (Node* turn = head->next; turn->next != NULL; turn = turn->next)
	{
		for (move = head->next; move->next != save; move = move->next)
		{
			if (move->student.score > move->next->student.score)
			{
				Student tmp = move->student;
				move->student = move->next->student;
				move->next->student = tmp;
			}
		}
		save = move;
	}
	printStudent(head);
}
