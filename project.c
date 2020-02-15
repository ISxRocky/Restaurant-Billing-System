#include<stdio.h>
#include<conio.h>
#include<string.h>
#include <time.h>

float prices[10]={80,80,75,120,180,300,100,50,20,80};
char itm[10][30]={"Buff Mo:Mo","Chowmin","Fried Rice","Chicken Fried Rice","Chopsy","Mixed Pizza","Buff Berger","Roti Tarkari","Milk Tea","Mixed Lassi"};
float tax[10];
int adnum,chnum;
char name[25];

void menu();
void oder();
float adult();
float children();
void manager();
int password();
struct bill{
	char name[25];
	char time[25];
	int anum;
	int cnum;
	float pa;
	float pc;
	float tt;
    }b1;

void main()
{
    char id1[15]="customer",id2[15]="manager",identity[15];
    char response='y';
    clrscr();
    error:
    printf("Please! Enter your identity:");
    scanf("%s",identity);
    if((strcmp(id1,identity))==0)
    {
    menu();

	while(response=='y'||response=='Y')
	{
	    printf("\tPlease,enter the number of adults:");
	    scanf("%d",&adnum);
	    printf("\tPlease,enter the number of children:");
	    scanf("%d",&chnum);

	    oder();
	    printf("\nWold you like to continue(y/n)");
	    scanf("\n%c",&response);
	    printf("\n\t\t************* THANK YOU FOR COMMING *************\n");
	    printf("\t   **************** PLEASE VISIT US NEXT TIME ***************** \n");
	}
    }
    else if((strcmp(id2,identity))==0)
	{manager();}
    else{printf("Invalid identity!.Enter either customer/manager\n");
    goto error;}
    getch();
}

void menu(){
    int i;
    printf("\n");
	printf("\t************* WELCOME TO KHWOPA RESTURANT & FAST FOOD ************* \n\n");
	printf(" \t\t Here is menu,\n");
	printf(" \t\t\t MEALS\t\t\tPRICE:\n");
	printf(" \t\t\t--------------------------------\n");
	for(i=0;i<10;i++){
	    printf(" \t\t\t %2d- %-15s\tRs.%.1f\n",i+1,itm[i],prices[i]);
	}
	printf("\n\t");
	for(i=0;i<70;i++){

		printf("_");
	}
	printf("\n");
}

void oder()// Billing and oderding
{
      FILE *fp;
    //for time and date...
	time_t current_time = time(NULL);
	struct tm *tm = localtime(&current_time);

    float adulttotal=0,childrentotal=0;
    float total,disc;
    printf("\n\n\t\t*************Please place your oder**************\n\n");

    adulttotal=adult();
    childrentotal=children();
    total=adulttotal+childrentotal ;
    clrscr();
     fp=fopen("bill.txt","ab+");
    printf("Enter ur name: ");
    scanf("%s",&b1.name);
    //assigning to structure then into file...
	strcpy(b1.time,asctime(tm));
	b1.anum=adnum;
	b1.cnum=chnum;
	b1.pa=adulttotal;
	b1.pc=childrentotal;

     printf("\n \t   ***************************************************** \n");
     printf(" \t\t***************** FINAL BILL ***************** \n");
     printf(" \t\t   %s\n",asctime(tm));
     printf(" \t\t   Name:%s\n",b1.name);
     printf(" \t\t   Adult/Children\tcount\t\tTotal price\n");
     printf(" \t\t    Adult\t\t %d\t\t %.2f\n",adnum,adulttotal);
     printf(" \t\t    Children\t\t %d\t\t %.2f\n",chnum,childrentotal);
     printf(" \t\t    Total Bill\t\t\t\t %.2f\n",total);
	//discount....
    if (total<500)
	{disc=((total * 2)/100);}
     else if(total>=1000 && total<2000)
	  {disc=((total * 5)/100);}
     else if(total>= 2000 && total<4000)
	 { disc=((total * 10)/100);}
	 else
		  {disc= ((total * 15)/100);}

	  printf(" \t\t    Total bill after discount\t\t %.2f\n",total-disc);
	  b1.tt=total-disc;

	 fwrite(&b1,sizeof(b1),1,fp);
	 fclose(fp);


}
float adult() //oder and calculation for adults
{
      int item,i,amount;
      char response = 'y';
      float t1= 0.0,total = 0.0;
      clrscr();
      menu();
      if(adnum<=0)
		   printf("\n ");
	  else
      printf("\t*Adults:\n");
      for(i=0;i<adnum;i++)
     {
	       printf("\tAdult %d, Please! Enter your orders\n",i+1);
	       while(response == 'y' || response == 'Y')
	       {
			      printf("\tPlease! Enter your option:");
			      scanf("%d",&item);
							  if(item<1 || item>9)
							  {
								  printf("\tSorry we don`t have this order \nagain! ");
								  continue;
							  }
			      printf("\tPlease! Enter tthe number of plates/amount:");
			      scanf("%d",&amount);


			   t1= t1+(amount * prices[item-1] );

			      printf("\n\tWould you like to enter more orders(y/n):");
			      scanf("\n%c",&response);

	       }
	       printf("\n");
	       total=total +t1;
	       t1= 0.0;
	       response = 'y';
     }
    total=total+((total*10)/100);//10%-service charge and taxes

     return total;
}

