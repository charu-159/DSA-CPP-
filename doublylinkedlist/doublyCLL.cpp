//double circular
#include<iostream>
using namespace std;
struct DCLL{
    int data;
    DCLL*next,*prev;
};
DCLL *first,*temp,*ttemp,*p;
void init(){
  first=temp=ttemp=p;
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
void before_first(int x){
   temp=first;
   ttemp=new DCLL;
   ttemp->data=x;
   ttemp->next=first;
   first->prev->next=ttemp;
   ttemp->prev=first->prev;
   first->prev=ttemp;
   first=ttemp;
}
void after_first(int x){
temp=first->next;
ttemp=new DCLL;
ttemp->data=x;
ttemp->prev=first;
ttemp->next=temp;
temp->prev=ttemp;
first->next=ttemp;
}
void add_after_given(int x,int y){
temp=first;
while(temp->data!=x){
    temp=temp->next;
    p=temp->next;
    ttemp=new DCLL;
    ttemp->data =y;
   ttemp->prev=temp;
   temp->next=ttemp;
   ttemp->next=p;
   p->prev=ttemp;

}
}
void add_before_givendata(int x,int y){
    
}
void del_first(){
    temp=first->prev;
    ttemp=first->next;
    ttemp->prev=temp;
    temp->next=ttemp;
    first->prev=NULL;
    first->next=NULL;
    delete (first);
}
void del_last(){
temp=first->prev;
ttemp=temp->prev;
ttemp->next=first;
first->prev=ttemp;
temp->next=NULL;
temp->prev=NULL;
delete temp;
}
void swap12(){
temp=first->next;
ttemp=temp->next;
p=first->prev;
p->next=temp;
temp->prev=p;
temp->next=first;
first->prev=temp;
first->next=ttemp;
ttemp->prev=first;
first=temp;
}
void swaplsl(){
    temp=first->prev;
    ttemp=temp->prev;
    p=ttemp->prev;
    p->next=ttemp;
    temp->prev=p;
    temp->next=ttemp;
    ttemp->prev=temp;
    ttemp->next=first;
    first->prev=ttemp;
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
    before_first(10);
    disp();
    cout<<"\n";
    after_first(10);
    disp();
    cout<<"\n";
    add_after_given(10,70);
    disp();
    cout<<"\n";
    del_first();
    disp();
    cout<<"\n";
    del_last();
    disp();
    cout<<"\n";
    swap12();
    disp();
    cout<<"\n";
    swaplsl();
    disp();
    cout<<"\n";
}