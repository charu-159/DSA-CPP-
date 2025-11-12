//single
#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    node *next;
};
node *first,*temp,*ttemp,*p,*prevm,*prevn;
void init(){
    first=temp=ttemp=p=prevm=prevn=NULL;
}
void create_first(int n){
   first=new node;
   first->next=NULL;
   first->data=n;
  
}
void del_first(){
    temp=first;
    first=first->next;
    temp->next=NULL;
    delete temp;
}
void add_before_first(int x){
    temp=new node;
    temp->data=x;
    temp->next=first;
    first=temp; 
}
void add_before(int x,int y){
    temp=first;
    while(temp->data!=x){
        ttemp=temp;
        temp=temp->next;
    }
    p=new node;
    p->data=y;
    p->next=temp;
    ttemp->next=p;
}
void add_node(int x){
    temp=first;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    ttemp=new node;
    ttemp->data=x;
    ttemp->next=NULL;
    temp->next=ttemp;
}
void add_after(int x,int y){
    temp=first;
    while(temp->data!=x){
        temp=temp->next;
        ttemp=temp->next;
    }
    p=new node;
    p->data=y;
    p->next=ttemp;
    temp->next=p;
}
void add_before_last(int x){
    temp=first;
    while(temp->next!=NULL){
      ttemp=temp;
      temp=temp->next;
    }
    p=new node;
    p->data=x;
    p->next=temp;
    ttemp->next=p;
}
void del_after(int x){
    temp=first;
    while(temp->data!=x){
      temp=temp->next;
      ttemp=temp->next;
    }
    p=ttemp->next;
    temp->next=p;
    ttemp->next=NULL;
    delete(ttemp);
}
void del_before(int x){
   temp=first;
   while(temp->next->data!=x){
      ttemp=temp;
      temp=temp->next;
   }
   p=temp->next;
   ttemp->next=p;
   temp->next=NULL;
   delete(temp);
}
void del_2last(){
   temp=first;
   while(temp->next->next!=NULL){
      ttemp=temp;
      temp=temp->next;
   }
   p=temp->next;
   ttemp->next=p;
   temp->next=NULL;
   delete(temp);
}
void swap12(){
    temp=first;
    ttemp=temp->next;
    p=ttemp->next;
    temp->next=p;
    ttemp->next=temp;
    first=ttemp;
} 
void swapFL() {
    temp = first;
    while(temp->next!=NULL){
      ttemp=temp;
      temp=temp->next;
    }
    p=first->next;
    ttemp->next=first;
    first->next=NULL;
    temp->next=p;
    first = temp;

}
// void swapFL() {
//     temp = first;
//     while (temp->next->next != NULL)     // Step 1: reach 2nd last node
//         temp = temp->next;

//     ttemp = temp->next;                  // Step 2: ttemp = last node
//     p = first->next;                     // Step 3: p = 2nd node

//     ttemp->next = p;                     // Step 4: last node points to 2nd node
//     temp->next = first;                  // Step 5: 2nd last node points to 1st node
//     first->next = NULL;                  // Step 6: old first becomes last
//     first = ttemp;                       // Step 7: update head to new first
// }
void swap2ll(){
    temp=first;
    while(temp->next->next!=NULL){
       ttemp=temp;
       temp=temp->next;
    }
    p=temp->next;
    temp->next=NULL;
    ttemp->next=p;
    p->next=temp;
}


void display(){
    temp=first;
    while(temp!=NULL){
        cout<<temp->data;
        cout<<endl;
        temp=temp->next;
    }
}

int main(){
init();
create_first(1);
add_node(2);
add_node(10);
add_node(20);
add_node(60);
add_node(3);
add_node(4);
add_node(77);
add_node(23);
add_node(90);
add_after(3,7);
add_before(4,5);
add_before_first(0);
// add_before_last(1);
del_after(1);
del_before(60);
del_2last();
swap12();
swapFL();
swap2ll();


display();
}