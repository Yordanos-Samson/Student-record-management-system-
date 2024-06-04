/*   Car rental management system
By:
  Feven Gurju        BDU 1404550
  Gelila Azanaw      BDU 1410564
  Samrawit Abate     BDU 1404046

*/

#include<iostream>
#include<fstream>
#include<conio.h>
#include<string.h>
using namespace std;

struct customer{
char name[20];
int age;
char car_model[10];
char sex[6];
int ID_NO;
int noofdays;
float price;
int car_no;
customer *next;
};
struct customer *start=NULL;

void ReadFromFile();
void InsertAtTheEnd();
void InsertAtAPosition();
void DeleteAtTheBeginning();
void DeleteAtTheEnd();
void DeleteAtAPosition();
void DeleteAnodewithgivenattributes();
void SearchByMinPrice();
void SearchByMaxPrice();
void CalculateAveragePrice();
void CalculateAverageAge();
void DeleteByMaxAge();
void DeleteByMinAge();
void SearchByAttribute();
void DisplayAllInformation();
void WriteInFile();
void CountNoOfCustomers();
void CountOccurrence();
void Update();
void sortbyname();
void sortbyage();
void sortbycarmodel();
void sortbynoofdays();
void sortbysex();
void sortbyprice();
void sortbycarno();
void sortbyIDNO();
void sortbyname();
void sortswap(customer *temp1,customer *temp2);
void Sort();
void DisplayTopCustomer();
void topname();
void toptenname();
void topfifteenname();
void toptwentyname();
void topsex();
void toptensex();
void topfifteensex();
void toptwentysex();
void topage();
void toptenage();
void topfifteenage();
void toptwentyage();
void topcarno();
void toptencarno();
void topfifteencarno();
void toptwentycarno();
void topIDNO();
void toptenIDNO();
void topfifteenIDNO();
void toptwentyIDNO();
void topprice();
void toptenprice();
void topfifteenprice();
void toptwentyprice();
void topnoofday();
void toptennoofday();
void topfifteennoofday();
void toptwentynoofday();
void topcarmodel();
void toptencarmodel();
void topfifteencarmodel();
void toptwentycarmodel();



