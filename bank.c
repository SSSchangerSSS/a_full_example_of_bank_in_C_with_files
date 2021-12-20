#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include<stdlib.h>
#include <time.h>

//Long long signed integer type. Capable of containing at least the 
//[-9,223,372,036,854,775,807, +9,223,372,036,854,775,807] range
struct Bank_Account{
char name[50];
char last_name[50];
char left_money[18]; 
char Bank_account_number[50];
char account_id_number[50];
char address[50];
char telephone[50];	
};

struct Financial_transactions{
	
char Bank_account_number[50]; 
char Cost[18]; 	
char Title[50];	
char Type[50];
char day[4];	
char month[4];
char year[4];
};


void menu();
int insert_account();
int insert_financial_transactions();
int get_how_many_accounts();
int get_how_many_Financial_transactions();
void show_all_accounts();
void show_all_financial_transactions();
void show_all_financial_transactions_by_type(char Type[]);
void show_all_financial_transactions_by_title(char Title[]);
void show_all_financial_transactions_by_date(char year[],char month[],char day[]);
void show_all_financial_transactions_of_current_month(char year[],char month[]);
void show_all_financial_transactions_from_date_to_date(char year[],char month[],char day[],char year2[], char month2[] , char day2[]);
void show_account(struct Bank_Account m);
void show_financial_transactions(struct Financial_transactions m);
int increase_left_money(char name[],char last_name[],char Bank_account_number[],char meghdar[]);
int sort_accounts();
int compare(char s1[] , char s2[]);
int check_date(struct Financial_transactions m,char year[],char month[],char day[]);
int check_month(struct Financial_transactions m,char year[],char month[]);
int check_period_of_time(struct Financial_transactions m,char year[],char month[],char day[],char year2[],char month2[],char day2[]);

int main(){
	
int choice;	

int how_many;
	
char name[50];	
char last_name[50];
char Bank_account_number[50];
char Type[50];	
char Title[50];
char year[4];
char month[4];
char day[4];
char year2[4];
char month2[4];
char day2[4];
bool finisher_of_the_loop = false;
char x[18];
	
while(true){

if (finisher_of_the_loop == false){
	
menu();	
printf("\n");
scanf("%d",&choice);	

if (choice == 1){
insert_account();	
sort_accounts();
how_many = get_how_many_accounts();
printf("how_many_accounts = %d",how_many);
}

if (choice == 2){
how_many = get_how_many_accounts();
if (how_many == -1){
printf("\naccounts list is empty\n");
break;
}
how_many = get_how_many_accounts();
printf("\nhow_many_accounts = %d",how_many);
printf("\n");
sort_accounts();
show_all_accounts();	
}

if (choice == 3){
insert_financial_transactions();	
how_many = get_how_many_Financial_transactions();
printf("how_many_financial_transactions = %d",how_many);
}

if (choice == 4){
how_many = get_how_many_Financial_transactions();
if (how_many == -1){
printf("\nFinancial_transactions list is empty\n");
break;
}
how_many = get_how_many_Financial_transactions();
printf("\nhow_many_financial_transactions = %d",how_many);
printf("\n");
show_all_financial_transactions();	
}

if (choice == 5){
how_many = get_how_many_Financial_transactions();	
if (how_many == -1){
printf("\nFinancial_transactions list is empty\n");
break;
}
printf("\nplease enter the type of account:\n");
scanf("%s",&Type);	
printf("\n");
show_all_financial_transactions_by_type(Type);
}


if (choice == 6){
how_many = get_how_many_Financial_transactions();	
if (how_many == -1){
printf("\nFinancial_transactions list is empty\n");
break;
}
printf("\nplease enter title:\n");
scanf("%s",&Title);	
printf("\n");
show_all_financial_transactions_by_title(Title);
}

if (choice == 7){
how_many = get_how_many_Financial_transactions();	
if (how_many == -1){
printf("\nFinancial_transactions list is empty\n");
break;
}
printf("\nplease enter year:\n");
scanf("%s",&year);	
printf("\n");
printf("\nplease enter month:\n");
scanf("%s",&month);	
printf("\n");
printf("\nplease enter day:\n");
scanf("%s",&day);	
printf("\n");
show_all_financial_transactions_by_date(year,month,day);
}


if (choice == 8){
how_many = get_how_many_accounts();	
if (how_many == -1){
printf("\nbank account list is empty\n");
break;
}
printf("\nplease enter name:\n");
scanf("%s",&name);	
printf("\n");
printf("\nplease enter last_name:\n");
scanf("%s",&last_name);	
printf("\n");
printf("\nplease enter bank account number:\n");
scanf("%s",&Bank_account_number);	
printf("\n");
printf("\nplease enter how much you want to increase youre left money:\n");
scanf("%s",&x);	
printf("\n");
increase_left_money(name,last_name,Bank_account_number,x);
}

	

if (choice == 9){
how_many = get_how_many_Financial_transactions();	
if (how_many == -1){
printf("\nFinancial_transactions list is empty\n");
break;
}
  time_t t = time(NULL);
  struct tm tm = *localtime(&t);
sprintf(year, "%d", tm.tm_year + 1900);
sprintf(month, "%d", tm.tm_mon + 1);
sprintf(day, "%d", tm.tm_mday);
//printf("\n%s%s%s\n",year,month,day);
show_all_financial_transactions_by_date(year, month, day);
}

if (choice == 10){
how_many = get_how_many_Financial_transactions();	
if (how_many == -1){
printf("\nFinancial_transactions list is empty\n");
break;
}
  time_t t = time(NULL);
  struct tm tm = *localtime(&t);
sprintf(year, "%d", tm.tm_year + 1900);
sprintf(month, "%d", tm.tm_mon + 1);
show_all_financial_transactions_of_current_month(year,month);
}


if (choice == 11){
how_many = get_how_many_Financial_transactions();	
if (how_many == -1){
printf("\nFinancial_transactions list is empty\n");
break;
}
printf("\nplease enter year1:\n");
scanf("%s",&year);	
printf("\n");
printf("\nplease enter month1:\n");
scanf("%s",&month);	
printf("\n");
printf("\nplease enter day1:\n");
scanf("%s",&day);	
printf("\n");
printf("\nplease enter year2:\n");
scanf("%s",&year2);	
printf("\n");
printf("\nplease enter month2:\n");
scanf("%s",&month2);	
printf("\n");
printf("\nplease enter day2:\n");
scanf("%s",&day2);	
printf("\n");
show_all_financial_transactions_from_date_to_date(year,month,day,year2,month2,day2);
}	
	
if (choice == 12){
finisher_of_the_loop = true;
}
	
}//if finisher of the loop == false
else{
break;	
}		
	
}//while


}//int main


