
#include<stdio.h>
#include<string.h>
main()
{
 FILE *t,*p;
 char another,choice;
  struct telephone
 {
  char name[30];
  long int code;
  long int number;
  };
  struct telephone data;
  char custname[30];
  long int n;
  long int recsize;

   t=fopen("TELEPHONE.DAT","rb+");
   if(t==NULL)
   {
       t=fopen("TELEPHONE.DAT","wb+");
	   if(t==NULL)
	   {
	     printf("The File can't open\n");
		 exit();
		 }
		 }
     printf("          TELEPHONE DIRECTORY               \n");
	 printf("          *******************               \n");

	 recsize=sizeof(data);

  while(1)
  {
	  printf("\n\n");
   printf("1.Add Records\n");
   printf("2.List Records\n");
   printf("3.Modify Records\n");
   printf("4.Finding Number\n");
   printf("5.Finding Name\n");
   printf("6.Delete Records\n");
   printf("0.Exit\n");
   printf("Your Choice:");

   fflush(stdin);
   choice=getche();

   switch(choice)
   {
   case '1':

	   fseek(t,0,SEEK_END);

	   another='y';

	   while(another=='y')
	   {
		   printf("\nEnter Customer name,Code number and Telephone number\n");
		   scanf("%s  %ld %ld",data.name,&data.code,&data.number);
		   fwrite(&data,recsize,1,t);

		   printf("Add another data(y/n):");
		   fflush(stdin);
		   another=getche();
		   printf("\n");
	   }
	   break;

   case '2':

	   rewind(t); 
	   printf("\n");
	   printf("---------------------------------------------\n");
	   printf("|   CUSTOMER      |   CODE   |  TELEPHONE   |\n");
       printf("---------------------------------------------\n");
       rewind(t);

	   while(fread(&data,recsize,1,t)==1)

	   printf("|  %-18s %-2ld %12ld    |\n\n",data.name,data.code,data.number);
	   printf("--------------------------------------------\n");
       getch();
	   

	   printf("\n");
	   break;

   case '3':
	   another='y';
	   while(another=='y')
	   {
		   printf("\nEnter name of customer to modify:");
		   scanf("%s",custname);
		   rewind(t);
		   while(fread(&data,recsize,1,t)==1)
		   {
			   if(strcmp(data.name,custname)==0)
			   {
				   printf("\nEnter new name,code and telephone number\n");
				   scanf("%s %ld &ld",data.name,&data.code,&data.number);

				   fseek(t,-recsize,SEEK_CUR);
                   fwrite(&data,recsize,1,t);
				   break;
			   }
		   }
		   printf("Modify another record(y/n):");
				   fflush(stdin);
				   another=getche();
				   printf("\n");
	   }

	   break;


   case '4':

	   another='y';
	   while(another=='y')
	   {
	   printf("\nEnter name of customer:");
	   scanf("%s",custname);

	   rewind(t);
	   while(fread(&data,recsize,1,t)==1)
	   {
	   if(strcmp(data.name,custname)==0)
	   {
		   printf("Telephone Number=%ld %ld\n",data.code,data.number);
		   getch();
	   }
	   }
		   printf("Find another number(y/n)? ");
	   fflush(stdin);
	   another=getche();
	   printf("\n");
	   }
	   break;

   case '5':

	   another='y';
	   while(another=='y')
	   {
		   printf("\nEnter number of customer:");
		   scanf("%ld",&n);

		   rewind(t);
		   while(fread(&data,recsize,1,t)==1)
		   {
		   if(data.number==n)
		   {
			   printf("The Name is %s\n",data.name);
			   getch();
		   }
		   }
		   printf("Find another name(y/n)? ");
		   fflush(stdin);
		   another=getche();
		   printf("\n");
	   }
	   break;

   case '6':

	   another='y';
	   while(another=='y')
	   {
		   printf("\nEnter name of customer to delete:");
		   scanf("%s",custname);

		   p=fopen("TEMP.DAT","wb");

		   rewind(t);
		   while(fread(&data,recsize,1,t)==1)
		   {
			   if(strcmp(data.name,custname)!=0)
				   fwrite(&data,recsize,1,p);
		   }
		   fclose(t);
		   fclose(p);

		   remove("TELEPHONE.DAT");
		   rename("TEMP.DAT","TELEPHONE.DAT");

		   t=fopen("TELEPHONE","rb+");
		        
            printf("Delete another record(y/n):");
			fflush(stdin);
			another=getche();
	   }
	   break;


  case '0':

	   printf("\n");
	   fclose(t);
	   exit();
	   }  
   }
   }
