#include<stdio.h>

#include<stdlib.h>

#include<conio.h>

#include<string.h>

#include<windows.h>

#include<process.h>

int password();

void addrecord();

void viewrecord();

void editrecord();

void editpassword();

void deleterecord();

void aboutus();

void contact();

struct record

{

    char time[6];

    char name[30];

    char day[20];

    int price;

    char note[500];

};


int main()
{


   system("COLOR FC");



    SetConsoleTitleA("EXPENDITURE RECORDING SOFTWARE--BY UMBRELLA.");

     int ch;

    printf("\n\n\t**************************************************\t\n");

    printf("\t*PASSWORD PROTECTED EXPENDITURE RECORDING DIARY.*\n");

    printf("\t**************************************************\t");


   while(1)


        {

                printf("\n\n\t\tMAIN PAGE:");

                printf("\n\n\tADD RECORD\t[1]");

                printf("\n\tVIEW RECORD\t[2]");

                printf("\n\tEDIT RECORD\t[3]");

                printf("\n\tDELETE RECORD\t[4]");

                printf("\n\tEDIT PASSWORD\t[5]");

                printf("\n\tABOUT US\t[6]");

                printf("\n\tCONTACT US\t[7]");

                printf("\n\tEXIT SOFTWARE\t[8]");

                printf("\n\n\tENTER YOUR CHOICE:");

                scanf("%d",&ch);


            switch(ch)

                    {

                            case 1:

                            addrecord();

                            break;


                            case 2:

                            viewrecord();

                            break;


                            case 3:

                            editrecord();

                            break;


                            case 4:

                            deleterecord();

                            break;


                            case 5:

                            editpassword();

                            break;

                            case 6:

                            aboutus();

                            break;

                            case 7:

                                 contact();

                                break;

                            case 8:

                           printf("\n\n\tEXITING!!!!!!!!!!!!!");

                            printf("\n\tTHANKYOU FOR USING THE EXPENDITURE RECORDING SOFTWARE.\n\t");

                            printf("\n\tDEVELOPED BY:UMBRELLA\n\t");

                            printf("\n\n\tVERSION:1.0.0\n\t");

                            printf("\n\t");

                            getch();

                            exit(0);


                            default:

                            printf("\nYOU ENTERED WRONG CHOICE..");

                            printf("\nPRESS ANY KEY TO TRY AGAIN");

                            getch();

                            break;

                    }

                system("cls");

        }

            return 0;

}

void addrecord( )

{

    int i,items,sum=0;

                system("cls");

                FILE *fp ;

                char another = 'Y' ,time[10];

                struct record e;

                char filename[15];

                int choice;

                printf("\n\n\t\t***************************\n");

                printf("\t\t* WELCOME TO THE ADD PAGE.*");

                printf("\n\t\t***************************\n\n");

                printf("\n\n\tENTER DATE HERE:[IN B.S]:[YYYY-MM-DD]:");

                fflush(stdin);

                gets(filename);

                fp = fopen (filename, "ab+" ) ;

                if ( fp == NULL )

                {

                fp=fopen(filename,"wb+");

                if(fp==NULL)

                {

                    printf("\nSYSTEM ERROR...");

                    printf("\nPRESS ANY KEY TO EXIT");

                    getch();

                    return ;

                }

                }



                while ( another == 'Y'|| another=='y' )

                {

                    choice=0;

                    fflush(stdin);

                printf ( "\n\tENTER TIME:[hh:mm]:");

                scanf("%s",time);

                rewind(fp);

                while(fread(&e,sizeof(e),1,fp)==1)

                {

                    if(strcmp(e.time,time)==0)

                    {

                        printf("\n\tTHE RECORD ALREADY EXISTS.\n");

                        choice=1;

                    }

                }

                    if(choice==0)

                    {

                        strcpy(e.time,time);

                        printf("\n\tEnter Day:");

                        fflush(stdin);

                        gets(e.day);

                        printf("\n\tHOW MANY ITEMS DO YOU WANT TO STORE?\n\t");

                        scanf("%d",&items);

                        for(i=0;i<items;i++){

                        printf("\n\tFOR ITEM NO. %d\n\t",i+1);

                        printf("\n\tENTER NAME:");

                        fflush(stdin);

                        gets(e.name);

                        fflush(stdin);

                        printf("\n\tENTER PRICE:");

                        scanf("%d",&e.price);

                        fflush(stdin);

                        printf("\n\tYOUR TEXT HERE:");

                        gets(e.note);

                        sum=sum+e.price;

                        fwrite ( &e, sizeof ( e ), 1, fp ) ;
                        }

                        printf("\n\tThe money you have spent till is Rs.%d\n\t",sum);

                        printf("\nYOUR RECORD IS ADDED...\n");

                    }

                        printf ( "\n\tADD ANOTHER RECORD...(Y/N) " ) ;

                        fflush ( stdin ) ;

                        another = getchar( ) ;

                }


                fclose ( fp ) ;

                printf("\n\n\tPRESS ANY KEY TO EXIT...");

                getch();


    }


