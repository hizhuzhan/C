#include <stdio.h>
#include <string>

/*定义学生结构体*/ 
/*Define student struct*/ 

struct Student  

{  
	
	char ID[20];  
	
	char Name[20];  
	
	float Mark1;  
	
	float Mark2;  
	
	float Mark3;  
	
	float Average;  
	
};  


struct Student students[1000];  

int num=0;  

float Avg(struct Student stu)  

{  
	
	return (stu.Mark1+stu.Mark2+stu.Mark3)/3;  
	
}  



/*通过学号返回数组下标*/  

int Student_SearchByIndex(char id[])  

{  
	
	int i;  
	
	for (i=0;i<num;i++)  
		
	{  
		
		if (strcmp(students[i].ID,id)==0)  
			
		{  
			
			return i;  
			
		}  
		
	}  
	
	return -1;  
	
}  



/*通过姓名返回数组下标*/  

int Student_SearchByName(char name[])  

{  
	
	int i;  
	
	for (i=0;i<num;i++)  
		
	{  
		
		if (strcmp(students[i].Name,name)==0)  
			
		{  
			
			return i;  
			
		}  
		
	}  
	
	return -1;  
	
}  



/*显示单条学生记录*/  

void Student_DisplaySingle(int index)  

{  
	
	printf("%10s%10s%8s%8s%8s%10s\n","学号","姓名","英语成绩","数学成绩","计算机成绩","平均成绩");  
	
	printf("=============================================================\n");  
	
	printf("%10s%10s%8.2f%8.2f%8.2f%10.2f\n",students[index].ID,students[index].Name,  
		
		students[index].Mark1,students[index].Mark2,students[index].Mark3,students[index].Average);  
	
}  



/*插入学生信息*/  

void Student_Insert()  

{  
	
	while(1)  
		
	{  
		
		printf("请输入学号:");  
		
		scanf("%s",&students[num].ID);  
		
		getchar();  
		
		
		
		printf("请输入姓名:");  
		
		scanf("%s",&students[num].Name);  
		
		getchar();  
		
		
		
		printf("请输入英语成绩:");  
		
		scanf("%f",&students[num].Mark1);  
		
		getchar();  
		
		
		
		printf("请输入数学成绩:");  
		
		scanf("%f",&students[num].Mark2);  
		
		getchar();  
		
		
		
		printf("请输入计算机成绩:");  
		
		scanf("%f",&students[num].Mark3);  
		
		getchar();  
		
		
		
		students[num].Average=Avg(students[num]);  
		
		num++;  
		
		
		
		printf("是否继续?(y/n)");  
		
		if (getchar()=='n')  
			
		{  
			
			break;  
			
		}  
		
	}  
	
	
	
}  



/*修改学生信息*/  

void Student_Modify()  

{  
	
	//float mark1,mark2,mark3;  
	
	while(1)  
		
	{  
		
		char id[20];  
		
		int index;  
		
		printf("请输入要修改的学生的学号:");  
		
		scanf("%s",&id);  
		
		getchar();  
		
		index=Student_SearchByIndex(id);  
		
		if (index==-1)  
			
		{  
			
			printf("学生不存在!\n");  
			
		}  
		
		else  
			
		{  
			
			printf("你要修改的学生信息为:\n");  
			
			Student_DisplaySingle(index);  
			
			printf("-- 请输入新值--\n");  
			
			
			printf("请输入学号:");  
			
			scanf("%s",&students[index].ID);  
			
			getchar();  
			
			
			printf("请输入姓名:");  
			
			scanf("%s",&students[index].Name);  
			
			getchar();  
			
			
			printf("请输入英语成绩:");  
			
			scanf("%f",&students[index].Mark1);  
			
			getchar();  
			
			
			printf("请输入数学成绩:");  
			
			scanf("%f",&students[index].Mark2);  
			
			getchar();  
			
			
			printf("请输入计算机成绩:");  
			
			scanf("%f",&students[index].Mark3);  
			
			getchar();  
			
			
			students[index].Average=Avg(students[index]);  
			
		}  
		
		printf("是否继续?(y/n)");  
		
		if (getchar()=='n')  
			
		{  
			
			break;  
			
		}  
		
	}  
	
}  



/*删除学生信息*/  

void Student_Delete()  

