typedef struct node
{
    int x;
    struct node * r ;
    struct node * l ;
} Node;

void add(Node** top, int value)
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
        else if((*top)->x < value)
            add(&(*top)->r,value);
        else
            return;
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

Node* find_node(Node* e, int v)
{
    if(e == NULL) return NULL;
    else {
        if(e->x == v) return e;
        else if( e->x > v)
            find_node(e->l,v);
        else
            find_node(e->r,v);
    }
}

void del(Node *e, int v)
{
    if(e == NULL ) return;
    else{
        Node* prev = NULL;
        while(e && e->x != v)
        {
            prev = e;
            if(e->x > v)
                e = e->l;
            else
                e = e->r;
        }

        if(!e) return;

        if(e->l == NULL && e->r == NULL) /* dont have children  */
        {
            if(prev->x > e->x)
                prev->l = NULL;
            else
                prev->r = NULL;
            free(e);
            e = NULL;

        }else if(e->l == NULL )         /* have 1 child right */
        {
            Node *tmp = e->r;
            free(e);
            if(prev->x > tmp->x)
                prev->l = tmp;
            else
                prev->r = tmp;

        }else if( e->r == NULL)         /* have 1 child left */
        {
            Node *tmp = e->l;
            free(e);
            if(prev->x > tmp->x)
                prev->l = tmp;
            else
                prev->r = tmp;
        }
        else                            /* have 2 child */
        {
            /* find min elem right branch */
            Node * min = e->r;          /* move right branch subtree */
            Node *prevMin = NULL;
            while( min->l != NULL){
                prevMin = min;
                min = min->l;
            }

            prevMin->l = min->r;        /* change ptr previos min node */

            min->l = e->l;              
            min->r = e->r;

            free(e);
            e = NULL;

            if(prev->x > min->x)
                prev->l = min;
            else
                prev->r = min;
        }
    }
}

int main(int, char**)
{
    using namespace std;

    Node *head = NULL;
    add(&head,7);
    add(&head,2);
    add(&head,9);
    add(&head,8);
    add(&head,11);
    add(&head,10);
    add(&head,12);
    print(head);
    printf("\n");
    del(head,2);
    print(head);
    printf("\n");
    return 0;
}