void viewrecord( )

{
    int sum=0;

        FILE *fpte ;

        system("cls");

        struct record expenditure ;

        char time[6],choice,filename[14];

        int ch;

        printf("\n\n\t\t*******************************\n");

        printf("\t\t* WELCOME TO THE VIEWING PAGE.*");

        printf("\n\t\t*******************************\n\n");

        choice=password();

        if(choice!=0)

            {

                return ;

            }

        do

            {

                    printf("\n\tENTER THE DATE TO VIEW YOUR EXPENDITURE RECORD:[IN B.S]:[YYYY-MM-DD]:");

                    fflush(stdin);

                    gets(filename);


                    fpte = fopen ( filename, "rb" ) ;

                    if ( fpte == NULL )

                            {

                                puts ( "\nTHE RECORD DOES NOT EXIST...\n" ) ;

                                printf("PRESS ANY KEY TO EXIT...");

                                getch();

                                return ;

                            }

                            system("cls");

                printf("\n\tHOW WOULD YOU LIKE TO VIEW YOUR EXPENDITURE RECORD:\n");

                printf("\n\t1.WHOLE RECORD OF THE DAY.");

                printf("\n\t2.RECORD OF FIX TIME.");

                printf("\n\t\tENTER YOUR CHOICE:");

                scanf("%d",&ch);

                switch(ch)

                {

                    case 1:

                        system("CLS");

                            printf("\n\tTHE WHOLE RECORD FOR %s IS:\n\t",filename);

                         while ( fread ( &expenditure, sizeof ( expenditure ), 1, fpte ) == 1 )

                         {

                            printf("\n");

                            printf("\n\tTIME: %s\t",expenditure.time);

                            printf("\n\tDAY: %s\t",expenditure.day);

                            printf("\n\tNAME: %s\t",expenditure.name);

                            printf("\n\tPRICE: %d\t",expenditure.price);

                            printf("\n\tYOUR TEXT: %s\t",expenditure.note);

                            printf("\n");

                            sum=sum+expenditure.price;

                         }
                         printf("\n\n\tTOTAL = Rs.%d.\t",sum);

                         break;


                    case 2:

                            fflush(stdin);

                            printf("\nENTER TIME:[hh:mm]:");

                            gets(time);

                            while ( fread ( &expenditure, sizeof ( expenditure ), 1, fpte ) == 1 )


                            {

                                if(strcmp(expenditure.time,time)==0)

                                {
                                    system("CLS");

                                    printf("\nYOUR RECORD IS:");

                                    printf("\n\tTIME: %s",expenditure.time);

                                    printf("\n\tDAY: %s",expenditure.day);

                                    printf("\n\tNAME: %s",expenditure.name);

                                     printf("\n\tPRICE: %d",expenditure.price);

                                    printf("\n\tYOUR TEXT: %s",expenditure.note);


                                }


                            }


                            break;


                    default: printf("\nSORRY!!!YOU HAVE CHOOSEN INVALID CHOICE......\n");

                             break;

                }


               printf("\n\nWOULD YOU LIKE TO CONTINUE VIEWING YOUR EXPENDITURE RECORD?...(Y/N):");

               fflush(stdin);

            scanf("%c",&choice);

        }while(choice=='Y'||choice=='y');

            fclose ( fpte ) ;

            return ;

}

