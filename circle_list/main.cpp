//Один из недостатков линейных списков заключается в том, что, зная указатель p на звено списка, мы не имеем доступа к предшествующим ему звеньям.
//Если производится просмотр списка, то для повторного обращения к нему исходный указатель на начало списка должен быть сохранен.

#include <iostream>

struct element{
    element * next = nullptr;
    int data;
};


class cList{
    element *head;
    size_t sizeList;
    element *last;
public:
    cList(){
        head = nullptr;
        sizeList = 0;
        last = nullptr;
    }
    ~cList(){
        element * tmp = nullptr;
        while(!isEmpty()){
            tmp = head->next;
            delete head;
            head = tmp;
            sizeList--;
        }
    }
    void push(int data){
        element * tmp = new element;
        tmp->data = data;
        tmp->next = head;
        head = tmp;
        //if(tmp->next == nullptr){//первый элемент
        if(isEmpty()){
            last = tmp;
            last->next = tmp;
        }
        else
            last->next = tmp;

        sizeList++;
    }
    void show(){
        if(!isEmpty()){
        int mas[sizeList];
        element *tmp = head;
        for(int i = 0; i < sizeList; i++){
            mas[i] = tmp->data;
            tmp = tmp->next;
        }
        for(int i=sizeList-1; i >= 0; i--)
            std::cout <<mas[i] <<" ";
        std::cout << std::endl;
        }
    }

    void showCount(int count)
    {
        for(size_t i=0; i < count; i++){
            std::cout << head->data << " ";
            head = head->next;
        }
        std::cout << std::endl;
    }

    void pop()
    {
        if(!isEmpty()){
            element *tmp = head;
            head = tmp->next;
            last->next = tmp->next;
            delete tmp;
            sizeList--;
        }
    }

    int getSizeList()
    {
        return sizeList;
    }

    int insertInList(int index, int value)
    {
        if((index > 0) && (index <= sizeList) && (!isEmpty())){
            element * tmp = head;
            for(int i=0; i<sizeList-index; i++){
                tmp = tmp->next;
            }
            element *newTmp = new element;
            newTmp->data = value;
            newTmp->next = tmp->next;
            tmp->next = newTmp;
            if(newTmp->next == head) last = newTmp; //если вставляем первый элемент
            sizeList++;
            return 1;
        }
        return 0;
    }

    int removeOnIndex(int index)
    {
        if((index > 0) && (index <= sizeList) && (!isEmpty())){
            element *tmp = head;
            element *prev = nullptr;
            for(int i=0; i < sizeList-index; i++){
                prev = tmp;
                tmp = tmp->next;
            }
            if(tmp == last){

                if(sizeList == 1) delete tmp;
                else{
                    prev->next = tmp->next;
                    last = prev;
                    delete tmp;
                }
            } else if(tmp == head){
                head = tmp->next;
                last->next = tmp->next;
                delete tmp;
            } else {
                prev->next = tmp->next;
                delete tmp;
            }
            sizeList--;
            return 1;
        }
        return 0;
    }

    int isEmpty(){
        return (sizeList == 0) ? 1 : 0;
    }
};

int main(int argc, char *argv[])
{
    cList lst;

    int count=10;

    for(int i=1; i < count; i++){
        lst.push(i);
        lst.show();
    }

    while(!lst.isEmpty()){
        lst.removeOnIndex(1);
        lst.show();
    }

   for(int i=1; i < count; i++){
        lst.push(i);
        lst.show();
    }

   while(!lst.isEmpty()){
       lst.removeOnIndex(1);
       lst.show();
   }
    return 0;
}
