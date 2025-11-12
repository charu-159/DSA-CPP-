//single circular
#include<iostream>
using namespace std;
struct scll{
    int data;
    scll*next;
};
scll *temp,*first,*ttemp,*p;
void create_first(int n){
    first=new scll;
    first->data=n;
    first->next=first;
}
void add_node(int x){
    temp=first;
    while(temp->next!=first){
    temp=temp->next;
    }
    ttemp=new scll;
    ttemp->data=x;
    ttemp->next=first;
    temp->next=ttemp;

}
  void add_before_first(int x){
    temp=first;
    while(temp->next!=first){
     temp=temp->next;
    }
    ttemp=new scll;
    ttemp->data=x;
    ttemp->next=first;
    temp->next=ttemp;
     first=ttemp;
     

    }
    void delete1st(){
  temp=first;
  while(temp->next!=first)
  temp=temp->next;
  p=first->next;
  first->next=NULL;
  temp->next=p;
  delete first;
  first=p;
}
void deletelast(){
  temp=first;
  while (temp->next!=first)
  {
   ttemp=temp;
   temp=temp->next;

  }
  p=temp->next;
  temp->next=NULL;
  delete temp;
  ttemp->next=p;
  
}
void swap1st_2nd(){
  temp=first;
   ttemp=temp->next;
   p=ttemp->next;
   while(temp->next!=first){
    temp=temp->next;
   }
   first->next=p;
   temp->next=first;
   temp->next=ttemp;
   first=ttemp;
}
void swapLSL(){
  temp=first;
    while(temp->next->next!=first){
        ttemp=temp;
    temp=temp->next;
   }
   p=temp->next;
   ttemp->next=temp;
  p->next=temp;
   temp->next=first;
}
void swapF_Last()
{
    temp=first;
    p=first->next;
    while(temp->next!=first){
        ttemp=temp;
        temp=temp->next;

    }
    ttemp->next=first;
    first->next=temp;
    temp->next=p;
    first=temp;
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
    add_before_first(60);
    disp();
    delete1st();
    disp();
    deletelast();
    disp();
    swap1st_2nd();
    disp();
    swapLSL();
    disp();
    swapF_Last();
    disp();
    return 0;
}