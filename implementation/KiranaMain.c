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

    int main()
{
    int choice;
    system("cls");
    printf("\nDeepak's Kirana Store Customer Accounts Management E-System");

    printf("\n1.Create a new customer account\n2.Update information of an existing customer\n3.For Payments\n4.Check the details of an existing customer\n5.Removing an existing customer's account\n6.View customer's list\n7.Exit\n\n Enter your choice:");
    scanf("%d",&choice);

    system("cls");
    switch(choice)
    {
        case 1:new_acc();
        break;
        case 2:update();
        break;
        case 3:payments();
        break;
        case 4:display();
        break;
        case 5:delete_acc();
        break;
        case 6:customers();
        break;
        case 7:close();
        break;

    }


        return 0;
}
