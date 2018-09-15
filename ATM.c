#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Account_Holder
{
    char Name[30];
    int Acc_No;
    char password[9];
    float Amount;

};
int main()
{
    struct Account_Holder A_N[10] = {
    {"Chetan",1051,"ABCD1234",3000},
    {"Gourav",1052,"BCDE2345",4000},
    {"Mona",1053,"CDEF3456",5000},
    {"Sushil",1054,"DEFG4567",6000},
    {"Mansi",1055,"EFGH5678",7000}
    };
    struct Account_Holder *a;
    float amount;
    int num1,num2,AccNo,count=0,count1=0,count2=0;
    char password[9];
    do
    {
        system("cls");
        printf("\n________________________________\n");
        printf("Welcome to TechTelegraph Bank :)\n");
        printf("Press 1: Excisting Customer\n");
        printf("Press 2: New Customer\n");
        printf("Press 3: Exit\n");
        printf("Enter Value: ");
        scanf("%d",&num1);
        fflush(stdin);
        switch(num1)
        {
            case 1:
                    printf("\nEnter Account No ");
                    fflush(stdin);
                    scanf("%d",&AccNo);
                    fflush(stdin);
                    for(int i = 0 ;i < 10;i++)
                    {
                        if(A_N[i].Acc_No==AccNo)
                        {
                            do
                            {
                                system("cls");
                                if(count1 > 0)
                                {
                                    printf("\n %d Chances Left\n",(3-count1));
                                    getch();
                                }
                                printf("\nHello Mr/Mrs %s Enter Password : ",A_N[i].Name);
                                fflush(stdin);
                                gets(password);
                                if(strcmp(password,A_N[i].password) == 0)
                                {
                                    system("cls");
                                    do{
                                        system("cls");
                                        a = &A_N[i];
                                        printf("\nWelcome to Account %s :", A_N[i].Name);
                                        printf("_________________________________");
                                        printf("\nEnter_No\tOperation");
                                        printf("\n1\t\tBalace Inquiry");
                                        printf("\n2\t\tCash Deposit");
                                        printf("\n3\t\tCash Withdraw");
                                        printf("\n4\t\tChange Password\n5\t\tExit\nEnter Option:");
                                        scanf("%d",&num2);
                                        fflush(stdin);
                                        switch(num2)
                                        {
                                        case 1:
                                            printf("\nYour Balance is : %0.2f",a->Amount);
                                            getch();
                                            break;
                                        case 2:
                                            printf("\n Enter the Amount to Deposit:");
                                            scanf("%f",&amount);
                                            fflush(stdin);
                                            a->Amount = a->Amount + amount;
                                            printf("\n New Balance is %f",a->Amount);
                                            getch();
                                            break;
                                        case 3:
                                            printf("\n Enter the Amount to Withdraw:");
                                            scanf("%f",&amount);
                                            A_N[i].Amount = A_N[i].Amount - amount;
                                            printf("\n New Balance is %0.2f",A_N[i].Amount);
                                            getch();
                                            break;
                                        case 4:
                                            printf("\n Enter New Password :");
                                            fflush(stdin);
                                            gets(password);
                                            strcpy(a->password, password);
                                            printf("\nBank Never Ask You for Password please dont share it with anyone");
                                            getch();
                                            break;
                                        case 5:
                                            count2 = 1;
                                            printf("Thank You for using Tech_Telegraph");
                                            getch();
                                            break;
                                        }
                                        fflush(stdin);
                                    }while(count2 != 1);
                                }
                                else if(count1 == 3)
                                {
                                    break;
                                }
                                else
                                {
                                    count1++;
                                    printf("Wrong Password");
                                }

                            }while(count1 != 3 && count2 == 0);
                            break;
                            }
                            else
                            {
                                printf("Wrong Account Number");
                            }
                            fflush(stdin);
                        }
                    break;
            case 3:
                printf("Exiting");
                count++;
                getch();
                break;
            default:
                printf("Enter a valid Value");
                break;
        }
    }while(count != 1);

    return 0;
}