int main()
{
  char check='y';
   while (check=='y'||check=='Y')
     {
       int key;
        char choice;
        cout<<"       Welcome to our company      "<<endl;
        cout<<"                 Menu      "<<endl;
        cout<<"Press 1:To insert data from notepad file"<<endl;
        cout<<"Press 2: To insert a data at the end of the list from user"<<endl;
        cout<<"Press 3: To Insert a data at a position"<<endl;
        cout<<"Press 4: TO delete the first element in the list"<<endl;
        cout<<"Press 5: TO delete the last element in the list"<<endl;
        cout<<"Press 6: To delete a data based on attribute"<<endl;
        cout<<"Press 7: To delete at a position"<<endl;
        cout<<"Press 8: To search and find a car with minimum price"<<endl;
        cout<<"Press 9: To search and find a car with maximum price"<<endl;
        cout<<"Press 10: To calculate average price"<<endl;
        cout<<"Press 11: To calculate average age"<<endl;
        cout<<"Press 12: To delete a customer with maximum age"<<endl;
        cout<<"Press 13: To delete a customer with minimum age"<<endl;
        cout<<"Press 14: To search by attribute"<<endl;
        cout<<"Press 15: To display all information about all customers"<<endl;
        cout<<"Press 16: To write information about all customers in a notepad file"<<endl;
        cout<<"Press 17: To count the number of customers"<<endl;
        cout<<"Press 18: To count number of occurrences of a certain value of an attribute"<<endl;
        cout<<"Press 19: To update required attributes"<<endl;
        cout<<"Press 20: To sort by each attribute"<<endl;
        cout<<"Press 21: To display information about the top customers"<<endl;
        cin>>key;

       if(key==1)
          {
             ReadFromFile();
          }
       else if(key==2)
          {
              InsertAtTheEnd();
          }
       else if(key==3)
          {
             InsertAtAPosition();

          }
      else if(key==4)
          {
             DeleteAtTheBeginning();
          }
      else if(key==5)
          {
            DeleteAtTheEnd();
          }
       else if(key==6)
          {
            DeleteAnodewithgivenattributes();
          }
      else if(key==7)
         {
           DeleteAtAPosition();
        }

      else if(key==8)
         {
             SearchByMinPrice();
         }

     else if(key==9)
        {
           SearchByMaxPrice();
         }

      else if(key==10)
         {
           CalculateAveragePrice();
         }

       else if(key==11){
             CalculateAverageAge();
           }

      else if(key==12)
         {
             DeleteByMaxAge();
         }

      else if(key==13)
         {
            DeleteByMinAge();
         }

      else if(key==14)
          {
             SearchByAttribute();
          }
      else if(key==15)
         {
            DisplayAllInformation();
         }
      else if(key==16)
        {
          WriteInFile();
        }
    else if(key==17)
        {
         CountNoOfCustomers();
        }
    else if(key==18)
        {
          CountOccurrence();
        }

    else if(key==19)
        {
            Update();
         }
    else if(key==20)
        {
            Sort();
        }
    else if(key==21)
        {
           DisplayTopCustomer();
        }

    else
         cout<<"Enter valid number"<<endl;


    cout<<"Do you want to go back to the main menu?(Y/N)"<<endl;
      cin>>check;
}
}
void ReadFromFile()
{
    ifstream indata;
    string line;
    indata.open("customers.txt");
    if(!indata)
        {
        cout<<"Error, can't open file";
    exit(1);
        }
        indata>>line;
        while(!indata.eof())
            {
             cout<<"  "<<line<<endl;
             indata>>line;
            }
            indata.close();
}
void WriteInFile()
{

  fstream myfile;
  myfile.open("Customers.txt",ios::out);
  if(myfile.is_open())
   {
     for(customer *n=start; n!=NULL ;n=n->next)
      {
          myfile<<n->name<<endl;
          myfile<<n->age<<endl;
          myfile<<n->car_model<<endl;
          myfile<<n->sex<<endl;
          myfile<<n->ID_NO<<endl;
          myfile<<n->price<<endl;
          myfile<<n->noofdays<<endl;
          myfile<<n->car_no<<endl;
          myfile.close();
      }
  }
}
void InsertAtTheEnd()
{
    customer *n=new customer;
    cout<<"Enter name"<<endl;
    cin>>n->name;
    cout<<"Enter age"<<endl;
    cin>>n->age;
    cout<<"Enter Car model"<<endl;
    cin>>n->car_model;
    cout<<"Enter sex"<<endl;
    cin>>n->sex;
    cout<<"Enter ID NO"<<endl;
    cin>>n->ID_NO;
    cout<<"Enter price"<<endl;
    cin>>n->price;
    cout<<"Enter no of days"<<endl;
    cin>>n->noofdays;
    cout<<"Enter car number"<<endl;
    cin>>n->car_no;
    n->next=NULL;
    if(start==NULL)
      start=n;
    else
      {
        customer *i=start;
          while(i->next!=NULL)
            {
               i=i->next;
            }
          i->next=n;
      }
}
void InsertAtAPosition()
{
    customer *n=new customer;
    cout<<"Enter name"<<endl;
    cin>>n->name;
    cout<<"Enter age"<<endl;
    cin>>n->age;
    cout<<"Enter Car model"<<endl;
    cin>>n->car_model;
    cout<<"Enter sex"<<endl;
    cin>>n->sex;
    cout<<"Enter ID NO"<<endl;
    cin>>n->ID_NO;
    cout<<"Enter price"<<endl;
    cin>>n->price;
    cout<<"Enter no of days"<<endl;
    cin>>n->noofdays;
    cout<<"Enter car number"<<endl;
    cin>>n->car_no;
    n->next=NULL;
    if(start==NULL)
      start=n;
    else
       {
          int p,i=1;
           customer *temp=start;
           customer *newnode;
            cout<<"Enter Position";
            cin>>p;
           while(i<p-1)
             {
                temp=temp->next;
                i++;
             }
          n->next=temp->next;
          temp->next=n;
       }
    cout<<"Customer is Successfully registered "<<endl;
}
void DeleteAtTheBeginning()
{
   if(start==NULL)
     cout<<"The list is empty,can't delete"<<endl;
   else if(start->next==NULL)
     delete start;
   else
     {
        customer *temp;
        temp=start;
        start=start->next;
        temp->next=NULL;
        delete temp;
   }
}
void DeleteAtTheEnd()
{
   if(start==NULL)
      cout<<"The list is empty";
   else if(start->next==NULL)
      delete start;
    else
      {
        customer *t1,*t2;
        t1=start;
        while(t1->next!=NULL)
          {
             t2=t1;
             t1=t1->next;
             t2->next=NULL;
             delete t1;
          }
      }
}
void DeleteAnodewithgivenattributes()
{
   char key[20];
   int m;
   int n;
   cout<<"Press 1: To delete using name"<<endl;
   cout<<"press 2: To delete using age"<<endl;
   cout<<"Press 3:To delete using car model"<<endl;
   cout<<"press 4: To delete using number of days"<<endl;
   cout<<"Press 5:To delete using sex"<<endl;
   cout<<"Press 6: To delete using price"<<endl;
   cout<<"press 7: To delete using ID NO"<<endl;
   cout<<"press 8: To delete using car number"<<endl;
   cin>>m;
   if(m==1)
     {
       cout<<"Enter the name of the customer you wanted to delete";
       cin>>key;
       if(start==NULL)
       cout<<"List is empty,can't delete";
   else
     {
       customer *t1,*t2;
       t2=start;
       t1=start;
      while(t1!=NULL)
       {
         if(strcmp(key,t1->name)==0)
          {
            t2->next=t1->next;
            t1->next=NULL;
            delete t1;
            break;
          }
        else
         {
           t2=t1;
           t1=t1->next;

         }
      }
    }
   }
   if(m==2)
    {
       char n;
       cout<<"Enter the age of the customer you wanted to delete";
       cin>>n;
       if(start==NULL)
          cout<<"List is empty";
       else
        {
           customer *t1,*t2;
           t2=start;
           t1=start;
           while(t1!=NULL)
             {
               if(n==t1->age)
                  {
                    t2->next=t1->next;
                    t1->next=NULL;
                    delete t1;
                    break;
                  }
              else
               {
                 t2=t1;
                 t1=t1->next;
              }
           }
        }
   }
   if(m==3)
     {
       char n[10];
       cout<<"enter car model you want to delete";
       cin>>n;
       if(start==NULL)
          cout<<"list is empty,can't delete";
       else
        {
          customer *t1,*t2;
          t1=start;
          t2=start;
          while(t1!=NULL)
            {
              if(strcmp(t1->car_model,n)==0)
                {
                  t2->next=t1->next;
                  t1->next=NULL;
                  delete t1;
                  break;
                }
             else
               {
                 t2=t1;
                 t1=t1->next;
               }
            }
       }
    }

   if(m==4)
    {
      cout<<"enter number of days you want to delete";
      cin>>n;
      if(start==NULL)
         cout<<"list is empty,can't delete";
      else
       {
          customer *t1,*t2;
          t1=start;
          t2=start;
          while(t1!=NULL)
           {
             if(n==t1->noofdays)
               {
                 t2->next=t1->next;
                 t1->next=NULL;
                 delete t1;
                 break;
               }
            else
             {
               t2=t1;
               t1=t1->next;
             }
         }
    }
   }
   if(m==5)
    {
      cout<<"Enter sex of the customer you wanted to delete";
      cin>>key;
      if(start==NULL)
         cout<<"List is empty,can't delete";
      else
        {
           customer *t1,*t2;
            t1=start;
            t2=start;
            while(t1!=NULL)
              {
                if(strcmp(key,t1->sex)==0)
                  {
                    t2->next=t1->next;
                    t1->next=NULL;
                    delete t1;
                    break;
                 }
               else
                {
                  t2=t1;
                  t1=t1->next;
                }
            }
       }
   }
   if(m==6)
     {
        cout<<"enter price you want to delete";
        cin>>n;
        if(start==NULL)
            cout<<"list is empty,can't delete";
         else
           {
             customer *t1,*t2;
             t1=start;
             t2=start;
             while(t1!=NULL)
              {
                 if(n==t1->price)
                   {
                     t2->next=t1->next;
                     t1->next=NULL;
                     delete t1;
                     break;
                  }
                else
                  {
                     t2=t1;
                     t1=t1->next;
                  }

             }
          }
      }
    if(m==7)
       {
         cout<<"Enter ID NO of the customer you wanted to delete";
         cin>>n;
         if(start==NULL)
           cout<<"List is empty";
        else
         {
           customer *t1,*t2;
           t1=start;
           t2=start;
           while(t1!=NULL)
             {
                if(n==t1->ID_NO)
                  {
                    t2->next=t1->next;
                    t1->next=NULL;
                    delete t1;
                    break;
                  }
                else
                  {
                    t2=t1;
                    t1=t1->next;
                  }
            }
         }
     }

    if(m==8)
     {
        cout<<"Enter the car number you wanted to delete";
        cin>>n;
        if(start==NULL)
          cout<<"List is empty";
        else
          {
             customer *t1,*t2;
             t1=start;
             t2=start;
             while(t1!=NULL)
               {
                 if(n==t1->car_no)
                  {
                     t2->next=t1->next;
                     t1->next=NULL;
                     delete t1;
                      break;
                  }
               else
                {
                  t2=t1;
                  t1=t1->next;
                }
             }
         }
      }
}
void CalculateAverageAge()
{
    int count=0,sum=0,avgage;
    for(customer *i=start;i!=NULL;i=i->next)
        {
            sum=sum+i->age;
            count++;
        }
    avgage=sum/count;
    cout<<endl<<"the average age is "<<avgage<<endl;

}
void CalculateAveragePrice()
{
    int avgprice;
    int count=0,sum=0;
    for(customer *i=start;i!=NULL;i=i->next)
    {
        sum=sum+i->price;
        count++;

    }
    avgprice=sum/count;
    cout<<endl<<"the average price of car is "<<avgprice<<endl;
}