void menu(){
	
  time_t t = time(NULL);
  struct tm tm = *localtime(&t);
  printf("\nnow: %d-%02d-%02d %02d:%02d:%02d\n", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);

printf("\nmenu:");	
printf("\n1.add Bank_Account");	
printf("\n2.show all Bank_Accounts");	
printf("\n3.add Financial_transactions");
printf("\n4.show all Financial_transactions");
printf("\n5.show Financial_transactions by Type");
printf("\n6.show Financial_transactions by Title");
printf("\n7.show Financial_transactions by date");
printf("\n8.increase left_money");
printf("\n9.show today Financial_transactions");
printf("\n10.show Financial_transactions of current month");
printf("\n11.show Financial_transactions from date to date (period of time)");
printf("\n12.exit\n");	
	
}


int insert_account(){
	
FILE *fp;
  fp = fopen("BANK_ACCOUNTS.txt", "a+");

struct Bank_Account m;
char a[50],b[50],c[50],d[50],e[50],f[50],g[18];

 
printf("\nplease enter name\n");
scanf("%s",&a);
strcpy(m.name , a);

printf("\nplease enter last_name\n");
scanf("%s",&b);
strcpy(m.last_name , b);


printf("\nplease enter address\n");
scanf("%s",&c);
strcpy(m.address , c);

printf("\nplease enter bank account id number\n");
scanf("%s",&d);
strcpy(m.account_id_number , d);

printf("\nplease enter telephone\n");
scanf("%s",&e);
strcpy(m.telephone , e);

printf("\nplease enter bank account number\n");
scanf("%s",&f);
strcpy(m.Bank_account_number , f);

printf("\nplease enter left money\n");
scanf("%s",&g);
strcpy(m.left_money , g);



  fputs(m.name,fp);
  fputs("\t",fp);
  fputs(m.last_name,fp);
  fputs("\t",fp);
  fputs(m.address,fp);
  fputs("\t",fp);
  fputs(m.account_id_number,fp);
  fputs("\t",fp);
  fputs(m.telephone,fp);
  fputs("\t",fp);
  fputs(m.Bank_account_number,fp);
  fputs("\t",fp);
  fputs(m.left_money,fp); 
  fputs("\n",fp);  
  fclose(fp);	
  
  return 1;
		
}






