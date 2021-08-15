#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
struct node
{
    int itemno,quantity;
    char foodname[30];
    float price;
    struct node *link;
};
typedef struct node *NODE;
NODE head,head1;

NODE insert(NODE head,int itemno,char foodname[30],float price);
void display(NODE head);
float calculation1(NODE head,int inum,int q);
NODE order(NODE head1,int itemno,char foodname[30],float price,int q);
void displayorder(NODE head1,int q);
void OPTION2();
void combo1(float budget,float i1,float i2,float i3);
void formula1(float budget);
void combo2(float budget,float i1,float i2,float i3);
void formula2(float budget);
void OPTION1();
void restaurant1();
void restaurant2();
void restaurant3();

void main()
{
    char name[30],add[100],suggests[100];
    char phno[10],cardno[30],cvv[5],phno1[10];
    int confirm,rate;
    int x,op,inum,q,mode,otp,diff;
    float y;
    char fooditem[30];
    int choice;
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~  WELCOME TO OPTIO  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
    printf("\nEnter your name: ");
    getchar();
    gets(name);
    printf("\nEnter your phone number: ");
    while(1)
    {
        scanf("%s",phno);
        if(strlen(phno)!=10)
        {
            printf("Error!Re Enter phone number: ");
            continue;
        }
        break;
    }
    printf("\nEnter your address: ");
    getchar();
    gets(add);
    printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~  RESTAURANTS  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("\n1.The Burger Place \n2.Indian Delight \n3.The Pizzeria\n");
    printf("\nSELECT A RESTRAUNT: ");
    while(1)
    {
         scanf("%d",&choice);
         if(choice!=1 && choice!=2 && choice!=3)
         {
             printf("\nRe Enter your choice: ");
             continue;
         }
         break;
    }
   switch(choice)
    {
        case 1: restraunt1();
                break;

        case 2: restraunt2();
                break;

        case 3 :restaurant3();
                break;

        default:printf("INVALID OPTION!\n");
    }
     printf("\n\nEnter the mode of payment\n");
     printf("\n1)Cash on Delivery\n2)Debit Card\n3)UPI\n");
     printf("\nMode of payment: ");
      while(1)
     {
         scanf("%d",&mode);
         if(mode!=1 && mode!=2 && mode!=3)
         {
             printf("Re Enter the correct choice: ");
             continue;
         }
         break;
     }
     switch(mode)
     {
         case 1: break;
         case 2: printf("\nEnter the Debit Card number:  ");
         while(1)
         {
             scanf("%s",cardno);
             if(strlen(cardno)!=16)
             {
                 printf("\nError!Re enter your Debit Card no: ");
                 continue;
             }
             break;
          }
          printf("\nEnter the CVV number: ");
         while(1)
         {
             scanf("%s",cvv);
             if(strlen(cvv)!=3)
             {
                 printf("\nError!Re enter your CVV: ");
                 continue;
             }
             break;
         }
          printf("\nEnter the generated OTP: ");
          while(1)
         {
             scanf("%s",otp);
             if(strlen(otp)!=4)
             {
                 printf("\nError!Re Enter your OTP: ");
                 continue;
             }
             break;
         }
         printf("\nYour payment has been processed!!");
         break;

         case 3: printf("\nEnter the phone no: ");
           while(1)
           {
               scanf("%s",phno1);
               diff=strcmp(phno,phno);
               if(diff!=0)
               {
                   printf("Error!Please enter the right phone number: ");
                   continue;
               }
               break;
           }
               printf("\nEnter the OTP generated: ");
               while(1)
           {
                scanf("%s",otp);
                if(strlen(otp)!=4)
                {
                    printf("\nError!Re enter your OTP: ");
                    continue;
                }
                break;
           }
                printf("\nYour payment has been processed!!");
                break;
         default: printf("Inavlid Choice!!!");
                break;
       }
           printf("\nYour order will be delivered to your address in the next 30 minutes\n");
           printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
           printf("\nHave you received your order?\n");
           printf("\n1)Yes\n2)No\n");
           printf("\nEnter the choice: ");
           while(1)
           {
               scanf("%d",&confirm);
               if(confirm==2)
               {
                   printf("Please wait your order will arrive soon!\n");
                   printf("\nHave you received your order?\n");
                   printf("\n1)Yes\n2)No\n");
                   printf("\nEnter the choice: ");
                   continue;
               }
               break;
           }
           printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
           printf("\nPlease rate the service out of 5!\n");
           printf("\n1-Unsatisfactory\n2-Satisfactory\n3-Good\n4-Very Good\n5-Excellent\n");
           printf("\nRATING: ");
           while(1)
           {
           scanf("%d",&rate);
           if(rate>5)
           {
               printf("Enter the correct choice; ");
               continue;
           }
           break;
           }
           printf("\n\nPlease suggest in what aspects we can improve\n");
           scanf("%s",suggests);
           printf("\nThank you for the feedback.All points will be noted down and will be taken into consideration!!\n");
           printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Thank You for ordering from Optio~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

}