void DisplayAllInformation()
{
   customer *n;
   for(n=start ;n!=NULL; n=n->next)
    {
        cout<<"    "<<endl;

        cout<<endl<<"Name "<<n->name<<endl;
        cout<<endl<<"Age "<<n->age<<endl;
        cout<<endl<<"Sex "<<n->sex<<endl;
        cout<<endl<<"Price "<<n->price<<endl;
        cout<<endl<<"car model "<<n->car_model<<endl;
        cout<<endl<<"ID NO "<<n->ID_NO<<endl;
        cout<<endl<<"No of days "<<n->noofdays<<endl;
        cout<<endl<<"car number "<<n->car_no<<endl;
       cout<<"    " <<endl;

  }
}
void DeleteAtAPosition()
{


    int n;
    int i=1;
    customer *node;
    customer *temp=start;
    cout<<"Enter the position you wanted to delete";
    cin>>n;
    while(i<n-1)
     {
        temp=temp->next;
        i++;
     }
    node=temp->next;
    temp->next=node->next;
    node->next=NULL;
    delete node;
}
void SearchByAttribute()
{
    int m;
    int n;
    char key[20];
    cout<<"Press 1: To search using name"<<endl;
    cout<<"press 2: To search using age"<<endl;
    cout<<"Press 3:To search using car model"<<endl;
    cout<<"press 4: To search using number of days"<<endl;
    cout<<"Press 5:To search using sex"<<endl;
    cout<<"Press 6: To search using price"<<endl;
    cout<<"Press 7: To search using car number"<<endl;
    cout<<"Press 8: To search using ID number"<<endl;
    cin>>m;
    if(m==1)
      {
        cout<<"Enter the name you wanted to find"<<endl;
        cin>>key;
        for(customer *i=start;i!=NULL;i=i->next)
          {
            if(strcmp(key,i->name)==0)
              {
                cout<<"Found"<<endl;
                break;
              }
           else
            {
              cout<<"not found"<<endl;
              break;
             }
         }
     }
   else if(m==2)
     {
       int n;
       cout<<"Enter the age you wanted to find"<<endl;
       cin>>n;
       for(customer *i=start;i!=NULL;i=i->next)
        {
           if(n==i->age)
             {
               cout<<"Found";
               break;
             }
           else
             {
               cout<<"Not found!!"<<endl;
               break;
            }
       }
    }
   else if(m==3)
    {
      cout<<"Enter the car model you wanted to find"<<endl;
      cin>>key;
        for(customer *i=start;i!=NULL;i=i->next)
          {
             if(strcmp(key,i->car_model)==0)
               {
                 cout<<"Found";
                 break;
               }
             else
              {
                 cout<<"Not found!!"<<endl;
                 break;
              }
          }
     }
    else if(m==4)
      {
        cout<<"Enter the number of days you wanted to find"<<endl;
        cin>>n;
        for(customer *i=start;i!=NULL;i=i->next)
          {
            if(n==i->noofdays)
              {
                cout<<"Found";
                break;
              }
           else
             {
               cout<<"Not found!!"<<endl;
               break;
             }
         }
    }
   else if(m==5)
     {

        cout<<"Enter the sex you wanted to find"<<endl;
        cin>>key;
        for(customer *i=start;i!=NULL;i=i->next)
          {
             if(strcmp(key,i->sex)==0)
               {
                 cout<<"Found";
                  break;
               }
             else
               {
                  cout<<"Not found!!"<<endl;
                  break;
               }
         }
    }
  else if(m==6)
   {
     cout<<"Enter the price you wanted to find"<<endl;
     cin>>n;
     for(customer *i=start;i!=NULL;i=i->next)
       {
         if(n==i->price)
           {
             cout<<"Found";
             break;
           }
         else
           {
             cout<<"Not found!!"<<endl;
             break;
           }
       }
   }
   else if(m==6)
    {
       cout<<"Enter the ID number you wanted to find"<<endl;
       cin>>n;
       for(customer *i=start;i!=NULL;i=i->next)
         {
           if(n==i->ID_NO)
             {
                 cout<<"Found";
                break;
             }
          else
            {
               cout<<"Not found!!"<<endl;
                break;
            }
         }
     }
}


void CountNoOfCustomers()
{
    int count=0;
    for(customer *i=start;i!=NULL;i=i->next)
    {
     count++;
    }
    cout<<"The number of customers is "<<count<<endl;
}