void editrecord()

{

        system("cls");

        FILE *fpte ;

        struct record expenditure ;

        char time[6],choice,filename[14];

        int num,count=0;

        printf("\n\n\t\t*******************************\n");

        printf("\t\t* WELCOME TO THE EDITING PAGE.*");

        printf("\n\t\t*******************************\n\n");

        choice=password();

        if(choice!=0)

            {

                return ;

            }

        do

            {

                    printf("\n\tENTER THE CORRECT DATE TO EDIT YOUR EXPENDITURE RECORD:[IN B.S]:[yyyy-mm-dd]:");

                    fflush(stdin);

                    gets(filename);

                    printf("\n\tENTER TIME:[hh:mm]:");

                    gets(time);

                    fpte = fopen ( filename, "rb+" ) ;

                    if ( fpte == NULL )

                            {

                                printf( "\nSORRY!!RECORD DOES NOT EXISTS:" ) ;

                                printf("\nPRESS ANY KEY TO GO BACK");

                                getch();

                                return;

                            }

                    while ( fread ( &expenditure, sizeof ( expenditure ), 1, fpte ) == 1 )

                    {

                        if(strcmp(expenditure.time,time)==0)

                        {

                            printf("\nYOUR OLD EXPENDITURE RECORD WAS AS:");

                            printf("\n\tTIME: %s",expenditure.time);

                            printf("\n\tDAY: %s",expenditure.day);

                           printf("\n\tNAME:%s",expenditure.name);

                           printf("\n\tPRICE:%d",expenditure.price);

                            printf("\n\tYOUR TEXT: %s",expenditure.note);


                            printf("\n\n\t\tWHAT WOULD YOU LIKE TO EDIT..");

                                printf("\n\t1.TIME.");

                                printf("\n\t2.DAY.");

                                printf("\n\t3.NAME.");

                                printf("\n\t4.PRICE.");

                                printf("\n\t5.YOUR TEXT.");

                                printf("\n\t6.WHOLE RECORD.");

                                printf("\n\t7.GO BACK TO MAIN MENU.");

                                do

                                {

                                        printf("\n\tENTER YOUR CHOICE:");

                                        fflush(stdin);

                                        scanf("%d",&num);

                                        fflush(stdin);

                                        switch(num)

                                        {

                                            case 1: printf("\n\tENTER THE NEW DATA:");

                                                    printf("\n\tNEW TIME:[hh:mm]:");

                                                    gets(expenditure.time);

                                                    break;

                                            case 2:
                                                printf("\n\tENTER THE NEW DATA:");

                                                printf("\n\tNEW DAY:");

                                                gets(expenditure.day);

                                                        break;

                                            case 3: printf("\n\tENTER THE NEW DATA:");

                                                    printf("\n\tNEW NAME:");

                                                    gets(expenditure.name);

                                                    break;


                                            case 4: printf("\n\tENTER THE NEW DATA:");

                                                    printf("\n\tNEW PRICE:");

                                                    scanf("%d",&expenditure.price);

                                                    break;


                                            case 5: printf("\n\tENTER THE NEW DATA:");

                                                    printf("\n\tYOUR NEW TEXT:");

                                                    gets(expenditure.note);

                                                    break;


                                            case 6:  printf("\n\tENTER THE NEW DATA:");

                                                     printf("\n\tNEW TIME:[hh:mm]:");

                                                     gets(expenditure.time);

                                                     printf("\n\tENTER THE NEW DATA:");

                                                    printf("\n\tNEW DAY:");

                                                    gets(expenditure.day);

                                                     printf("\n\tNEW NAME:");

                                                     gets(expenditure.name);

                                                     printf("\n\tENTER THE NEW DATA:");

                                                     printf("\n\tNEW PRICE:");

                                                     scanf("%d",&expenditure.price);

                                                    printf("\n\tENTER THE NEW DATA:");

                                                    printf("\n\tYOUR NEW TEXT:");

                                                    gets(expenditure.note);

                                                     break;


                                            case 7: printf("\n\tPRESS ANY KEY TO GO BACK...\n");

                                                    getch();

                                                    return ;

                                                    break;


                                            default: printf("\n\tSORRY!!!!YOU TYPED SOMETHING INVALID!!...TRY AGAIN\n");

                                                     break;

                                        }


                                }while(num<1||num>8);

                            fseek(fpte,-sizeof(expenditure),SEEK_CUR);

                            fwrite(&expenditure,sizeof(expenditure),1,fpte);

                            fseek(fpte,-sizeof(expenditure),SEEK_CUR);

                            fread(&expenditure,sizeof(expenditure),1,fpte);

                            choice=5;

                            break;

                        }

                    }

                    if(choice==5)

                    {

                    system("cls");

                    printf("\n\t\tHURRAY!!!EDITING COMPLETED!!!!-_-...\n");

                    printf("-----------------------------------------\n");

                    printf("THE NEW EXPENDITURE RECORD IS:\n");

                    printf("-------------------------------------------\n");

                    printf("\n\tTIME: %s",expenditure.time);

                    printf("\n\tDAY: %s",expenditure.day);

                    printf("\n\tNAME: %s",expenditure.name);

                    printf("\n\tPRICE: %d",expenditure.price);

                    printf("\n\tYOUR TEXT: %s",expenditure.note);

                    fclose(fpte);

                    printf("\n\n\tWOULD YOU LIKE TO EDIT ANOTHER EXPENDITURE RECORD.(Y/N)");

                    scanf("%c",&choice);

                    count++;

                    }

                    else

                    {

                        printf("\n\tTHE RECORD DOES NOT EXIST::\n");

                        printf("\n\tWOULD YOU LIKE TO TRY AGAIN...(Y/N)");

                        scanf("%c",&choice);

                    }


            }while(choice=='Y'||choice=='y');

            fclose ( fpte ) ;


            if(count==1)

            printf("\n\t%d FILE IS EDITED...\n",count);

            else if(count>1)

            printf("\n\t%d FILES ARE EDITED..\n",count);

            else

            printf("\n\tNO FILES EDITED...\n");

            printf("\n\tPRESS ENTER TO EXIT EDITING PAGE.");

            getch();

}

