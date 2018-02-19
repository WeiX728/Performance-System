#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

/*学生信息结构体*/
typedef struct Node
{
	char Name[10];		//学生姓名
	char ID[15];		//学生学号
	int Score[3];	//三科成绩（数学、英语、数据结构）
	float Ave_Sco;
	struct Node *next;
}Lnode;

void Display();   /*界面显示函数*/
void GetScore(Lnode *&h);  /*成绩录入函数*/
void PrintScore(Lnode *h);  /*成绩打印函数*/
void ModifyScore(Lnode *h);  /*成绩修改函数*/
void FindInf(Lnode *h);    /*查找信息*/
void Delete(Lnode *h);   /*删除函数*/
void Quit(Lnode *h);    /*退出函数*/
void SaveInf(Lnode *h);
void LoadInf(Lnode *h);

/*初始化链表*/
void InitList(Lnode *&head)  
{
	head = (Lnode *)malloc(sizeof(Lnode));
	if (head == NULL)
	{
		printf("error!");
		exit(1);
	}
	head->next = NULL;    //使头节点指针域为空
}

int main()
{
	Lnode *ScoreList;    //建立成绩链表，所有学生信息存放在此链表
	int Function;
	char flag; 
	int t = 0;
	InitList(ScoreList);
	LoadInf(ScoreList);

	while (1)
	{
		Display();
		printf("请选择操作： ");
		scanf("%d", &Function);
		switch (Function)
		{
		case 1: while (1)
		{
			GetScore(ScoreList);
			printf("是否继续输入 （Y/N）");
			scanf("%s", &flag);
			if (flag == 'N' || flag == 'n')break;
		} 	system("cls"); break;
		case 2: PrintScore(ScoreList);	_getch(); system("cls"); break;
		case 3: ModifyScore(ScoreList);	system("cls"); break;
		case 4: FindInf(ScoreList); _getch(); system("cls"); break;
		case 5: Delete(ScoreList); _getch(); system("cls"); break;
		case 6: Quit(ScoreList); break;

		default: printf("Error！！！ 请重新输入：");
			break;
		} //switch结束
	}
	
	return 0;
}

/*系统界面显示*/
void Display()
{
	printf("\t\t**********************************************\n");
	printf("\t\t*************欢迎使用成绩管理系统*************\n");
	printf("\t\t**********************************************\n");
	printf("\t\t\t\t1、录入成绩\n");
	printf("\t\t\t\t2、打印成绩\n");
	printf("\t\t\t\t3、修改成绩\n");
	printf("\t\t\t\t4、查找学生信息\n");
	printf("\t\t\t\t5、删除学生信息\n");
	printf("\t\t\t\t6、退出系统\n");
	printf("\n\n\n\n\n\n");
}

/*成绩录入*/
void GetScore(Lnode *&h)
{
	Lnode *p, *q = h;
	char name[10], id[15];
	int Math, English, Datastruct;
	p = (Lnode *)malloc(sizeof(Lnode));		//为学生信息申请节点
	printf("请依次输入学生信息：\n");
	printf("姓名 学号 数学 英语 数据结构\n");
	scanf("%s %s %d %d %d", &name, &id, &Math, &English, &Datastruct);

	for (; q->next != NULL; q = q->next){;}    //移动到尾节点
	
	strcpy(p->Name, name);
	strcpy(p->ID, id);
	p->Score[0] = Math;
	p->Score[1] = English;
	p->Score[2] = Datastruct;
	p->Ave_Sco = ((float)((p->Score[0] + p->Score[1] + p->Score[2]) - 150)) / 30;

	p->next = NULL;
	q->next = p;
	q = p;
}

/*成绩打印*/
void PrintScore(Lnode *h)
{

	Lnode *p = h->next;
	printf("%-14s%-8s%-8s%-8s%-8s%-8s\n","排名", "学号", "姓名", "数学", "英语", "数据结构", "平均绩点");
	while (p != NULL)
	{
		printf("%-14s%-8s%-8d%-8d%-8d%.2f\n", p->ID, p->Name, p->Score[0], p->Score[1], p->Score[2], p->Ave_Sco);
		p = p->next;
	}
}