{  
	
	int i;  
	
	while(1)  
		
	{  
		
		char id[20];  
		
		int index;  
		
		printf("请输入要删除的学生的学号:");  
		
		scanf("%s",&id);  
		
		getchar();  
		
		index=Student_SearchByIndex(id);  
		
		if (index==-1)  
			
		{  
			
			printf("学生不存在!\n");  
			
		}  
		
		else  
			
		{  
			
			printf("你要删除的学生信息为:\n");  
			
			Student_DisplaySingle(index);  
			
			printf("是否真的要删除?(y/n)");  
			
			if (getchar()=='y')  
				
			{  
				
				for (i=index;i<num-1;i++)  
					
				{  
					
					students[i]=students[i+1];
					
				}  
				
				num--;  
				
			}  
			
			getchar();  
			
		}  
		
		printf("是否继续?(y/n)");  
		
		if (getchar()=='n')  
			
		{  
			
			break;  
			
		}  
		
	}  
	
}  



/*按姓名查询*/  

void Student_Select()  

{  
	
	while(1)  
		
	{  
		
		char id[20];  
		
		int index;  
		
		printf("请输入要查询的学生的学号:");  
		
		scanf("%s",&id);  
		
		getchar();  
		
		index=Student_SearchByIndex(id);
		
		if (index==-1)  
			
		{  
			
			printf("学生不存在!\n");  
			
		}  
		
		else  
			
		{  
			
			printf("你要查询的学生信息为:\n");  
			
			Student_DisplaySingle(index);  
			
		}  
		
		printf("是否继续?(y/n)");  
		
		if (getchar()=='n')  
			
		{  
			
			break;  
			
		}  
		
	}  
	
}  

/*按平均分统计*/

void Student_Count()

{
	
	int  i=0,a=0,b=0,c=0,d=0,e=0;
	
	for(i=0;i<num;i++)
		
	{
		
		if(students[i].Average<60)
			
		{
			
			a++;
			
		}
		
		
		else if(students[i].Average>=60 && students[i].Average<70)
			
		{
			
			b++;
			
		}
		
		else if(students[i].Average>=70 && students[i].Average<80)
			
		{
			
			c++;
			
		}
		
		else if(students[i].Average>=80 && students[i].Average<90)
			
		{
			
			d++;
			
		}
		
		else if(students[i].Average>=60 && students[i].Average<70)
			
		{
			
			e++;
			
		}
		
	}


 printf("\n				按平均分统计各分数段学生人数\n");

 printf("\n============================================================\n");
 printf("	分数段		0--59	60--69	70--79	80--89	90--100\n");
 printf("	人数		%d	%d	%d	%d	%d\n", a,b,c,d,e);
	
}

/*按平均值排序*/  

void Student_SortByAverage()  

{  
	
	int i,j;  
	
	struct Student tmp;  
	
	for (i=0;i<num;i++)  
		
	{  
		
		for (j=1;j<num-i;j++)  
			
		{  
			
			if (students[j-1].Average<students[j].Average)  
				
			{  
				
				tmp=students[j-1];  
				
				students[j-1]=students[j];  
				
				students[j]=tmp;  
				
			}  
			
		}  
		
	}  
	
}  



/*显示学生信息*/  

void Student_Display()  

{  
	
	int i;  
	
	printf("%10s%10s%8s%8s%8s%10s\n","学号","姓名","英语","数学","计算机","平均成绩");  
	
	printf("=============================================================\n");  
	
	for (i=0;i<num;i++)  
		
	{  
		
		printf("%10s%10s%8.2f%8.2f%8.2f%10.2f\n",students[i].ID,students[i].Name,  
			
			students[i].Mark1,students[i].Mark2,students[i].Mark3,students[i].Average);  
		
	}  
	
}  






/*主程序*/  

void main()  

{  
	
	int choice;  
	
	while(1)  
		
	{  
		
		/*主菜单*/  
		printf("\n			    主菜单\n");  
		
		printf("\n============================================================\n");  
		
		printf("	1. 数据输入		2. 数据输出\n");  
		
		
		printf("	3. 数据排序（按平均分）	4. 数据查找（按学号）\n");
		
		printf("	5. 数据插入		6. 数据删除\n");  
		
		printf("	7. 数据统计（按平均分）	0. 退出\n");  
		
		printf("============================================================\n");  
		
		
		scanf("%d",&choice);  
		
		getchar();  
		
		switch(choice)  
			
		{  
			
		case 1:  
			
			Student_Insert();  
			
			break;  
			
		case 2:
			
			Student_Display();
			
			break;
			
		case 3:  
			
			Student_SortByAverage();  
			
			Student_Display();  
			
			break;
			
		case 4:  
			
			Student_Select();  
			
			break;  
			
		case 5:  
			
			Student_Modify();  
			
			break;  
			
		case 6:  
			
			Student_Delete();  
			
			break;  
			
		case 7:
			
			Student_Count();

			break;

		case 0:  
			
			exit(0);  
			
			break;  
			
		}  
		
	}  
	
}  