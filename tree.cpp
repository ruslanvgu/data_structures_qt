typedef struct node
{
    int x;
    struct node * r ;
    struct node * l ;
} Node;

Node* add(Node** top, int value)
{
    if( (*top) == NULL )
    {
        (*top) = (Node*)malloc(sizeof(Node));
        (*top)->x = value;
        (*top)->r = (*top)->l = NULL;
    }
    else
    {
        if((*top)->x > value)
            add(&(*top)->l,value);
        else
            add(&(*top)->r,value);
    }
}

void print(Node *elem)
{
    if(elem == NULL) return;
    else{
            print(elem->l);
            printf("%d ",elem->x);
            print(elem->r);
    }
}

int main(int, char**)
{
    using namespace std;


    Node *head = NULL;
    add(&head,4);
    add(&head,2);
    add(&head,3);
    add(&head,1);
    print(head);


    return 0;
}