float children() //oder and calculation for children
{
      int item,i,amount;
      char response = 'y';
      float t2= 0.0,total = 0.0;
      clrscr();
      menu();
       if(chnum<=0)
		   printf("\n");
	   else
       printf("\t*Children:\n");
       for(i=0;i<chnum;i++)
     {
	       printf("\tChild %d Please! Enter your order\n",i+1);
	       while(response == 'y' || response == 'Y')
	       {
			      printf("\tPlease! Enter your option:");
			      scanf("%d",&item);
							  if(item<1 || item>9)
							  {
								  printf("\tSorry we don`t have this order \nagain! ");
				  continue;
							  }
			      printf("\tPlease! Enter your amount of order:");
			      scanf("%d",&amount);
			      t2=t2+(amount*prices[item-1]);
							  printf("\tWould you like to enter more orders(y/n):");
			      scanf("\n%c",&response);
	       }
	       total=total+t2;

	       response = 'y';
	       t2= 0.0;
	       printf("\n");
     }
     total=total-(((15-5)*total)/100); //5% service charge for children and 15%discount on children food.

     return total;
}

//Manager...
void manager()
{
	int p,i,a=1;
      FILE * fp;
	p=password();
	printf("\n\n\n");
	if(p==0){
	menu();
	}
	else
	{
	printf("\nIncorrect Password! \n Re-Enter your Password\n");
	password();
	}
    fp =fopen("bill.txt","a+b");
    rewind(fp);
    while(!feof(fp)){
	fread(&b1,sizeof(b1),1,fp);
	printf("\n\t  %d.\n",a);
	     printf(" \t\t   %s\n",b1.time);
	     printf(" \t\t   Name:%s\n",b1.name);
	     printf(" \t\t   Adult/Children\tcount\t\tTotal price\n");
	     printf(" \t\t    Adult\t\t %d\t\t %.2f\n",b1.anum,b1.pa);
	     printf(" \t\t    Children\t\t %d\t\t %.2f\n",b1.cnum,b1.pc);
	     printf(" \t\t    Total Bill\t\t\t\t %.2f\n",b1.tt);
	     printf("\t");
	     a=a+1;
       for(i=0;i<70;i++){
	printf("_");}
    }
    printf("\n");
	fclose(fp);


}

int password()
{
    char pwd[20];
    int i = 0,j;
	char ch;
	printf("Enter your password:");
	while(1){
		ch = getch();	//get key

		if(ch==13 || ch==9){      //ASCII value of TAB=9 &  enter=13 and pressing of those key indicates end of password.
			pwd[i] = '\0';             // store last char as null char to teminate reading.
			break;
		}else if(ch==8){        //ACSII of backspace=8. so to allowed the backspace n allow to enter new character place of cleared one.
			if(i > 0){
				i--;
				printf("\b \b");		//for backspace- for retuning to position of just cleared character
			}
		}else{
			pwd[i++] = ch;
			printf("* \b");				//to replace password character with ....//length of pw is given by value of "i".
		}
	}
	j=strcmp(pwd,"manager@123");
	return j;


}


