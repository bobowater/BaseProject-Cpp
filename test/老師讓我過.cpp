#include "stdio.h"
#include "stdlib.h" 
#include "string.h"
#include "windows.h"

int rename( const char *oldname, const char *newnametxt );
int remove(char * filename);

struct task
{
	int Num = 0;
	char title[50];
	char content[100];
	char category[20];
	char feedback[50];
	int status = 1;
	
	bool duplicate();
	void classify();
	void adddata();
	void addmission();
	void search();
	void accept();
};

struct id
{
	char name[30],pwd[10];
	int totalscore=0;//�`���� 
	int totalnumberofratings=0;//�`�������� 
	float Evaluation=0; //���� 
	int Q[10]={NULL};//�o������ 

};

struct id user1;
struct id user2;




void regist()//�㸹���U�t�� 
{

	system("pause");
	system("cls");//�M�� 

	printf("\n\n\t\t\t�w��ϥε��U�t��\n\n");
	while(1)
	{
		printf("\t\t�п�J�Τ�W[����j��8?�r��]�G");//��J�Τ�W 
		scanf("%s",user1.name);


		if(strlen(user1.name)<=8)//�P�_�Τ�W 
		{
			while(1)
			{
				printf("\n\t\t�п�J�K�X[�K�X���פj��K��]�G");//��J�K�X 
				scanf("%s",user1.pwd);


				if(strlen(user1.pwd)>=8)//�P�_�K�X 
				{
					printf("\n\n\t\t���U%s,�K�X�O%s\n\n",user1.name,user1.pwd);
					FILE *fptr;
					fptr = fopen("123.txt","a");
					fprintf(fptr,"%s",&user1.name);
					fprintf(fptr,"\n");
					fprintf(fptr,"%s",&user1.pwd);
					fprintf(fptr,"\n");
					fprintf(fptr,"%d",user1.totalscore);
					fprintf(fptr,"\n");
					fprintf(fptr,"%d",user1.totalnumberofratings);
					fprintf(fptr,"\n");
					fprintf(fptr,"%f",user1.Evaluation);
					fprintf(fptr,"\n");
					for(int i=0;i<10;i++){
						if(user1.Q[0]==NULL){
							fprintf(fptr,NULL);
							break;
						}
						if(user1.Q[i]==0)
							break;
						else
							fprintf(fptr,"%d ",user1.Q[i]);
					}
					fprintf(fptr,"\n");
					fclose(fptr);
					break;
				}
				else
				{
					printf("\n\t\t�K�X���׬�%d�A�Э��s��J\n",strlen(user1.pwd));
				}
			}
			break;
		}
		else
		{
			printf("\n\t\t�Τ�W���׬�%d�A�Э��s��J\n\n",strlen(user1.name));
		}
	}
}


int judge()//�P�_�O�_���U�F 
{
	FILE *fptr;
	fptr = fopen("123.txt","r");
	fscanf(fptr,"%s",&user1.name);
	while(!feof(fptr)){
		if(strcmp(user2.name,user1.name)==0){
		
			fscanf(fptr,"%s",&user1.pwd);
			return 1;
		}
		fscanf(fptr,"%s",&user1.name);
        fscanf(fptr,"%s",&user1.name);
        fscanf(fptr,"%s",&user1.name);
        fscanf(fptr,"%s",&user1.name);
        fscanf(fptr,"%s",&user1.name);
		
	}
	
	printf("\n\n\t\t�z�|�����U�A�Х����U�I\n\n");
	return 0;
	
}


bool dl()//�Τ�n�J 
{
	int i;
	system("pause");
	system("cls");

	printf("\n\n\t\t\t�B�w��ϥεn���t��\n");
	for(i=1;i<=3;i++)//3���n�J���� 
	{
		printf("\t\t�п�J�Τ�W:");
		scanf("%s",user2.name);
		if(judge()==0){
			printf("\n\n\t\t�n�J���ѡA�Э��s�n�J�A�A�٦�%d�����|\n\n",3-i);
				if(i==3){
				system("pause");
				system("cls");
				printf("���ꤤ�A60��Z�A���s�}��") ;
				Sleep(30000);
				printf("�t�έ��s�}��");
				system("cls");
			}	 
			continue;
		}
		printf("\n\t\t�п�J�K�X�G");
		scanf("%s",user2.pwd);
		if(strcmp(user1.name,user2.name)==0&&strcmp(user1.pwd,user2.pwd)==0)
		{
			printf("\n\n\t\t�n�����\�A�w��ϥΨt��\n\n");
			return true;
		}
		else
		{
			printf("\n\n\t\t�n�J���ѡA�Э��s�n�J�A�A�٦�%d�����|\n\n",3-i);
		}
		if(i==3){
			system("pause");
			system("cls");
			printf("���ꤤ�A60��Z�A���s�}��") ;
			Sleep(30000);
			printf("�t�έ��s�}��");
			system("cls");
		} 

	}

}