int insert_financial_transactions(){
	
	
	
	
	
///// read bank accounts for subtract left money from Financial_transactions Cost and store updated informations



		
 FILE *fp2;
 fp2 = fopen("BANK_ACCOUNTS.txt", "r");
int how_many = get_how_many_accounts();
struct Bank_Account c[how_many];
int counter = 0;
while (!feof(fp2))
{
fscanf(fp2,"%s\t%s\t%s\t%s\t%s\t%s\t%s",&c[counter].name,&c[counter].last_name,&c[counter].address,&c[counter].account_id_number,&c[counter].telephone,&c[counter].Bank_account_number,&c[counter].left_money);
counter = counter + 1;
}
fclose(fp2);



/////##################
	

////////////taking input from user for creating new Financial_transactions 

struct Financial_transactions m;
char Type[50],Title[50],Cost[18],Bank_account_number[50],year[4],month[4],day[4];

 
printf("\nplease enter type\n");
scanf("%s",&Type);
strcpy(m.Type , Type);

printf("\nplease enter title\n");
scanf("%s",&Title);
strcpy(m.Title , Title);


printf("\nplease enter cost\n");
scanf("%s",&Cost);
strcpy(m.Cost , Cost);

printf("\nplease enter bank account number\n");
scanf("%s",&Bank_account_number);
strcpy(m.Bank_account_number , Bank_account_number);

printf("\nplease enter year\n");
scanf("%s",&year);
strcpy(m.year , year);

printf("\nplease enter month\n");
scanf("%s",&month);
strcpy(m.month , month);

printf("\nplease enter day\n");
scanf("%s",&day);
strcpy(m.day , day);

//////////##################


////////////////check that Financial_transactions is more than left_money or not



int i ;
int detect = 0;
int the_one_that_should_change = 0;

for(i = 0 ; i < how_many ; i++){
if (strcmp(Bank_account_number , c[i].Bank_account_number) == 0 ){
detect = 1;	
the_one_that_should_change = i;
}
}

if(detect == 1){

//convert string to long for sumition
char value[18],value2[18];
    char *eptr,*eptr2;
    long long result;
	long long result2;
	long long result3;

    strcpy(value, Cost);
    strcpy(value2, c[the_one_that_should_change].left_money);
printf("Cost:%s\n", Cost);
    result = strtoll(value, &eptr, 10);	
	result2 = strtoll(value2, &eptr2, 10);
	result3 = result2 - result;

 printf("%lld decimal1\n", result);	
 printf("%lld decimal2\n", result2);
  printf("%lld decimal3\n", result3);
//convert long result to string
if(result3>=0) {
 
 
sprintf(c[the_one_that_should_change].left_money, "%lld", result3);

 printf("c[the_one_that_should_change]:%s\n", c[the_one_that_should_change].left_money);		
	
}

else{
	
printf("\nentered Financial_transactions Cost is more than left_money hessab!");	
return -1;	
	
}
	
}
else{
printf("\nentered bank account is not exist!");	
return -1;
}

/////////////////################





////////////storing bank accounts again

FILE *sf;
 sf = fopen("BANK_ACCOUNTS.txt", "w");

for(i = 0 ; i < how_many ; i++){
  fputs(c[i].name,sf);
  fputs("\t",sf);
  fputs(c[i].last_name,sf);
  fputs("\t",sf);
  fputs(c[i].address,sf);
  fputs("\t",sf);
  fputs(c[i].account_id_number,sf);
  fputs("\t",sf);
  fputs(c[i].telephone,sf);
  fputs("\t",sf);
  fputs(c[i].Bank_account_number,sf);
  fputs("\t",sf);
  fputs(c[i].left_money,sf); 
  fputs("\n",sf);  
  }

fclose(sf);

///////////////////////////////////////#############






///// storing Financial_transactions in makharej_ha file 

FILE *fp3;
  fp3 = fopen("Financial transactions.txt", "a+");

  fputs(m.Type,fp3);
  fputs("\t",fp3);
  fputs(m.Title,fp3);
  fputs("\t",fp3);
  fputs(m.Cost,fp3);
  fputs("\t",fp3);
  fputs(m.Bank_account_number,fp3);
  fputs("\t",fp3);
  fputs(m.year,fp3);
  fputs("\t",fp3);
  fputs(m.month,fp3);
  fputs("\t",fp3);
  fputs(m.day,fp3); 
  fputs("\n",fp3);  
  fclose(fp3);	
 
 ///////###############
  
  return 1;
		
}




