#include<iostream>
#include<fstream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

using namespace std;

int bloom[130]={0};
int Repeated_keys[25];
int RepCount=0;
int CreateBloom();
int DisplayBFilter();
int RepeatedKeys();
int n=0;


int hash1(char*);
int hash2(int);
int hash3(int);
int rehash1(int);
int rehash2(int);
int rehash3(int);
int AddIP();
int CheckIP();

int main()
{
    char ipadd[25],ch;
    int choice;
    CreateBloom();
    while(1)
{
    system("cls");
    cout<<"\t\t\t\t\tIP ADDRESS LOOK-UP USING BLOOM FILTER";
    cout<<"\n1.Add an IP address";
    cout<<" \n2.Check for an IP address ";
    cout<<"\n3.Display bloom filter ";
    cout<<"\n4.Display repeated keys ";
    cout<<"\n5.Exit";
    cout<<"\n\n Enter your choice:";
    cin>>choice;
    switch(choice)
    {
        case 1:AddIP();
               exit(0);
               break;
        case 2:CheckIP();
               break;
        case 3:DisplayBFilter();
               break;
        case 4:RepeatedKeys();
               break;
        case 5:exit(0);
               break;
     }
 ch=getchar();
 ch=getchar();
 }
     return 0;
}

int DisplayBFilter()
{
    cout<<endl;
  for(int i=0;i<33;++i)
  {
    if(i>=10)
    cout<<bloom[i]<<"  ";
    else
    cout<<bloom[i]<<" ";
  }
  cout<<endl;
  for(int i=0;i<33;++i)
     cout<<i<<" ";

  cout<<endl<<endl;

  for(int i=33;i<67;i++)
    cout<<bloom[i]<<"  ";
cout<<endl;
     for(int i=33;i<67;i++)
        cout<<i<<" ";

    cout<<endl<<endl;

  for(int i=67;i<100;i++)
    cout<<bloom[i]<<"  ";

    cout<<endl;

    for(int i=67;i<100;i++)
      cout<<i<<" ";
      cout<<endl<<endl;

    for(int i=100;i<130;i++)
    cout<<bloom[i]<<"   ";

    cout<<endl;

    for(int i=100;i<130;i++)
      cout<<i<<" ";

    return 0;
}

int RepeatedKeys()
{
    cout<<"\n Total number of keys is "<<n;
    cout<<endl;
    cout<<"\n Total number of repeated keys is "<<RepCount;
    cout<<endl;
    int j=0;
    for(int i=0;i<RepCount;++i)
        {
           cout<<" "<<Repeated_keys[i];
           j=1;
        }
        if(j==0)
        {
            cout<<"\n No repeated keys";
        }

}
int hash1(char *a)
{
    int t=strlen(a);
    int total=0;
    for(int i=0;i<t;i++)
    {
        total=total+a[i]*i;
    }
    total=(total/t)%199;
    if(total>130 && total <150)
        return hash2(total);
    else if(total>=150)
        return hash3(total);
    else
        return total;
}

int hash2(int total)
{
    total=(total+(total/2))%20;

    return total;
}

int hash3(int total)
{

    total=(total+(total/2))%40;
    return total;
}

int rehash1(int x)
{

    x=((x*3)/2)/2;
    return x;
}

int rehash2(int x)
{

    x=((x*3)/4)/2;
    return x;
}

int rehash3(int x)
{

    x=((x*3)/6)/2;
    return x;
}


int CheckIP()
{
    char ipadd[25];
    int x;
     cout<<"\n Enter the IP address to be Checked:";
     cin>>ipadd;
     x=hash1(ipadd);

         if(bloom[x]==1)
            x=rehash1(x);
         if(bloom[x]==1)
            x=rehash2(x);
         if(bloom[x]==1)
            x=rehash3(x);
            cout<<x;
            if(bloom[x]==1)
                cout<<"\n Maybe found";
            else
                cout<<"\n Surely not found";

}


int CreateBloom()
{

    char ipadd[25];
    int x;
    ifstream f1("ip.txt",ios::in);
       while(!f1.eof())
         {
             n++;
              f1>>ipadd;
              x=hash1(ipadd);

         if(bloom[x]==1)
            x=rehash1(x);
         if(bloom[x]==1)
            x=rehash2(x);
         if(bloom[x]==1)
            x=rehash3(x);
         if(bloom[x]==1)
              {Repeated_keys[RepCount++]=x;}

         bloom[x]=1;
       }
    f1.close();
}

int AddIP()
{   char ipadd[26];
    ofstream f1("ip.txt",ios::app);
    cout<<"\nEnter the IP address to be added";
    cin>>ipadd;
    f1<<'\n';
    f1<<ipadd;
    f1.close();
    cout<<"\nSuccessfully added the IP address into the list";
    return 0;
}

