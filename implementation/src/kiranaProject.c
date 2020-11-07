#include<kirana.h>

int i,j;
int main_exit;
struct date{
    int month,day,year;

    };
struct {

    char name[50];
    int acc_no,age;
    char address[100];

    double phone;

    float amt;

    struct date balance;


    }add,upd,check,rem,transaction;
void new_acc()

{
    int choice;
    FILE *ptr;
    int i,k;
    ptr=fopen("record.dat","a+");
    account_no:
    //system("cls");
    printf("ADD RECORD");
    printf("\n\n\nEnter today's date(mm/dd/yyyy):");
    scanf("%d/%d/%d",&add.balance.month,&add.balance.day,&add.balance.year);
    printf("\nEnter the customer's account number:");
    scanf("%d",&check.acc_no);
    while(fscanf(ptr,"%d %s %d %s %lf %f %d/%d/%d\n",&add.acc_no,add.name,&add.age,add.address,&add.phone,&add.amt,&add.balance.month,&add.balance.day,&add.balance.year)!=EOF)
    {
        if (check.acc_no==add.acc_no)
            {printf("Account no. already in use!");
            for(i=0;i<10000;i++)
                k=i;
                goto account_no;

            }
    }
    add.acc_no=check.acc_no;
    printf("\nEnter the customer's name:");
    scanf("%s",add.name);

    printf("\nEnter the customer's age:");
    scanf("%d",&add.age);
    printf("\nEnter the customer's address:");
    scanf("%s",add.address);

    printf("\nEnter the customer's phone number: ");
    scanf("%lf",&add.phone);
    printf("\nEnter the amount to add to this customer's account:$");
    scanf("%f",&add.amt);


        fprintf(ptr,"%d %s %d %s %lf %f %d/%d/%d\n",add.acc_no,add.name,add.age,add.address,add.phone,add.amt,add.balance.month,add.balance.day,add.balance.year);


    fclose(ptr);
    printf("\nAccount created successfully!");
    add_invalid:
    printf("\n\n\n\t\tEnter 1 to go to the main menu and 0 to exit:");
    scanf("%d",&main_exit);
    //system("cls");
    if (main_exit==1)
        main();
    else if(main_exit==0)
            close();
    else
        {
            printf("\nInvalid!\a");
            goto add_invalid;
        }
}
void customers()
{
    FILE *view;
    view=fopen("record.dat","r");
    int test=0;
    //system("cls");
    printf("\nACC. NO.\tNAME\t\t\tADDRESS\t\t\tPHONE\n");

    while(fscanf(view,"%d %s %d %s %lf %f %d/%d/%d\n",&add.acc_no,add.name,&add.age,add.address,&add.phone,&add.amt,&add.balance.month,&add.balance.day,&add.balance.year)!=EOF)
       {
           printf("\n%6d\t %10s\t\t\t%10s\t\t%.0lf",add.acc_no,add.name,add.address,add.phone);
           test++;
       }

    fclose(view);
    if (test==0)
        {   //system("cls");
            printf("\nNO RECORDS!!\n");}

    view_list_invalid:
     printf("\n\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d",&main_exit);
        //system("cls");
        if (main_exit==1)
            main();
        else if(main_exit==0)
            close();
        else
        {
            printf("\nInvalid!\a");
            goto view_list_invalid;
        }
}
void update(void)
{
    int choice,test=0;
    FILE *old,*newrec;
    old=fopen("record.dat","r");
    newrec=fopen("new.dat","w");

    printf("\nEnter the account no. of the customer whose info you want to change:");
    scanf("%d",&upd.acc_no);
    while(fscanf(old,"%d %s %d %s %lf %f %d/%d/%d\n",&add.acc_no,add.name,&add.age,add.address,&add.phone,&add.amt,&add.balance.month,&add.balance.day,&add.balance.year)!=EOF)
    {
        if (add.acc_no==upd.acc_no)
        {   test=1;
            printf("\nWhich information do you want to change?\n1.Address\n2.Phone\n\n\nEnter your choice(1 for address and 2 for phone):");
            scanf("%d",&choice);
            //system("cls");
            if(choice==1)
                {printf("Enter the new address:");
                scanf("%s",upd.address);
                fprintf(newrec,"%d %s %d %s %lf %f %d/%d/%d\n",add.acc_no,add.name,add.age,upd.address,add.phone,add.amt,add.balance.month,add.balance.day,add.balance.year);
                //system("cls");
                printf("Changes saved!");
                }
            else if(choice==2)
                {
                    printf("Enter the new phone number:");
                scanf("%lf",&upd.phone);
                fprintf(newrec,"%d %s %d %s %lf %f %d/%d/%d\n",add.acc_no,add.name,add.age,add.address,upd.phone,add.amt,add.balance.month,add.balance.day,add.balance.year);
                //system("cls");
                printf("Changes saved!");
                }

        }
        else
            fprintf(newrec,"%d %s %d %s %lf %f %d/%d/%d\n",add.acc_no,add.name,add.age,add.address,add.phone,add.amt,add.balance.month,add.balance.day,add.balance.year);
    }
    fclose(old);
    fclose(newrec);
    remove("record.dat");
    rename("new.dat","record.dat");

if(test!=1)
        {   //system("cls");
            printf("\nRecord not found!!\a\a\a");
            edit_invalid:
              printf("\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
              scanf("%d",&main_exit);
              //system("cls");
                 if (main_exit==1)

                    main();
                else if (main_exit==2)
                    close();
                else if(main_exit==0)
                    update();
                else
                    {printf("\nInvalid!\a");
                    goto edit_invalid;}
        }
    else
        {printf("\n\n\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d",&main_exit);
        //system("cls");
        if (main_exit==1)
            main();
        else
            close();
        }
}

void payments(void)
{   int choice,test=0;
    FILE *old,*newrec;
    old=fopen("record.dat","r");
    newrec=fopen("new.dat","w");

        printf("Enter the account no. of the customer:");
    scanf("%d",&transaction.acc_no);
    while (fscanf(old,"%d %s %d %s %lf %f %d/%d/%d\n",&add.acc_no,add.name,&add.age,add.address,&add.phone,&add.amt,&add.balance.month,&add.balance.day,&add.balance.year)!=EOF)
   {

            if(add.acc_no==transaction.acc_no)
            {   test=1;

                printf("\n\nDo you want to\n1.Add\n2.Deduct?\n\nEnter your choice(1 for deposit and 2 for withdraw):");
                scanf("%d",&choice);
                if (choice==1)
                {
                    printf("Enter the amount you want to Add:$ ");
                    scanf("%f",&transaction.amt);
                    add.amt+=transaction.amt;
                    fprintf(newrec,"%d %s %d %s %lf %f %d/%d/%d\n",add.acc_no,add.name,add.age,add.address,add.phone,add.amt,add.balance.month,add.balance.day,add.balance.year);
                    printf("\n\nAdded successfully!");
                }
                else
                {
                    printf("Enter the amount you want to Deduct:$ ");
                    scanf("%f",&transaction.amt);
                    add.amt-=transaction.amt;
                    fprintf(newrec,"%d %s %d %s %lf %f %d/%d/%d\n",add.acc_no,add.name,add.age,add.address,add.phone,add.amt,add.balance.month,add.balance.day,add.balance.year);
                    printf("\n\nPayment Done successfully!");
                }

            }
            else
            {
               fprintf(newrec,"%d %s %d %s %lf %f %d/%d/%d\n",add.acc_no,add.name,add.age,add.address,add.phone,add.amt,add.balance.month,add.balance.day,add.balance.year);
            }
   }
   fclose(old);
   fclose(newrec);
   remove("record.dat");
   rename("new.dat","record.dat");
   if(test!=1)
   {
       printf("\n\nRecord not found!!");
       transact_invalid:
      printf("\n\n\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
      scanf("%d",&main_exit);
      //system("cls");
      if (main_exit==0)
        payments();
    else if (main_exit==1)
        main();
    else if (main_exit==2)
        close();
    else
    {
        printf("\nInvalid!");
        goto transact_invalid;
    }

   }
   else
   {
       printf("\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d",&main_exit);
       // system("cls");
        if (main_exit==1)
            main();
        else
            close();
   }

}
void delete_acc(void)
{
    FILE *old,*newrec;
    int test=0;
    old=fopen("record.dat","r");
    newrec=fopen("new.dat","w");
    printf("Enter the account no. of the customer you want to delete:");
    scanf("%d",&rem.acc_no);
    while (fscanf(old,"%d %s %d %s %lf %f %d/%d/%d\n",&add.acc_no,add.name,&add.age,add.address,&add.phone,&add.amt,&add.balance.month,&add.balance.day,&add.balance.year)!=EOF)
   {
        if(add.acc_no!=rem.acc_no)
            fprintf(newrec,"%d %s %d %s %lf %f %d/%d/%d\n",add.acc_no,add.name,add.age,add.address,add.phone,add.amt,add.balance.month,add.balance.day,add.balance.year);

        else
            {test++;
            printf("\nCustomer deleted successfully!\n");
            }
   }
   fclose(old);
   fclose(newrec);
   remove("record.dat");
   rename("new.dat","record.dat");
   if(test==0)
        {
            printf("\nRecord not found!!\a\a\a");
            erase_invalid:
              printf("\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
              scanf("%d",&main_exit);

                 if (main_exit==1)
                    main();
                else if (main_exit==2)
                    close();
                else if(main_exit==0)
                    delete_acc();
                else
                    {printf("\nInvalid!\a");
                    goto erase_invalid;}
        }
    else
        {printf("\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d",&main_exit);
       // system("cls");
        if (main_exit==1)
            main();
        else
            close();
        }

}

void display(void)
{
    FILE *ptr;
    int test=0,rate;
    int choice;
    float time;
    float intrst;
    ptr=fopen("record.dat","r");
    printf("Do you want to check by\n1.Account no\n2.Name\nEnter your choice:");
    scanf("%d",&choice);
    if (choice==1)
    {   printf("Enter the account number:");
        scanf("%d",&check.acc_no);

        while (fscanf(ptr,"%d %s %d %s %lf %f %d/%d/%d\n",&add.acc_no,add.name,&add.age,add.address,&add.phone,&add.amt,&add.balance.month,&add.balance.day,&add.balance.year)!=EOF)
        {
            if(add.acc_no==check.acc_no)
            {   //system("cls");
                test=1;

                printf("\nAccount NO.:%d\nName:%s \nAge:%d \nAddress:%s \nPhone number:%.0lf \nAmount:$ %.2f \nDate Of update:%d/%d/%d\n\n",add.acc_no,add.name,add.age,add.address,add.phone,add.amt,add.balance.month,add.balance.day,add.balance.year);


            }
        }
    }
    else if (choice==2)
    {   printf("Enter the name:");
        scanf("%s",&check.name);
        while (fscanf(ptr,"%d %s %d %s %lf %f %d/%d/%d\n",&add.acc_no,add.name,&add.age,add.address,&add.phone,&add.amt,&add.balance.month,&add.balance.day,&add.balance.year)!=EOF)
        {
            if(strcmpi(add.name,check.name)==0)
            {   //system("cls");
                test=1;
                printf("\nAccount NO.:%d\nName:%s \nAge:%d \nAddress:%s \nPhone number:%.0lf \nAmount:$ %.2f \nDate Of update:%d/%d/%d\n\n",add.acc_no,add.name,add.age,add.address,add.phone,add.amt,add.balance.month,add.balance.day,add.balance.year);

            }
        }
    }


    fclose(ptr);
     if(test!=1)
        {   //system("cls");
            printf("\nRecord not found!!\a\a\a");
            see_invalid:
              printf("\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
              scanf("%d",&main_exit);
              //system("cls");
                 if (main_exit==1)
                    main();
                else if (main_exit==2)
                    close();
                else if(main_exit==0)
                    display();
                else
                    {
                       // system("cls");
                        printf("\nInvalid!\a");
                        goto see_invalid;}
        }
    else
        {printf("\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d",&main_exit);}
        if (main_exit==1)
        {
            //system("cls");
            main();
        }

        else
           {

            // system("cls");
            close();
            }

}


void close(void)
{
    printf("\n\nThank you!");
    }