int get_how_many_Financial_transactions(){
 FILE *fp;
 fp = fopen("Financial transactions.txt","a+");
int size = 0;
struct Financial_transactions c;
char str[1000];

while (fgets(str,1000,fp) != NULL)
{	
size = size + 1;
}

fclose(fp);

return size;
}






int get_how_many_accounts(){
 FILE *fp;
 fp = fopen("BANK_ACCOUNTS.txt","a+");
int size = 0;
struct Bank_Account c;
char str[1000];

while (fgets(str,1000,fp) != NULL)
{	
size = size + 1;
}

fclose(fp);

return size;
}


void show_all_accounts(){
 FILE *fp;
 fp = fopen("BANK_ACCOUNTS.txt", "r");
int how_many = get_how_many_accounts();
struct Bank_Account c[how_many],m;
int counter = 0;
while (!feof(fp))
{
fscanf(fp,"%s\t%s\t%s\t%s\t%s\t%s\t%s",&c[counter].name,&c[counter].last_name,&c[counter].address,&c[counter].account_id_number,&c[counter].telephone,&c[counter].Bank_account_number,&c[counter].left_money);
counter = counter + 1;
}
fclose(fp);

int i = 0;

for(i = 0; i<how_many; i++)
show_account(c[i]);


}




void show_account(struct Bank_Account m){
printf("\nname:%s,last_name:%s,address:%s,email:%s,telephone:%s,Bank_account_number:%s,left_money:%s\n",m.name,m.last_name,m.address,m.account_id_number,m.telephone,m.Bank_account_number,m.left_money);
}





void show_all_financial_transactions(){
 FILE *fp;
 fp = fopen("Financial transactions.txt", "r");
int how_many = get_how_many_Financial_transactions();
struct Financial_transactions c[how_many];
int counter = 0;
while (!feof(fp))
{
fscanf(fp,"%s\t%s\t%s\t%s\t%s\t%s\t%s",&c[counter].Type,&c[counter].Title,&c[counter].Cost,&c[counter].Bank_account_number,&c[counter].year,&c[counter].month,&c[counter].day);
counter = counter + 1;
}
fclose(fp);

int i = 0;

for(i = 0; i<how_many; i++){
show_financial_transactions(c[i]);
}

}


void show_financial_transactions(struct Financial_transactions m){
printf("\ntype:%s,Title:%s,Cost:%s,Bank_account_number:%s,year:%s,month:%s,day:%s\n",m.Type,m.Title,m.Cost,m.Bank_account_number,m.year,m.month,m.day);
}

int check_date(struct Financial_transactions m,char year[],char month[],char day[]){
if(strcmp(m.year,year)==0&&strcmp(m.month,month)==0&&strcmp(m.day,day)==0)	
return 1;
else
return -1;	
}

int check_month(struct Financial_transactions m,char year[],char month[]){
if(strcmp(m.year,year)==0&&strcmp(m.month,month)==0)	
return 1;
else
return -1;	
}


int check_period_of_time(struct Financial_transactions m,char year[],char month[],char day[],char year2[],char month2[],char day2[]){
if((strcmp(m.year,year)==0&&strcmp(m.month,month)==0&&strcmp(m.day,day)==0)||(strcmp(m.year,year2)==0&&strcmp(m.month,month2)==0&&strcmp(m.day,day2)==0))	
return 1;
else if(strcmp(m.year,year)>=0&&strcmp(m.year,year2)<0)
return 1;
else if(strcmp(m.year,year)>=0&&strcmp(m.year,year2)<=0&&strcmp(m.month,month)>=0&&strcmp(m.month,month2)<0)
return 1;
else if(strcmp(m.year,year)>=0&&strcmp(m.year,year2)<=0&&strcmp(m.month,month)>=0&&strcmp(m.month,month2)<=0&&strcmp(m.day,day)>=0&&strcmp(m.day,day2)<0)
return 1;
else
return -1;	
}




int compare(char s1[] , char s2[]){
int size = sizeof(s1)/sizeof(s1[0]);
	int i;
	for(i = 0 ; i < size ; i++)
{
	if (s1[i]>s2[i])
	return 1;
	else if(s1[i]< s2[i])
	return -1;
	else{
	continue;
    }
}
return 0;
}

	
	