/*成绩修改*/
void ModifyScore(Lnode *h)
{
	Lnode *p = h->next;
	char name[10], id[15];
	int Math, English, Datastruct;
	printf("请输入学生姓名：");
	scanf("%s", name);
	printf("请输入学生学号：");
	scanf("%s", id);

	while (p)
	{
		if (strcmp(p->Name, name)==0 && strcmp(p->ID, id)==0)
		{
			printf("当前学生信息:\n");
			printf("%-14s%-8s%-8s%-8s%-8s\n", "学号", "姓名", "数学", "英语", "数据结构");
			printf("%-14s%-8s%-8d%-8d%-8d\n", p->ID, p->Name, p->Score[0], p->Score[1], p->Score[2]);
			printf("请输入更正后的数学成绩：");
			scanf("%d", &Math);
			printf("请输入更正后的英语成绩：");
			scanf("%d", &English);
			printf("请输入更正后的数据结构成绩：");
			scanf("%d", &Datastruct);
			p->Score[0] = Math;
			p->Score[1] = English;
			p->Score[2] = Datastruct;
			break;
		}
		else
		{
			p = p->next;
		}
	}//while循环结束
}

/*信息查找*/
void FindInf(Lnode *h)
{
	Lnode *p = h->next;
	char name[10], id[15];
	printf("请输入学生姓名：");
	scanf("%s", name);
	printf("请输入学生学号：");
	scanf("%s", id);

	while (p)
	{
		if (strcmp(p->Name, name) == 0 && strcmp(p->ID, id) == 0)
		{
			printf("当前学生信息:\n");
			printf("%-14s%-8s%-8s%-8s%-8s\n", "学号", "姓名", "数学", "英语", "数据结构");
			printf("%-14s%-8s%-8d%-8d%-8d\n", p->ID, p->Name, p->Score[0], p->Score[1], p->Score[2]);
			break;
		}
		else
		{
			p = p->next;
		}
	}//while循环结束
}

/*删除*/
void Delete(Lnode *h)
{
	Lnode *p = h, *q;
	q = p->next;
	char name[10], id[15];
	printf("请输入学生姓名：");
	scanf("%s", name);
	printf("请输入学生学号：");
	scanf("%s", id);

	while (q)
	{
		if (strcmp(q->Name, name) == 0 && strcmp(q->ID, id) == 0)
		{
			p->next = q->next;
			free(q);    //删除p节点		
			printf("删除成功\n");
			break;
		}
		else
		{
			p = p->next;
			q = q->next;
		}
	}//while循环结束
}

/*退出系统*/
void Quit(Lnode *h)
{
	SaveInf(h);    //退出时保存信息
	exit(0);
}

/*打开文件*/
void LoadInf(Lnode *h)
{
	Lnode *p = h;
	Lnode *q;   //临时变量 用于保存从文件中读取的信息
	FILE* file = fopen("./Information.dat", "rb");
	if (!file)
	{
		printf("文件打开失败！");
		return ;
	}

	/*
		使用feof判断文件是否为结束要注意的问题：
			当读取文件结束时，feof函数不会立即设置标志符为-1，而是
			需要再读取一次后，才会设置。所以要先读一次。
	*/
	q = (Lnode *)malloc(sizeof(Lnode));
	fread(q, sizeof(Lnode), 1, file);
	while (!feof(file))    //一直读到文件末尾
	{
		p->next = q;
		p = q;
		q = (Lnode *)malloc(sizeof(Lnode));
		fread(q, sizeof(Lnode), 1, file);
	} //while循环结束

	p->next = NULL;
	fclose(file);
}

/*保存信息到文件中*/
void SaveInf(Lnode *h)
{
	Lnode *p = h->next;
	int flag;
	FILE* file = fopen("./Information.dat", "wb");
	if (!file)
	{
		printf("文件打开失败！");
		return;
	}
	while (p != NULL)
	{
		flag = fwrite(p, sizeof(Lnode), 1, file);   //将p的内容写到文件中
		if (flag != 1)
		{
			break;
		}
		p = p->next;
	}
	fclose(file);
}

