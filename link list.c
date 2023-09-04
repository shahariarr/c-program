#include<stdio.h>
#include<stdlib.h>
struct node *head=NULL,*temp=NULL,*newnode=NULL,*newhead=NULL;
typedef struct node
{
    int data;
    struct node* next;
};
struct node* createLinkedList(int choice)
{
    while(choice--)
    {
        newnode = (struct node*)(malloc(sizeof(struct node)));
        scanf("%d", &newnode->data);
        newnode->next = NULL;

        if (head == NULL)
        {
            head = temp = newnode;
        }
        else
        {
            temp->next = newnode;
            temp = temp->next;
        }
    }

    return head;
}
void printLinkedList(struct node* head)
{
    temp = head;
    while (temp != NULL)
    {
        printf("%d", temp->data);
        if(temp->next != NULL){
          printf(" -> ");
        }
        temp = temp->next;
    }
}
void countnode(struct node* head)
{
    int count=0;
    temp = head;
    while (temp != NULL)
    {

        count++;
        temp = temp->next;
    }
    printf("%d\n",count);
}
void summation(struct node* head)
{
    int sum=0;
    temp = head;
    while (temp != NULL)
    {

        sum+=temp->data;
        temp = temp->next;
    }
    printf("%d\n",sum);
}
void indexfind(struct node* head,int x)
{
    int count=0;
    temp = head;
    while(temp != NULL){
             count++;
            if(temp->data == x){
                break;
                }

        temp = temp->next;
    }
    printf("%d\n",count);
}

void searchlist(struct node* head,int x)
{
    temp = head;
    int count=0;

    while (temp !=  NULL)
    {
        if(temp->data == x)
        {
            count++;
        }
        temp = temp->next;

    }
    if(count==0){
       printf("Not Found");
    }
    else{
        printf("Found");
    }
}



struct node* deletelist(struct node *head,int x){

    temp=head;
    struct node *prev=NULL;

    while(temp!= NULL){
            if(temp->data == x){
                if(head==temp){
                    head = head->next;
                    break;
                }
                else{
                    prev->next= temp->next;
                    break;
                }
            }
        prev = temp;
        temp = temp->next;
    }
    free(temp);
    return head;

}

struct node* deletelistfirst(struct node* head)
{
    temp = head;
    head = head->next;
    free(temp);
    return head;
}

void deletelistlast(struct node* head)
{
    temp = head;
    struct node *prev = NULL;
    while (temp->next != NULL)
    {
        prev = temp;
        temp = temp->next;
    }
    prev->next =  temp->next;
    free(temp);
}

struct node* addlistfirst(struct node* head)
{
    temp = head;
    newnode = (struct node*)(malloc(sizeof(struct node)));
    scanf("%d", &newnode->data);
    newnode->next = temp;
    head = newnode;
    return head;
}

struct node* reverse(struct Node *head)
{
    struct node* prev = NULL;
    struct node* temp = head;
    struct node* next = NULL;
    while (temp != NULL) {
        next = temp->next;
        temp->next = prev;
        prev = temp;
        temp = next;
    }
    newnode = prev;
    return newnode;
}



int main()
{

    int choice;
    int data;

    printf("Enter Your linked list size: ");
    scanf("%d",&choice);
    head = createLinkedList(choice);
    printLinkedList(head);

    printf("\nEnter Your data for search:\n ");
    scanf("%d",&data);
    searchlist(head,data);

    printf("\nEnter Your data for delete:\n ");
    scanf("%d",&data);
    head = deletelist(head,data);
    printLinkedList(head);

    printf("\nDelete First node:\n ");
    head = deletelistfirst(head);
    printLinkedList(head);

    printf("\nDelete last node:\n ");
    deletelistlast(head);
    printLinkedList(head);

    printf("\nAdd first node:\n ");
    head = addlistfirst(head);
    printLinkedList(head);

    printf("\nCount node:\n ");
    countnode(head);

    printf("\nSummation node data:\n ");
    summation(head);

    printf("\n node index find:\n ");
    scanf("%d",&data);
    indexfind(head,data);

    printf("\n reverse node\n ");
    newhead = reverse(head);
    printLinkedList(newhead);




    return 0;
}
