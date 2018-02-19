#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

/*ѧ����Ϣ�ṹ��*/
typedef struct Node
{
	char Name[10];		//ѧ������
	char ID[15];		//ѧ��ѧ��
	int Score[3];	//���Ƴɼ�����ѧ��Ӣ����ݽṹ��
	float Ave_Sco;
	struct Node *next;
}Lnode;

void Display();   /*������ʾ����*/
void GetScore(Lnode *&h);  /*�ɼ�¼�뺯��*/
void PrintScore(Lnode *h);  /*�ɼ���ӡ����*/
void ModifyScore(Lnode *h);  /*�ɼ��޸ĺ���*/
void FindInf(Lnode *h);    /*������Ϣ*/
void Delete(Lnode *h);   /*ɾ������*/
void Quit(Lnode *h);    /*�˳�����*/
void SaveInf(Lnode *h);
void LoadInf(Lnode *h);

/*��ʼ������*/
void InitList(Lnode *&head)  
{
	head = (Lnode *)malloc(sizeof(Lnode));
	if (head == NULL)
	{
		printf("error!");
		exit(1);
	}
	head->next = NULL;    //ʹͷ�ڵ�ָ����Ϊ��
}

int main()
{
	Lnode *ScoreList;    //�����ɼ���������ѧ����Ϣ����ڴ�����
	int Function;
	char flag; 
	int t = 0;
	InitList(ScoreList);
	LoadInf(ScoreList);

	while (1)
	{
		Display();
		printf("��ѡ������� ");
		scanf("%d", &Function);
		switch (Function)
		{
		case 1: while (1)
		{
			GetScore(ScoreList);
			printf("�Ƿ�������� ��Y/N��");
			scanf("%s", &flag);
			if (flag == 'N' || flag == 'n')break;
		} 	system("cls"); break;
		case 2: PrintScore(ScoreList);	_getch(); system("cls"); break;
		case 3: ModifyScore(ScoreList);	system("cls"); break;
		case 4: FindInf(ScoreList); _getch(); system("cls"); break;
		case 5: Delete(ScoreList); _getch(); system("cls"); break;
		case 6: Quit(ScoreList); break;

		default: printf("Error������ ���������룺");
			break;
		} //switch����
	}
	
	return 0;
}

/*ϵͳ������ʾ*/
void Display()
{
	printf("\t\t**********************************************\n");
	printf("\t\t*************��ӭʹ�óɼ�����ϵͳ*************\n");
	printf("\t\t**********************************************\n");
	printf("\t\t\t\t1��¼��ɼ�\n");
	printf("\t\t\t\t2����ӡ�ɼ�\n");
	printf("\t\t\t\t3���޸ĳɼ�\n");
	printf("\t\t\t\t4������ѧ����Ϣ\n");
	printf("\t\t\t\t5��ɾ��ѧ����Ϣ\n");
	printf("\t\t\t\t6���˳�ϵͳ\n");
	printf("\n\n\n\n\n\n");
}