int password()

{

        char pass[15]={0},check[15]={0},ch;

        FILE *fpp;

        int i=0,j;

        printf("\n\t*********************************************\n\t");

        printf("\t::FOR SECURITY PURPOSE::\t");

        printf("\n\tWARNING::ONLY THREE TRIALS ARE ALLOWED!!!\t");

        printf("\n\t*********************************************\t");

        for(j=0;j<3;j++)

        {

                        i=0;

                        printf("\n\n\tENTER THE PASSWORD:");

                        pass[0]=getch();

                        while(pass[i]!='\r')

                        {

                            if(pass[i]=='\b')

                            {

                                i--;

                                printf("\b");

                                printf(" ");

                                printf("\b");

                                pass[i]=getch();

                            }

                            else

                            {

                                printf("*");

                                i++;

                                pass[i]=getch();

                            }

                        }

                        pass[i]='\0';

                        fpp=fopen("SE","r");

                        if (fpp==NULL)

                        {

                            printf("\nERROR WITH THE SYSTEM FILE...[FILE MISSING]\n");

                            getch();

                            return 1;

                        }

                        else

                        i=0;

                        while(1)

                        {

                            ch=fgetc(fpp);

                            if(ch==EOF)

                            {

                                check[i]='\0';

                                break;

                            }

                            check[i]=ch-5;

                            i++;

                        }

                        if(strcmp(pass,check)==0)

                        {

                            printf("\n\n\tCORRECT PASSWORD!!!!ACCESS GRANTED...!!!!\n");



                            return 0;

                        }

                        else

                        {

                            printf("\n\n\tWRONG PASSWORD..\n\n\tACCESS DENIED...\n");

                        }

        }

        printf("\n\n\t::YOU HAVE ENTERED WRONG PASSWORD THREE TIMES!!\n\t::YOU ARE NOT ALLOWED TO ACCESS ANY FILES:.:\n\n\tPRESS ANY KEY TO GO BACK...");

        getch();

        return 1;

}

