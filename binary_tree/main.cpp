#include <iostream>
struct element
{
    int data;
    element *r = nullptr;
    element *l = nullptr;
    element *parent = nullptr;
};

class Tree
{
    element *root;
    int sizeTree;

public:

    Tree()
    {
        root = nullptr;
        sizeTree = 0;
    }

    ~Tree(){}

    void push(int value){
        _push(value, root);
    }

    void _push( int value, element *next = nullptr){
        if(root == nullptr) {
            element * tmp = new element;
            root = tmp;
            tmp->data = value;
            sizeTree++;
        } else {
            if(next->data > value) {
                if(next->l != nullptr) _push(value,next->l);
                else {
                    element *newTmp = new element;
                    next->l = newTmp;
                    newTmp->data = value;
                    newTmp->parent = next;
                    sizeTree++;
                }
            } else {
                if(next->r != nullptr) _push(value, next->r);
                else {
                    element *newTmp = new element;
                    next->r = newTmp;
                    newTmp->data = value;
                    newTmp->parent = next;
                    sizeTree++;
                }
            }
        }
    }

    int isEmpty(){
        return (root == nullptr);
    }

    void showTree(){
        _showTree(root);
    }

    void _showTree(element * next) // simmetrichny
    {
        if(next != nullptr){
            _showTree(next->l);
            std::cout << next->data <<" ";
            _showTree(next->r);
        }
    }

    int contain(int value){
        return _contain(value,root);
    }
    int _contain(int value, element *next){
        while(next != nullptr)
        {
            if(next->data > value)
                next = next->l;
            else if(next->data < value)
                next = next->r;
            else
                return 1;
        }
        return 0;
    }

    element * findPtrElement(int value){
        return _findPtrElement(value, root);
    }
    element * _findPtrElement(int value, element *next){
        while(next != nullptr){
            if(next->data > value)
                next = next->l;
            else if(next->data < value)
                next = next->r;
            else
                return next;
        }
        return nullptr;
    }

    void removeItem(int value){
        return _removeItem(value, root);
    }
    void _removeItem(int value, element * next){
        if(!isEmpty()){
            element *pElement = findPtrElement(value);
            if(pElement != nullptr){
                if(pElement->l == nullptr && pElement->r == nullptr){
                    if(pElement->parent->data > pElement->data){
                        pElement->parent->l = nullptr;
                    } else {
                        pElement->parent->r = nullptr;
                    }
                    delete pElement;

                } else if(pElement->l == nullptr && pElement->r != nullptr){
                    if(pElement->parent->data > pElement->data){
                        pElement->parent->l = pElement->r;
                    }
                    else{
                        pElement->parent->r = pElement->r;
                    }
                    pElement->r->parent = pElement->parent;
                    delete pElement;
                } else if(pElement->l != nullptr && pElement->r == nullptr){
                    if(pElement->parent->data > pElement->data){
                        pElement->parent->l = pElement->l;
                    }
                    else{
                        pElement->parent->r = pElement->l;
                    }
                    pElement->l->parent = pElement->parent;
                    delete pElement;
                } else if(pElement->l != nullptr && pElement->r != nullptr){
                    element* minLeftSubTree = _findMin(pElement->r); //find min element in right sub tree(or max in left sub tree)

                    if(minLeftSubTree->parent->data > minLeftSubTree->data){
                        if(minLeftSubTree->r != nullptr)
                            minLeftSubTree->parent->l = minLeftSubTree->r; // if exist right subtree at min element
                        else
                            minLeftSubTree->parent->l = nullptr;
                    }else{
                        if(minLeftSubTree->r != nullptr)
                            minLeftSubTree->parent->r = minLeftSubTree->r; // if exist right subtree at min element
                        else
                            minLeftSubTree->parent->r = nullptr;
                    }
                    minLeftSubTree->l = pElement->l;
                    minLeftSubTree->r = pElement->r;
                    minLeftSubTree->parent = pElement->parent;
                    if(pElement->parent->r == pElement)
                        pElement->parent->r = minLeftSubTree;
                    else
                        pElement->parent->l = minLeftSubTree;

                    if(minLeftSubTree->l != nullptr)
                        minLeftSubTree->l->parent = minLeftSubTree;
                    if(minLeftSubTree->r != nullptr)
                        minLeftSubTree->r->parent = minLeftSubTree;
                    delete pElement;
                }
            }
        }
    }
    void testDelete(int value, element * next)
    {
        if(!isEmpty()){

        }
    }

    element *findMin(){
        return _findMin(root);
    }
    element *_findMin(element *next){
        while(next->l != nullptr){
            next = next->l;
        }
        return next;
    }
};

int main(int argc, char *argv[])
{


    Tree tree;
    tree.push(4);
    tree.push(2);
    tree.push(3);
    tree.push(1);
    tree.push(7);
    tree.push(10);
    tree.push(11);
    tree.push(5);
    tree.push(9);
    tree.push(6);
    std::cout << std::endl;
    tree.showTree();
    std::cout << std::endl;

    tree.removeItem(7);
    tree.showTree();
    std::cout << std::endl;
    tree.removeItem(11);
    tree.showTree();
    std::cout << std::endl;
    tree.removeItem(9);
    tree.showTree();
    std::cout << std::endl;
    tree.removeItem(1);
    tree.showTree();
    std::cout << std::endl;
    return 0;
}
