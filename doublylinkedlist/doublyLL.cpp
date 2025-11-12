//double linked list
#include<iostream>
using namespace std ;
struct node{
    int data;
    node *next,*prev;
};
node *first ,*temp,*ttemp,*p;
void init(){
    first=temp=ttemp=NULL;
}
void create_first(int x){
    first=new node;
    first->data=x;
    first->next=NULL;
    first->prev=NULL;
}
void add_node(int x){
   temp=first;
   while(temp->next!=NULL){
    temp=temp->next;
   }
   ttemp=new node;
   ttemp->data=x;
   ttemp->next=NULL;
   ttemp->prev=temp;
   temp->next=ttemp;
}
void display(){
    temp=first;
    while(temp!=NULL){
        cout<<temp->data;
        cout<<endl;
        temp=temp->next;
    }
}
void add_before_first(int x){
    temp=new node;
    temp->data=x;
    temp->next=first;
    temp->prev=NULL;   
    first->prev=temp;
    first=temp; 
}
void add_before(int x,int y){
    temp=first;
    while(temp->data!=x){
        temp=temp->next;
    }
    ttemp=temp->prev;
    p=new node;
    p->data=y;
    ttemp->next=p;
    p->prev=ttemp;
    p->next=temp;
    temp->prev=p;
}
void del_after(int x){
    temp=first;
    while(temp->data!=x){
      temp=temp->next;
    }
    ttemp=temp->next;
    p=ttemp->next;
    temp->next=p;
    p->prev=temp;
    ttemp->next=NULL;
    ttemp->next=NULL;
    delete(ttemp);
}
void delete_before(int x){
    // 2,4,3
    temp=first;
    while(temp->data!=x)
    temp=temp->next;
    ttemp=temp->prev;
    p=ttemp->prev;
    p->next=temp;
    temp->prev=p;
    ttemp->next=NULL;
    ttemp->prev=NULL;
    delete(ttemp);
}
void delete_first(){
    temp=first;
    ttemp=temp->next;
    temp->next=NULL;
    ttemp->prev=NULL;
    first=ttemp;
    delete(temp);
}
void swap1last(){
    temp=first;
    ttemp=temp;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    p=temp->prev;
    temp->next = ttemp->next;   
    ttemp->next->prev = temp;   
    temp->prev = NULL;          
    ttemp->next = NULL; 
    ttemp->prev=p;
    p->next=ttemp;
    first=temp;
}
void swapll2nd(){
   temp=first;
   while(temp->next!=NULL){
    temp=temp->next;
   }
   ttemp=temp->prev;
   ttemp->prev->next=temp;
   temp->prev=ttemp->prev;
   temp->next=ttemp;
   ttemp->prev=temp;
   ttemp->next=NULL;
}
void swapmn(int m,int n){
    temp=first;
    while(temp->data!=m){
        temp=temp->next;
    }
    ttemp=first;
    while(ttemp->data!=n){
        ttemp=ttemp->next;
    }
    // temp=m
    // ttemp=n
    p=temp->prev;//m KA PREVIOUS
    temp->prev->next=ttemp;
    temp->prev=ttemp->prev;
    temp->next->prev=ttemp;
    temp->next=ttemp->next;
    p->next->next->prev=ttemp;
    ttemp->prev=p;
    ttemp->next=p->next->next;
    p->next=ttemp;
}
void swap12(){
    temp=first;
    ttemp=temp->next;
    temp->next=ttemp->next;
    ttemp->next->prev=temp;
    temp->prev=ttemp;
    ttemp->next=temp;
    ttemp->prev=NULL;
    first=ttemp;
}
void swap1l(){
    temp=first->prev;     
    ttemp=temp->prev;
    p=first->next;
    temp->next=p;
    temp->prev=first;
    p->prev=temp;
    ttemp->next=first;
    first->prev=ttemp;
    first->next=temp;
    first=temp;
}
    

int main(){
     init();
     create_first(1);
     add_node(2);
     add_node(3);
     add_node(8);
     add_node(4);
    //  add_before_first(0);
    //  add_before(2,22);
    //  del_after(1);
    //  delete_before(4);
    //  delete_first();
    //  swap12();
    //  swap1last();
    //  swapll2nd();
     swapmn(3,8);
     display();
     swap1l();
     return 0;
}