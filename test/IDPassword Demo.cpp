#include "stdio.h"
#include "stdlib.h" 
#include "string.h"
#include "windows.h"
 
struct id
{
	char name[30],pwd[10];
	int totalscore=0;//���֔� 
	int totalnumberofratings=0;//���u�ִΔ� 
	float Evaluation=0; //�u�r 
	
};

struct id user1;
struct id user2;



void regist()//�~̖�]��ϵ�y 
{
	
	system("pause");
	system("cls");//���� 
	
	printf("\n\n\t\t\t�gӭʹ���]��ϵ�y\n\n");
	while(1)
	{
		printf("\t\tՈݔ���Ñ���[���ܴ��8���ַ�]��");//ݔ���Ñ��� 
		scanf("%s",user1.name);
		
		
		if(strlen(user1.name)<=8)//�Д��Ñ��� 
		{
			while(1)
			{
				printf("\n\t\tՈݔ���ܴa[�ܴa�L�ȴ�춰�λ]��");//ݔ���ܴa 
				scanf("%s",user1.pwd);
				
				
				if(strlen(user1.pwd)>=8)//�Д��ܴa 
				{
					printf("\n\n\t\t�]��%s,�ܴa��%s\n\n",user1.name,user1.pwd);
					break;
				}
				else
				{
					printf("\n\t\t�ܴa�L�Ȟ�%d��Ո����ݔ��\n",strlen(user1.pwd));
				}
			}
			break;
		}
		else
		{
			printf("\n\t\t�Ñ����L�Ȟ�%d��Ո����ݔ��\n\n",strlen(user1.name));
		}
	}
}
 

int judge()//�Д��Ƿ��]���� 
{
	if(strcmp(user1.name,"")==0&&strcmp(user1.pwd,"")==0)
	{
		printf("\n\n\t\t����δ�]�ԣ�Ո���]�ԣ�\n\n");
		return 0;
	}
	else
	{
		return 1;
	}
}
 

bool dl()//�Ñ����� 
{
	int i;
	system("pause");
	system("cls");
	
	printf("\n\n\t\t\t���gӭʹ�õ��ϵ�y\n");
	for(i=1;i<=3;i++)//3�ε�����C 
	{
		printf("\t\tՈݔ���Ñ���:");
		scanf("%s",user2.name);
		printf("\n\t\tՈݔ���ܴa��");
		scanf("%s",user2.pwd);
		if(strcmp(user1.name,user2.name)==0&&strcmp(user1.pwd,user2.pwd)==0)
		{
			printf("\n\n\t\t��䛳ɹ����gӭʹ��ϵ�y\n\n");
			return true;
		}
		else
		{
			printf("\n\n\t\t����ʧ����Ո���µ��룬��߀��%d�ΙC��\n\n",3-i);
		}
		if(i==3){
			system("pause");
			system("cls");
			printf("���i�У�60����������_��") ;
			Sleep(3000);
			printf("ϵ�y�����_����");
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
		printf("\n\n\t\t\t����ϵ�y\n");
		
		printf("\t\t\t1:�]��\n");
		printf("\t\t\t2:����\n");
		printf("\t\t\t0:�˳�\n\n");
		
		printf("\t\tՈ�x���ܾ�̖��");
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
				printf("\n\t\t��ݔ��Ĺ��ܾ�̖���`��Ո����ݔ�룡\n");
		}
		
	}
	
}

