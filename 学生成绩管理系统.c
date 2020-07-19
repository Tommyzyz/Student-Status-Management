#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define STU sizeof(struct student)
struct clsname
{
    char class1name[20];
	double class1credit; 	
    char class2name[20];
	double class2credit;	 
	char class3name[20];
	double class3credit;	 
	char class4name[20];
	double class4credit;	 
	char class5name[20];
	double class5credit;	  	
}; 

struct grade
{
   double class1;
   double class2;
   double class3;   
   double class4;  
   double class5; 		
}; 

struct student    //学生信息
{
    int id;                 //学号
    char name[20];          //姓名
    struct clsname cls;   //课程名 
    struct grade score;     //成绩
    double gpa;             //学分绩 
    int rank;               //排名 
    struct student *next; 
};
void Menu();    //主菜单
void Add();     //新增学生信息
void Show();    //显示所有学生信息
void Find();    //完成按学号查找学生记录，并显示
void Sort();    //对学生信息进行排序
void Insert();  //插入学生的一条记录并按平均学分绩排序
void Delete();  //删除学生信息 

int stuCnt = 0;   //学生人数
struct student *head;

int main()
{

        Menu();  //显示菜单 
		int num;
        scanf("%d",&num);
		while(num<0 || num >6)
        {
            printf("请输入一个有效选项：\n");
            scanf("%d",&num);
        }
		while(num>0 && num<=6)
		{
            switch(num)
            {
                case 1:
                    Add();
                    break;
                case 2:
                    Find();
                    break;
                case 3:
                    Show();
                    break;
                case 4:
                    Insert();
                    break;
                case 5:
                    Sort();
                    break;
                case 6:
                    Delete();
	                break;
		    }
		    Menu(); 
			scanf("%d",&num);
			while(num<0 || num >6)
                {
                    printf("请输入一个有效选项：\n");
                    scanf("%d",&num);
                }		    
		}
	    return 0;
}

void Menu()   //主菜单
{
    printf("*************************************************\n");
    printf("*\t\t学生成绩管理系统\t\t*\n");
    printf("*************************************************\n");
    printf("*\t\t1.新增学生信息\t\t\t*\n");
    printf("*\t\t2.查找学生信息\t\t\t*\n");
    printf("*\t\t3.显示学生信息\t\t\t*\n");
    printf("*\t\t4.插入学生信息\t\t\t*\n");
    printf("*\t\t5.排序学生信息\t\t\t*\n");
    printf("*\t\t6.删除学生信息\t\t\t*\n");
    printf("*\t\t0.退出系统\t\t\t*\n");
    printf("*************************************************\n");
    printf("请选择功能:");
}

void Add() 
{
	struct student *p,*p1,*pbefore;
    int i=1,x=1,num=0;
	do
    	{
	    printf("正在新增学生信息...\n");
	    p1=(struct student *) malloc(STU);
	    if(stuCnt==0)
	        {
	    	printf("请输入五个课程名:\n");
            scanf("%s%s%s%s%s",p1->cls.class1name,p1->cls.class2name,p1->cls.class3name,p1->cls.class4name,p1->cls.class5name);
			printf("请输入五个课程各自学分绩:\n"); 
			scanf("%lf%lf%lf%lf%lf",&p1->cls.class1credit,&p1->cls.class2credit,&p1->cls.class3credit,&p1->cls.class4credit,&p1->cls.class5credit);
	    	}
	    else
	        {
	        strcpy(p1->cls.class1name,head->cls.class1name);
	        strcpy(p1->cls.class2name,head->cls.class2name);
	        strcpy(p1->cls.class3name,head->cls.class3name);
	        strcpy(p1->cls.class4name,head->cls.class4name);
	        strcpy(p1->cls.class5name,head->cls.class5name);
	        p1->cls.class1credit=head->cls.class1credit;
	        p1->cls.class2credit=head->cls.class2credit;
	        p1->cls.class3credit=head->cls.class3credit;
	        p1->cls.class4credit=head->cls.class4credit;
	        p1->cls.class5credit=head->cls.class5credit;      
			}
		printf("请输入该学生的学号:\n");
        scanf("%d",&p1->id);
        printf("请输入该学生的姓名:\n");
        scanf("%s",p1->name);
		printf("请输入该学生的%s成绩:\n",p1->cls.class1name);
        scanf("%lf",&p1->score.class1);        
        printf("请输入该学生的%s成绩:\n",p1->cls.class2name);
        scanf("%lf",&p1->score.class2);
        printf("请输入该学生的%s成绩:\n",p1->cls.class3name);
        scanf("%lf",&p1->score.class3);
        printf("请输入该学生的%s成绩:\n",p1->cls.class4name);
        scanf("%lf",&p1->score.class4);        
        printf("请输入该学生的%s成绩:\n",p1->cls.class5name);
        scanf("%lf",&p1->score.class5);
	    p1->gpa=(p1->score.class1*p1->cls.class1credit+p1->score.class2*p1->cls.class2credit+p1->score.class3*p1->cls.class3credit+p1->score.class4*p1->cls.class4credit+p1->score.class5*p1->cls.class5credit)/(p1->cls.class1credit+p1->cls.class2credit+p1->cls.class3credit+p1->cls.class4credit+p1->cls.class5credit);
	    p1->next=NULL;
	    if(stuCnt == 0)
            {
			head=p1;
		    stuCnt++;
            }
        else
		    {
            num=0;
            p=head;
			while(p->gpa>p1->gpa)
                {
        	    if(p->next==NULL)
        	        {
				    num=2;
				    break;
					}
				pbefore=p;	
        	    p=p->next;
        	    num=1;
			    }
			if(num==2)
			    {
				p->next=p1;
				}    
            if(num==0)
                {
			    p1->next=p;
			    head=p1;
				}
			if(num==1)
			    {
				p1->next=p;
				pbefore->next=p1;
				}	
	        stuCnt++;
			}
		p=head;
		x=1;
		do                 //修复排名 
	    	{
		    p->rank=x;
		    p=p->next;
		    x++;
	        }while(p!=NULL);
	    printf("请问要继续输入吗？是（1）退出（0）\n");
	    scanf("%d",&i);			
        }while(i==1);
        system("cls");
}

