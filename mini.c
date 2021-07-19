#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct srecord
{
	char fname[30];
	char lname[30];
	int usn;
	char pname[30];
	char address[30];
	long int phoneno;
	struct srecord *link;
};
struct srecord *first=NULL;
void Insert()
{
FILE *p1;
	struct srecord *p,*t;
	p1=fopen("third.txt","ab");
	p=(struct srecord*)malloc(sizeof(struct srecord));
	printf("enter the first name\n");
	scanf("%s",p->fname);
	fprintf(p1,"%s\n",p->fname);
	printf("enter the last name\n");
	scanf("%s",p->lname);
	fprintf(p1,"%s\n",p->lname);
	printf("enter USN no\n");
	scanf("%d",&p->usn);
	fprintf(p1,"%d\n",p->usn);
	printf("enter the parent name\n");
	scanf("%s",p->pname);
	fprintf(p1,"%s\n",p->pname);
	printf("enter the address\n");
	scanf("%s",p->address);
	fprintf(p1,"%s\n",p->address);
	printf("enter the phone number\n");
	scanf("%ld",&p->phoneno);
	fprintf(p1,"%ld\n",p->phoneno);
	printf("\n");
	fprintf(p1,"\n");
	p->link=NULL;
	if(first==NULL)
	{
		first=p;
	}
	else
	{
		t=first;
		while(t->link!=NULL)
		{
			t=t->link;
		}
		t->link=p;
	}
	fclose(p1);
}
void addtofile()
{
	 struct srecord *p=first;
	 FILE *p1;
	 p1=fopen("third.txt","ab");
	 while (p!=NULL)
{
		fprintf(p1,"%s\n",&p->fname);
		fprintf(p1,"%s\n",&p->lname);
		fprintf(p1,"%d\n",&p->usn);
	  	fprintf(p1,"%s\n",&p->pname);
	 	fprintf(p1,"%s\n",&p->address);
		fprintf(p1,"%d\n",&p->phoneno);
		 p=p->link;
	 }
		fclose(p1);
	 }
void create()
{
	struct srecord *p,*t;
		long int len;
		char phoneno[11];
	p=(struct srecord*)malloc(sizeof(struct srecord));
	printf("enter the first name\n");
	scanf("%s",p->fname);
	printf("enter the last name\n");
	scanf("%s",p->lname);
	printf("enter USN no\n");
	scanf("%d",&p->usn);
	printf("enter the parent name\n");
	scanf("%s",p->pname);
	printf("enter the address\n");
	scanf("%s",p->address);
	printf("enter the phone number\n");
	scanf("%ld",&p->phoneno);
	len=strlen(phoneno);
	while(len!=10)
	{
		printf("invalid phone number\n");
		printf("enter the correct phone number\n");
		scanf("%s\n",p->phoneno);
	}
	p->link=NULL;
	if(first==NULL)
	{
		first=p;
	}
	else
	{
		t=first;
		while(t->link!=NULL)
		{
			t=t->link;
		}
		t->link=p;
	}
}
void display1()
{
	struct srecord *temp;
	
	temp=first;
	if(first==NULL)
	{
		
		printf("doesnot exist");
	}
	else
	{
		while(temp!=NULL)
		{
			printf("first name\n");
			printf("%s\n",temp->fname);
			printf("last name\n");
			printf("%s\n",temp->lname);
			printf("usn\n");
			printf("%d\n",temp->usn);
			printf("parents name\n");
			printf("%s\n",temp->pname);
			printf("address\n");
			printf("%s\n",temp->address);
			printf("phone no.\n");
			printf("%ld\n",temp->phoneno);
			temp=temp->link;
		}
	}
}
void deleteoffile()
{
	struct srecord *j;
	int flag=0;
	int usn;
	FILE *p1,*l;
	p1=fopen("third.txt","rb"); 
	l=fopen("tmp.txt","ab");
	printf("DETETE STUDENT DETAIL\n");
	printf("enter student usn to delete:\n");
	scanf("%d",&usn);
	while((fscanf(p1,"%s",&j->fname),fscanf(p1,"%s",&j->lname),fscanf(p1,"%d",&j->usn),fscanf(p1,"%s",&j->pname),fscanf(p1,"%s",&j->address),fscanf(p1,"%d",&j->phoneno))==1)
	{
		if(j->usn==usn)
		{
			printf("student name %s -%d data has been deleted\n");
			flag =1;
		}
		else
		{
			fprintf(l,"%s\t",&j->fname);
			fprintf(l,"%s\t",&j->lname);
			fprintf(l,"%d\t",&j->usn);
			fprintf(l,"%s\t",&j->pname);
			fprintf(l,"%s\t",&j->address);
			fprintf(l,"%d\t",&j->phoneno);
			j=j->link;
		}
	}
	fclose(p1);
	fclose(l);
	if(flag==0)
	printf("\n\n student name %d not found",usn);
	remove("third.txt");
	rename("temp.txt","third.txt");
}
void delspec()
{
struct srecord *f ,*p;
int usn,flag=0;
printf("enter the student usn");
scanf("%d",&usn);
f=first;
if(first==NULL)
{
printf("details doesnot exist\n");
flag=1;
}
else if(f->link==NULL)
{
	if(f->usn==usn)
	{
		first=NULL;
		free(f);
		flag=1;
	}
}
else if(f->usn==usn && f->link!=NULL)
{
	flag=1;
	first=f->link;
	free(f);
}
else
{
	while(f!=NULL)
	{
		if(f->usn==usn)
		{
			flag=1;
			p->link=f->link;
			free(f);
			break;
		}
		else
		{
			p=f;
			f=f->link;
		}
	}
}
if(flag==0)
{
	printf("element doesnot exist\n");
}
}
void search()
{
	char fname[30];
	struct srecord *k;
	int flag=0;
	printf("enter the name to be search\n");
	scanf("%s",fname);
	k=first; 
	while(k!=NULL)
		{
			if(strcmp(fname,k->fname)==0)
			{
				printf("FIRST NAME: %s\n",k->fname);
				printf("LAST NAME: %s\n",k->lname);
				printf("USN: %d\n",k->usn);
				printf("PARENT NAME: %s\n",k->pname);
				printf("ADDRESS: %s\n",k->address);
				printf("PHONE NO.:%d\n",k->phoneno);
			flag=1;
			break;
			}
			else
		k=k->link;
	
	}
	if(flag==0)
	{
	printf("STUDENT DETAILS NOT FOUND\n");
	}
}
int count()
{
FILE *p1;
	int k=0;
	struct srecord *t;
	if(first==NULL)
	{
		printf("%d",k);
		
	}
	else
	{
		t=first;
		while(t!=NULL)
		{
		k++;
		t=t->link;
		}
	printf("no. of student %d",k);
	}
}
int main()
{
	int i,ch;
	do
	{
	printf("welcome to Hostel\n");
	printf("menu\n");
	printf("1.insert the details\n2.display the details\n3 delete the details\n4:search the details\n5 count the details\n6 deleteoffile\n7 create\n");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:Insert();
			break;
		case 2:display1();
		     break;
		case 3:delspec();
		     break;
		case 4:search();
		      break;
		case 5:count();
				break;
		case 6:deleteoffile();
				break;	
		default:printf("invalid\n");
		  	break;
	}
	printf("\ndo you want to continue\n 1.continue\n0.exit\n");
	scanf("%d",&i);
}while(i==1);
	addtofile();
	return 0;

}