/*�ɼ�¼��*/
void GetScore(Lnode *&h)
{
	Lnode *p, *q = h;
	char name[10], id[15];
	int Math, English, Datastruct;
	p = (Lnode *)malloc(sizeof(Lnode));		//Ϊѧ����Ϣ����ڵ�
	printf("����������ѧ����Ϣ��\n");
	printf("���� ѧ�� ��ѧ Ӣ�� ���ݽṹ\n");
	scanf("%s %s %d %d %d", &name, &id, &Math, &English, &Datastruct);

	for (; q->next != NULL; q = q->next){;}    //�ƶ���β�ڵ�
	
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

/*�ɼ���ӡ*/
void PrintScore(Lnode *h)
{

	Lnode *p = h->next;
	printf("%-14s%-8s%-8s%-8s%-8s%-8s\n","����", "ѧ��", "����", "��ѧ", "Ӣ��", "���ݽṹ", "ƽ������");
	while (p != NULL)
	{
		printf("%-14s%-8s%-8d%-8d%-8d%.2f\n", p->ID, p->Name, p->Score[0], p->Score[1], p->Score[2], p->Ave_Sco);
		p = p->next;
	}
}

/*�ɼ��޸�*/
void ModifyScore(Lnode *h)
{
	Lnode *p = h->next;
	char name[10], id[15];
	int Math, English, Datastruct;
	printf("������ѧ��������");
	scanf("%s", name);
	printf("������ѧ��ѧ�ţ�");
	scanf("%s", id);

	while (p)
	{
		if (strcmp(p->Name, name)==0 && strcmp(p->ID, id)==0)
		{
			printf("��ǰѧ����Ϣ:\n");
			printf("%-14s%-8s%-8s%-8s%-8s\n", "ѧ��", "����", "��ѧ", "Ӣ��", "���ݽṹ");
			printf("%-14s%-8s%-8d%-8d%-8d\n", p->ID, p->Name, p->Score[0], p->Score[1], p->Score[2]);
			printf("��������������ѧ�ɼ���");
			scanf("%d", &Math);
			printf("������������Ӣ��ɼ���");
			scanf("%d", &English);
			printf("���������������ݽṹ�ɼ���");
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
	}//whileѭ������
}

/*��Ϣ����*/
void FindInf(Lnode *h)
{
	Lnode *p = h->next;
	char name[10], id[15];
	printf("������ѧ��������");
	scanf("%s", name);
	printf("������ѧ��ѧ�ţ�");
	scanf("%s", id);

	while (p)
	{
		if (strcmp(p->Name, name) == 0 && strcmp(p->ID, id) == 0)
		{
			printf("��ǰѧ����Ϣ:\n");
			printf("%-14s%-8s%-8s%-8s%-8s\n", "ѧ��", "����", "��ѧ", "Ӣ��", "���ݽṹ");
			printf("%-14s%-8s%-8d%-8d%-8d\n", p->ID, p->Name, p->Score[0], p->Score[1], p->Score[2]);
			break;
		}
		else
		{
			p = p->next;
		}
	}//whileѭ������
}

/*ɾ��*/
void Delete(Lnode *h)
{
	Lnode *p = h, *q;
	q = p->next;
	char name[10], id[15];
	printf("������ѧ��������");
	scanf("%s", name);
	printf("������ѧ��ѧ�ţ�");
	scanf("%s", id);

	while (q)
	{
		if (strcmp(q->Name, name) == 0 && strcmp(q->ID, id) == 0)
		{
			p->next = q->next;
			free(q);    //ɾ��p�ڵ�		
			printf("ɾ���ɹ�\n");
			break;
		}
		else
		{
			p = p->next;
			q = q->next;
		}
	}//whileѭ������
}

/*�˳�ϵͳ*/
void Quit(Lnode *h)
{
	SaveInf(h);    //�˳�ʱ������Ϣ
	exit(0);
}

/*���ļ�*/
void LoadInf(Lnode *h)
{
	Lnode *p = h;
	Lnode *q;   //��ʱ���� ���ڱ�����ļ��ж�ȡ����Ϣ
	FILE* file = fopen("./Information.dat", "rb");
	if (!file)
	{
		printf("�ļ���ʧ�ܣ�");
		return ;
	}

	/*
		ʹ��feof�ж��ļ��Ƿ�Ϊ����Ҫע������⣺
			����ȡ�ļ�����ʱ��feof���������������ñ�־��Ϊ-1������
			��Ҫ�ٶ�ȡһ�κ󣬲Ż����á�����Ҫ�ȶ�һ�Ρ�
	*/
	q = (Lnode *)malloc(sizeof(Lnode));
	fread(q, sizeof(Lnode), 1, file);
	while (!feof(file))    //һֱ�����ļ�ĩβ
	{
		p->next = q;
		p = q;
		q = (Lnode *)malloc(sizeof(Lnode));
		fread(q, sizeof(Lnode), 1, file);
	} //whileѭ������

	p->next = NULL;
	fclose(file);
}

/*������Ϣ���ļ���*/
void SaveInf(Lnode *h)
{
	Lnode *p = h->next;
	int flag;
	FILE* file = fopen("./Information.dat", "wb");
	if (!file)
	{
		printf("�ļ���ʧ�ܣ�");
		return;
	}
	while (p != NULL)
	{
		flag = fwrite(p, sizeof(Lnode), 1, file);   //��p������д���ļ���
		if (flag != 1)
		{
			break;
		}
		p = p->next;
	}
	fclose(file);
}