void Show()
{
    int i=1;
	struct student *p;
    if(stuCnt == 0)
    {
        printf("系统中暂无学生信息，请录入后再来查看\n");
    }
    else
    {
        printf("*   学号\t*   姓名\t*%-20s*%-20s*%-20s*%-20s*%-20s*平均学分绩\n",head->cls.class1name,head->cls.class2name,head->cls.class3name,head->cls.class4name,head->cls.class5name);
        p=head;
        do
            {
            printf("*%-10d\t*%-10s\t*%-20.2lf*%-20.2lf*%-20.2lf*%-20.2lf*%-20.2lf*%-8.2lf\n",p->id,p->name,p->score.class1,p->score.class2,p->score.class3,p->score.class4,p->score.class5,p->gpa);
            p=p->next;
            }while(p!=NULL);
    }
	do
    	{
		printf("退出（0）\n");
	    scanf("%d",&i);
	    }while(i==1);
	system("cls");	
}

void Find()
{
	int i=-1;
	struct student *p;
	if(stuCnt == 0)
    {
        printf("系统中暂无学生信息，请录入后再来\n");
    }
    else
    {
        printf("请输入需查找学生学号\n");
		scanf("%d",&i);
		p=head;
	    do
            {
            if(p->id==i)
			{
			printf("*   学号\t*   姓名\t*%-20s*%-20s*%-20s*%-20s*%-20s*平均学分绩\n",p->cls.class1name,p->cls.class2name,p->cls.class3name,p->cls.class4name,p->cls.class5name);
			printf("*%-10d\t*%-10s\t*%-20.2lf*%-20.2lf*%-20.2lf*%-20.2lf*%-20.2lf*%-8.2lf\n",p->id,p->name,p->score.class1,p->score.class2,p->score.class3,p->score.class4,p->score.class5,p->gpa);
			break;
			}
            p=p->next;
            }while(p!=NULL);
    	if(p==NULL)
    	printf("没有找到学生");
    	
	}
	do
    	{
		printf("退出（0）\n");
	    scanf("%d",&i);
	    }while(i==1);
	system("cls");
}

void Sort()
{
    int i=1;
	struct student *p;
    if(stuCnt == 0)
    {
        printf("系统中暂无学生信息，请录入后再来查看\n");
    }
    else
    {
        p=head;        
		printf("*   学号\t*   姓名\t*%-20s*%-20s*%-20s*%-20s*%-20s*平均学分绩\t*排名\t*\n",p->cls.class1name,p->cls.class2name,p->cls.class3name,p->cls.class4name,p->cls.class5name);
        do
            {
            printf("*%-10d\t*%-10s\t*%-20.2lf*%-20.2lf*%-20.2lf*%-20.2lf*%-20.2lf*%-5.2lf\t\t*%-4d\t*\n",p->id,p->name,p->score.class1,p->score.class2,p->score.class3,p->score.class4,p->score.class5,p->gpa,p->rank);
            p=p->next;
            }while(p!=NULL);
    }
	do
    	{
		printf("退出（0）\n");
	    scanf("%d",&i);
	    }while(i==1);
	system("cls");	
}

