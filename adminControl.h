int isAdmin = 0;
void AdminLogin(char num[20],char pass[20]){
    if(strlen(num)>10&&strlen(pass)>5){
            if(strcmp(num,"01883132667")==0&&strcmp(pass,"meheraj")==0){
                puts("Welcome You are admin");
                isAdmin = 1;
                main();
            }else{
                puts("The number or password are incorrect.");
            }
    }else{
    if(strlen(num)<11){
        puts("Number is too short.");
    }else if(strlen(pass)<6){
        puts("Password is too short.");
    }
    }
}

void viewUsers(){
    FILE *file;
    file =  fopen("users.db","r");
    if(file == NULL)
    {
        printf("Error: users data not found");
        return;
    }
    else
    {
        int r = 0, rc = 0;
        system("cls");
        printf("|--UserList\n|--  No\t\tUsername\tNumber\t\tAccount created\n");
        do
        {
             char mobile[20],name[50],ept[25];
            r =  fscanf(file,
                        "%49[^,],%19[^,],%s\n",&name,mobile,ept);


            if(r == 3){
                rc++;
                printf("|--%3d\t%15s\t%11s\t%20s",rc,name,mobile,eptostdTime(atoi(ept)));
            };

            if(r!= 3 && !feof(file))
            {
                puts("Data format incorectly");
                return;
            }

        }
        while(!feof(file));

    }

    fclose(file);
    printf("Press any key to return home!");
    getchar();
    getchar();
    system("cls");
    main();

}


//Adds foods
void addsFoods(struct Foods foods){

        FILE *file;
        file =  fopen("foods.txt","a");
        if(file == NULL)
        {
            puts("Can't Open File");
            return;
        }
        else
        {
            int currenttime = currentEpochTime();
            fprintf(file,
                        "%s,%s,%s,%s\n",foods.name,foods.price,foods.rating,foods.categories);
            fclose(file);
            printf("%s",foods.name);
            puts(" Added successfully!");
            printf("Press any key to continue");
            getchar();
            main();
        }
}


//See order history

void viewOrderHistory(){



FILE *file;
    file =  fopen("orderhistory.db","r");
    if(file == NULL)
    {
        printf("Error: users data not found");
        return;
    }
    else
    {
        int r = 0, rc = 0;
        system("cls");
        printf("|--UserList\n|--  No\tUsername\tNumber\t\tFoodName\tTotal  Price\t\Order\n");
        do
        {
             char umobile[12],uname[50],orderedT[25],foodName[25],tPrice[13],totalQ[4];
            r =  fscanf(file,
                        "%49[^,],%11[^,],%25[^,],%3[^,],%12[^,],%s\n",&uname,umobile,foodName,totalQ,tPrice,orderedT);


            if(r == 6){
                rc++;
                printf("|--%3d\t%-15s\t%-11s\t%-15s  %s    %s\t%-20s",rc,uname,umobile,foodName,totalQ,tPrice,eptostdTime(atoi(orderedT)));
            };

            if(r!= 6 && !feof(file))
            {
                puts("Data format incorectly");
                return;
            }

        }
        while(!feof(file));

    }

    fclose(file);
    printf("Press any key to return home!");
    getchar();
    getchar();
    system("cls");
    main();


}