void editpassword()

{

    system("cls");

    printf("\n");

    char pass[15]={0},confirm[15]={0},ch;

    int choice,i,check;

    FILE *fp;

    fp=fopen("SE","rb");

    if(fp==NULL)

    {

        fp=fopen("SE","wb");

        if(fp==NULL)

        {

            printf("SYSTEM ERROR...");

            getch();

            return ;

        }

        fclose(fp);

        printf("\nSYSTEM RESTORED...\nYOUR PASSWORD IS 'ENTER'\n PRESS ENTER TO CHANGE PASSWORD\n\n");

        getch();

    }

        fclose(fp);

        check=password();

    if(check==1)

    {

        return ;

    }

    do

    {

        if(check==0)

                    {

                        i=0;

                        choice=0;

                        printf("\n\n\tENTER THE NEW PASSWORD:");

                        fflush(stdin);

                        pass[0]=getch();

                        while(pass[i]!='\r')

                        {

                            if(pass[i]=='\b')

                            {

                                i--;

                                printf("\b");

                                printf(" ");

                                printf("\b");

                                pass[i]=getch();

                            }

                            else

                            {

                                printf("*");

                                i++;

                                pass[i]=getch();

                            }

                        }

                        pass[i]='\0';

                        i=0;

                        printf("\n\tCONFIRM PASSWORD:");

                        confirm[0]=getch();

                        while(confirm[i]!='\r')

                        {

                            if(confirm[i]=='\b')

                            {

                                i--;

                                printf("\b");

                                printf(" ");

                                printf("\b");

                                confirm[i]=getch();

                            }

                            else

                            {

                                printf("*");

                                i++;

                                confirm[i]=getch();

                            }

                        }

                        confirm[i]='\0';

                        if(strcmp(pass,confirm)==0)

                        {

                            fp=fopen("SE","wb");

                            if(fp==NULL)

                            {

                                printf("\n\t\tSYSTEM ERROR");

                                getch();

                                return ;

                            }

                            i=0;

                            while(pass[i]!='\0')

                            {

                                ch=pass[i];

                                putc(ch+5,fp);

                                i++;

                            }

                            putc(EOF,fp);

                            fclose(fp);

                        }

                        else

                        {

                            printf("\n\tSORRY!!!THE NEW PASSWORD DOES NOT MATCH.");

                            choice=1;


                        }


                    }

}while(choice==1);


    printf("\n\n\tPASSWORD CHANGED SUCCESSFULLY...\n\n\tPRESS ANY KEY TO GO BACK...");

    getch();

}


void aboutus()

{
    system("CLS");

    printf("\n\tTHIS SOFTWARE IS DEVELOPED BY UMBRELLA.THE MAIN PURPOSE OF DEVELOPING THIS \n\tSOFTWARE IS TO MAKE THE WORK EASIER,");

    printf("\n\tTO STORE THE DATA IN A SECURE WAY AND TO UPGRADE THE LIFESTYLE.\n\t");

    printf("\n\n\n\nANY DISTRUBTION OF THIS SOFTWARE WITHOUT THE OWNER'S PERMISSION IS ILLEGAL.\n\t");

    printf("\n\tPress any key to go back.\n\t");

    getch();
}

