#include<iostream>
#include<fstream>
#define user_name "Aamish"
#define pass "Aamish123"
using namespace std;
const int size=100;
struct product
{
int *id=new int[size];
int *quantity=new int[size];
string *name=new string[size];
double *price=new double[size]; 
};
void read(product products,int &count)
{
ifstream read;
read.open("Inventory Stock Data.txt");
if(!read){
cout<<"File Does Not exist"<<endl;	
}	
else
{
string line;
getline(read,line);
while(read>>products.id[count]>>products.name[count]>>products.price[count]>>products.quantity[count]){
count++;}	
read.close(); 
}
}
void write(product products,int &count)
{
int max_length=0;	
for(int a=0;a<count;a++)
{
int len=products.name[a].length();
if(len>max_length)
{
max_length=len;	
}
}		
ofstream data;
data.open("Inventory Stock Data.txt");
data<<"ID\tNAME\t\tPRICE\tQUANTITY"<<endl;
for(int a=0;a<count;a++)
{
data<<products.id[a]<<"\t"<<products.name[a];
int len=products.name[a].length();
int space=max_length-len;
data<<std::string(space,' ');
data<<"\t"<<products.price[a]<<"\t"<<products.quantity[a]<<endl;		
}	
}
void authentication(string &user,string &password,int &valid_pass)
{
cout<<"Enter Username: ";
cin>>user;
cout<<"Enter Password: ";
cin>>password;	
if(user_name ==user && password==pass)
{
valid_pass++;	
}
else
{
cout<<"Invalid UserName Or Password!\nTry Again"<<endl;
}
}
void insert(product products,int &count)
{
ofstream data;
data.open("Inventory Stock Data.txt");	
int add;	
cout<<"How many Products you want to Insert?: ";
cin>>add;
data<<"ID\tNAME\t\tPRICE\tQUANTITY"<<endl;
for(int a=0;a<add;a++)
{
cout<<"Enter Product ID: ";
cin>>products.id[count];
data<<products.id[count]<<"\t";
cout<<"Enter Product Name: ";
cin>>products.name[count];
data<<products.name[count]<<"\t";
cout<<"Enter Product Price: ";
cin>>products.price[count];
data<<products.price[count]<<"\t";
cout<<"Enter Product Quantity: ";
cin>>products.quantity[count];
data<<products.quantity[count]<<endl;
count++;	
}	
}
void search(product products,int count)
{
int condition=false;	
int search;	
cout<<"Enter The ID you want to find!: ";
cin>>search;
for(int a=0;a<count;a++)
{
if(search==products.id[a])	
{
cout<<"ID\tName\tPrice\tQuantity"<<endl;
cout<<products.id[a]<<"\t"<<products.name[a]<<"\t"<<products.price[a]<<"\t"<<products.quantity[a]<<endl;
condition=true;	
}	
}	
if(condition==false)
{
cout<<"ID Not Found"<<endl;	
}
}
void display_all(product products,int count)
{
int max_length=0;	
for(int a=0;a<count;a++)
{
int len=products.name[a].length();
if(len>max_length)
{
max_length=len;	
}
}	
cout<<"ID\tName\t\tPrice\tQuantity"<<endl;	
for(int a=0;a<count;a++)
{
cout<<products.id[a]<<"\t";
int len=products.name[a].length();
int space=max_length-len;
cout<<products.name[a];
cout<<std::string(space,' ');
cout<<"\t"<<products.price[a]<<"\t"<<products.quantity[a]<<endl;	
}		
}
void display_single(product products,int count)
{
display_all(products,count);	
int condition=false;	
int search;	
cout<<"Enter The ID Of The Product you want to Display!: ";
cin>>search;
for(int a=0;a<count;a++)
{
if(search==products.id[a])	
{
cout<<"ID\tName\tPrice\tQuantity"<<endl;
cout<<products.id[a]<<"\t"<<products.name[a]<<"\t"<<products.price[a]<<"\t"<<products.quantity[a]<<endl;
condition=true;	
}	
}	
if(condition==false)
{
cout<<"ID Not Found"<<endl;	
}
}
void update(product products,int count)
{	
int condition=false;	
int search;	
cout<<"Enter The ID you want to find!: ";
cin>>search;
for(int a=0;a<count;a++)
{
if(search==products.id[a])	
{
cout<<"Enter Updated ID: ";
cin>>products.id[a];
cout<<"Enter Updated Name: ";	
cin>>products.name[a];
cout<<"Enter Updated Price: ";
cin>>products.price[a];
cout<<"Enter Updated Quantity: ";
cin>>products.quantity[a];
condition=true;
}	
}	
if(condition==true)
{
cout<<"ID\tName\tPrice\tQuantity"<<endl;	
ofstream data;
data.open("Inventory Stock Data.txt");
for(int a=0;a<count;a++)
{
data<<products.id[a]<<"\t"<<products.name[a]<<"\t"<<products.price[a]<<"\t"<<products.quantity[a]<<endl;	
}	
}
if(condition==false)
{
cout<<"Record Not Found"<<endl;	
}	
}
void delete_rec(product products,int &count)
{
display_all(products,count);	
int condition=false;	
int search;	
cout<<"Enter The ID you want to find!: ";
cin>>search;
for(int a=0;a<count;a++)
{
if(search==products.id[a])	
{	
for(int b=a;b<count-1;b++)
{
products.id[b]=products.id[b+1];
products.name[b]=products.name[b+1];
products.price[b]=products.price[b+1];
products.quantity[b]=products.quantity[b+1];
}
condition=true;	
count--;
}	
}	
if(condition==false)
{
cout<<"ID Not Found"<<endl;	
}	
else
{
cout<<"Record Found And Deleted Successfully!"<<endl;	
}	
}
void exit()
{
cout<<"Good-Bye Admin!"<<endl;
}
void buy(product products,int count,double &total_bill,int *index,int *quantity)
{
bool condition=false;	
display_all(products,count);
int search;
cout<<"Enter ID Of the item You Want to Buy: ";
cin>>search;
for(int a=0;a<count;a++)
{
if(search==products.id[a] && products.quantity!=0)
{	
condition=true;	
int quan;	
cout<<"How many Quantity of "<<products.name[a]<<"?: ";
cin>>quan;
if(products.quantity[a]>=quan)
{
quantity[a]=quantity[a]+quan;	
index[a]++;	
total_bill=total_bill+(quan*products.price[a]);
products.quantity[a]=products.quantity[a]-quan;
}
else
{
cout<<"Not Enough Stock"<<endl;	
}
}
}
if(count==0)
{
cout<<"No Item In inventory"<<endl;	
}
if(condition==false)
{
cout<<"Invalid Information"<<endl;	
}		
}
void cancel(product products,int count,double &total_bill,int *index,int *quantity){
cout<<"ID\tName\tPrice\tQuantity"<<endl;	
for(int a=0;a<count;a++){	
if(index[a]>0){
cout<<products.id[a]<<"\t"<<products.name[a]<<"\t"<<products.price[a]<<"\t"<<quantity[a]<<endl;	
}	
}		
bool condition=false;	
int id;
cout<<"Enter ID Of the Item You Want To Cancel"<<endl;
cin>>id;
for(int a=0;a<count;a++){
if(id==products.id[a]){
condition=true;	
if(index[a]>0){
total_bill=total_bill-(products.price[a]*quantity[a]);
index[a]=0;		
products.quantity[a]=products.quantity[a]+quantity[a];
quantity[a]=0;
cout<<"Cancelled Successfully"<<endl;
}
else{
cout<<"You Have Not Added "<<products.name[a]<<" In Your Cart"<<endl;	
}			
}	
}	
if(condition==false){
cout<<"Invalid ID"<<endl;	
}
}
void checkout(product products,int count,double total_bill,int *index,int *quantity,string &review, string *customer_name)
{	
int max_length=0;
int name_count=0;
ofstream sales_data;
sales_data.open("Sales Data.txt",ios::app);
bool condition=false;
char choice;
cout<<"Enter Your Name"<<endl;
cin.ignore();
getline(cin,customer_name[name_count]);
if(total_bill!=0)	
{	
cout<<"\tYour Reciept"<<endl;	
cout<<"Customer Name: "<<customer_name[name_count]<<endl;
cout<<"ID\tNAME\t\tPRICE\tQUANTITY\tTOTAL BILL"<<endl;
sales_data<<"Customer Order Details"<<endl;
sales_data<<"Customer Name: "<<customer_name[name_count]<<endl;
sales_data<<"ID\tNAME\t\tPRICE\tQUANTITY\tTOTAL BILL"<<endl;	
for(int a=0;a<count;a++)
{
if(index[a]!=0)
{	
for(int a=0;a<count;a++)
{
int len=products.name[a].length();
if(len>max_length)
{
max_length=len;	
}
}	
cout<<products.id[a]<<"\t";
sales_data<<products.id[a]<<"\t";
int len=products.name[a].length();
int space=max_length-len;
sales_data<<products.name[a];
sales_data<<std::string(space,' ');
cout<<products.name[a];
cout<<std::string(space,' ');
cout<<"\t"<<products.price[a]<<"\t "<<quantity[a]<<" \t\t"<<products.price[a]*quantity[a]<<endl;	
sales_data<<"\t"<<products.price[a]<<"\t "<<quantity[a]<<" \t\t"<<products.price[a]*quantity[a]<<endl;	
}	
}
sales_data<<" \tTOTAL BILL\t\t\t  = Rs. "<<total_bill<<endl;	
cout<<" \tTOTAL BILL\t\t\t  = Rs. "<<total_bill<<endl;	
}	
else

{
cout<<"You Ordered Nothing"<<endl;
cout<<customer_name[name_count]<<" Your Total Bill is= "<<total_bill<<"Rs"<<endl;
}
cout<<"Do You Want To Review our Services?"<<endl;
cout<<"y/Y for Yes"<<endl;
cout<<"n/N for NO"<<endl;
cin>>choice;
for(int a=0;a<10;a++)
{
if(choice=='Y' || choice =='y')
{
cout<<"Enter Review"<<endl;
condition=true;
break;	
}
if(choice=='N' || choice =='n')
{
break;	
}
if(choice!='Y' || choice !='y' && choice!='N' || choice !='n')	
{
cout<<"Invalid Input"<<endl;
cout<<"y/Y for Yes"<<endl;
cout<<"N/N for Yes"<<endl;
cin>>choice;	
}	
}
if(condition==true)
{
cin.ignore();
getline(cin,review);	
cout<<"Thank you For your Review"<<endl;
ofstream off;
off.open("Reviews.txt",ios::app);
off<<"Customer Name: ";
off<<customer_name[name_count]<<endl;
off<<"Review: "<<review<<endl;
}
write(products,count);
name_count++;
}
void sell_old(product products,double &total_bill,int count){
string name_old_item_customer;	
ofstream sales_data;
sales_data.open("Sales Data Old Items.txt",ios::app);	
bool nego_condition=false;	
bool accept_condition=false;
int temp;		
cout<<"NOTE: WE ONLY BUY PRODUCTS THAT ARE IN WORKING CONDITION!"<<endl;
int id;	
for(int a=0;a<count;a++){
cout<<products.id[a]<<"\t"<<products.name[a]<<endl;	
}
cout<<"Enter ID of the Product: ";
cin>>id;
temp=id-1;
for(int a=0;a<count;a++){
if(id==products.id[a]){	
cout<<"The Max I Could Give You for "<<products.name[a]<<"is Rs. "<<products.price[a]*0.3<<endl;	
cout<<"1. Accept this Offer"<<endl;
cout<<"2. Reject this Offer"<<endl;
int offer_choice;
cout<<"Enter Your Choice: ";
cin>>offer_choice;
if(offer_choice==1){
accept_condition=true;	
total_bill=total_bill-(products.price[a]*0.3);
products.quantity[a]++;	
}	
if(offer_choice==2)
{
int choice;	
cout<<"My Last Offer! Rs. "<<products.price[a]*0.4<<endl;	
cout<<"1. Accept"<<endl;
cout<<"2. Reject"<<endl;
cout<<"Enter Your Choice: ";
cin>>choice;
if(choice==1)
{	
nego_condition=true;
accept_condition=true;
total_bill=total_bill-(products.price[a]*0.4);	
products.quantity[a]++;	
}
if(choice==2)
{
cout<<"Hope we could make Business in the Future!"<<endl;	
}
	}	
	
	}	
	}
if(accept_condition==true)
{
if(nego_condition==false)
{
cout<<"Enter Your Name: ";	
cin.ignore();
getline(cin,name_old_item_customer);	
sales_data<<"Customer Name: "<<name_old_item_customer<<endl;
cout<<"ID\tNAME\tPRICE\tTOTAL BILL"<<endl;
sales_data<<"ID\tNAME\tPRICE\tTOTAL BILL"<<endl;
sales_data<<products.id[temp]<<"\t"<<products.name[temp]<<"\t"<<products.price[temp]*0.3<<"\t"<<total_bill<<endl;	
cout<<products.id[temp]<<"\t"<<products.name[temp]<<"\t"<<products.price[temp]*0.3<<"\t"<<total_bill<<endl;	
cout<<"Recieve Rs."<<products.price[temp]*0.3<<" from the Counter!"<<endl;
}
else
{
cout<<"Enter Your Name: ";	
cin.ignore();
getline(cin,name_old_item_customer);	
sales_data<<"Customer Name: "<<name_old_item_customer;	
sales_data<<"ID\tNAME\tPRICE\tTOTAL BILL"<<endl;
sales_data<<products.id[temp]<<"\t"<<products.name[temp]<<"\t"<<products.price[temp]*0.3<<"\t"<<total_bill<<endl;	
cout<<"ID\tNAME\tPRICE\tTOTAL BILL"<<endl;
cout<<products.id[temp]<<"\t"<<products.name[temp]<<"\t"<<products.price[temp]*0.4<<"\t"<<total_bill<<endl;	
cout<<"Recieve Rs."<<products.price[temp]*0.4<<" from the Counter!"<<endl;
}		
}			
total_bill=0;	
}
int main()
{
string *customer_name=new string [size];	
int admin_intro=0;	
string review;	
int* quantity=new int[100]{0};	
int count_authentication=0;	
string user,password;	
double total_bill=0;
int *index=new int[100]{0};
int count_insert=0;	
product products;	
int cus_choice;	
int choice;	
read(products,count_insert);
int main_choice;	
cout<<"\t\t\t\t\t\t\t__________________________________________________\n"<<endl;
cout<<"\t\t\t\t\t\t\t\tCOMPUTER SALE POINT BILLING SYSTEM\n";
cout<<"\t\t\t\t\t\t\t__________________________________________________"<<endl;
cout<<"\t\t\t\t\t\t\t__________________________________________________\n"<<endl;
cout<<"\t\t\t\t\t\t\t\t\t   MAIN MENU\n";
cout<<"\t\t\t\t\t\t\t__________________________________________________"<<endl;
cout<<"1. Customer Mode"<<endl;
cout<<"2. Admin Mode"<<endl;
cout<<"Enter Your Choice: ";
cin>>main_choice;
while(true)
{
if(main_choice==1)
{
cout<<"\t\t\t\t\t\t\t__________________________________________________\n"<<endl;
cout<<"\t\t\t\t\t\t\t\t\t CUSTOMER MENU\n";
cout<<"\t\t\t\t\t\t\t__________________________________________________"<<endl;
cout<<"1. Buy an Item"<<endl;
cout<<"2. Checkout"<<endl;
cout<<"3. Main Menu"<<endl;
cout<<"4. Cancel An Item From Checkout"<<endl;
cout<<"5. Sell Your OLD Item"<<endl;
cout<<"6. Exit Application"<<endl;
cout<<"Enter Your Choice: ";
cin>>cus_choice;
if(cus_choice==1)
{
buy(products,count_insert,total_bill,index,quantity);	
}
if(cus_choice==2)
{
checkout(products,count_insert,total_bill,index,quantity,review,customer_name);
cout<<"Good-Bye Our Valuable Customer Customer"<<endl;
total_bill=0;
for(int a=0;a<count_insert;a++)
{
index[a]=0;	
}
}
if(cus_choice==3)
{
cout<<"1. Customer Mode"<<endl;
cout<<"2. Admin Mode"<<endl;
cout<<"Enter Your Choice: ";
cin>>main_choice;	
}
if(cus_choice==4)
{
cancel(products,count_insert,total_bill,index,quantity);	
}
if(cus_choice==5)
{
sell_old(products,total_bill,count_insert);	
}
if(cus_choice==6)
{
exit();
write(products,count_insert);
break;	
}
}
if(main_choice==2)
{
if(count_authentication==0)	
{
authentication(user,password,count_authentication);
}
if(admin_intro==0 && count_authentication!=0)
{
cout<<"\t\t\t\t\t\t\t__________________________________________________\n"<<endl;
cout<<"\t\t\t\t\t\t\t\t\t WELCOME ADMIN\n";
cout<<"\t\t\t\t\t\t\t__________________________________________________"<<endl;
cout<<"\t\t\t\t\t\t\t__________________________________________________\n"<<endl;
cout<<"\t\t\t\t\t\t\t\t\t   ADMIN MENU\n";
cout<<"\t\t\t\t\t\t\t__________________________________________________"<<endl;
admin_intro++;
}
if(count_authentication!=0)
{
cout<<"1. Insert Record"<<endl;
cout<<"2. Update Record"<<endl;
cout<<"3. Delete Record"<<endl;
cout<<"4. Search Record"<<endl;
cout<<"5. Display Single Record"<<endl;
cout<<"6. Display All Records"<<endl;
cout<<"7. Main Menu"<<endl;
cout<<"8. Exit"<<endl;
cout<<"Enter your choice: ";	
cin>>choice;
if(choice==1)
{	
insert(products,count_insert);
}
if(choice==2)
{
update(products,count_insert);	
}
if(choice==3){
delete_rec(products,count_insert);	
}
if(choice==4){	
search(products,count_insert);
}	
if(choice==5){
display_single(products,count_insert);
}	
if(choice==6){
display_all(products,count_insert);
}
if(choice==7){
count_authentication=0;	
admin_intro=0;
cout<<"\t\t\t\t\t\t\t__________________________________________________\n"<<endl;
cout<<"\t\t\t\t\t\t\t\tCOMPUTER SALE POINT BILLING SYSTEM\n";
cout<<"\t\t\t\t\t\t\t__________________________________________________"<<endl;
cout<<"\t\t\t\t\t\t\t__________________________________________________\n"<<endl;
cout<<"\t\t\t\t\t\t\t\t\t   MAIN MENU\n";
cout<<"\t\t\t\t\t\t\t__________________________________________________"<<endl;
cout<<"1. Customer Mode"<<endl;
cout<<"2. Admin Mode"<<endl;
cout<<"Enter Your Choice: ";
cin>>main_choice;	
}	
if(choice==8){
exit();
write(products,count_insert);
break; }	
}
}
}	
}