int sort_accounts(){	
	
 FILE *fileobj;
 fileobj = fopen("BANK_ACCOUNTS.txt", "r");
int i , j;
int how_many = get_how_many_accounts();
struct Bank_Account c[how_many];
int counter = 0;
while (!feof(fileobj))
{
fscanf(fileobj,"%s\t%s\t%s\t%s\t%s\t%s\t%s",&c[counter].name,&c[counter].last_name,&c[counter].address,&c[counter].account_id_number,&c[counter].telephone,&c[counter].Bank_account_number,&c[counter].left_money);
counter = counter + 1;
}
fclose(fileobj);


struct Bank_Account temp_bank_account;
int temp;
int temp2;
for(i=0;i<how_many;i++){
for(j=0;j<how_many-1;j++){	
temp = compare(c[j].last_name,c[j+1].last_name);
if (temp == 1){
//if previous bank account is bigger than next bank account (last_name).
temp_bank_account = c[j];
c[j] = c[j+1];
c[j+1] = temp_bank_account;
}
else if(temp == 0){
//if previous bank account is equal to next bank account (last_name) we should check names too.
temp2 = compare(c[j].name,c[j+1].name);
if(temp2 == 1){
temp_bank_account = c[j];
c[j] = c[j+1];
c[j+1] = temp_bank_account;	
}
}
else
continue;
}		
}


FILE *fileobj1;
 fileobj1 = fopen("BANK_ACCOUNTS.txt", "w");
for(i=0;i<how_many;i++){
  
  fputs(c[i].name,fileobj1);
  fputs("\t",fileobj1);
  fputs(c[i].last_name,fileobj1);
  fputs("\t",fileobj1);
  fputs(c[i].address,fileobj1);
  fputs("\t",fileobj1);
  fputs(c[i].account_id_number,fileobj1);
  fputs("\t",fileobj1);
  fputs(c[i].telephone,fileobj1);
  fputs("\t",fileobj1);
  fputs(c[i].Bank_account_number,fileobj1);
  fputs("\t",fileobj1);
  fputs(c[i].left_money,fileobj1);
  fputs("\n",fileobj1);  
  
}
fclose(fileobj1);


return 1;
	
}








int increase_left_money(char name[],char last_name[],char Bank_account_number[],char meghdar[]){
	
		
 FILE *fp;
 fp = fopen("BANK_ACCOUNTS.txt", "r");
int how_many = get_how_many_accounts();
struct Bank_Account c[how_many],m;
int counter = 0;
while (!feof(fp))
{
fscanf(fp,"%s\t%s\t%s\t%s\t%s\t%s\t%s",&c[counter].name,&c[counter].last_name,&c[counter].address,&c[counter].account_id_number,&c[counter].telephone,&c[counter].Bank_account_number,&c[counter].left_money);
counter = counter + 1;
}
fclose(fp);


int i ;
int detect = 0;
int the_one_that_should_change = 0;

for(i = 0 ; i < how_many ; i++){
if ((strcmp(name , c[i].name) == 0 )&&(strcmp(last_name , c[i].last_name) == 0 )&&(strcmp(Bank_account_number , c[i].Bank_account_number) == 0 )){
detect = 1;	
the_one_that_should_change = i;
}
}

if(detect == 1){

//convert string to long and do the sumition	
char value[18],value2[18];
    char *eptr,*eptr2;
    long long result;
	long long result2;
	long long result3;

    strcpy(value, meghdar);
    strcpy(value2, c[the_one_that_should_change].left_money);
printf("meghdar:%s\n", meghdar);
    result = strtoll(value, &eptr, 10);	
	result2 = strtoll(value2, &eptr2, 10);
	result3 = result + result2;

 printf("%lld decimal1\n", result);	
 printf("%lld decimal2\n", result2);
  printf("%lld decimal3\n", result3);
//convert result long to string
 
sprintf(c[the_one_that_should_change].left_money, "%lld", result3);

 printf("c[the_one_that_should_change]:%s\n", c[the_one_that_should_change].left_money);		
	
}
else{
printf("\nentered bank account is not exist!\n");	
return -1;
}



FILE *sf;
 sf = fopen("BANK_ACCOUNTS.txt", "w");

for(i = 0 ; i < how_many ; i++){
  fputs(c[i].name,sf);
  fputs("\t",sf);
  fputs(c[i].last_name,sf);
  fputs("\t",sf);
  fputs(c[i].address,sf);
  fputs("\t",sf);
  fputs(c[i].account_id_number,sf);
  fputs("\t",sf);
  fputs(c[i].telephone,sf);
  fputs("\t",sf);
  fputs(c[i].Bank_account_number,sf);
  fputs("\t",sf);
  fputs(c[i].left_money,sf); 
  fputs("\n",sf);  
  }

fclose(sf);

return 0;
}

