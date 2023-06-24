 #include<stdio.h>
 #include<string.h>
 #include <stdlib.h>
 void create_file();
 int ask_who();
 void create_file();
 int starting_data();
 void create_account_as_candidate();
 void login_candidate();
 void starting_data_user();
 void create_account_as_user();
 void login_user();
 void leader();
 int candidate_count();
 void vote ();
 void leading_candidate();


int count1=0; int count2=0; int count3=0; int count4=0; int count5=0; int count6=0;

int main()
{
  
int user_input;

char v='v',c='c';

   create_file();
for( int a=1; a>0;a++)
 {
    user_input=ask_who();
    if (user_input==1)
    {
      starting_data_user(); 
    }

    else if(user_input==2)
    {
      starting_data();
    }

    else if(user_input==3)
    {
     leader();
    }

  }

 return 0;
} 



void create_file()
{
  
FILE *fp = NULL;

  fp = fopen("candidate.txt", "w");
    if(fp == NULL)
    {
      printf("Error in creating the file\n");
       exit(1);
   }
    fclose(fp);


FILE *file = NULL;

  file = fopen("voter.txt", "w");
    if(file == NULL)
    {
      printf("Error in creating the file\n");
       exit(1);
    }
fclose(file);


FILE *abc = NULL;

  abc = fopen("candidate_username.txt", "w");
    if(abc == NULL)
    {
      printf("Error in creating the file\n");
       exit(1);
    }
    fclose(abc);


FILE *pqr = NULL;

pqr = fopen("Number_vote.txt", "w");
  if(pqr == NULL)
  {
    printf("Error in creating the file\n");
     exit(1);
  }
fclose(pqr);
}


int ask_who()
{
int user;
 
  printf("\n__who are you__\n 1=voter\n 2=candidate\n 3=leader\n");
  scanf("%d",&user);
   if(user==1)
   {
    return 1;
   }
    else if(user==2)
      {
       return 2 ;
      }
       else if(user==3)
       {
        return 3;
        }
         else
         {
          printf("invalid input");
         }
}


