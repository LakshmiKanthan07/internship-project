#include<stdio.h>
#include<stdlib.h>  
#include<string.h>
struct student{
    int rollno;
    char name[50];
    struct student *next;
};
struct student *head=NULL;
struct student *Create(){
      struct student *temp,*p;
      temp=(struct student*)malloc(sizeof(struct student));
      printf("\nEnter the roll  no : ");
      scanf("%d",&temp->rollno);
      printf("\nEnter the name : ");
      scanf("%s",temp->name);
      temp->next=NULL;
      if(head==NULL){
        head=temp;
      }
      else{
        p=head;
        while(p->next!=NULL){
            p=p->next;
        }
        p->next=temp;
      }
      return head;
}
void Display() {
    struct student *p = head;
    while (p!= NULL) {
        printf("Roll No: %d", p->rollno);
        printf("  Name : %s\n",p->name);
        p = p->next;
    }
}

void Find(int search){
      struct student *p=head;
      while(p!=NULL){
            if(p->rollno==search){
                  printf("\nStudent found\n");
                  printf("%d",p->rollno);
                  printf("  %s\n",p->name);
                  return;
            }
            p=p->next;
      }
            printf("\nElement not found.\n");
      }
struct student *Insertatfirst(){
  struct student *temp;
  temp=(struct student*)malloc(sizeof(struct student));
  printf("\nEnter the roll  no : ");
  scanf("%d",&temp->rollno);
  printf("\nEnter the name : ");
  scanf("%s",temp->name);
  temp->next=head;
  head=temp;
  return head;
}
struct student *Insertatend(){
  struct student *temp,*p;
  temp=(struct student *)malloc(1*sizeof(struct student));
  printf("\nEnter the roll  no : ");
  scanf("%d",&temp->rollno);
  printf("\nEnter the name : ");
  scanf("%s",temp->name);
  temp->next=NULL;
  p=head;
  while(p->next!=NULL){
    p=p->next;
    }
  p->next=temp;
  return head;
}
struct student *Insert(int position){
  struct student *temp,*p;
  temp=(struct student *)malloc(1*sizeof(struct student));
  printf("\nEnter the roll number:");
  scanf("%d",&temp->rollno);
  printf("\nEnter the name:");
  scanf("%s",temp->name);
  temp->next=NULL;
  int i=1;
  p=head;
  while(i<position-1 && p!=NULL){
      p=p->next;
      i++;
  }
  if(p!=NULL){
     temp->next=p->next;
     p->next=temp;
    printf("\ndata inserted\n");
  }
  else{
    printf("\ninsertion failure\n");
  }
  return head;
}
struct student *Deletefirst(){
  struct student *p;
  if(head==NULL){
    printf("\nList is already empty.\n");
  }
  else{
    p=head;
    head=head->next;
    free(p);
    p=NULL;
    printf("\nDeleted successfully.\n");
  }
  return head;
}
void Deletelast(){
  if(head==NULL){
    printf("\nList is already empty.\n");
  }
  else if(head->next==NULL){
    free(head);
    head=NULL;
  }
  else{
    struct student *p1,*p2;
    p1=head;
    p2=NULL;
    while(p1->next!=NULL){
      p2=p1;
      p1=p1->next;
    }
    p2->next=NULL;
    free(p1);
    p1=NULL;
    printf("\nLast node deleted successfully.\n");
  }
}
struct student *Delete(int position){
  struct student *current,*previous;
  current=head;
  previous=head;
  if(head==NULL){
    printf("\nList is already empty.\n");
    return head;
  }
  else if(position==1){
    head=current->next;
    free(current);
    return head;
  }
  else{
    int i=1;
  while(i<position && current!=NULL){
    previous=current;
    current=current->next;  
    i++;
  }
  previous->next=current->next;
  free(current);
  current=NULL;
  }
  return head;
}
struct student *Deleteall(){
  struct student *temp;
  while(head!=NULL){
    temp=head;
    head=head->next;
    free(head);    
  }
  head=NULL;
  temp=NULL;
  return head;
} 
void Sort(){
  struct student *i,*j;
  int temprollno;
  char tempname[50];
  for(i=head;i!=NULL;i=i->next){
    for(j=i->next;j!=NULL;j=j->next){
      if(i->rollno > j->rollno){
        temprollno=i->rollno;
        i->rollno=j->rollno;
        j->rollno=temprollno;
        strcpy(tempname,i->name);
        strcpy(i->name,j->name);
        strcpy(j->name,tempname);

      }
    }
  }
  printf("\nList sorted successfully.\n");

}
void Reverse(){
   struct student *p,*q;
   p=NULL;
   q=NULL;
   while(head!=NULL){
    q=head->next;
    head->next=p;
    p=head;
    head=q;
   }
   head=p;
}

int main(){
    int n, i,choice;
    while(1){ 
      printf("\n1.Creating a singly linked list.\n");
      printf("2.Displaying a linked list.\n");
      printf("3.Searching a data in the linked list.\n");
      printf("4.Inserting at the first position of the linked list.\n");
      printf("5.Inserting at the last position of the linked list.\n");
      printf("6.Inserting at any position of the linked list.\n");
      printf("7.Deleting the first element of the linked list.\n");
      printf("8.Deleting the last element of the linked list.\n");
      printf("9.Deleting any element in the linked list.\n");
      printf("10.Deleting every element in the linked list.\n");
      printf("11.Sorting the linked list.\n");
      printf("12.Reversing the linked list.\n");
      printf("13.Exit.\n");
      printf("\nEnter your choice: ");
      scanf("%d",&choice);
      switch (choice){
        case 1:{
          printf("\nHow many students: ");
          scanf("%d", &n);
          for (i = 0; i <n; i++) {
            head=Create();
          }
          break;
          }
        case 2:{
          printf("\nStudent list:\n");
          Display();
          break;
          }
        case 3:{
          int search;
          printf("\nEnter the roll no to search : ");
          scanf("%d",&search);
          Find(search);
          break;
          }
        case 4:{
          head=Insertatfirst();
          Display();
          break;
          }
        case 5:{
          head=Insertatend();
          Display();
          break;
          }
        case 6:{
          int position;
          printf("\nEnter the position to insert : ");
          scanf("%d",&position);
          head=Insert(position);
          Display();
          break;
          }
        case 7:{
          head=Deletefirst();
          Display();
          break;
          }
        case 8:{
          Deletelast();
          Display();
          break;
          }
        case 9:{
          int position;
          printf("\nEnter the position to delete : ");
          scanf("%d",&position);
          head=Delete(position);
          Display();
          break;
          }
        case 10:{
          head=Deleteall();
          if(head==NULL){
          printf("\nDeleted successfully.\n");
          }
          Display();
          break;
          }
        case 11:{
          Sort();
          Display();
          break;
          }
        case 12:{
          Reverse();
          Display();
          break;
          }
        case 13:{
          printf("\nThankyou for using.\n");
          return 0;
          }
        default:{
          printf("\nEnter the correct option.\n");
          }
        }
    }
}