void show_all_financial_transactions_by_type(char Type[]){
	
 FILE *fp;
 fp = fopen("Financial transactions.txt", "r");
int how_many = get_how_many_Financial_transactions();
struct Financial_transactions c[how_many];
int counter = 0;
while (!feof(fp))
{
fscanf(fp,"%s\t%s\t%s\t%s\t%s\t%s\t%s",&c[counter].Type,&c[counter].Title,&c[counter].Cost,&c[counter].Bank_account_number,&c[counter].year,&c[counter].month,&c[counter].day);
counter = counter + 1;
}
fclose(fp);

int i;

printf("\n Type:%s",Type);
printf("\n");
for(i = 0; i < how_many; i++){
if(strcmp(c[i].Type , Type) == 0)
show_all_financial_transactions(c[i]);	
}
	
	
}

void show_all_financial_transactions_by_title(char Title[]){
	
 FILE *fp;
 fp = fopen("Financial transactions.txt", "r");
int how_many = get_how_many_Financial_transactions();
struct Financial_transactions c[how_many];
int counter = 0;
while (!feof(fp))
{
fscanf(fp,"%s\t%s\t%s\t%s\t%s\t%s\t%s",&c[counter].Type,&c[counter].Title,&c[counter].Cost,&c[counter].Bank_account_number,&c[counter].year,&c[counter].month,&c[counter].day);
counter = counter + 1;
}
fclose(fp);

int i;

printf("\n Title:%s",Title);
printf("\n");
for(i = 0; i < how_many; i++){
if(strcmp(c[i].Title , Title) == 0)
show_all_financial_transactions(c[i]);	
}
	
	
}


void show_all_financial_transactions_by_date(char year[],char month[],char day[]){
	
 FILE *fp;
 fp = fopen("Financial transactions.txt", "r");
int how_many = get_how_many_Financial_transactions();
struct Financial_transactions c[how_many];
int counter = 0;
while (!feof(fp))
{
fscanf(fp,"%s\t%s\t%s\t%s\t%s\t%s\t%s",&c[counter].Type,&c[counter].Title,&c[counter].Cost,&c[counter].Bank_account_number,&c[counter].year,&c[counter].month,&c[counter].day);
counter = counter + 1;
}
fclose(fp);

int i = 0;

printf("\nyear:%s,month:%s,day:%s",year,month,day);
printf("\n");
for(i = 0; i < how_many; i++){
if(check_date(c[i],year,month,day) == 1)
show_all_financial_transactions(c[i]);
}
	
	
}


void show_all_financial_transactions_of_current_month(char year[],char month[]){
	
 FILE *fp;
 fp = fopen("Financial transactions.txt", "r");
int how_many = get_how_many_Financial_transactions();
struct Financial_transactions c[how_many];
int counter = 0;
while (!feof(fp))
{
fscanf(fp,"%s\t%s\t%s\t%s\t%s\t%s\t%s",&c[counter].Type,&c[counter].Title,&c[counter].Cost,&c[counter].Bank_account_number,&c[counter].year,&c[counter].month,&c[counter].day);
counter = counter + 1;
}
fclose(fp);

int i = 0;

printf("\nyear:%s,month:%s",year,month);
printf("\n");
for(i = 0; i < how_many; i++){
if(check_month(c[i],year,month) == 1)
show_all_financial_transactions(c[i]);	
}
	
	
}


void show_all_financial_transactions_from_date_to_date(char year[],char month[],char day[],char year2[], char month2[] , char day2[]){
	
 FILE *fp;
 fp = fopen("Financial transactions.txt", "r");
int how_many = get_how_many_Financial_transactions();
struct Financial_transactions c[how_many];
int counter = 0;
while (!feof(fp))
{
fscanf(fp,"%s\t%s\t%s\t%s\t%s\t%s\t%s",&c[counter].Type,&c[counter].Title,&c[counter].Cost,&c[counter].Bank_account_number,&c[counter].year,&c[counter].month,&c[counter].day);
counter = counter + 1;
}
fclose(fp);

int i = 0;

printf("\nyear1:%s,month1:%s,day1:%s",year,month,day);
printf("\nyear2:%s,month2:%s,day2:%s\n",year2,month2,day2);
for(i = 0; i < how_many; i++){
if(check_period_of_time(c[i],year,month,day,year2,month2,day2) == 1)
show_all_financial_transactions(c[i]);
}
	
	
}




