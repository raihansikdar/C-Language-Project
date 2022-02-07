#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#define ENTER 13
#define TAB 9
#define BKSP 8
#define SPACE 32
char date[20];
char uname[20];
char bname[20];
char mno[15];
long int cost;
int n,i;
void write()
{
    FILE *fp;
    char dat[20];
    char unam[100];
    char bnam[20];
    char mn[15];
    long int cos;
    printf("\n\tEnter date    :: ");
    scanf("%s",&dat);
    printf("\n\tEnter name of customer   :: ");
    scanf("%s",&unam);
    printf("\n\tEnter mobile number      :: ");
    scanf("%s",&mn);
    printf("\n\tEnter name of book       :: ");
    scanf("%s",&bnam);
    printf("\n\tEnter cost of book       :: ");
    scanf("%ld",&cos);
    fp=fopen("Record.txt","a");
    //fprintf(fp,"\nDate\t\t-\tUser Name\t-\tMobile Number\t-\tBook Name\t-\tBook Cost ");
    fprintf(fp,"\n%s  %s  %s  %s  %ld\n",dat,unam,mn,bnam,cos);
    printf("\n\t\t  >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
    printf("\t\t||     Record has been written successfully     ||\n");
    printf("\t\t  <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n\n");
    fclose(fp);

}
void display(char da[])
{
    FILE *fp;
    int res;
    fp=fopen("Record.txt","r");
    while(fscanf(fp,"%s  %s  %s  %s  %ld\n",date,uname,mno,bname,&cost)!=EOF)
    {
       res=strcmp(date,da);
    if(res==0)
    {
        printf("\n\n\tCustomer name = %s",uname);
        printf("\n\n\tMobile number = %s",mno);
        printf("\n\n\tBook name     = %s",bname);
        printf("\n\n\tBook cost     = %ld\n\n",cost);
    }
    }
    fclose(fp);
}
int main()
{

    int num;
    char lm[20];
    char password[30];
    int c,i=0;
    char ch;
    printf("\t  _____________________________\n");
    printf("\t||\t  Enter Password :     ||\n");
    printf("\t||_____________________________||\n");
    printf("\t                |           \n");
    printf("\t                V           \n");
    printf("\t              ");
    while(1)
    {
        ch=getch();
        if(ch==ENTER)
        {
            password[i]='\0';
            break;
        }
        else if(ch==BKSP)
        {
            if(i>0)
            {
                i--;
                printf("\b \b");
            }
        }
        else if(ch==TAB || ch==SPACE)
        {
            continue;
        }
        else
        {
            password[i]=ch;
            i++;
            printf("*");
        }
    }
         printf("\n\t\t\t\t  ____________________________________\n");
         printf("\t\t\t\t|| Do you want to show your password  ||\n");
         printf("\t\t\t\t||----------------->><<---------------||\n");
         printf("\t\t\t\t|| 1.   To show your password         ||\n");
         printf("\t\t\t\t||------------------------------------||\n");
         printf("\t\t\t\t|| 2.  Not to show your password     ||\n");
         printf("\t\t\t\t||____________________________________||\n");

         printf("\n\n\t\t\t\t      Enter your choice : ");

         scanf("%d",&c);


      if(c==1)
      {
         printf("\n\n\t  _________________________________\n");
         printf("\t||  Your password is :  %s      ||\n",password);
         printf("\t||_________________________________||\n");

      }
      else
      {
         printf("\n\n\t  _________________________________\n");
         printf("\t||  Don't show my password         ||\n");
         printf("\t||_________________________________||\n");
      }
        printf("\n\n\t\t\t\t\t*********************************************\n");
        printf("\t\t\t\t\t||<<<<<<<< WELCOME TO MY BOOKSHOP >>>>>>>>>||\n");
        printf("\t\t\t\t\t*********************************************\n");
        printf("\t\t\t\t\t                       |                           \n");
        printf("\t\t\t\t\t                       V                           \n");

  do
    {
        printf("\t\t\t\t\t  ___________________________________\n");
        printf("\t\t\t\t\t||               MAIN MENU            ||\n");
        printf("\t\t\t\t\t||------------------------------------||\n");
        printf("\t\t\t\t\t|| 1. To create entry for book        ||\n");
        printf("\t\t\t\t\t||------------------------------------||\n");
        printf("\t\t\t\t\t|| 2. To display on specific date     ||\n");
        printf("\t\t\t\t\t||------------------------------------||\n");
        printf("\t\t\t\t\t|| 0. To exit                         ||\n");
        printf("\t\t\t\t\t||____________________________________||\n");

        printf("\n\n\t\t\tEnter choice  :: ");
        scanf("%d",&num);

     switch(num)
     {
         case 1:
             write();
              break;
         case 2:
             printf("\n\n\tENTER DATE  :: ");
             scanf("%s",&lm);
             display(lm);
                  break;
         case 0:
             exit(0);
        default :
            printf("\n\n\t\t\t###### Invalid selection #####\n");
     }

   }while(ch!=0);

}