void Update()
{
    int m;
   cout<<"Press 1: To update name"<<endl;
   cout<<"press 2: To update car model"<<endl;
   cout<<"Press 3:To update number of days"<<endl;
   cout<<"Press 4:To update sex"<<endl;
   cout<<"Press 5: To update price"<<endl;
   cout<<"Press 6: To update car number"<<endl;
   cout<<"Press 7: To update ID number"<<endl;
   cout<<"Press 8: To update age"<<endl;
   cin>>m;
   char key[20];
   char update[20];
   int n;
   int up;
   int found=0;
   if(m==1)
     {
        cout<<"Enter the name of the customer you wanted to update"<<endl;
        cin>>key;
        for(customer *i=start;i!=NULL;i=i->next)
 {
 if(strcmp(key,i->name)==0){
 cout<<"Enter the updated name"<<endl;
 cin>>update;
 found=1;
 strcpy(i->name,update);

 break;
 }
 else
 found=0;
 }
 if(found==0)
 cout<<"The "<<key<<" is not found"<<endl;
 else
 cout<<"The name "<<key<<"is update to "<<update<<endl;
 }
 else if(m==8)
 {
  cout<<"Enter the age of the customer you wanted to update"<<endl;
 cin>>n;
 for(customer *i=start;i!=NULL;i=i->next)
 {
     if(i->age==n){
     cout<<"Enter the updated age"<<endl;
 cin>>up;
 found=1;
 i->age=up;
 break;
     }
     else
 found=0;
 }
 if(found==0)
 cout<<"The "<<n<<" is not found"<<endl;
 else
 cout<<"The age "<<n<<"is update to "<<up<<endl;
 }


else if(m==3)
 {
  cout<<"Enter the number of days you wanted to update"<<endl;
 cin>>n;
 for(customer *i=start;i!=NULL;i=i->next)
 {
     if(i->noofdays==n){
     cout<<"Enter the updated number of day"<<endl;
 cin>>up;
 found=1;
 i->noofdays=up;
 break;
     }
     else
 found=0;
 }
 if(found==0)
 cout<<"The "<<n<<" is not found"<<endl;
 else
 cout<<"The number of days "<<n<<"is update to "<<up<<endl;


 }
 else if(m==4)
 {
     char update[6];
 cout<<"Enter the sex of the customer you wanted to update"<<endl;
 cin>>key;
 for(customer *i=start;i!=NULL;i=i->next)
 {
 if(strcmp(key,i->sex)==0){
 cout<<"Enter the updated sex"<<endl;
 cin>>update;
 found=1;
 strcpy(i->sex,update);
 break;
 }
 else
 found=0;
 }
 if(found==0)
 cout<<"The "<<key<<" is not found"<<endl;
 else
 cout<<"The sex "<<key<<"is update to "<<update<<endl;
 }
else if(m==5)
 {
  cout<<"Enter the price you wanted to update"<<endl;
 cin>>n;
 for(customer *i=start;i!=NULL;i=i->next)
 {
     if(i->noofdays==n){
     cout<<"Enter the updated price"<<endl;
 cin>>up;
 found=1;
 i->price=up;
 break;
     }
     else
 found=0;
 }
 if(found==0)
 cout<<"The "<<n<<" is not found"<<endl;
 else
 cout<<"The price "<<n<<"is update to "<<up<<endl;
}
else if(m==6)
 {
  cout<<"Enter the car number you wanted to update"<<endl;
 cin>>n;
 for(customer *i=start;i!=NULL;i=i->next)
 {
     if(i->car_no==n){
     cout<<"Enter the updated car number"<<endl;
 cin>>up;
 found=1;
 i->car_no=up;
 break;
     }
     else
 found=0;
 }
 if(found==0)
 cout<<"The "<<n<<" is not found"<<endl;
 else
 cout<<"The car number "<<n<<"is update to "<<up<<endl;
}
else if(m==2)
 {
 cout<<"Enter the car model you wanted to update"<<endl;
 cin>>key;
 for(customer *i=start;i!=NULL;i=i->next)
 {
     char update[10];
 if(strcmp(key,i->car_model)==0){
 cout<<"Enter the updated car model"<<endl;
 cin>>update;
 found=1;
 strcpy(i->car_model,update);
 break;
 }
 else
 found=0;
 }
 if(found==0)
 cout<<"The "<<key<<" is not found"<<endl;
 else
 cout<<"The car model "<<key<<"is update to "<<update<<endl;
 }
else if(m==7)
 {
  cout<<"Enter the ID NO of the customer you wanted to update"<<endl;
 cin>>n;
 for(customer *i=start;i!=NULL;i=i->next)
 {
     if(i->ID_NO==n){
     cout<<"Enter the updated ID NO"<<endl;
 cin>>up;
 found=1;
 i->ID_NO=up;
 break;
     }
     else
 found=0;
 }
 if(found==0)
 cout<<"The "<<n<<" is not found"<<endl;
 else
 cout<<"The ID_NO "<<n<<"is update to "<<up<<endl;
 }
}
void SearchByMaxPrice()
{
    customer *temp;
    temp=start;
    int i=1;
    int max=temp->price;

    while(temp!=NULL)
    {
         if(max<temp->price)
            {
              max=temp->price;
            }
       temp=temp->next;
    }
    cout<<"The Maximum Price Of Car is "<<max<<endl;
}
void SearchByMinPrice()
{
    customer *temp;
     temp=start;
    int i=1;
    int min=temp->price;

    while(temp!=NULL)
    {
         if(min>temp->price)
            {
              min=temp->price;
         }
     temp=temp->next;
    }
    cout<<"The Minimum price of car "<<min<<endl;
}
void DeleteByMinAge()
{
        customer *temp1,*temp2,*min;
        temp1=start->next;
        temp2=start;
        min=start;

    while(temp1!=NULL)
    {
         if(min->age>temp1->age)
            {
              min=temp1;
         }
        temp1=temp1->next;
         }
   while(temp2->next!=min)
    {
    temp2=temp2->next;
    }
    temp2->next=min->next;
    min->next=NULL;
    delete min;
}
void DeleteByMaxAge()
{
   customer *temp1,*temp2,*max;
        temp1=start->next;
        temp2=start;
        max=start;

    while(temp1!=NULL)
    {
         if(max->age<temp1->age)
            {
              max=temp1;
         }
     temp1=temp1->next;
         }
   while(temp2->next!=max)
    {
    temp2=temp2->next;
    }
    temp2->next=max->next;
    max->next=NULL;
    delete max;
}

void Sort()
{
    int m;

    cout<<"press 1:to sort using name"<<endl;
    cout<<"press 2:to sort  using age"<<endl;
    cout<<"press 3:to sort using car model"<<endl;
    cout<<"press 4:to sort using  number of days"<<endl;
    cout<<"press 5:to sort using sex"<<endl;
    cout<<"press 6:to sort using price"<<endl;
    cout<<"press 7:to sort using car_no"<<endl;
    cout<<"press 8:to sort using ID_NO"<<endl;
   cin>>m;
   switch(m)
   {
   case 1:
   sortbyname();
   break;
   case 2:
    sortbyage();
    break;
   case 3:
    sortbycarmodel();
    break;
   case 4:
    sortbynoofdays();
    break;
   case 5:
     sortbysex();
     break;
   case 6:
     sortbyprice();
     break;
   case 7:
    sortbycarno();
    break;
   case 8:
    sortbyIDNO();
    break;
   }
}
void sortbyname()
{
    if(start==NULL)
        cout<<"No customer is registered,can't be sorted"<<endl;
    else
    {
        for(customer *temp1=start;temp1->next!=NULL;temp1=temp1->next)
        {
            for(customer *temp2=temp1->next;temp2!=NULL;temp2=temp2->next)
            {
                if(strcmp(temp1->name,temp2->name)>0)
                {
                 sortswap(temp1,temp2);
                }
            }
        }

    }

}
void sortbyage()
{
    if(start==NULL)
        cout<<"No customer is registered,can't be sorted"<<endl;
    else
    {
         for(customer *temp1=start;temp1->next!=NULL;temp1=temp1->next)
        {
            for(customer *temp2=temp1->next;temp2!=NULL;temp2=temp2->next)
            {
                if(temp1->age>temp2->age)
                {
                 sortswap(temp1,temp2);
                }
          }
       }
    }

}
void sortbycarno()
{
    if(start==NULL)
        cout<<"No customer is registered,can't be sorted"<<endl;
    else
    {
        for(customer *temp1=start;temp1->next!=NULL;temp1=temp1->next)
        {
            for(customer *temp2=temp1->next;temp2!=NULL;temp2=temp2->next)
            {
                if(temp1->car_no>temp2->car_no)
                {
                    sortswap(temp1,temp2);
                }
            }
        }
     }
}