NODE insert(NODE head,int itemno,char foodname[30],float price)
{
    NODE temp,cur;
    temp=(NODE*)malloc(sizeof(struct node));
    temp->itemno=itemno;
    temp->price=price;
    strcpy(temp->foodname,foodname);
    temp->link=temp;
    cur=head;
    if(cur->link==NULL)
        {
            cur->link=temp;
            temp->link=head;
        }
    else
        {
            while(cur->link!=head)
            {
                cur=cur->link;
            }
            cur->link=temp;
            temp->link=head;
        }
     return head;
}

void restraunt1()
{
  int op,inum,q,combo;
  int choice;
  float amount,totalamount=0;
  head=NULL;
  head=insert(&head,1,"Small Fries",100);
  head=insert(&head,2,"Medium Fries",150);
  head=insert(&head,3,"Large Fries",175);
  head=insert(&head,4,"Veg Burger-S",250);
  head=insert(&head,5,"Veg Burger-L",300);
  head=insert(&head,6,"Chikn Burger-S",350);
  head=insert(&head,7,"Chickn Burger-L",400);
  head=insert(&head,8,"Small Pepsi",100);
  head=insert(&head,9,"Medium Pepsi",125);
  head=insert(&head,10,"Large Pepsi",150);
  display(head);
  printf("\nOption 1: Select any item from the menu of your choice\n");
  printf("\nOption 2: Enter your budget and select any combo from the two combos that will be displayed\n");
  printf("\nSelect Option 1 or Option 2: ");
  while(1)
    {
         scanf("%d",&op);
         if(op!=1 && op!=2)
         {
             printf("\nRe Enter your choice: ");
             continue;
         }
         break;
    }
  if(op==1)
    OPTION1();

  if(op==2)
    OPTION2();
}

void restraunt2()
{
    int op,choice,inum,q,combo;
    float amount,i1,i2,i3;
    float totalamount=0;
    head=NULL;
    head=insert(&head,1,"Paneer 65",100);
    head=insert(&head,2,"Chicken 65",150);
    head=insert(&head,3,"Chikn Tikka(4)",175);
    head=insert(&head,4,"Veg Biryani",250);
    head=insert(&head,5,"Spl Veg Biryani",300);
    head=insert(&head,6,"Chikn Biryani",350);
    head=insert(&head,7,"Sp Chkn Biryani",400);
    head=insert(&head,8,"Vanilla Shake",100);
    head=insert(&head,9,"Chocolate Shake",125);
    head=insert(&head,10,"Oreo Shake",150);
    display(head);
    printf("\nOption 1: Select any item from the menu of your choice\n");
    printf("\nOption 2: Enter your budget and select any combo from the two combos that will be displayed\n");
    printf("\nSelect Option 1 or Option 2: ");
    while(1)
    {
         scanf("%d",&op);
         if(op!=1 && op!=2)
         {
             printf("\nRe Enter your choice: ");
             continue;
         }
         break;
    }
    if(op==1)
      OPTION1();

    if(op==2)
      OPTION2();
}

void restaurant3()
{
    int op;
    head=NULL;
    head=insert(&head,1,"French Fries",100);
    head=insert(&head,2,"Potato Fingers",150);
    head=insert(&head,3,"Garlic Bread(4)",175);
    head=insert(&head,4,"Veg Exotica",250);
    head=insert(&head,5,"Very Veggie",300);
    head=insert(&head,6,"Chikn Pizza",350);
    head=insert(&head,7,"Pepperoni Pizza",400);
    head=insert(&head,8,"Small Pepsi",100);
    head=insert(&head,9,"Medium Pepsi",125);
    head=insert(&head,10,"Large Pepsi",150);
    display(head);
    printf("\nOption 1: Select any item from the menu of your choice\n");
    printf("\nOption 2: Enter your budget and select any combo from the two combos that will be displayed\n");
    printf("\nSelect Option 1 or Option 2: ");
    while(1)
    {
         scanf("%d",&op);
         if(op!=1 && op!=2)
         {
             printf("\nRe Enter your choice: ");
             continue;
         }
         break;
    }
    if(op==1)
       OPTION1();

    if(op==2)
       OPTION2();
}

