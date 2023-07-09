#include<stdio.h>
#include<stdlib.h>
#include<string.h>


struct node
{
   char name[50] ;
   double prcnt;
   struct node *link;
};
struct node *head=NULL;
void display(head);

struct node* add_beg(struct node *head,char *name,double prcnt)
{
   
    struct node *ptr=(struct node*)malloc(sizeof(struct node));
 
    strcpy(ptr->name,name);
    ptr->link=NULL;
    ptr->prcnt=prcnt;
     if(head==NULL)
        {
          head = ptr;
        }
     else 
  {
    ptr->link=head;

    head=ptr;
   }
   display(head);
    return head;
}

void add_end(struct node* head, char *name,double prcnt)
{
    struct node *ptr,*temp;
    ptr=head;
    temp=(struct node*)malloc(sizeof(struct node));
    strcpy(temp->name,name);
    temp->prcnt=prcnt;
    temp->link=NULL;
    while(ptr->link!=NULL)
         ptr=ptr->link;

    ptr->link=temp;


}

void display(struct node *head)
{
   int i=1;
   struct node *ptr;
   if (head==NULL)
      {
      printf("\nLinked List is Empty");
      }
   else
   {
   ptr=head;
   while(ptr!=NULL)
      {
         printf("\nName of the student %d is : %s",i,ptr->name);
         printf("\nPercentage is %2.2lf",ptr->prcnt);
         ptr=ptr->link;
         i++;
      }
   }

}

struct node* add_pos(head,name,prcnt);
{
  
}


int main()
{
   int n,y;
   char name [50];
   double prcnt;

  /* head=(struct node *)malloc(sizeof(struct node));
   strcpy(head->name,"AKIB MANER");
   head->prcnt=85;
   head->link=NULL;
 
   struct node *current=(struct node *)malloc(sizeof(struct node));
   strcpy(current->name,"OSMOND MARCSCEHANS");
   current->prcnt=70;
   current->link=NULL;
   head->link=current;

   struct node * current1=(struct node *)malloc(sizeof(struct node));
   strcpy(current1->name,"GUDDU PANDIT");
   current1->prcnt=83;
   current1->link=NULL;
   head->link->link=current1;  */
   

   printf("\n1: Insertion at the start \n2: Insertion at the end \n3: Insertiom at the specific location ");
   printf("\n4: Deletion at the start \n5: Deletion at the end \n6: Deletion at the specific location ");
   printf("\n7: Display ");
   scanf("%d",&n);
   switch (n)
         {
         case 1 :
              
                  printf("\nInserting the node at the start ");
                  printf("\nEnter the name : ");
                  scanf("%s",name);
                  printf("\nEnter the percentage  : ");
                  scanf("%lf",&prcnt);
                  head=add_beg(head,name,prcnt);
                  
                   break;

         case 2 :
                  printf("\nInserting the node at the end ");
                  printf("\nEnter the name : ");
                  scanf("%s",name);
                  printf("\nEnter the percentage  : ");
                  scanf("%lf",&prcnt);
                  add_end(head,name,prcnt);
                 
                   break;
   
         case 4:
                  printf("\nInserting the node at the position ");
                  printf("\nEnter the name : ");
                  scanf("%s",name);
                  printf("\nEnter the percentage  : ");
                  scanf("%lf",&prcnt);
                  add_pos(head,name,prcnt);
        
           
         case 7 :
                   printf("\n%s",head->name);
                  display(head);
 
                  break;
              
         


         }
   printf("\nDo u want to continue (1;yes)");
   scanf("%d",&y);
   if(y==1)
     main();
   else
      exit(0);

   return 0;
}