void sortbysex()
{
    if(start==NULL)
        cout<<"No customer is registered,can't be sorted"<<endl;
    else
    {
        for(customer *temp1=start;temp1->next!=NULL;temp1=temp1->next)
        {
            for(customer *temp2=temp1->next;temp2!=NULL;temp2=temp2->next)
            {
                if(strcmp(temp1->sex,temp2->sex)>0)
                {
                                    sortswap(temp1,temp2);
                }
            }
        }
    }
}
void sortbycarmodel()
{
    if(start==NULL)
        cout<<"No customer is registered,can't be sorted"<<endl;
    else
    {
        for(customer *temp1=start;temp1->next!=NULL;temp1=temp1->next)
        {
            for(customer *temp2=temp1->next;temp2!=NULL;temp2=temp2->next)
            {
                if(strcmp(temp1->car_model,temp2->car_model)>0)
                {
                    sortswap(temp1,temp2);
                }
            }
       }
   }
}
void sortbyIDNO()
{
    if(start==NULL)
        cout<<"No customer is registered,can't be sorted"<<endl;
    else
    {
        for(customer *temp1=start;temp1->next!=NULL;temp1=temp1->next)
        {
            for(customer *temp2=temp1->next;temp2!=NULL;temp2=temp2->next)
            {
                if(temp1->ID_NO>temp2->ID_NO)
                {
                    sortswap(temp1,temp2);
                }
            }
        }
    }
}
void sortbyprice()
{
    if(start==NULL)
        cout<<"No customer is registered,can't be sorted"<<endl;
    else
    {
        for(customer *temp1=start;temp1->next!=NULL;temp1=temp1->next)
        {
            for(customer *temp2=temp1->next;temp2!=NULL;temp2=temp2->next)
            {
                if(temp1->price>temp2->price)
                {
                    sortswap(temp1,temp2);
                }
            }
        }
    }
}

void sortbynoofdays()
{
    if(start==NULL)
        cout<<"No customer is registered,can't be sorted"<<endl;
    else
    {
        for(customer *temp1=start;temp1->next!=NULL;temp1=temp1->next)
        {
            for(customer *temp2=temp1->next;temp2!=NULL;temp2=temp2->next)
            {
                if(temp1->noofdays>temp2->noofdays)
                {
                    sortswap(temp1,temp2);
                }
            }
        }
    }
}

void sortswap(customer *temp1,customer *temp2)
{
    customer *temp3=new customer;

    strcpy(temp3->name,temp1->name);
    temp3->age=temp1->age;
    temp3->car_no=temp1->car_no;
    strcpy(temp3->sex,temp1->sex);
    temp3->ID_NO=temp1->ID_NO;
    temp3->price=temp1->price;
    temp3->noofdays=temp1->noofdays;
    strcpy(temp3->car_model,temp1->car_model);


    strcpy(temp1->name,temp2->name);
    temp1->age=temp2->age;
    temp1->car_no=temp2->car_no;
    strcpy(temp1->sex,temp2->sex);
    temp1->ID_NO=temp2->ID_NO;
    temp1->price=temp2->price;
    temp1->noofdays=temp2->noofdays;
    strcpy(temp1->car_model,temp2->car_model);



    strcpy(temp2->name,temp3->name);
    temp2->age=temp3->age;
    temp2->car_no=temp3->car_no;
    strcpy(temp2->sex,temp3->sex);
    temp2->ID_NO=temp3->ID_NO;
    temp2->price=temp3->price;
    temp2->noofdays=temp3->noofdays;
    strcpy(temp2->car_model,temp3->car_model);
}
void CountOccurrence()
{
   int m;
   cout<<"Press 1: To count number of occurence by name"<<endl;
   cout<<"press 2: To count number of occurence by car model"<<endl;
   cout<<"Press 3:To count number of occurence by number of days"<<endl;
   cout<<"Press 4:To count number of occurence by sex"<<endl;
   cout<<"Press 5: To count number of occurence by price"<<endl;
   cout<<"Press 6: To count number of occurence by age"<<endl;
   cin>>m;
   if(m==1)
    {
      int count=0;
      char key[20];
      cout<<"Enter the name to count the occurence."<<endl;
      cin>>key;
      customer *temp;
      temp=start;
      while(temp!=NULL)
       {
         if(strcmp(key,temp->name)==0)
          {

             count++;
          }
        temp=temp->next;
      }
     if(count==0)
        cout<<"There is no customer by this name"<<endl;
     else if( count==1)
        cout<<"There is only one customer by this name"<<endl;
     else
      cout<<"There are "<<count<<" customers by this name"<<endl;
   }
   else if (m==2)
    {
       int count=0;
       char key[19];
       cout<<"Enter the car model to count the occurance"<<endl;
       cin>>key;
       customer *temp;
       temp=start;
       while(temp!=NULL)
        {
           if(strcmp(key,temp->car_model)==0)
             {

                count++;
             }
           temp=temp->next;
        }
       if(count==0)
        {
           cout<<"There is no car with "<<key<<" car model"<<endl;
         }
       else if ( count==1)
         {
           cout<<"There is only one car with "<<key<<" car model"<<endl;
          }
       else
         cout<<"There are "<<count<<" cars with "<<key<<" car model"<<endl;
     }
   else if(m==3)
    {
       int count=0;
       int key;
        cout<<"Enter the no day to count the occurance"<<endl;
       cin>>key;
       customer *temp;
       temp=start;
       while(temp!=NULL)
        {
          if(temp->noofdays==key)
             {

                count++;
              }
          temp=temp->next;
       }
       if(count==0)
        cout<<"There are no customers who rent a car for "<<key<<" number of day"<<endl;
       else if( count==1)
        cout<<"There is only one customer that rent a car for "<<key<<" number of days"<<endl;
       else
         cout<<"There are "<<count <<" customers that rent a car for "<<key<<" number of days"<<endl;
      }
     else if(m==4)
        {
           int count=0;
           char key[6];
           cout<<"Enter the sex to count the occurance"<<endl;
           cin>>key;
           customer *temp;
           temp=start;
           while(temp!=NULL)
            {
              if(strcmp(key,temp->sex)==0)
                 {

                   count++;
                 }
              temp=temp->next;
           }
         if(count==0)
           cout<<"the sex "<<key<<"you enter is not found in this  system"<<endl;
         else if( count==1)
           cout<<"the sex"<<key<<"you enter is  found only one time in this  system"<<endl;
          else
            cout<<"the sex"<<key<<"you enter is  found "<<count<<" times in this  system"<<endl;
        }
     else if(m==5)
        {
          int count=0;
          int key;
          cout<<"Enter the price to count the occurance"<<endl;
          cin>>key;
          customer *temp;
          temp=start;
          while(temp!=NULL)
            {
              if(temp->price==key)
                 {

                   count++;
                }
             temp=temp->next;
            }
         if(count==0)
            cout<<"No car have "<<key<<" price"<<endl;
         else if( count==1)
           cout<<"Only one car have "<<key<<" price"<<endl;
         else
            cout<<count<<" Cars have "<<key<<" price "<<endl;
        }
     else if(m==6)
        {
          int count=0;
          int key;
          cout<<"Enter the age to count the occurance"<<endl;
          cin>>key;
          customer *temp;
          temp=start;
          while(temp!=NULL)
            {
              if(temp->age==key)
                {

                   count++;
                }
             temp=temp->next;
            }
        if(count==0)
          cout<<"No customer have "<<key<<" age"<<endl;
        else if( count==1)
         cout<<"Only one customer has "<<key<<" age"<<endl;
         else
           cout<<count<<" Customers have "<<key<<" age"<<endl;
       }
}

