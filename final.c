#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 50

struct node
{
    char name[MAX];
    double phn;
    struct node *link;    //defining our structure which stores data in collection order
};
struct node *head=NULL;
void display(struct node *head);
struct node *stack[MAX];
int top=-1;
char temp;

struct node* add(struct node *head,char *name,double phn)    //function which adds new contact
{
    int i;
    struct node *old;
    struct node *q;
    q=head;
    struct node *ptr=(struct node*)malloc(sizeof(struct node));
    if(head==NULL)
    {
        strcpy(ptr->name,name);
        ptr->link=NULL;
        ptr->phn=phn;
        head=ptr;

    }
    else
    {
        old=q;

        while(strcmp(q->name,name)>0)
        {


            printf("\n i is %d",i);
            old=q;
            q=q->link;
            if(q==NULL)
            {
                break;
            }


        }


        strcpy(ptr->name,name);
        ptr->phn=phn;
        ptr->link=old->link;
        old->link=ptr;

    }


    /* strcpy(p->name,name);
     p->link=NULL;
     p->phn=phn;
     if(head==NULL)
     {
         head = p;
     }
     else
     {
         p->link=head;

         head=p;                           //logic for storing details and creating link
     }  */

    return head;
}

int push(struct node *p)   //function which keeps the record of user called call history
//stack is used
{
    struct node *r;
    r=p;
    if (top==MAX-1)
    {
        printf("\n****************************************");
        printf("\n");
        printf("\n|  History limit is full                |");
        printf("\n****************************************");
        printf("\n");

    }
    else
    {
        top++;
        stack[top]=r;        //logic to add data on to the stack
    }

}

int dsply_hstry()                   //function which displays called history
//uses the traversing and display method of stack
{
    int i,t=1;
    struct node *q;
    if(top==-1)
    {
        printf("\n****************************************");
        printf("\n");
        printf("\nHistory is empty ...no calls has been made yet");
        printf("\n****************************************");
        printf("\n");
    }
    else
    {
        printf("\n  Recent calls are as follows___");
        for( i=top; i>=0; i--)
        {
            q=stack[i];
            printf("\n****************************************");
            printf("\n");
            printf("\n  %d call is made to ",t);
            printf("\n  Name is : %s                     ",q->name);
            printf("\n  Number is : %.0lf                   ",q->phn);
            printf("\n****************************************");
            printf("\n");      //logic to display called history
            //top=top-1;
        }
    }

}

struct node* search(struct node* head )           //function for searching of contact
{
    struct node *ptr;
    ptr=head;
    int flag=0,t;
    char key[50];
    printf("\n****************************************");
    printf("\n");
    printf("\n| Enter the name u want to search :      |\n");    //user input for which u want to search
    scanf("%c",&temp);
    scanf("%[^\n]",key);
    printf("\n****************************************");
    printf("\n");
    t=strcmp(ptr->name,key);
    if(ptr==NULL)
    {
        printf("\nDirectory is empty");

    }
    else
    {
        while(ptr!=NULL)
        {
            t=strcmp(ptr->name,key);

            if(t==0)
            {
                printf("\n****************************************");
                printf("\n");
                printf("\n  Contact found!!!                 ");
                printf("\n  Name is %s                         ",key);
                printf("\n  Number is %.0lf                    ",ptr->phn);    //logic to search and display teh found contact
                printf("\n****************************************");
                printf("\n");
                flag=0;                                  //using string compare built-in function and traversing the array
                push(ptr);
                break ;
            }

            ptr=ptr->link;
        }


    }
    if(flag==1)
        printf("\nContact not found");    //flag to maintain the record if contact is found or not



}
void display(struct node *head)           // function to display all the contact details
{
    int i=1;
    struct node *ptr;
    if (head==NULL)
    {
        printf("\n****************************************");
        printf("\n");
        printf("\n|   Contact directory is empty         |");
        printf("\n****************************************");
        printf("\n");
    }
    else
    {
        ptr=head;
        while(ptr!=NULL)
        {
            printf("\n****************************************");
            printf("\n");
            printf("\n|  Name is :  is : %s                  |",ptr->name);           // traverse the using the linked list till the end and display the data of each node
            printf("\n|  Phone nomber is :  %.00lf              |",ptr->phn);
            printf("\n****************************************");
            printf("\n");
            ptr=ptr->link;    //traverse till the end is NULL
            printf("\n");
            i++;
        }
    }

}

void update(struct node *p)           //update the contact when user want to do so
{
    int t,i,flag=1;
    char edit[MAX];
    struct node *ptr;
    ptr=p;
    printf("\n****************************************");
    printf("\n");
    printf("\n| Enter the name of contact u want to edit :  \n");    // take the contact name form user
    scanf("%c",&temp);
    scanf("%[^\n]",edit);
    printf("\n****************************************");
    printf("\n");


    if(ptr==NULL)
    {
        printf("\nDirectory is empty");

    }
    else
    {


        while(ptr!=NULL)
        {
            t=strcmp(ptr->name,edit);    //search for the user input

            if(t==0)
            {
                printf("\n****************************************");
                printf("\n");
                printf("\n  Contact found!!!");
                printf("\n  Name is %s",edit);
                printf("\n  Number is %.0lf",ptr->phn);
                printf("\n****************************************");
                printf("\n");
                flag=0;
                break ;
            }

            ptr=ptr->link;
        }


    }
    if(flag==1)
    {
        printf("\n****************************************");
        printf("\n");
        printf("\n|   Contact not found                   |");
        printf("\n****************************************");
        printf("\n");
    }

    else
    {
        printf("\n****************************************");
        printf("\n");
        printf("\nEnter The new name : ");     //when the search contact found update it by overwriting
        scanf("%s",(ptr->name));
        printf("\nEnter the new number : ");
        scanf("%lf",&(ptr->phn));
        printf("\n****************************************");
        printf("\n");

    }

}



int main()
{
    int n,y,t;
    char name [MAX],key[MAX];
    double phn;
    printf("\n****************************************");
    printf("\n| 1:\t Add New Contact               |");
    printf("\n| 2:\t Number search                 |");
    printf("\n| 3:\t Display                       |");
    printf("\n| 4:\t Update the contact            |");    //printing the menu list for the user
    printf("\n| 5:\t Calling history               |");
    printf("\n****************************************");
    printf("\n");
    scanf("%d",&n);
    printf("\n");


    switch (n)           //switch case for calling the respective function that user want to perform
    {
    case 1 :
        printf("\n****************************************");
        printf("\n");
        printf("\nEnter the name : ");
        scanf("%c",&temp);
        scanf("%[^\n]",name);    //Here compiler stores, null (0) to the string’s first character that is name[0]  so prevent that temp variable is used
        printf("\nEnter the phone no. : ");
        scanf("%lf",&phn);
        printf("\n****************************************");
        head=add(head,name,phn);   //calling add function for inserting the details

        break;



    case 2:
        search(head);  //search function call
        break;


    case 3:

        display(head);  //display function call

        break;

    case 4:
        update(head);   //update function call
        break ;

    case 5:
        dsply_hstry();  //display
        break ;




    }
    printf("\n****************************************");
    printf("\n");
    printf("\nDo u want to continue (1;yes)");
    scanf("%d",&y);   //asking user to to continue
    printf("\n****************************************");
    printf("\n");
    if(y==1)
        main();   //if yes calling the main function again to execute
    else
        exit(0);

    return 0;
}
/*
search   completed
update   completed
sort by name
history checkup

*/

