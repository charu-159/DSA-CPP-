//DCswapmn.cpp
#include<iostream>
using namespace std;
struct DCLL{
    int data;
    DCLL*next,*prev;
};
DCLL *first,*temp,*ttemp,*p,*s;
void init(){
  first=temp=ttemp=p=s;
}
void create_first( int x){
    first=new DCLL;
    first->data=x;
    first->next-first;
    first->prev=first;
}
void add_node(int x){
temp=first->prev;
ttemp=new DCLL;
ttemp->data=x;
ttemp->next=first;
first->prev=ttemp;
temp->next=ttemp;
ttemp->prev=temp;

}
void swapMN(int m,int n)
{
  if(m==n) return;

  if(m>n)
   {m=m+n;
   n=m-n;
   m=m-n;}
   temp=ttemp=first;

   //find m
   for(int i=1;i<m && temp->next!=first;i++)
   {
    temp=temp->next;
   }

   for(int j=1;j<n && ttemp->next!=first;j++)
   {
    ttemp=ttemp->next;
   }
   
   //check wheather m and n are adjacent or not
   
   if(m==n-1)  //adjacent
  {
   temp->prev->next=ttemp;
   ttemp->next->prev=temp;
   temp->next=ttemp->next;
   ttemp->prev=temp->prev;
   temp->prev=ttemp;
   ttemp->next=temp;
   if(m==1)
    first=ttemp;
  }

  else
  {
    p=ttemp->prev;
    s=temp->next;
    p->next=temp;
    s->prev=ttemp;
    temp->prev->next=ttemp;
    ttemp->next->prev=temp;
    temp->next=ttemp->next;
    ttemp->next=s;
    ttemp->prev=temp->prev;
    temp->prev=p;
    if(m==1)
     first=ttemp;
 }
}


void disp(){
temp=first;
    do{
        cout<<temp->data;
        temp=temp->next;
    }while(temp!=first);
}
int main(){
create_first(10);
    add_node(20);
    add_node(30);
    add_node(40);
    add_node(50);
    disp();
    cout<<"\n";
    swapMN(2,3);
    disp();

}