void Insert()
{
	struct student *p,*p1,*pbefore;
    int x=1,i=1,num=0;
	if(stuCnt == 0)
        {
        printf("系统中暂无学生信息，请录入后再来\n");
        }
    else
	    {
		printf("正在插入学生信息...\n");
	    p1=(struct student *) malloc(STU);
	    strcpy(p1->cls.class1name,head->cls.class1name);
	    strcpy(p1->cls.class2name,head->cls.class2name);
	    strcpy(p1->cls.class3name,head->cls.class3name);
	    strcpy(p1->cls.class4name,head->cls.class4name);
	    strcpy(p1->cls.class5name,head->cls.class5name);
	    p1->cls.class1credit=head->cls.class1credit;
	    p1->cls.class2credit=head->cls.class2credit;
	    p1->cls.class3credit=head->cls.class3credit;
	    p1->cls.class4credit=head->cls.class4credit;
	    p1->cls.class5credit=head->cls.class5credit;	    
	    printf("请输入该学生的学号:\n");
        scanf("%d",&p1->id);
        printf("请输入该学生的姓名:\n");
        scanf("%s",p1->name);
		printf("请输入该学生的%s成绩:\n",p1->cls.class1name);
        scanf("%lf",&p1->score.class1);        
        printf("请输入该学生的%s成绩:\n",p1->cls.class2name);
        scanf("%lf",&p1->score.class2);
        printf("请输入该学生的%s成绩:\n",p1->cls.class3name);
        scanf("%lf",&p1->score.class3);
        printf("请输入该学生的%s成绩:\n",p1->cls.class4name);
        scanf("%lf",&p1->score.class4);        
        printf("请输入该学生的%s成绩:\n",p1->cls.class5name);
        scanf("%lf",&p1->score.class5);
	    p1->gpa=(p1->score.class1*p1->cls.class1credit+p1->score.class2*p1->cls.class2credit+p1->score.class3*p1->cls.class3credit+p1->score.class4*p1->cls.class4credit+p1->score.class5*p1->cls.class5credit)/(p1->cls.class1credit+p1->cls.class2credit+p1->cls.class3credit+p1->cls.class4credit+p1->cls.class5credit);
		p1->next=NULL;
	    num=0;
            p=head;
			while(p->gpa>p1->gpa)
                {
        	    if(p->next==NULL)
        	        {
				    num=2;
				    break;
					}
				pbefore=p;	
        	    p=p->next;
        	    num=1;
			    }
			if(num==2)
			    {
				p->next=p1;
				}    
            if(num==0)
                {
			    p1->next=p;
			    head=p1;
				}
			if(num==1)
			    {
				p1->next=p;
				pbefore->next=p1;
				}	
	        stuCnt++;
	    
		p=head;
		do                 //修复排名 
	    	{
		    p->rank=x;
		    p=p->next;
		    x++;
	    }while(p!=NULL);
    }
	do
        {
	   	printf("退出（0）\n");
	    scanf("%d",&i);
	    }while(i==1);
    system("cls");		    
}

void Delete()
{
	int i=-1,x=1,flag=0;
	struct student *p,*p1;
	if(stuCnt == 0)
    {
        printf("系统中暂无学生信息，请录入后再来\n");
    }
    else
    {
        printf("请输入要删除的学生学号:\n");
		scanf("%d",&i);
		p=head;
	    do
            {
            if(p->id==i)
			    {
					flag=1;
                    stuCnt--;
                	printf("已删除学生数据\n");
                    if(stuCnt==0)
                        {
                    	free(p);
                    	break;
					    }
					if(p==head)
                        {
                        head=p->next;
                        free(p);
						break;
						}
                    else 
                        {
                        p1->next=p->next;
					    free(p);	
					    }    
			    break;
			    }
		    p1=p;    
            p=p->next;    
            }while(p!=NULL);
    	if(flag==0)           
    	printf("没有找到学生\n");	
	}
    p=head;
	do                 //修复排名 
	    {
	    p->rank=x;
	    p=p->next;
	    x++;
	    }while(p!=NULL);
	x=1;		
	do
    	{
		printf("退出（0）\n");
	    scanf("%d",&x);
	    }while(x==1);
	system("cls");			
}