int starting_data()
{
int user_choice;
int a;

printf("\n__Welcome dear candidate__");
  printf("\n--Enter your choice?--\n");
  printf("1) login\n2) Create account\n3)Login as voter\n4)Login as leader\n");
  scanf("%d",&a);
   switch(a)
   {
    case 1:login_candidate();
         break;

    case 2:create_account_as_candidate();
         break;

    case 3: starting_data_user();
        break;

    case 4: leader();
        break;

    default :printf("invalid input pls try agian\n"); 
              starting_data();
        break;
   }
}


 void create_account_as_candidate()
 {
  char username[20];
  char password[20];
  char user_data[1000];
  char* search;
  int count;

   printf("\n--you choice to create account as candidate--\n");
   printf("\n--You can create maximum 5 account as candidate--\n\n");

    count=candidate_count();
   printf("--The number of account right now are %d--\n",count);
   if(count<5)
   {
      printf("Enter your username:- ");
      scanf("%s",username);

  FILE *abc = NULL;
      abc = fopen("candidate_username.txt", "a");
      if(abc == NULL)
      {
      printf("Error in creating the file\n");
      exit(1);
      }
      fprintf(abc,"%s-",username);
    fclose(abc);


    printf("Enter your password:- ");
    scanf("%s",password);


    strcat(username,password);

  FILE *fp = NULL;
    fp = fopen("candidate.txt", "r");
    if(fp == NULL)
     {
      printf("Error in creating the file\n");
      exit(1);
     }

    fscanf(fp,"%s",&user_data);
    fclose(fp);

     search=strstr(user_data, username);

    if(search)
    {
     printf("\n--Your account aleredy exist--");
     starting_data();
    }
    else
    {

  FILE *fp = NULL;
      fp = fopen("candidate.txt", "a");
      if(fp == NULL)
      {
       printf("Error in creating the file\n");
       exit(1);
      }
      fprintf(fp,"%s-",username);
     fclose(fp);

  starting_data();
    }

     }
     else
     {
      printf("\n--Maximum account have been created--\n");
      
  starting_data();
    }
 }


 void login_candidate()
 {
   char user_data[1000];
   char username[20];
   char password[20];
   char* search;
   int a;

    printf("--you choice to log in as candidate--\n");

    printf("Enter your username:- ");
    scanf("%s",username);

    printf("Enter your password:- ");
    scanf("%s",password);


    strcat(username,password);
 FILE *fp = NULL;
     fp = fopen("candidate.txt", "r");
     if(fp == NULL)
       {
         printf("Error in creating the file\n");
         exit(1);
       }

     fscanf(fp,"%s",&user_data);

   fclose(fp);


        search=strstr(user_data, username);
        if (search)
         {
           abc:
            printf("\n\n__welcome__\n");
            printf("__What you would like to do__\n");
            printf("1)Vote\n2)Back to sub menu\n3)switch to voter\n4)switch to leader");
            scanf("%d",&a);
           switch (a)
           {
             case 1: vote();
              break;
   
             case 2: starting_data();
              break;
             
             case 3: starting_data_user();
              break;

              case 4: leader();
               break;
   
             
             default: printf("invalid input please try agian");
                   goto abc;
               break;
           }  
         }

        else{
              printf("\n\n--WRONG PASSWORD OR YOUR ACCOUNT DOES NOT EXIST--\n");
            }
   starting_data();
  }


 void starting_data_user()
{
 int user_choice;

 printf("\n__Welcome dear voter__ \n");
   
  printf("\n--Enter your choice?--\n");
  printf("1) login\n2) Create account\n3)switch to candidate\n4)switch to leader\n");
  scanf("%d",&user_choice);
    switch(user_choice)
   {
      case 1: login_user();
         break;

     case 2 : create_account_as_user();
         break;

      case 3 : starting_data();
         break;

      case 4 : leader();
         break;

     default :starting_data_user();
         break;
   }

}


 void create_account_as_user()
{
  //this is separate boz we have to count number of candidates
   char candidate_name;
   char username[20];
   char password[20];
   char* search;
   char user_data[1000];

   printf("\n--You choose to create account as voter--\n");
   printf("Enter your username:- ");
   scanf("%s",username);
   printf("Enter your password:- ");
   scanf("%s",password);
   strcat(username,password); //combine two stirng in username 
 

 FILE *fp = NULL;
    fp = fopen("voter.txt", "r");
     if(fp == NULL)
    {
      printf("Error in creating the file\n");
      exit(1);
    }
    fscanf(fp,"%s",&user_data);
  fclose(fp);

    search=strstr(user_data, username);
    if(search)
    {
      printf("Your account alerdy exist");
    }
     else
    {
     FILE *fp = NULL;
        fp = fopen("voter.txt", "a");
        if(fp == NULL)
        {
          printf("Error in creating the file\n");
          exit(1);
        }
        fprintf(fp,"%s-",username);
       
      fclose(fp);

     starting_data_user();


    }
}


void login_user()
{
 char user_data[1000];
 char vote_data[1000];
 char username[20];
 char username1[20];
 char password[20];
 char flag[]="@";
 char* search;
 char* search2;
 int a;
 int flag2;

    printf("--You choose to login as voter--\n");
    printf("Enter your username:- ");
    scanf("%s",username);
    printf("Enter your password:- ");
    scanf("%s",password);
    strcat(username,password);
        
         strcpy(username1,username);
         strcat(username1,flag);
  FILE *abc = NULL;
        abc = fopen("Number_vote.txt", "r");
        if(abc == NULL)
        {
          printf("Error in creating the file\n");
          exit(1);
        }
        fscanf(abc,"%s",&vote_data);
  fclose(abc);
      search2=strstr(vote_data, username1);
       if(search2)
      {
        flag2=1;
      }
      else
      {
        flag2=0;
      }
         
         
  FILE *fp = NULL;
      fp = fopen("voter.txt", "r");
      if(fp == NULL)
        {
          printf("Error in creating the file\n");
          exit(1);
        }
      fscanf(fp,"%s",&user_data);
  fclose(fp);
     
      
  FILE *pqr = NULL;
      pqr = fopen("Number_vote.txt", "a");
      if(pqr == NULL)
        {
          printf("Error in creating the file\n");
          exit(1);
        }
     
     search=strstr(user_data, username);
      if (search) 
  {
        abc:
         
        printf("\n__What you would like to do__\n");
        printf("1)Vote\n2)switch to candidate\n3)switch to leader\n4)Back to sub menu\n");
        scanf("%d",&a);

        switch (a)
      {
        case 1: if(flag2==1)
                 {
                   printf("--You have already voted!!--\n ");
                   goto abc;
                 }
               else if(flag2==0)
               {
                  fprintf(pqr,"%s-",username1);
      fclose(pqr);
      vote();
               }
       break;

        case 2: starting_data();
           break;

        case 3: leader();
           break;
        
        case 4: starting_data_user();
           break;
         
         default:goto abc;
           break;
      }    
  } 

 else
 {
   printf("\n\n--WRONG PASSWORD OR YOUR ACCOUNT DOES NOT EXIST--\n\n");
   starting_data_user();
 }

}