id calculation(id user3){
	int num;
	while(1){
		printf("�п�J-5~5�@������:");
		scanf("%d",&num);
		if(num>=-5&&num<=5)
			break;
	}
	user3.totalscore += num;
	user3.totalnumberofratings += 1;
	user3.Evaluation = (float)user3.totalscore/user3.totalnumberofratings;
	
	return user3;
}

int main()
{
	int num,standby=1;

	while(standby)
	{
		system("pause");
		system("cls");
		printf("\n\n\t\t\t�޲z�t��\n");

		printf("\t\t\t1:���U\n");
		printf("\t\t\t2:�n�J\n");
		printf("\t\t\t0:�h�X\n\n");

		printf("\t\t�п�ܥ\��s���G");
		scanf("%d",&num);

		switch(num)
		{
			case 1:regist();break;
			case 2:
					if(dl()==true){
						standby=0;
						break;
					}

				break;
			case 0:exit(1);break;
			default:
				printf("\n\t\t�z��J���\��s�����~�A�Э��s��J�I\n");
		}

	}


	int input,n;
	task user;
	while(1)
	{
		printf("Choose your function\n");
		printf("1.Addmission 2.search mission 3.finish 4.exit\n");
		scanf("%d",&input);
		switch(input)
		{
			case 1:
				user.addmission();
				break;
			case 2:
				user.search();
				printf("�A�{�b�n�Fԣ?\n");
				printf("��J�ʧ@\n1:������ ��J��L��:�~��\n");
				scanf("%d",&n);
				if(n==1){
					user.accept();
				}
				break;
			case 3:
				printf("��ܧ���������:");
	
		
			case 4:
				exit(1);
				break;
			default :
				break; 
		}
	}
}



bool task::duplicate(){
	int x,b,c,flag;
	char test[50];
	FILE *fptr;
	fptr = fopen("mission.txt","r");
	fscanf(fptr,"%s",&test);
	fscanf(fptr,"%s",&test);
	
	while(!feof(fptr)){
		flag = 0;
		b = strlen(test);
		c = strlen(title);

		if(b==c){
			flag = 1;
			for(int i=0;i<b;i++){
				if(test[i]!=title[i]){
					flag = 2;
				}
			}
			
		}
		if(flag == 1){
			return false;
		}
		if(flag == 2||flag ==0){
			fscanf(fptr,"%s",&test);
	        fscanf(fptr,"%s",&test);
	        fscanf(fptr,"%s",&test);
	        fscanf(fptr,"%s",&test);
	        fscanf(fptr,"%s",&test);
	        fscanf(fptr,"%s",&test);
		}

	}
	fclose(fptr);
	return true;

}
void task::classify()
{
	int flag = 0,number;
	while(flag!=1)
	{
		printf("enter the number to choose the category\n");
		printf("1.Food\n2.Study\n3.Happy\n4.Tool\n5.others\n");
		scanf("%d",&number);
		switch(number)
		{
			case 1:
					flag = 1;
					printf("Finish select Food\n");
					category[0] = 'F';
					category[1] = 'o';
					category[2] = 'o';
					category[3] = 'd';
					category[4] = '\0';
					break;
				
			case 2:
					flag = 1;
					printf("Finish select Study\n");
					category[0] = 'S';
					category[1] = 't';
					category[2] = 'u';
					category[3] = 'd';
					category[4] = 'y';
					category[5] = '\0';
					break;
				
			case 3:
					flag = 1;
					printf("Finish select Happy\n");
					category[0] = 'H';
					category[1] = 'a';
					category[2] = 'p';
					category[3] = 'p';
					category[4] = 'y';
					category[5] = '\0';
					break;
				
			case 4:
					flag = 1;
					printf("Finish select Tool\n");
					category[0] = 'T';
					category[1] = 'o';
					category[2] = 'o';
					category[3] = 'l';
					category[4] = '\0';
					break;
				
			case 5:
					flag = 1;
					printf("Please input the Name of Category:\n");
					scanf("%s",category);
					printf("Finish the category\n");
					break;
				
			default :
			
					printf("try again\n");
					break;
		}
	}
	
}