void topage()
{
    int m;
   cout<<"Press 1:To display top ten employees"<<endl;
   cout<<"Press 2:To display top fifteen employees"<<endl;
   cout<<"Press 3:To display top twenty employees"<<endl;
   cin>>m;
   if(m==1)
    {
    toptenage();
    }
   else if(m==2)
     {
       topfifteenage();
     }
    else if(m==3);
      {
       toptwentyage();
      }
}

void topprice()
{
    int m;
   cout<<"Press 1:To display top ten employees"<<endl;
   cout<<"Press 2:To display top fifteen employees"<<endl;
   cout<<"Press 3:To display top twenty employees"<<endl;
   cin>>m;
   if(m==1)
    {
    toptenprice();
    }
   else if(m==2)
     {
       topfifteenprice();
     }
    else if(m==3);
      {
       toptwentyprice();
      }
}

void topcarno()
{
    int m;
   cout<<"Press 1:To display top ten employees"<<endl;
   cout<<"Press 2:To display top fifteen employees"<<endl;
   cout<<"Press 3:To display top twenty employees"<<endl;
   cin>>m;
   if(m==1)
    {
    toptencarno();
    }
   else if(m==2)
     {
       topfifteencarno();
     }
    else if(m==3);
      {
       toptwentycarno();
      }
}

void topcarmodel()
{
    int m;
   cout<<"Press 1:To display top ten employees"<<endl;
   cout<<"Press 2:To display top fifteen employees"<<endl;
   cout<<"Press 3:To display top twenty employees"<<endl;
   cin>>m;
   if(m==1)
    {
    toptencarmodel();
    }
   else if(m==2)
     {
       topfifteencarmodel();
     }
    else if(m==3);
      {
       toptwentycarmodel();
      }
}
void topnoofday()
{
    int m;
   cout<<"Press 1:To display top ten employees"<<endl;
   cout<<"Press 2:To display top fifteen employees"<<endl;
   cout<<"Press 3:To display top twenty employees"<<endl;
   cin>>m;
   if(m==1)
    {
    toptennoofday();
    }
   else if(m==2)
     {
       topfifteennoofday();
     }
    else if(m==3);
      {
       toptwentynoofday();
      }
}

void topIDNO()
{
    int m;
   cout<<"Press 1:To display top ten employees"<<endl;
   cout<<"Press 2:To display top fifteen employees"<<endl;
   cout<<"Press 3:To display top twenty employees"<<endl;
   cin>>m;
   if(m==1)
    {
    toptenIDNO();
    }
   else if(m==2)
     {
       topfifteenIDNO();
     }
    else if(m==3);
      {
       toptwentyIDNO();
      }
}
void topsex()
{
    int m;
   cout<<"Press 1:To display top ten customer"<<endl;
   cout<<"Press 2:To display top fifteen customer"<<endl;
   cout<<"Press 3:To display top twenty customer"<<endl;
   cin>>m;
   if(m==1)
    {
    toptensex();
    }
   else if(m==2)
     {
       topfifteensex();
     }
    else if(m==3);
      {
       toptwentysex();
      }
}
void toptenname()
{
   if(start==NULL)
        cout<<"No customer is registered";
   else
   {
       sortbyname();
           int count=0;
       customer *i=start;
       while(i!=NULL&&count<10)
       {
           cout<<endl;
           cout<<i->name<<endl;
            cout<<i->age<<endl;
            cout<<i->car_no<<endl;
            cout<<i->sex<<endl;
            cout<<i->ID_NO<<endl;
            cout<<i->price<<endl;
            cout<<i->noofdays<<endl;
            cout<<i->car_model<<endl;
            cout<<endl;
           i=i->next;
           count++;
       }
       if(count<10)
       {
           cout<<"  there are only "<<count<<" customers";
       }
   }
}
   void topfifteenname()
{

    if(start==NULL)
    {
         cout<<"No customer is registered"<<endl;

    }

       sortbyname();
          int count=0;
       customer *i=start;
       while(i!=NULL&&count<15)
       {
           cout<<endl;
           cout<<i->name<<endl;
            cout<<i->age<<endl;
            cout<<i->car_no<<endl;
            cout<<i->sex<<endl;
            cout<<i->ID_NO<<endl;
            cout<<i->price<<endl;
            cout<<i->noofdays<<endl;
            cout<<i->car_model<<endl;
           cout<<endl;
           i=i->next;
           count++;


       }
       if(count<15)
       {
         cout<<"there are only "<<count<<"customers";
       }
   }


   void toptwentyname()
{

    if(start==NULL)
        cout<<"No customer is registered";
   else
   {

       sortbyname();
          int count=0;
       customer *i=start;
       while(i!=NULL&&count<20)
       {
           cout<<endl;
           cout<<i->name<<endl;
            cout<<i->age<<endl;
            cout<<i->car_no<<endl;
            cout<<i->sex<<endl;
            cout<<i->ID_NO<<endl;
            cout<<i->price<<endl;
            cout<<i->noofdays<<endl;
            cout<<i->car_model<<endl;
           cout<<endl;
           i=i->next;
           count++;


       }
       if(count<20)
       {
         cout<<"there are only "<<count<<"customers";
       }
   }
}
void toptenprice()
{

    if(start==NULL)
        cout<<"No customer is registered";
   else
   {
       sortbyprice();
       int count=0;
       customer *i=start;
       while(i!=NULL&&count<10)
       {
            cout<<endl;
           cout<<i->name<<endl;
            cout<<i->age<<endl;
            cout<<i->car_no<<endl;
            cout<<i->sex<<endl;
            cout<<i->ID_NO<<endl;
            cout<<i->price<<endl;
            cout<<i->noofdays<<endl;
            cout<<i->car_model<<endl;
           cout<<endl;
           i=i->next;
           count++;

       }
       if(count<10)
       {
          cout<<"there are only "<<count<<"customers";
       }
   }
}
   void topfifteenprice()
{

    if(start==NULL)
        cout<<"No customer is registered";
   else
   {
       sortbyprice();
       int count=0;
       customer *i=start;
       while(i!=NULL&&count<15)
       {
            cout<<endl;
           cout<<i->name<<endl;
            cout<<i->age<<endl;
            cout<<i->car_no<<endl;
            cout<<i->sex<<endl;
            cout<<i->ID_NO<<endl;
            cout<<i->price<<endl;
            cout<<i->noofdays<<endl;
            cout<<i->car_model<<endl;
           cout<<endl;
           i=i->next;
           count++;

       }
       if(count<15)
       {
          cout<<"there are only "<<count<<"customers";
       }
   }
}
   void toptwentyprice()
{
    if(start==NULL)
        cout<<"No customer is registered";
   else
   {
       sortbyprice();

    int count=0;
       customer *i=start;
       while(i!=NULL&&count<20)
       {
            cout<<endl;
           cout<<i->name<<endl;
            cout<<i->age<<endl;
            cout<<i->car_no<<endl;
            cout<<i->sex<<endl;
            cout<<i->ID_NO<<endl;
            cout<<i->price<<endl;
            cout<<i->noofdays<<endl;
            cout<<i->car_model<<endl;
           cout<<endl;
           i=i->next;
           count++;

       }
       if(count<20)
       {
           cout<<"there are only "<<count<<"customers";
       }
   }
}
void toptenage()
{

    if(start==NULL)
        cout<<"No customer is registered";
   else
   {
       sortbyage();
       int count=0;
       customer*i=start;
       while(i!=NULL&&count<10)
       {
            cout<<endl;
           cout<<i->name<<endl;
            cout<<i->age<<endl;
            cout<<i->car_no<<endl;
            cout<<i->sex<<endl;
            cout<<i->ID_NO<<endl;
            cout<<i->price<<endl;
            cout<<i->noofdays<<endl;
            cout<<i->car_model<<endl;
           cout<<endl;
           i=i->next;
           count++;

       }
       if(count<10)
       {
          cout<<"there are only "<<count<<"customers";
       }
   }
}
void topfifteenage()
{

    if(start==NULL)
        cout<<"No customer is registered";
   else
   {
       sortbyage();
       int count=0;
       customer*i=start;
       while(i!=NULL&&count<15)
       {
            cout<<endl;
           cout<<i->name<<endl;
            cout<<i->age<<endl;
            cout<<i->car_no<<endl;
            cout<<i->sex<<endl;
            cout<<i->ID_NO<<endl;
            cout<<i->price<<endl;
            cout<<i->noofdays<<endl;
            cout<<i->car_model<<endl;
           cout<<endl;
           i=i->next;
           count++;

       }
       if(count<15)
       {
           cout<<"there are only "<<count<<"customers";
       }
   }
}
void toptwentyage()
{

    if(start==NULL)
        cout<<"No customer is registered";
   else
   {
       sortbyage();
       int count=0;
       customer*i=start;
       while(i!=NULL&&count<20)
       {
           cout<<endl;
           cout<<i->name<<endl;
            cout<<i->age<<endl;
            cout<<i->car_no<<endl;
            cout<<i->sex<<endl;
            cout<<i->ID_NO<<endl;
            cout<<i->price<<endl;
            cout<<i->noofdays<<endl;
            cout<<i->car_model<<endl;
           cout<<endl;
           i=i->next;
           count++;

       }
       if(count<20)
       {
           cout<<"there are only "<<count<<"customers";
       }
   }
}
void topfifteencarno()
{

    if(start==NULL)
        cout<<"No customer is registered";
   else
   {
       sortbycarno();
       int count=0;
       customer*i=start;
       while(i!=NULL&&count<15)
       {
           cout<<endl;
           cout<<i->name<<endl;
            cout<<i->age<<endl;
            cout<<i->car_no<<endl;
            cout<<i->sex<<endl;
            cout<<i->ID_NO<<endl;
            cout<<i->price<<endl;
            cout<<i->noofdays<<endl;
            cout<<i->car_model<<endl;
           cout<<endl;
           i=i->next;
           count++;

       }
       if(count<15)
       {
          cout<<"there are only "<<count<<"customers";
       }
   }
}
void toptwentycarno()
{

    if(start==NULL)
        cout<<"No customer is registered";
   else
   {
       sortbycarno();
         int count=0;
       customer*i=start;
       while(i!=NULL&&count<20)
       {
            cout<<endl;
           cout<<i->name<<endl;
            cout<<i->age<<endl;
            cout<<i->car_no<<endl;
            cout<<i->sex<<endl;
            cout<<i->ID_NO<<endl;
            cout<<i->price<<endl;
            cout<<i->noofdays<<endl;
            cout<<i->car_model<<endl;
           cout<<endl;
           i=i->next;
           count++;

       }
       if(count<20)
       {
        cout<<"there are only "<<count<<"customers";
       }
   }
}
void toptencarno()
{

    if(start==NULL)
        cout<<"No customer is registered";
   else
   {
       sortbycarno();
        int count=0;
       customer*i=start;
       while(i!=NULL&&count<10)
       {
           cout<<endl;
           cout<<i->name<<endl;
            cout<<i->age<<endl;
            cout<<i->car_no<<endl;
            cout<<i->sex<<endl;
            cout<<i->ID_NO<<endl;
            cout<<i->price<<endl;
            cout<<i->noofdays<<endl;
            cout<<i->car_model<<endl;
           cout<<endl;
           i=i->next;
           count++;

       }
       if(count<=10)
       {
          cout<<"there are only "<<count<<"customers";
       }
   }


}