void contact()
{
    system("CLS");

    printf("\n\n\tFOR MORE INFORMATION OF THIS SOFTWARE PLEASE,CONTACT UMBRELLA COMPANY.\n\t");

    printf("\n\tMOBILE NO:+977987654321\n\t");

    printf("\n\tG-MAIL:umbrella2016@gmail.com\n\t");

    printf("\n\n\n\n\tPress any key to go main page.\n\t");

    getch();
}


void deleterecord( )

{

                system("cls");

                FILE *fp,*fptr ;

                struct record file ;

                char filename[15],another = 'Y' ,time[10];

                int choice,check;

                printf("\n\n\t\t*********************************\n");

                printf("\t\t* WELCOME TO DELETE PAGE.*");

                printf("\n\t\t**********************************\n\n");

                check = password();

                    if(check==1)

                    {

                        return ;

                    }


                while ( another == 'Y' )

                {

                printf("\n\n\tWHAT WOULD YOU LIKE TO DELETE?");

                printf("\n\n\t##DELETE WHOLE EXPENDITURE RECORD.\t\t\t[1]");

                printf("\n\t##DELETE A PARTICULAR EXPENDITURE RECORD BY TIME.\t[2]");


                do

                {

                        printf("\n\t\tENTER YOU CHOICE:");

                        scanf("%d",&choice);


                    switch(choice)

                        {

                            case 1:

                            printf("\n\tENTER THE DATE OF RECORD TO BE DELETED:[yyyy-mm-dd]:");

                            fflush(stdin);

                            gets(filename);

                            fp = fopen (filename, "wb" ) ;

                            if ( fp == NULL )

                            {

                                printf("\nSORRY!!!THE FILE DOES NOT EXISTS");

                                printf("\nPRESS ANY KEY TO GO BACK.");

                                getch();

                                return ;

                            }

                            fclose(fp);

                            remove(filename);

                            printf("\nDELETED SUCCESFULLY!!!!!");

                            break;


                            case 2:

                            printf("\n\tENTER THE DATE OF RECORD:[IN B.S]:[yyyy-mm-dd]:");

                            fflush(stdin);

                            gets(filename);

                            fp = fopen (filename, "rb" ) ;

                            if ( fp == NULL )

                            {

                                printf("\nSORRY!!!THE FILE DOES NOT EXISTS.");

                                printf("\nPRESS ANY KEY TO GO BACK.");

                                getch();

                                return ;

                            }

                            fptr=fopen("temp","wb");

                            if(fptr==NULL)

                            {

                                printf("\nSYSTEM ERROR");

                                printf("\nPRESS ANY KEY TO GO BACK");

                                getch();

                                return ;

                            }

                            printf("\n\tENTER THE TIME OF RECORD TO BE DELETED:[hh:mm]:");

                            fflush(stdin);

                            gets(time);

                            while(fread(&file,sizeof(file),1,fp)==1)

                            {

                                if(strcmp(file.time,time)!=0)

                                fwrite(&file,sizeof(file),1,fptr);

                            }


                            fclose(fp);

                            fclose(fptr);

                            remove(filename);

                            rename("temp",filename);

                            printf("\nDELETED SUCCESFULLY...");

                            break;


                    default:

                            printf("\n\tSORRY!!!YOU ENTERED INVALID CHOICE.");

                            break;

                    }

                }while(choice<1||choice>2);



                    printf("\n\tDO YOU LIKE TO DELETE YOUR ANOTHER EXPENDITURE RECORD? (Y/N):");

                    fflush(stdin);

                    scanf("%c",&another);

                }

                printf("\n\n\tPRESS ANY KEY TO EXIT...");

                getch();

}