void task::adddata(){
	char test[50];
	FILE *fptr;
	fptr = fopen("mission.txt","r");
	while(!feof(fptr)){
		fscanf(fptr,"%d",&Num);
		fscanf(fptr,"%s",&test);
        fscanf(fptr,"%s",&test);
        fscanf(fptr,"%s",&test);
        fscanf(fptr,"%s",&test);
        fscanf(fptr,"%s",&test);

	}
	Num += 1;
	fclose(fptr);
	

	fptr = fopen("mission.txt","a");
	fprintf(fptr,"%d",Num);
	fprintf(fptr,"\n");
	fprintf(fptr,"%s",&title);
	fprintf(fptr,"\n");
	fprintf(fptr,"%s",&content);
	fprintf(fptr,"\n");
	fprintf(fptr,"%s",&category);
	fprintf(fptr,"\n");
	fprintf(fptr,"%s",&feedback);
	fprintf(fptr,"\n");
	fprintf(fptr,"%d",status);
	fprintf(fptr,"\n");
	fclose(fptr);
}
void task::addmission()
{
	task mimi;
	printf("Please Name The Task Title  :\n");
	while(1)
	{
		scanf("%s",mimi.title);
		
		if(mimi.duplicate()==false)
		{
			printf("Fail\nPlease try other name\n");
		}
		else
		{
			printf("Done\n");
			break;
		}
	}
	printf("Please enter the mission's content\n");
	scanf("%s",mimi.content);
	printf("Please enter the mission's feedback\n");
	scanf("%s",mimi.feedback);
	printf("Please select the mission's category\n");
	mimi.classify();
	printf("%s %s %s %s\n",mimi.title,mimi.content,mimi.category,mimi.feedback);
	fflush(stdin);
	mimi.adddata();
}
void task::search()
{
	int number;
	char s0[50],s1[50],s2[50],s3[50],s4[50],s5[50];
	FILE *fptr;
	fptr = fopen("mission.txt","r");
	printf("enter the number to choose the category\n");
	printf("1.Food\n2.Study\n3.Happy\n4.Tool\n5.others\n");
	scanf("%d",&number);
	switch(number)
	{
		case 1: 	
			while(!feof(fptr))
			{
				fscanf(fptr,"%s",&s0);
				fscanf(fptr,"%s",&s1);
		        fscanf(fptr,"%s",&s2);
		        fscanf(fptr,"%s",&s3);
		        fscanf(fptr,"%s",&s4);
		        fscanf(fptr,"%s",&s5);
		        if(s3[0]=='F'&&s3[1]=='o'&&s3[2]=='o'&&s3[3]=='d')
		        {
		        	printf("#%s\n%s\n%s\n%s\n%s\n\n",s0,s1,s2,s3,s4);
				} 	
		    }	
			fclose(fptr);
			break;
		case 2:
			while(!feof(fptr))
			{
				fscanf(fptr,"%s",&s0);
				fscanf(fptr,"%s",&s1);
		        fscanf(fptr,"%s",&s2);
		        fscanf(fptr,"%s",&s3);
		        fscanf(fptr,"%s",&s4);
		        fscanf(fptr,"%s",&s5);
		        if(s3[0]=='S'&&s3[1]=='t'&&s3[2]=='u'&&s3[3]=='d'&&s3[4]=='y')
		        {
		        	printf("#%s\n%s\n%s\n%s\n%s\n\n",s0,s1,s2,s3,s4);
				} 
		    }	
			fclose(fptr);
			break;
		case 3:
				while(!feof(fptr))
			{
				fscanf(fptr,"%s",&s0);
				fscanf(fptr,"%s",&s1);
		        fscanf(fptr,"%s",&s2);
		        fscanf(fptr,"%s",&s3);
		        fscanf(fptr,"%s",&s4);
		        fscanf(fptr,"%s",&s5);
		        if(s3[0]=='H'&&s3[1]=='a'&&s3[2]=='p'&&s3[3]=='p'&&s3[4]=='y')
		        {
		        	printf("#%s\n%s\n%s\n%s\n%s\n\n",s0,s1,s2,s3,s4);
				} 	
		    }	
			fclose(fptr);
			break;
		case 4:
				while(!feof(fptr))
			{
				fscanf(fptr,"%s",&s0);
				fscanf(fptr,"%s",&s1);
		        fscanf(fptr,"%s",&s2);
		        fscanf(fptr,"%s",&s3);
		        fscanf(fptr,"%s",&s4);
		        fscanf(fptr,"%s",&s5);
		        if(s3[0]=='T'&&s3[1]=='o'&&s3[2]=='o'&&s3[3]=='l')
		        {
		        	printf("#%s\n%s\n%s\n%s\n%s\n\n",s0,s1,s2,s3,s4);
				}
		    }	
			fclose(fptr);
			break;
		case 5:
				while(!feof(fptr))
			{
				fscanf(fptr,"%s",&s0);
				fscanf(fptr,"%s",&s1);
		        fscanf(fptr,"%s",&s2);
		        fscanf(fptr,"%s",&s3);
		        fscanf(fptr,"%s",&s4);
		        fscanf(fptr,"%s",&s5);
		        if(s3[5]!='\0')
		        	printf("#%s\n%s\n%s\n%s\n%s\n\n",s0,s1,s2,s3,s4);
		    }	
			fclose(fptr);
			break;
		default :
			printf("nice boy!\n");
			break;
	}
}	