void toptensex()
{

    if(start==NULL)
        cout<<"No customer is registered";
   else
   {
       sortbysex();
          int count=0;
       customer*i=start;
       while(i!=NULL&&count<10)
       {
           cout<<endl;
           cout<<i->name<<endl;
            cout<<i->age<<endl;
            cout<<i->car_no<<endl;
            cout<<i->sex<<endl;
            cout<<i->ID_NO<<endl;
            cout<<i->price<<endl;
            cout<<i->noofdays<<endl;
            cout<<i->car_model<<endl;
           cout<<endl;
           i=i->next;
           count++;

       }
       if(count<10)
       {
            cout<<"there are only "<<count<<"customers";
       }
   }


}




void topfifteensex()
{

    if(start==NULL)
        cout<<"No customer is registered";
   else
   {
       sortbysex();
       int count=0;
       customer*i=start;
       while(i!=NULL&&count<15)
       {
           cout<<endl;
           cout<<i->name<<endl;
            cout<<i->age<<endl;
            cout<<i->car_no<<endl;
            cout<<i->sex<<endl;
            cout<<i->ID_NO<<endl;
            cout<<i->price<<endl;
            cout<<i->noofdays<<endl;
            cout<<i->car_model<<endl;
           cout<<endl;
           i=i->next;
           count++;

       }
       if(count<15)
       {
            cout<<"there are only "<<count<<" customers";
       }
   }


}




void toptwentysex()
{

    if(start==NULL)
        cout<<"No customer is registered";
   else
   {
       sortbysex();
        int count=0;
       customer*i=start;
       while(i!=NULL&&count<20)
       {
            cout<<endl;
           cout<<i->name<<endl;
            cout<<i->age<<endl;
            cout<<i->car_no<<endl;
            cout<<i->sex<<endl;
            cout<<i->ID_NO<<endl;
            cout<<i->price<<endl;
            cout<<i->noofdays<<endl;
            cout<<i->car_model<<endl;
           cout<<endl;
           i=i->next;
           count++;

       }
       if(count<20)
       {
          cout<<"there are only "<<count<<"customers";
       }
   }


}



void toptwentyIDNO()
{

    if(start==NULL)
        cout<<"No customer is registered";
   else
   {
       sortbyIDNO();
       int count=0;
       customer*i=start;
       while(i!=NULL&&count<20)
       {
           cout<<endl;
           cout<<i->name<<endl;
            cout<<i->age<<endl;
            cout<<i->car_no<<endl;
            cout<<i->sex<<endl;
            cout<<i->ID_NO<<endl;
            cout<<i->price<<endl;
            cout<<i->noofdays<<endl;
            cout<<i->car_model<<endl;
           cout<<endl;
           i=i->next;
           count++;

       }
       if(count<20)
       {
          cout<<"there are only "<<count<<"customers";
       }
   }


}



