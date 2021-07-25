#include <stdio.h>
#include <stdlib.h>
typedef struct node {
    int data;
    struct node* next;
} node;

typedef void (*callback)(node* data);

/*
    create a new node
    initialize the data and next field

    return the newly created node
*/
node* create(int data,node* next) {
    node* new_node = (node*)malloc(sizeof(node));
    if(new_node == NULL) {
        printf("Error creating a new node.\n");
        exit(0);
    }
    new_node->data = data;
    new_node->next = NULL;

    return new_node;
}

/*
    add a new node at the beginning of the list
*/
node* Insert_Beginning(node* head,int data) {
    node* new_node;
    new_node = (node*)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = head;
    head = new_node;
    return head;
}

/*
    add a new node at the end of the list
*/
node* Insert_End(node* head, int data) {
    if(head == NULL) {
        node* new_node;
        new_node = (node*)malloc(sizeof(node));
        new_node->data = data;
        new_node->next = head;
        head = new_node;
        return head;
    }

    /* Create a new node */
    node* new_node;
    new_node = (node*)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = NULL;

    /* go to the last node */
    node *temp = head;
    while(temp->next != NULL)
        temp = temp->next;

    /* create a new node */
    temp->next = new_node;

    return head;
}

/*
    insert a new node after the prev node
*/
node* Insert_After(node *head, int data, node* prev) {
    if(head == NULL || prev == NULL)
        return NULL;

    /* find the prev node, starting from the first node*/
/*
    node *temp = head;
    while(temp != prev)
        temp = temp->next;

    if(temp != NULL) {
        node* new_node;
        new_node = (node*)malloc(sizeof(node));
        new_node->data = data;
        new_node->next = temp->next;

        temp->next = new_node;

        return head;
    }
    else {
        return NULL;
    }
*/
    node* new_node;
    new_node = (node*)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = prev->next;

    prev->next = new_node;
    return head;
}

/*
    insert a new node before the nxt node
*/
node* Insert_Before(node *head, int data, node* nxt) {
    if(nxt == NULL || head == NULL)
        return NULL;

    if(head == nxt) {
        head = Insert_Beginning(head,data);
        return head;
    }

    /* find the prev node, starting from the first node*/
    node *temp = head;

    /*while(temp != NULL) {
        if(temp->next == nxt)
            break;
        temp = temp->next;
    }*/
    /* Or below one */

    while(temp->next != nxt)
        temp = temp->next;


    if(temp != NULL) {
        node* new_node;
        new_node = (node*)malloc(sizeof(node));
        new_node->data = data;
        new_node->next = temp->next;

        temp->next = new_node;

        return head;
    }
    else {
        return NULL;
    }
}

/*
    traverse the linked list
*/
void Traverse(node* head) {
    printf("\nList: ");
    node* temp = head;
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}
/*
    remove node from the front of list
*/
node* Delete_Beginning(node* head) {
    if(head == NULL)
        return NULL;
    node *temp = head;
    head = head->next;
    //front->next = NULL;

    /* is this the last node in the list */
    //if(front == head)
        //head = NULL;

    /* Clears the memory occupied by first node*/
    free(temp);
    return head;
}

/*
    remove node from the back of the list
*/
node* Delete_End(node* head)
{
    if(head == NULL)
        return NULL;

    node *temp = head;
    node *back = NULL;
    while(temp->next != NULL) {
        back = temp;
        temp = temp->next;
    }

    if(back != NULL) {
         /* Disconnect link of second last node with last node */
        back->next = NULL;
    }

    /* if this is the last node in the list*/
    if(temp == head)
        head = NULL;

    /* Delete the last node */
    free(temp);

    return head;
}

/*
    remove a node from the list
*/
node* Delete_Any(node* head,node* nd)
{
    if(nd == NULL)
        return NULL;
    /* if the node is the first node */
    if(nd == head) {
        printf("\n begin \n");
        return Delete_Beginning(head);
    }

    /* if the node is the last node */
    if(nd->next == NULL) {
        printf("\n end \n");
        return Delete_End(head);
    }

    /* if the node is in the middle */
    node* temp = head;
    while(temp != NULL) {
        if(temp->next == nd)
            break;
        temp = temp->next;
    }

    if(temp != NULL) {
        node* tmp = temp->next;
        temp->next = tmp->next;
        tmp->next = NULL;
        free(tmp);
    }
    return head;

}
/*
    display a node
*/
void display(node* n)
{
    if(n != NULL)
        printf("%d ", n->data);
}

void display_Rec(node* n)
{
    if(n == NULL) {
        return;
    } else {
        printf("%d ", n->data);
        display_Rec(n->next);
    }

}


