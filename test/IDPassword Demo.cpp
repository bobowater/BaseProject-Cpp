#include "stdio.h"
#include "stdlib.h" 
#include "string.h"
#include "windows.h"
 
struct id
{
	char name[30],pwd[10];
	int totalscore=0;//總分數 
	int totalnumberofratings=0;//總評分次數 
	float Evaluation=0; //評價 
	
};

struct id user1;
struct id user2;



void regist()//賬號註冊系統 
{
	
	system("pause");
	system("cls");//清屏 
	
	printf("\n\n\t\t\t歡迎使用註冊系統\n\n");
	while(1)
	{
		printf("\t\t請輸入用戶名[不能大於8个字符]：");//輸入用戶名 
		scanf("%s",user1.name);
		
		
		if(strlen(user1.name)<=8)//判斷用戶名 
		{
			while(1)
			{
				printf("\n\t\t請輸入密碼[密碼長度大於八位]：");//輸入密碼 
				scanf("%s",user1.pwd);
				
				
				if(strlen(user1.pwd)>=8)//判斷密碼 
				{
					printf("\n\n\t\t註冊%s,密碼是%s\n\n",user1.name,user1.pwd);
					break;
				}
				else
				{
					printf("\n\t\t密碼長度為%d，請重新輸入\n",strlen(user1.pwd));
				}
			}
			break;
		}
		else
		{
			printf("\n\t\t用戶名長度為%d，請重新輸入\n\n",strlen(user1.name));
		}
	}
}
 

int judge()//判斷是否註冊了 
{
	if(strcmp(user1.name,"")==0&&strcmp(user1.pwd,"")==0)
	{
		printf("\n\n\t\t您尚未註冊，請先註冊！\n\n");
		return 0;
	}
	else
	{
		return 1;
	}
}
 

bool dl()//用戶登入 
{
	int i;
	system("pause");
	system("cls");
	
	printf("\n\n\t\t\t、歡迎使用登錄系統\n");
	for(i=1;i<=3;i++)//3次登入驗證 
	{
		printf("\t\t請輸入用戶名:");
		scanf("%s",user2.name);
		printf("\n\t\t請輸入密碼：");
		scanf("%s",user2.pwd);
		if(strcmp(user1.name,user2.name)==0&&strcmp(user1.pwd,user2.pwd)==0)
		{
			printf("\n\n\t\t登錄成功，歡迎使用系統\n\n");
			return true;
		}
		else
		{
			printf("\n\n\t\t登入失敗，請重新登入，你還有%d次機會\n\n",3-i);
		}
		if(i==3){
			system("pause");
			system("cls");
			printf("封鎖中，60秒后再重新開放") ;
			Sleep(3000);
			printf("系統重新開放中");
			system("cls");
		} 
		
	}
	
}
int main()
{
	int num,standby=1;
	
	while(standby)
	{
		system("pause");
		system("cls");
		printf("\n\n\t\t\t管理系統\n");
		
		printf("\t\t\t1:註冊\n");
		printf("\t\t\t2:登入\n");
		printf("\t\t\t0:退出\n\n");
		
		printf("\t\t請選擇功能編號：");
		scanf("%d",&num);
		
		switch(num)
		{
			case 1:regist();break;
			case 2:
				if(judge()==1)
				{
					if(dl()==true){
						standby=0;
						break;
					}
					
				}
				break;
			case 0:exit(1);break;
			default:
				printf("\n\t\t您輸入的功能編號有誤，請重新輸入！\n");
		}
		
	}
	
}