void toptenIDNO()
{

    if(start==NULL)
        cout<<"No customer is registerd";
   else
   {
       sortbyIDNO();
       int count=0;
       customer*i=start;
       while(i!=NULL&&count<10)
       {
           cout<<endl;
           cout<<i->name<<endl;
            cout<<i->age<<endl;
            cout<<i->car_no<<endl;
            cout<<i->sex<<endl;
            cout<<i->ID_NO<<endl;
            cout<<i->price<<endl;
            cout<<i->noofdays<<endl;
            cout<<i->car_model<<endl;
           cout<<endl;
           i=i->next;
           count++;

       }
       if(count<10)
       {
         cout<<"there are only "<<count<<"customers";
       }
   }


}



void topfifteenIDNO()
{

    if(start==NULL)
        cout<<"No customer is registered";
   else
   {
       sortbyIDNO();
        int count=0;
       customer*i=start;
       while(i!=NULL&&count<15)
       {
           cout<<endl;
           cout<<i->name<<endl;
            cout<<i->age<<endl;
            cout<<i->car_no<<endl;
            cout<<i->sex<<endl;
            cout<<i->ID_NO<<endl;
            cout<<i->price<<endl;
            cout<<i->noofdays<<endl;
            cout<<i->car_model<<endl;
           cout<<endl;
           i=i->next;
           count++;

       }
       if(count<15)
       {
         cout<<"there are only "<<count<<"customers";
       }
   }


}



void toptennoofday()
{

    if(start==NULL)
        cout<<"NO customer is registered";
   else
   {
       sortbynoofdays();
         int count=0;
       customer*i=start;
       while(i!=NULL&&count<10)
       {
           cout<<endl;
           cout<<i->name<<endl;
            cout<<i->age<<endl;
            cout<<i->car_no<<endl;
            cout<<i->sex<<endl;
            cout<<i->ID_NO<<endl;
            cout<<i->price<<endl;
            cout<<i->noofdays<<endl;
            cout<<i->car_model<<endl;
           cout<<endl;
           i=i->next;
           count++;

       }
       if(count<10)
       {
           cout<<"there are only "<<count<<"customers";
       }
   }


}



void topfifteennoofday()
{

    if(start==NULL)
        cout<<"NO customer is registered";
   else
   {
       sortbynoofdays();
        int count=0;
       customer*i=start;
       while(i!=NULL&&count<15)
       {
           cout<<endl;
           cout<<i->name<<endl;
            cout<<i->age<<endl;
            cout<<i->car_no<<endl;
            cout<<i->sex<<endl;
            cout<<i->ID_NO<<endl;
            cout<<i->price<<endl;
            cout<<i->noofdays<<endl;
            cout<<i->car_model<<endl;
           cout<<endl;
           i=i->next;
           count++;

       }
       if(count<15)
       {
         cout<<"there are only "<<count<<"customers";
       }
   }


}




void toptwentynoofday()
{

    if(start==NULL)
        cout<<"NO customer is registered";
   else
   {
       sortbynoofdays();
        int count=0;
       customer*i=start;
       while(i!=NULL&&count<20)
       {
            cout<<endl;
           cout<<i->name<<endl;
            cout<<i->age<<endl;
            cout<<i->car_no<<endl;
            cout<<i->sex<<endl;
            cout<<i->ID_NO<<endl;
            cout<<i->price<<endl;
            cout<<i->noofdays<<endl;
            cout<<i->car_model<<endl;
           cout<<endl;
           i=i->next;
           count++;

       }
       if(count<20)
       {
         cout<<"there are only "<<count<<"customers";
       }
   }


}




void toptencarmodel()
{

    if(start==NULL)
        cout<<"No customer is registered";
   else
   {
       sortbycarmodel();
       int count=0;
       customer*i=start;
       while(i!=NULL&&count<10)
       {
           cout<<endl;
           cout<<i->name<<endl;
            cout<<i->age<<endl;
            cout<<i->car_no<<endl;
            cout<<i->sex<<endl;
            cout<<i->ID_NO<<endl;
            cout<<i->price<<endl;
            cout<<i->noofdays<<endl;
            cout<<i->car_model<<endl;
           cout<<endl;
           i=i->next;
           count++;

       }

   }


}



void topfifteencarmodel()
{

    if(start==NULL)
        cout<<"No customer is registerd";
   else
   {
       sortbycarmodel();
        int count=0;
       customer*i=start;
       while(i!=NULL&&count<15)
       {
            cout<<endl;
           cout<<i->name<<endl;
            cout<<i->age<<endl;
            cout<<i->car_no<<endl;
            cout<<i->sex<<endl;
            cout<<i->ID_NO<<endl;
            cout<<i->price<<endl;
            cout<<i->noofdays<<endl;
            cout<<i->car_model<<endl;
           cout<<endl;
           i=i->next;
           count++;

       }
       if(count<15)
       {
           cout<<"there are only "<<count<<"customers";
       }
   }


}



void toptwentycarmodel()
{

    if(start==NULL)
        cout<<"No customer is registered";
   else
   {
       sortbycarmodel();
       int count=0;
       customer*i=start;
       while(i!=NULL&&count<20)
       {
            cout<<endl;
           cout<<i->name<<endl;
            cout<<i->age<<endl;
            cout<<i->car_no<<endl;
            cout<<i->sex<<endl;
            cout<<i->ID_NO<<endl;
            cout<<i->price<<endl;
            cout<<i->noofdays<<endl;
            cout<<i->car_model<<endl;
           cout<<endl;
           i=i->next;
           count++;

       }
       if(count<20)
       {
        cout<<"there are only "<<count<<"customers";
       }
   }


}
void topname()
{
    int m;
   cout<<"Press 1:To display top ten customer"<<endl;
   cout<<"Press 2:To display top fifteen customer"<<endl;
   cout<<"Press 3:To display top twenty customer"<<endl;
   cin>>m;
   if(m==1)
    {
    toptenname();
    }
   else if(m==2)
     {
       topfifteenage();
     }
    else if(m==3);
      {
       toptwentyname();
      }
}
void DisplayTopCustomer()
{
    int m;

    cout<<"press 1:To display top customers using name"<<endl;
    cout<<"press 2:To display top customers using age"<<endl;
    cout<<"press 3:To display top customers using car model"<<endl;
    cout<<"press 4:To display top customers by using number of days"<<endl;
    cout<<"press 5:To display top customers using sex"<<endl;
    cout<<"press 6:To display top customers using price"<<endl;
    cout<<"press 7:To display top customers using car_no"<<endl;
    cout<<"press 8:To display top customers using ID_NO"<<endl;
   cin>>m;
   switch(m)
   {
   case 1:
   topname();
   break;
   case 2:
   topage();
    break;
   case 3:
   topcarmodel();
    break;
   case 4:
     topnoofday();
    break;
   case 5:
      topsex();
     break;
   case 6:
     topprice();
     break;
   case 7:
   topcarno();
    break;
   case 8:
    topIDNO();
    break;
   }
}




