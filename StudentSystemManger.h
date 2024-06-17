#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

//info of student

typedef struct _Student
{
	int stuNum;
	char name[20];
	int score;
}Student;

//info of node

typedef struct _Node
{
	Student student;
	struct _Node* next;
}Node;

void welcome();

void inputStudent(Node* head);

void printStudent(Node* head);

void countStudent(Node* head);

void searchStudent(Node* head);

void saveStudent(Node* head);

void loadStudent(Node* head);

void modifyStudent(Node* head);

void deleteStudent(Node* head);

void sortStudent(Node* head);