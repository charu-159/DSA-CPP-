#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    node *next;
};
node *first,*temp,*ttemp,*p,*ntemp,*mtemp,*nptemp,*mptemp;
void init(){
    first=temp=ttemp=p=ntemp=mtemp=nptemp=mptemp=NULL;
}
void create_first(int n){
   first=new node;
   first->next=NULL;
   first->data=n;
  
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

void display(){
    temp=first;
    while(temp!=NULL){
        cout<<temp->data;
        cout<<endl;
        temp=temp->next;
    }
}
void swap(int m, int n) {
    // If both positions are same, nothing to do
    if (m == n)
        return;

    // Ensure m < n (so we handle head cases easily)
    if (m > n) {
        int tempIndex = m;
        m = n;
        n = tempIndex;
    }

    // Initialize pointers
    mtemp = first;
    ntemp = first;
    mptemp = NULL;
    nptemp = NULL;

    // Traverse to mth node
    for (int i = 1; i < m && mtemp != NULL; i++) {
        mptemp = mtemp;
        mtemp = mtemp->next;
    }

    // Traverse to nth node
    for (int i = 1; i < n && ntemp != NULL; i++) {
        nptemp = ntemp;
        ntemp = ntemp->next;
    }

    // If either node not found (out of range)
    if (mtemp == NULL || ntemp == NULL)
        return;

    // Link previous of m to n (handle head)
    if (mptemp != NULL)
        mptemp->next = ntemp;
    else
        first = ntemp;

    // nptemp can't be NULL now because n > m always
    nptemp->next = mtemp;

    // Swap next pointers of m and n
    temp = mtemp->next;
    mtemp->next = ntemp->next;
    ntemp->next = temp;
}
int main(){
init();
create_first(10);
add_node(20);
add_node(30);
add_node(40);
add_node(60);
display();
cout<<"\n";
swap(4,3);
display();

}