void display(NODE head)
{
    NODE temp;
    temp=head->link;
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~        THE MENU        ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("\t\t\t\t _______________________________________________________\n");
    printf("\t\t\t\t|  ITEM NO.\t|\t  NAME\t\t|    TOTALPRICE |\n");
    printf("\t\t\t\t _______________________________________________________\n");
    printf("\t\t\t\t _______________________________________________________\n");
    while(temp!=head)
        {
            printf("\t\t\t\t|\t%d\t|\t%s\t|\t%0.2f\t|\n",temp->itemno,temp->foodname,temp->price);
            printf("\t\t\t\t _______________________________________________________\n");
            temp=temp->link;
        }
        printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
}

void OPTION1()
{

    int op,choice,inum,q,combo;
    float amount;
    float totalamount=0;
    while(1)
      {
        printf("\nEnter the item number: ");
        scanf("%d",&inum);
        printf("\nEnter the quantity: ");
        scanf("%d",&q);
        amount=calculation1(&head,inum,q);
        totalamount+=amount;
        printf("\nCurrent total is:%0.2f\n",totalamount);
        printf("\n1)Continue ordering 0)Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d",&choice);
        if(choice==1)
            continue;
        else
        {
            printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~   BILL    ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
            displayorder(&head1,q);
            printf("\nTotal Amount:%0.2f\n",totalamount);
            printf("~~~~~~~~~~~~~~~~~~~~~~");
            break;
        }
      }
}

float calculation1(NODE head,int inum,int q)
{
    NODE cur;
    int itemno,quantity;
    cur=head->link;
    float x;
    float price;
    char foodname[30];
    while(cur!=head)
    {

        if(inum==cur->itemno)
        {
            x=cur->price;
            x=x*q;
            itemno=cur->itemno;
            price=cur->price;
            strcpy(foodname,cur->foodname);
            head1=order(&head1,itemno,foodname,x,q);
            return x;
        }
        cur=cur->link;
    }
}

NODE order(NODE head1,int itemno,char foodname[30],float price,int q)
{
    NODE temp,cur;
    temp=(NODE*)malloc(sizeof(struct node));
    temp->itemno=itemno;
    temp->price=price;
    strcpy(temp->foodname,foodname);
    temp->quantity=q;
    temp->link=NULL;
    cur=head1;
    if(cur->link==NULL)
        {
            head1->link=temp;
            temp->link=head1;
        }
    else
        {
            while(cur->link!=head1)
            {
                cur=cur->link;
            }
            cur->link=temp;
            temp->link=head1;
        }
    return head1;
}

void displayorder(NODE head1,int q)
{
    NODE temp;
    temp=head1->link;
    printf("\t\t _________________________________________________________________________________\n");
    printf("\t\t|ITEM NO.\t|\tNAME\t\t|\tQUANTITY\t|\tTOTALPRICE|\n");
    printf("\t\t _________________________________________________________________________________\n");
    printf("\t\t _________________________________________________________________________________\n");
    while(temp!=head1)
        {
            printf("\t\t|\t%d\t|\t%s\t|\t%d\t\t|\t%0.2f\t  |\n",temp->itemno,temp->foodname,temp->quantity,temp->price);
            printf("\t\t _________________________________________________________________________________\n");
            temp=temp->link;
        }
        printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
}

void OPTION2()
{
    float budget;
    int combo;
    printf("\nPlease mention your budget in the range of 500 to 800 Rupees\n");
    printf("\nEnter your budget: ");
    while(1)
    {
       scanf("%f",&budget);
       if(budget<500 || budget>800)
       {
           printf("\nRe Enter your budget: ");
           continue;
       }
       break;
    }
    formula1(budget);
    formula2(budget);
    printf("\n\nWhich Combo would you like to order?\n");
    printf("\n1)COMBO 1\n2)COMBO 2\n");
    printf("\nSelect the COMBO: ");
    while(1)
    {
        scanf("%d",&combo);
        if(combo==1)
        {
           formula1(budget);
           break;
        }

        if(combo==2)
        {
            formula2(budget);
            break;
        }
        else
        {
            printf("\nError!Re enter your choice: ");
            continue;
        }

    }
}

