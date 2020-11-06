#include <iostream>
#include <string>


struct element
{
    element *next = nullptr;
    int data;
};

class list
{
    element *head;
    size_t sizeList;

public:

    list(){
        head = nullptr;
        sizeList = 0;
    }

    ~list(){
        element *tmp;
        while(!isEmpty()){
            tmp = head->next;
            delete head;
            head = tmp;
        }
    }

    void push(int data){
        element * tmp = new element;
        tmp->data = data;
        tmp->next = head;
        head = tmp;

        sizeList++;
    }

    void pop(){
        if(!isEmpty()){
            element *tmp =head;
            head = tmp->next;
            delete tmp;

            sizeList--;
        }
    }

    void show(){
        int mas[sizeList];
        element *tmp = head;
        for(int i = 0; tmp!=nullptr; i++){
            mas[i] = tmp->data;
            tmp = tmp->next;
        }
        for(int i=sizeList-1; i >= 0; i--)
            std::cout <<mas[i] <<" ";
        std::cout << std::endl;
    }

    size_t getSizeList(){
        return sizeList;
    }

    int getValue(const int index){

        if((!isEmpty()) && (index <= sizeList) && (index > 0)){
            element *tmp = head;
            for(int i =0; i < sizeList - index; i++)
                tmp = tmp->next;
            return tmp->data;
        }
        return -1;
    }

    int  removeOnIndex(size_t index){

        if((!isEmpty()) && (index <= sizeList) && (index > 0)){
            element *tmp = head;
            element *prev = nullptr;
            for(int i=0; i < (sizeList - index); i++){
                prev = tmp;
                tmp = tmp->next;
            }
            if(tmp == head){ //крайний правый элемент
                head = tmp->next;
                delete tmp;
                sizeList--;
            }
            else if(tmp->next == nullptr){ //крайне левый элемент
                prev->next = nullptr;
                delete tmp;
                sizeList--;
            }
            else{  //средний элемент
                prev->next = tmp->next;
                delete tmp;
                sizeList--;
            }
            return 1;
        }
        else
            return 0;
    }

    int removeOnValue(int value)
    {
        if(!isEmpty()){
            element *tmp = head;
            for(int i = 0; tmp != nullptr ; i++)
            {
                if(tmp->data == value){
                    return removeOnIndex(sizeList - i);
                }
                tmp = tmp->next;
            }
        }
        return 0;
    }

    int isEmpty(){
        return (sizeList == 0) ? 1 : 0;
    }

    int insertInList(int index, int value)
    {
        if((index <= sizeList) && (index > 0) && (!isEmpty())){
            element * tmp = head;
            for(int i = 0; i < sizeList - index; i++)
                tmp = tmp->next;

            element * newTmp = new element;
            newTmp->data = value;
            if(tmp->next == nullptr)
                newTmp->next = nullptr;
            else
                newTmp->next = tmp->next;
            tmp->next = newTmp;
            sizeList++;
        }
        return 0;
    }


};

int main(int argc, char *argv[])
{
    int count=10;
    list lst;

    for(int i=0; i < count; i++)
    {
        lst.push(i);
        lst.show();
    }

    while(!lst.isEmpty())
      {
          lst.removeOnIndex(lst.getSizeList());
          lst.show();
      }

    lst.push(1);
    for(int i=0; i < count; i++)
    {
        lst.insertInList(i,5);
        lst.show();
    }

    while(!lst.isEmpty())
    {
        lst.removeOnIndex(1);

        lst.show();
    }

    return 0;
}
