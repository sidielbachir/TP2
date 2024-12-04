#include<stdio.h>
#include<string.h>
#include<stdlib.h>


char* String(int n);

int Length(char *ch);

void FillTab(char *p, char Tab[],int m);

void InvTab(char Tab[], char T[], int m);

void DisTab(char Tab[], int m);

int main()
{
	char *ch=NULL;//ch is a pointer to a string
	int n=0;//n for max size of the string
	int m=0;//m for the length of the string
	char c='\0';//just to clear the stdin after sacnf 

	printf("\nEnter the max size:");
	scanf("%d",&n);
	while((c=getchar())!='\n');
	//clear the stdin
	ch=String(n);
//String is a function to read a string from the keyboard
	//printf("\nString : %s\n",ch);
	
	m=Length(ch);
//Length is a function to get the length of the input string
	printf("\nLength=%d\n",m);
	
	char Tab[m];
	char T[m];
	
	FillTab(ch,Tab,m);
//FillTab is a process which fills in Tab from ch(input string)
	printf("\nTab: ");
	DisTab(Tab,m);
//DisTab is a process which shows the elements of Tab as a string
	InvTab(Tab,T,m);
//InvTab is a process which fill in T from Tab but in oppsite way 
	printf("\nT: ");
	DisTab(T,m);
	
	free(ch);
//clear momery	
	return 0;
}

char* String(int n)
{
	char* ch=(char*)malloc(n+1);
	//dynamic allocation for momery to store the input string
	if(ch==NULL)//to make sure there is enough space in memory
	  {
	  	  printf("\nError String Allocation !!!");
	      exit(1);
	  }   
	else
	  {
		  printf("\nInput the string : ");
		  fgets(ch,n+1,stdin);
		  if(strlen(ch)<n)
		  ch[strlen(ch)-1]='\0';//removing the \n from the string
		  return ch;	
	  }
}
int Length(char *ch)
{
  int count =0;
  
  while(*(ch+count)!='\0')
       count++;
	   
  return count;	   	   	   	
}
void FillTab(char *p, char Tab[],int m)
{
	for(int i=0;i<m;i++)
	  Tab[i]=*(p+i);
	  
	return;  
}
void InvTab(char Tab[], char T[], int m)
{
	for(int i=0;i<m;i++)
	  T[i]=Tab[m-i-1];
	  
	return;  
}
void DisTab(char Tab[], int m)
{
  for(int i=0;i<m;i++)
    printf("%c",Tab[i]);

  return;	 	
}