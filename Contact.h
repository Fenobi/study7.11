#pragma once

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <memory.h>

#define MAX_NAME 20
#define MAX_SEX 5
#define MAX_TELE 12
#define MAX_ADD 30

#define MAX_CONTACT 200

typedef struct Contact
{
	char name[MAX_NAME];
	char sex[MAX_SEX];
	int age;
	char tele[MAX_TELE];
	char add[MAX_ADD];
}Contact;

typedef struct PhoneBook
{
	Contact data[MAX_CONTACT];
	int num;
}PhoneBook;


//初始化
void InitContact(PhoneBook* pc);

//打印
void PrintContact(PhoneBook* pc);

//增加联系人
void AddContact(PhoneBook* pc);

//删除联系人
void DelContact(PhoneBook* pc);

//查找联系人
void FindContact(PhoneBook* pc);

//排序
void SortContact(PhoneBook* pc);