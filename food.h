
#include <stdlib.h>
#include <string.h>



struct Foods
{
    char name[25];
    char price[10];
    char rating [6];
    char  categories[3];

};

char categories[7][20] = {{"Juice"},{"Ice Cream"},{"Shake"},{"Tea and Coffe"},{"Breakfast"},{"Lunch"},{"Dinner"}};



void showFoodsByID()
{


     puts("\n\n\n");
        printf("Hello %s\n",loggedinUserDetails.name);
        puts("   Welcome to VECTOR_STATICS FOOD MANAGEMENT & ORDERING SYSTEM");
        puts("|_________________________________________________________________|");
        puts(" SL\t\tFOOD CATEGORIES");
        puts("....\t\t..................");
        for(int i = 0; i< sizeof(categories)/sizeof(categories[0]); i++)
        {
            printf(" %2d\t\t%20s\n",i+1,categories[i]);
        }
        printf("Select categorie : ");
        char idd[2];
        scanf("%s",&idd);

    struct Foods ff[10];


    system("cls");

    FILE *file;
    file =  fopen("foods.txt","r");
    int rc = 0;
    if(file == NULL)
    {

        return;
    }
    else
    {
        printf("|--------------------------%s---------------------------------Price---------Ratings|\n",categories[atoi(idd)]);
        int r = 0,index = 1;
        do
        {
            struct Foods f;
            r =  fscanf(file,
                        "%50[^,],%10[^,],%6[^,],%s\n",f.name,f.price,f.rating,f.categories);

            if(strcmp(f.categories,idd)==0)
            {
                printf("%d\t%-25s\t\t\t\t%-6s\t\t%-5s\n",index,f.name,f.price,f.rating);

                strcpy(ff[index-1].categories,f.categories);
                strcpy(ff[index-1].name,f.name);
                strcpy(ff[index-1].rating,f.rating);
                strcpy(ff[index-1].price,f.price);
                index++;
            }


            if(r == 4) rc++;

            if(r!= 4 && !feof(file))
            {
                puts("Data format incorectly");
                return;
            }

        }
        while(!feof(file));

    }

    fclose(file);

    int selectItm,quantity;
    puts("\n\t\tSelect the food you want to order!");
    scanf("%d",&selectItm);
    puts("\n\t\tSelect How much you want to order!");
    scanf("%d",&quantity);

    if(selectItm<=rc && selectItm>0 && quantity<51 && quantity >0){

    double pprice = ((atof(ff[selectItm-1].price)*quantity)*0.15)+(atof(ff[selectItm-1].price)*quantity);
            foodOrderingHistory(ff[selectItm-1].name,pprice,quantity);
            printf("Customer:\t%-25s\nDate    : %-25s\nMobile  : %-25s\n\nItem List:\n----------------------------------------------------------\nItem\t\t\t\t  Quantity\tPrice\n----------------------------------------------------------\n",loggedinUserDetails.name,crrentTimeEpoch(),loggedinUserDetails.number);

    printf("%-25s\t\t%-2d\t%-10.2f\n",ff[selectItm-1].name,quantity,atof(ff[selectItm-1].price));
    puts("----------------------------------------------------------");
    printf("Subtotal:    $%-10.2f\nTax (15\%):    $%-10.2f\nTotal:       $%-12.2f",atof(ff[selectItm-1].price)*quantity,(atof(ff[selectItm-1].price)*quantity)*0.15,((atof(ff[selectItm-1].price)*quantity)*0.15)+(atof(ff[selectItm-1].price)*quantity));
    puts("\n");
    puts("Payment Method: Credit Card\nCard Number: **** **** **** 1234\n\nThank you for your purchase!");
    printf("1- Homepage\n2- Exit\n");
    int choiceHorE;
    scanf("%d",&choiceHorE);
    switch(choiceHorE)
    {
    case 1:
        system("cls");
         main();
         break;
    case 2:
        return 0;
        break;
    default:
        return 0;
        break;
    }

    }else{

        if(selectItm>rc||selectItm<1){
            printf("Sorry no food found with this number");
            showFoodsByID();
        }else if(quantity > 50){
            printf("Our stock is limited. select less than 50!");
            showFoodsByID();
        }else if(quantity<1){
            puts("Are you kidding me?");
            showFoodsByID();
        }

    }

}



//save food ordering history

void foodOrderingHistory(char fname[25],double tprice,int quantity){
    FILE *file;
        file =  fopen("orderhistory.db","a");
        if(file == NULL)
        {
            puts("Can't Open File");
            return;
        }
        else
        {
            int orderTime = currentEpochTime();
            fprintf(file,"%s,%s,%s,%d,%0.2lf,%d\n",loggedinUserDetails.name,loggedinUserDetails.number,fname,quantity,tprice,orderTime);
            fclose(file);
        }


}








