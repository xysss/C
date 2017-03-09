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
	fp1=fopen("通讯录.txt","r+");
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
void add()  //增加函数 
{
	call *a,*b;
	char choose;
	choose='y';
	while(choose=='y')  //选择 
	{
		a=head;
		while(a->next!=NULL) //判断是否到链表结尾 
		{
			a=a->next;
		}
		printf("请输入姓名：");
		scanf("%s",a->name);
		printf("请输入工作单位：");
		scanf("%s",a->adress);
		printf("请输入电话号码："); 
		scanf("%s",a->haoma);
		printf("请输入E-mail：");
		scanf("%s",a->email); 
		NUM++;      //计数 
		b=(call*)malloc(sizeof(call));  // 开辟空间 
		a->next=b;
		a=b;
		b->next=NULL;
		printf("已保存成功!!是否继续增加成员（y/n）： ");
		scanf("%s",&choose);
	}
}
void cutout()
{
	int i;
	int j;
	call *a,*b;
	show();     //调用展示函数 
	a=head;     //指到开头 
	printf("请输入想删除的序号"); 
	scanf("%d",&j);
	if(j<0||j==0||j>NUM)   //判断是否符合范围 
	printf("请正确输入");  
	else{
	for(i=1;i<j;i++)
	{
		a=a->next;
	}
	b=a->next;
	a->next=a->next->next;
	free(b);
	NUM--;
	printf("删除成功！");
}
 } 
 void seek()
 {
 	int n;
 	printf("按人名查询按'1',按电话号码查询请按'2'");
 	scanf("%d",&n);
 	switch(n)
 	{
 		case 1:ren();break;
		case 2:hao();break;
		default:printf("请按要求输入");break;
		system("cls"); 
	 }	
 }
void news()
{
	int i,j;
	char mima[20]={'n','b','r','s','j','j','d'};
	char mm[20];
	call *a;
L:	printf("请输入密码: ");
	scanf("%s",&mm);
	if(strcmp(mima,mm)!=0)
		goto L;
	a=head;
	show();
	printf("请输入想修改的序号:  ");
	scanf("%d",&j);
	if(j<0||j==0||j>NUM)
		printf("请正确输入"); 
	else{
	for(i=0;i<j;i++)
		a=a->next;
	printf("请输入姓名：");
	scanf("%s",a->name);
	printf("请输入工作单位：");
	scanf("%s",a->adress);
	printf("请输入电话号码："); 
	scanf("%s",a->haoma);
	printf("请输入E-mail：");
	scanf("%s",a->email); 
	printf("修改成功");}
}
void show()    //展示函数 
{
	FILE *fp;    //定义文件指针 
	call *a;     //链表指针 
	int i=1;     
	a=head->next;
	printf("序号    人名           地址           号码           邮编\n");
	while(a->next!=NULL)
	{
		printf("%-8d%-15s%-15s%-15s%-15s%\n",i,a->name,a->adress,a->haoma,a->email);
		a=a->next;
		i++;     //计数 
	}
}
void save()
{
	call *a;
	FILE *fp;
	a=head->next;
	fp=fopen("通讯录.txt","w");
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
	printf("\t\t|=======★☆★通讯系统★☆★=========|\n");
	printf("\t\t|\t     0. 退出                 |\n");
	printf("\t\t|\t     1. 增加成员             |\n");
	printf("\t\t|\t     2. 删除成员             |\n");
    printf("\t\t|\t     3. 查找成员             |\n");
	printf("\t\t|\t     4. 修改成员             |\n");
	printf("\t\t|\t     5. 浏览成员             |\n");
	printf("\t\t|====================================|\n\n");
	printf("\t\t\t选择(0-5):");
}
void hao()
{
	call *a;
	char o[20];
	printf("请输入想查找的电话号码:  ");
	scanf("%s",o);
	a=head->next;
	while(a->next!=NULL&&strcmp(o,a->haoma)!=0)
	{
		a=a->next;
	}
	if(a->next==NULL) 
	printf("您要查找的电话号码不存在");
	else 
	printf("%s %s %s %s",a->name,a->adress,a->haoma,a->email);
}
void ren()
{
	call *a;
	char p[200];
	printf("请输入想查找的人名:  ");
	scanf("%s",p);
	a=head->next;
	while(a->next!=NULL&&strcmp(p,a->name)!=0)
	{
		a=a->next;
	}
	if(a->next==NULL)
	printf("您要查找的人名不存在");
	else
	printf("%s %s %s %s",a->name,a->adress,a->haoma,a->email);
}




