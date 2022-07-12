#define _CRT_SECURE_NO_WARNINGS

#include "Contact.h"

//初始化
void InitContact(PhoneBook* pc)
{
	pc->num = 0;
	memset(pc->data, 0, sizeof(pc->data));
}

//打印
void PrintContact(PhoneBook* pc)
{
	int i = 0;
	//表头
	printf("%-20s\t%-5s\t%-5s\t%-12s\t%-20s\n", "名字", "性别", "年龄", "电话号码", "地址");
	for (i = 0; i < pc->num; i++)
	{
		printf("%-20s\t%-5s\t%-5d\t%-12s\t%-20s\n", pc->data[i].name, pc->data[i].sex, pc->data[i].age, pc->data[i].tele, pc->data[i].add);
	}
}

//增加联系人
void AddContact(PhoneBook* pc)
{
	if (pc->num == MAX_CONTACT)
	{
		printf("通讯录已满,无法添加\n");
		return;
	}
	printf("请输入姓名：");
	scanf("%s", &pc->data[pc->num].name);
	printf("请输入性别：");
	scanf("%s", &pc->data[pc->num].sex);
	printf("请输入年龄：");
	scanf("%d", &pc->data[pc->num].age);
	printf("请输入电话号码：");
	scanf("%s", &pc->data[pc->num].tele);
	printf("请输入地址：");
	scanf("%s", &pc->data[pc->num].add);
	pc->num++;
	printf("添加联系人成功！\n");
}

size_t FindNum(PhoneBook* pc, char name[MAX_NAME])
{
	for (int i = 0; i < pc->num; i++)
	{
		if (strcmp(pc->data[i].name, name) == 0)
		{
			return i;
		}
	}
	return -1;
}

//删除联系人
void DelContact(PhoneBook* pc)
{
	if (pc->num == 0)
	{
		printf("通讯录为空\n");
		return;
	}
	char name[MAX_NAME] = { 0 };
	printf("请输入要删除人的姓名：");
	scanf("%s", &name);
	int n = FindNum(pc, name);
	if (n == -1)
	{
		printf("查无此人\n");
	}
	else
	{
		int i = 0;
		for (i = n; i < pc->num - 1; i++)
		{
			pc->data[i] = pc->data[i + 1];
		}
		pc->num--;
		printf("删除成功\n");
	}
}

//查找联系人
void FindContact(PhoneBook* pc)
{
	char name[MAX_NAME] = { 0 };
	printf("请输入联系人姓名：");
	scanf("%s", &name);
	int i = FindNum(pc, name);
	printf("%-20s\t%-5s\t%-5d\t%-12s\t%-20s\n", pc->data[i].name, pc->data[i].sex, pc->data[i].age, pc->data[i].tele, pc->data[i].add);
}

//修改联系人
void RevContact(PhoneBook* pc)
{
	printf("请输入要修改联系人姓名：");
	char name[MAX_NAME] = { 0 };
	scanf("%s", &name);
	int n = FindNum(pc, name);
	if (n == -1)
	{
		printf("您要修改的联系人不存在");
		return;
	}
	else
	{
		printf("请输入姓名：");
		scanf("%s", &pc->data[n].name);
		printf("请输入性别：");
		scanf("%s", &pc->data[n].sex);
		printf("请输入年龄：");
		scanf("%d", &pc->data[n].age);
		printf("请输入电话号码：");
		scanf("%s", &pc->data[n].tele);
		printf("请输入地址：");
		scanf("%s", &pc->data[n].add);

		printf("修改联系人成功！\n");
	}
}



void CmpByName(void* e1, void* e2)
{
	assert(e1 && e2);
	return strcmp(*(Contact*)e1, *(Contact*)e2);
}

//排序
void SortContact(PhoneBook* pc)
{
	assert(pc);
	qsort(pc->data, pc->num, sizeof(pc->data[0]), CmpByName);
	printf("排序成功！");
}