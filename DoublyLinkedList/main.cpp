#include <iostream>

struct element{
    element * next = nullptr;
    element * prev = nullptr;
    int data;
};

class lList{
    element *head;
    size_t sizeList;
    element *last;
public:
    lList(){
        head = nullptr;
        sizeList = 0;
        last = nullptr;
    }
    ~lList(){

        element * tmp;
        while(!isEmpty()){
            tmp = head->next;
            delete head;
            head = tmp;
            sizeList--;
        }
    }

    void push(int value)
    {
        element *tmp = new element;
        tmp->data = value;
        if(sizeList != 0)
            head->prev = tmp;
        tmp->next = head;
        head = tmp;
        if(sizeList == 0) last = tmp;
        sizeList++;
    }
    void pop(){

    }
    void show()
    {
        if(!isEmpty())
        {
            element * tmp = last;
            while(tmp!=head){
                tmp = tmp->prev;
                std::cout << tmp->data << "" ;
            }
            std::cout << std::endl;
        }
    }
    int isEmpty()
    {
        return (sizeList == 0) ? 1 : 0;
    }
};

int main(int argc, char *argv[])
{

    lList lst;

    int count=10;

    for(int i=0; i < count; i++){
        lst.push(i);
        lst.show();
    }


    return 0;
}
