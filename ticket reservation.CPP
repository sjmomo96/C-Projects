#include <stdio.h>
#include <conio.h>
#include<string.h>
struct air
{
  char name[20];
  int phno;
  char address[50];
  int ticketno;

  }
  s;
void view();
void reserve();
void cancel();
void form();
void menu()

{

 int ch;

printf("\tBUS RESERVATION SYSTEM");
printf("\n\n1.VIEW ALL BUSES :");
printf("\n\n2.RESERVE A TICKET :");
printf("\n\n3.CANCEL A TICKET :");
printf("\n\n4.exit ");
printf("\n\nEnter your choice(1,2,3 or 4)");
scanf("%d",&ch);
switch(ch)
{ case 1: view();
	getch();
	menu();
	break;
  case 2: reserve();
	 getch();
	 menu();
	 break;
  case 3: cancel();
  getch();
  menu();
  break;
  default:printf("\nenter a valid choice");
}}
void view()
{

  printf("CODE      ROUTE         PARIBAHAN             TIMINGS   ");
  printf("\n\n100 Dhaka to Barisal    TANNI  PAR.            06:30      ");
  printf("\n101 Dhaka to kalaiya    TANNI  PAR.            12:00    ");
  printf("\n102 Dhaka to Bauphal    TANNI  PAR.            14:30    ");
  printf("\n103 Dhaka to Patuakhali TANNI  PAR.            18:00      ");
  printf("\n104 Dhaka to Dashmina   TANNI  PAR.            20:00      ");

  getch();

}

void form()
{
 printf("\nEnter Your name :");
 scanf("%s",&s.name);
 printf("\nEnter your phone number :");
 scanf("%d",&s.phno);
 printf("\n Enter your address :");
 scanf("%s",&s.address);
 printf("\n\Enter the seat no :");
 scanf("%d",&s.ticketno);
 printf("Your ticket is confirmed");
 getch();
}
void reserve()
{
  int code,total_seats=100,reserved=0,clas;

  if(reserved<total_seats)
  {
	reserved++;
	printf("Enter the train code :");
	scanf("%d",&code);
	if(code==100||code==101||code==102||code==103||code==104)
	 {

	  printf("\n 1.first class(fare 1500  taka)");
	  printf("\n 2.second class(fare 800 taka)");
	  printf("\n 3.sleeper class(fare 500 taka)");
	  scanf("%d",&clas);
		 if(clas==1)
		 {


 printf("Your fare is 1500 taka");
  form();
  menu();
		 }
		 else if(clas==2)
		 {

 printf("\nYour fare is  800 taka");
  form();
  menu();
		 }
		 else if(clas==3)
		 {

		 printf("\n Your fare is 500 taka");
  form();
  menu();
		 }
		 else
		 {

  printf("Enter valid choice(1, 2 or 3)");
  menu();
		 }
 getch();
}
else
 printf("WARNING! \nYOU HAVE ENTERED THE WRONG CODE");

}
}
void cancel()
{int ticket;
 char ch;

printf("Enter the ticket no :");
scanf("%d",&ticket);
 if(ticket==s.ticketno)
  {    printf("Your ticket is cancelled");
	getch();
	}
 else
 {printf("Ticket no is invalid");
  getch();
 menu();
}}
 main()
{

		printf("\t\tThanks for being with JESUN");
		 printf("\n\n\t      WELCOME TO TANNI Tarnsport co.Ltd");

 getch();
 menu();
}

