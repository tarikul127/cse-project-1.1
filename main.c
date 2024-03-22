#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include"userhandel.h"
#include"food.h"
#include "adminControl.h"





int main()
{



    if(isLoggedIn == 1&&isAdmin!=1)

    {



       if(strlen(loggedinUserDetails.name)!=0|| strlen(loggedinUserDetails.number)!=0){
            int  isNumExist = checknumberExist(loggedinUserDetails.number);
        if(isNumExist == 2){
            showFoodsByID();
        }else{
            isLoggedIn = 0;
            main();
        }

       }else{
        isLoggedIn = 0;
            main();
       }

    }else if(isLoggedIn == 0&& isAdmin ==1){

    puts("|-ADMIN PANEL  ");
        puts("|--");
        puts("|--1---Add Foods");
        puts("|--2---View Order History");
        puts("|--3---View Users");
        puts("|--4---Exit Admin Panel");
        puts("|--");

        int userChoice;
        scanf("%d",&userChoice);
        switch(userChoice)
        {

        case 1:
        {
            struct Foods foods;
            printf("Enter Food Categories (1-7): ");
            scanf("%s",foods.categories );
            getchar();
            printf("Enter Food Name: ");
            fgets(foods.name, 24, stdin);
            printf("Enter Food Price: ");
            scanf("%s",foods.price);
            printf("Enter Food Rating ");
            scanf("%s",foods.rating );
            foods.name[strcspn(foods.name,"\n")] = '\0';
            addsFoods(foods);
            break;
        }
        case 2:
            {
                viewOrderHistory();
                break;
            }
        case 3:
            {
                viewUsers();
                break;
            }
            case 4:{
                isAdmin = 0;
                system("cls");
                main();
                break;
            }

        default:
            break;
        }
    }
    else
    {
        puts("   Welcome to VECTOR_STATICS FOOD MANAGEMENT & ORDERING SYSTEM");
        puts("|--");
        puts("|--1---Create Account");
        puts("|--2---Login by number");
        puts("|--3---Admin Login");
        puts("|--4---Exit");
        puts("|--");
        int userChoice;
        scanf("%d",&userChoice);
        switch(userChoice)
        {

        case 1:
        {

            createu();
            break;
        }
        case 2:
        {
            char num[20];
            printf("Enter Number: ");
            scanf("%s", &num);
            int rt = checkUserExist(num);
            if(rt==2)
            {
                main();
            }
            else
            {
                system("cls");
                puts("Please register first!");
                createu();

            }
            break;
        }
        case 3:{
            char num[20],pass[20];
printf("Enter number: ");
            scanf("%s",&num);
            getchar();
            printf("Enter password: ");
            scanf("%s",&pass);
            getchar();
            AdminLogin(num,pass);

        }

        default:
            break;
        }
    }




    return 0;
}


//create a new user
void createu(){
struct UserSignup s;
            printf("Enter username: ");
            scanf("%s",&s.name);
            getchar();
            printf("Enter Number: ");
            scanf("%s",&s.number);
            getchar();
            createAccount(s);
            main();
}