/*
    Search for a specific node with input data

    return the first matched node that stores the input data,
    otherwise return NULL
*/
node* Search(node* head,int data) {
    node *temp = head;
    while(temp!=NULL) {
        if(temp->data == data)
            return temp;
        temp = temp->next;
    }
    return NULL;
}

/*
    remove all element of the list
*/
void dispose(node *head)
{
    node *cursor, *tmp;

    if(head != NULL)
    {
        cursor = head->next;
        head->next = NULL;
        while(cursor != NULL)
        {
            tmp = cursor->next;
            free(cursor);
            cursor = tmp;
        }
    }
}
/*
    return the number of elements in the list
*/
int count(node *head)
{
    node *cursor = head;
    int c = 0;
    while(cursor != NULL)
    {
        c++;
        cursor = cursor->next;
    }
    return c;
}
/*
    sort the linked list using insertion sort
*/
node* insertion_sort(node* head)
{
    node *x, *y, *e;

    x = head;
    head = NULL;

    while(x != NULL)
    {
        e = x;
        x = x->next;
        if (head != NULL)
        {
            if(e->data > head->data)
            {
                y = head;
                while ((y->next != NULL) && (e->data> y->next->data))
                {
                    y = y->next;
                }
                e->next = y->next;
                y->next = e;
            }
            else
            {
                e->next = head;
                head = e ;
            }
        }
        else
        {
            e->next = NULL;
            head = e ;
        }
    }
    return head;
}

/*
    reverse the linked list
*/
node* reverse(node* head)
{
    node* prev    = NULL;
    node* current = head;
    node* next;
    while (current != NULL)
    {
        next  = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
    return head;
}
/*
    display the menu
*/
void menu()
{
    printf("--- C Linked List Demonstration --- \n\n");
    printf("0.menu\n");
    printf("1.Insert an element at beginning\n");
    printf("2.Insert an element at end\n");
    printf("3.Search for an element\n");
    printf("4.Insert after an element\n");
    printf("5.Insert before an element\n");
    printf("6.Delete first node\n");
    printf("7.Delete last node\n");
    printf("8.Delete any node\n");
    printf("9.Sort the list\n");
    printf("10.Reverse the linked list\n");
    printf("-1.quit\n");

}

int main()
{
    int command = 0;
    int data;

    node* head = NULL;
    node* tmp = NULL;
    callback disp = display;

    menu();
    while(1)
    {
        printf("\nEnter a command(0-10,-1 to quit):");
        scanf("%d",&command);

        if(command == -1)
            break;
        switch(command)
        {
        case 0:
            menu();
            break;
        case 1:
            printf("Please enter a number to insert at beginning:");
            scanf("%d",&data);
            head = Insert_Beginning(head,data);
            Traverse(head);
            break;
        case 2:
            printf("Please enter a number at end:");
            scanf("%d",&data);
            head = Insert_End(head,data);
            Traverse(head);
            break;
        case 3:
            printf("Please enter a number to search:");
            scanf("%d",&data);
            tmp = Search(head,data);
            if(tmp != NULL) {
                printf("Element with value %d found.",data);
            }
            else {
                printf("Element with value %d not found.",data);
            }
            break;
        case 4:
            printf("Enter the element value where you want to insert after:");
            scanf("%d",&data);
            tmp = Search(head,data);
            if(tmp != NULL) {
                printf("Enter the element value to insert after:");
                scanf("%d",&data);
                head = Insert_After(head,data,tmp);
                if(head != NULL)
                    Traverse(head);
            }
            else {
                printf("Element with value %d not found.",data);
            }
            break;
        case 5:
            printf("Enter the element value where you want to insert before:");
            scanf("%d",&data);
            tmp = Search(head,data);
            if(tmp != NULL) {
                printf("Enter the element value to insert before:");
                scanf("%d",&data);
                head = Insert_Before(head,data,tmp);

                if(head != NULL)
                    Traverse(head);
            }
            else {
                printf("Element with value %d not found.",data);
            }
            break;
        case 6:
            head = Delete_Beginning(head);
            if(head != NULL)
                Traverse(head);
            break;
        case 7:
            head = Delete_End(head);
            if(head != NULL)
                Traverse(head);
            break;
        case 8:
            printf("Enter the element value to remove:");
            scanf("%d",&data);
            tmp = Search(head,data);
            if(tmp != NULL) {
                head = Delete_Any(head,tmp);
                if(head != NULL)
                    Traverse(head);
            }
            else {
                printf("Element with value %d not found.",data);
            }
            break;
        case 9:
            head = insertion_sort(head);
            if(head != NULL)
                Traverse(head);
            break;
        case 10:
            head = reverse(head);
            if(head != NULL)
                Traverse(head);
            break;
        }

    }
    dispose(head);
    return 0;
}