void formula1(float budget)
{
    float i1,i2,i3;
    i1=budget * (0.2);
    i2=budget * (0.5);
    i3=budget * (0.1);
    combo1(budget,i1,i2,i3);
}

void formula2(float budget)
{
    float i1,i2,i3;
    i1=budget * (0.2);
    i2=budget * (0.4);
    i3=budget * (0.2);
    combo2(budget,i1,i2,i3);
}

void combo1(float budget,float i1,float i2,float i3)
{
    NODE cur,item1,item2,item3;
    cur=head->link;
    float diff,price,tprice,d;
    while(cur->itemno<=3)
    {
        price=cur->price;
        diff=price-i1;

        if(fabs(diff)<25)
        {
            item1=cur;
        }
        cur=cur->link;
    }
    while(cur->itemno<=7)
    {
       price=cur->price;
       diff=price-i2;
        if(fabs(diff)<50)
        {
            item2=cur;
        }
        cur=cur->link;
    }
    while(cur->itemno<=10)
    {
        diff=cur->price-i3;
        if(fabs(diff)<=70)
        {
            item3=cur;
        }
        cur=cur->link;
    }
    tprice=item1->price+item2->price+item3->price;
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~   COMBO 1   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
    printf("\t\t\t\t _______________________________________________________\n");
    printf("\t\t\t\t|ITEM NO.\t|\tNAME\t\t|TOTALPRICE\t|\n");
    printf("\t\t\t\t _______________________________________________________\n");
    printf("\t\t\t\t _______________________________________________________\n");
    printf("\t\t\t\t|\t%d\t|\t%s\t|\t%0.2f\t|\n",item1->itemno,item1->foodname,item1->price);
    printf("\t\t\t\t|\t%d\t|\t%s\t|\t%0.2f\t|\n",item2->itemno,item2->foodname,item2->price);
    printf("\t\t\t\t|\t%d\t|\t%s\t|\t%0.2f\t|\n",item3->itemno,item3->foodname,item3->price);
    printf("\t\t\t\t _______________________________________________________\n");
    printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("Total price:%0.2f\n",tprice);
    printf("~~~~~~~~~~~~~~~~~~\n");
    d=budget-tprice;
    printf("\nAmount saved:%0.2f\n",d);
    printf("~~~~~~~~~~~~~~~~~~\n");
}

void combo2(float budget,float i1,float i2,float i3)
{
    NODE cur,item1,item2,item3;
    cur=head->link;
    float diff,price,tprice,d;
    while(cur->itemno<=3)
    {
        price=cur->price;
        diff=price-i1;
        if(fabs(diff)<50)
        {
            item1=cur;
        }
        cur=cur->link;
    }
    while(cur->itemno<=7)
    {
       price=cur->price;
       diff=price-i2;
        if(fabs(diff)<51)
        {
            item2=cur;
        }
        cur=cur->link;
    }
    while(cur->itemno<=10)
    {
        diff=cur->price-i3;
        if(fabs(diff)<=70)
        {
            item3=cur;
        }
        cur=cur->link;
    }
    tprice=item1->price+item2->price+item3->price;
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~   COMBO 2   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
    printf("\t\t\t\t _______________________________________________________\n");
    printf("\t\t\t\t|ITEM NO.\t|\tNAME\t\t|TOTALPRICE\t|\n");
    printf("\t\t\t\t _______________________________________________________\n");
    printf("\t\t\t\t _______________________________________________________\n");
    printf("\t\t\t\t|\t%d\t|\t%s\t|\t%0.2f\t|\n",item1->itemno,item1->foodname,item1->price);
    printf("\t\t\t\t|\t%d\t|\t%s\t|\t%0.2f\t|\n",item2->itemno,item2->foodname,item2->price);
    printf("\t\t\t\t|\t%d\t|\t%s\t|\t%0.2f\t|\n",item3->itemno,item3->foodname,item3->price);
    printf("\t\t\t\t _______________________________________________________\n");
    printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("Total price:%0.2f\n",tprice);
    printf("~~~~~~~~~~~~~~~~~~\n");
    d=budget-tprice;
    printf("\nAmount saved:%0.2f\n",d);
    printf("~~~~~~~~~~~~~~~~~\n");
}















