#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <string.h>
typedef struct call{
	char name[10];
	char adress[50];
	char haoma[20];
	char email[20];
	struct call *next;
}call;

call *head;

int NUM=0;
void ren();
void hao();
void add();
void cutout();
void news();
void show();
void seek();
void menu();
void save();
int main()
{
	int n;
	FILE *fp1;
	call *a,*b;
	fp1=fopen("ͨѶ¼.txt","r+");
	head=a=(call*)malloc(sizeof(call));
	head->next=NULL;
	while(!feof(fp1)){
		b=(call*)malloc(sizeof(call));
		a->next=b;
		a=b;
		b->next=NULL;
		fscanf(fp1,"%s",&b->name);
		fscanf(fp1,"%s",&b->adress);
		fscanf(fp1,"%s",&b->haoma);
		fscanf(fp1,"%s",&b->email);
		NUM++;	
	}NUM--;
	fclose(fp1);
	menu();
	scanf("%d",&n);
	while(n)
	{
		switch(n)
		{ 
			case 1:add();break;
			case 2:cutout();break;
			case 3:seek();break;
			case 4:news();break;
			case 5:show();break;
			default:break;	
		}
		getch(); 
		system("cls");
		save();
		menu();	
		scanf("%d",&n);
	}
	return 0;
}
void add()  //���Ӻ��� 
{
	call *a,*b;
	char choose;
	choose='y';
	while(choose=='y')  //ѡ�� 
	{
		a=head;
		while(a->next!=NULL) //�ж��Ƿ������β 
		{
			a=a->next;
		}
		printf("������������");
		scanf("%s",a->name);
		printf("�����빤����λ��");
		scanf("%s",a->adress);
		printf("������绰���룺"); 
		scanf("%s",a->haoma);
		printf("������E-mail��");
		scanf("%s",a->email); 
		NUM++;      //���� 
		b=(call*)malloc(sizeof(call));  // ���ٿռ� 
		a->next=b;
		a=b;
		b->next=NULL;
		printf("�ѱ���ɹ�!!�Ƿ�������ӳ�Ա��y/n���� ");
		scanf("%s",&choose);
	}
}
void cutout()
{
	int i;
	int j;
	call *a,*b;
	show();     //����չʾ���� 
	a=head;     //ָ����ͷ 
	printf("��������ɾ�������"); 
	scanf("%d",&j);
	if(j<0||j==0||j>NUM)   //�ж��Ƿ���Ϸ�Χ 
	printf("����ȷ����");  
	else{
	for(i=1;i<j;i++)
	{
		a=a->next;
	}
	b=a->next;
	a->next=a->next->next;
	free(b);
	NUM--;
	printf("ɾ���ɹ���");
}
 } 
 void seek()
 {
 	int n;
 	printf("��������ѯ��'1',���绰�����ѯ�밴'2'");
 	scanf("%d",&n);
 	switch(n)
 	{
 		case 1:ren();break;
		case 2:hao();break;
		default:printf("�밴Ҫ������");break;
		system("cls"); 
	 }	
 }
void news()
{
	int i,j;
	char mima[20]={'n','b','r','s','j','j','d'};
	char mm[20];
	call *a;
L:	printf("����������: ");
	scanf("%s",&mm);
	if(strcmp(mima,mm)!=0)
		goto L;
	a=head;
	show();
	printf("���������޸ĵ����:  ");
	scanf("%d",&j);
	if(j<0||j==0||j>NUM)
		printf("����ȷ����"); 
	else{
	for(i=0;i<j;i++)
		a=a->next;
	printf("������������");
	scanf("%s",a->name);
	printf("�����빤����λ��");
	scanf("%s",a->adress);
	printf("������绰���룺"); 
	scanf("%s",a->haoma);
	printf("������E-mail��");
	scanf("%s",a->email); 
	printf("�޸ĳɹ�");}
}
void show()    //չʾ���� 
{
	FILE *fp;    //�����ļ�ָ�� 
	call *a;     //����ָ�� 
	int i=1;     
	a=head->next;
	printf("���    ����           ��ַ           ����           �ʱ�\n");
	while(a->next!=NULL)
	{
		printf("%-8d%-15s%-15s%-15s%-15s%\n",i,a->name,a->adress,a->haoma,a->email);
		a=a->next;
		i++;     //���� 
	}
}
void save()
{
	call *a;
	FILE *fp;
	a=head->next;
	fp=fopen("ͨѶ¼.txt","w");
	while(a->next!=NULL)
	{
		fprintf(fp,"%s %s %s %s\n",a->name,a->adress,a->haoma,a->email);
		a=a->next;	
	}
	fclose(fp);	
}
void menu()
{
	printf("\n\n\n\n\n");
	printf("\t\t|=======����ͨѶϵͳ����=========|\n");
	printf("\t\t|\t     0. �˳�                 |\n");
	printf("\t\t|\t     1. ���ӳ�Ա             |\n");
	printf("\t\t|\t     2. ɾ����Ա             |\n");
    printf("\t\t|\t     3. ���ҳ�Ա             |\n");
	printf("\t\t|\t     4. �޸ĳ�Ա             |\n");
	printf("\t\t|\t     5. �����Ա             |\n");
	printf("\t\t|====================================|\n\n");
	printf("\t\t\tѡ��(0-5):");
}
void hao()
{
	call *a;
	char o[20];
	printf("����������ҵĵ绰����:  ");
	scanf("%s",o);
	a=head->next;
	while(a->next!=NULL&&strcmp(o,a->haoma)!=0)
	{
		a=a->next;
	}
	if(a->next==NULL) 
	printf("��Ҫ���ҵĵ绰���벻����");
	else 
	printf("%s %s %s %s",a->name,a->adress,a->haoma,a->email);
}
void ren()
{
	call *a;
	char p[200];
	printf("����������ҵ�����:  ");
	scanf("%s",p);
	a=head->next;
	while(a->next!=NULL&&strcmp(p,a->name)!=0)
	{
		a=a->next;
	}
	if(a->next==NULL)
	printf("��Ҫ���ҵ�����������");
	else
	printf("%s %s %s %s",a->name,a->adress,a->haoma,a->email);
}