void leader()
{
 int saved_data1,saved_data2;
 char username_pre[]="tejas_swaraj";
 char password_pre[]="tejas_swaraj";
 
 char username[20];
 char password[20];

   printf("__Welcome dear leader__\n\n");
   printf("Enter your username:-");
   scanf("%s",username);
   printf("Enter your password:-");
   scanf("%s",password);
   

   saved_data1=strcmp(username_pre,username);
   saved_data2=strcmp(password,password_pre);


   if(saved_data1==0 && saved_data2==0)
   {
     printf("Hello leader\n\n");
     leading_candidate();
    }
     else if(saved_data1!=0 || saved_data2!=0)
    {
      printf("Wrong username or password\n");
    }  
}


int candidate_count()
{

 char ch;
 int candidates = 0;
 FILE *file;
    file = fopen("candidate.txt", "r");
    if (file == NULL) 
    {
       printf("Error opening file!\n");
       return 0;
    }
    while ((ch = fgetc(file)) != EOF)
     {
        if (ch == '-') 
        {
           candidates++;
        }
      }
  fclose(file);

 return candidates;
}


void vote () 
{
 int b;
 int i;
 char user_data[1000];
 char a[]="-";
 int y;

   printf("--You chose to vote--\n");
   printf("\nWho would you like vote\n");
   

 FILE *fp = NULL;
    fp = fopen("candidate_username.txt", "r");
    if(fp == NULL)
      {
        printf("Error in creating the file\n");
        exit(1);
      }
     fscanf(fp,"%s",&user_data);
  fclose(fp);

  char* ptr = strtok(user_data,a);
     while(ptr!=NULL)
      { 
        for(i=1;i<=5;i++)
         {
           printf("%d)%s\n",i,ptr);
           ptr = strtok(NULL,a);
         }
      }
      printf("6)None of These");

      printf("\n--Type the number in front of candiate to vote them--\n ");
      scanf("%d",&b);
       switch (b)
          {
            case 1 : count1++;
              break;

           case 2 :  count2++;
            break;

           case 3 :  count3++;
            break;

           case 4 :  count4++;
            break;

           case 5 :  count5++;
            break; 

           case 6 :  count6++;
            break; 

           default:printf("invalid data\n");
            break;
          }
    
      printf("\n--Thanks For Voting!!--\n");

}

void leading_candidate()
{

 char a[]="-";
 char user_data[1000];
    
  FILE *fp = NULL;
    fp = fopen("candidate_username.txt", "r");
    if(fp == NULL)
     {
       printf("Error in creating the file\n");
       exit(1);
     }
    fscanf(fp,"%s",&user_data);
  fclose(fp);

  char* xyz = strtok(user_data,a);
    while(xyz!=NULL)
     { 
       for(int i=1;i<=5;i++)
        {
          printf("%d)%s\n",i,xyz);
          xyz = strtok(NULL,a);
        }
     }

  printf("--These was the candidate this time,");


    if(count1>count2 && count1>count3 && count1>count4 && count1>count5)
      {
      
        printf("and candidate number _1_ WON!!!");
      }

       else if(count2>count1 && count2>count3 && count2>count4 && count2>count5)
       {
         printf("and candidate number _2_ WON!!!");
       }

         else if(count3>count2 && count3>count1 && count3>count4 && count3>count5)
         {
           printf("and candidate number _3_ WON!!!");
         }

           else if(count4>count2 && count4>count3 && count4>count1 && count4>count5)
           {
             printf("and candidate number _4_ WON!!!");
           }

             else if(count5>count2 && count5>count3 && count5>count4 && count5>count1)
             {
               printf("and candidate number _5_ WON!!!");
             }

   printf("\n\n**And %d people chose not to vote any of this candidate**\n",count6);
}



// 