void task::accept(){
	int n,n1;
	char test[50];
	printf("��J�A�n�������Ƚs��: (ĵ�i)�ÿ�J�]�|�������(��Ӷ�)\n");
	scanf("%d",&n);
	FILE *fptr,*ouptr,*fptr2,*ouptr2;
	ouptr = fopen("newmission.txt","w");
	fptr = fopen("mission.txt","r");
	while(!feof(fptr)){
		fscanf(fptr,"%d",&n1);
		fprintf(ouptr,"%d",n1);
		fprintf(ouptr,"\n");
		fscanf(fptr,"%s",&test);
		fprintf(ouptr,"%s",&test);
		fprintf(ouptr,"\n");
        fscanf(fptr,"%s",&test);
        fprintf(ouptr,"%s",&test);
        fprintf(ouptr,"\n");
        fscanf(fptr,"%s",&test);
        fprintf(ouptr,"%s",&test);
        fprintf(ouptr,"\n");
        fscanf(fptr,"%s",&test);
        fprintf(ouptr,"%s",&test);
        fprintf(ouptr,"\n");
        fscanf(fptr,"%s",&test);
        if(n==n1){
        	fprintf(ouptr,"0");
        	fprintf(ouptr,"\n");
        	printf("���n�F\n");
        	while(!feof(fptr)){
        		test[0] = NULL;
				fscanf(fptr,"%s",&test);
				if(test[0]==NULL)
					break;
				fprintf(ouptr,"%s",&test);
				fprintf(ouptr,"\n");
			}
        	break;
		}
		fprintf(ouptr,"%s",&test);
		fprintf(ouptr,"\n");
	}
	fclose(fptr);
	fclose(ouptr);
	remove("mission.txt");
	rename( "newmission.txt", "mission.txt" );

	ouptr2 = fopen("new123.txt","w");
	fptr2 = fopen("123.txt","r");
	char s[50];
	while(!feof(fptr2)){
		fscanf(fptr2,"%s",&s);
		if(s[0]==NULL)
			break;
		fprintf(ouptr2,"%s",s);
		fprintf(ouptr2,"\n");
		fscanf(fptr2,"%s",&test);
		fprintf(ouptr2,"%s",&test);
		fprintf(ouptr2,"\n");
        fscanf(fptr2,"%s",&test);
        fprintf(ouptr2,"%s",&test);
        fprintf(ouptr2,"\n");
        fscanf(fptr2,"%s",&test);
        fprintf(ouptr2,"%s",&test);
        fprintf(ouptr2,"\n");
        fscanf(fptr2,"%s",&test);
        fprintf(ouptr2,"%s",&test);
        fprintf(ouptr2,"\n");
        test[0] = NULL;
        fscanf(fptr2,"%s",&test);
		fprintf(ouptr2,"%s",&test);
		if(strcmp(s,user2.name)==0){
			fprintf(ouptr2,"%d ",n);
		}
		fprintf(ouptr2,"\n");
		s[0] = NULL;
	}
	fclose(fptr2);
	fclose(ouptr2);
	
	
	
	
	remove("123.txt");
	rename("new123.txt", "123.txt" );
	

	
}


