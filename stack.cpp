/*
data structure - stack адаптер
language - c, c++
std::stack может быть инициализирован другим объектом stack или совместимыми контейнерами последовательностей, такими как deque,vector и list.(по умолчанию deque)
Однако  контейнер по умолчанию используемый для хранения элементов stack, - это deque

*/




#include <stack>




int main()
{
    /* --------создание и заполнение stack-------- */
    stack<int,list<int>> s;   /* Объявляем стек с указанием контейнера который лежит в основе*/
    s.push(1);                 /* метод push создает  копию элемента и переносит  ее в стек */
    s.emplace(4);              /* метод emplace создает элемент  неповсредственно в коллекции(в стеке), без копирования и  перемещения. т.о. пыволняется быстрее.
    
    /* --------печать -----------------------------*/
    print_from_while(s);

      
      
      
      
      
      return 0;
}

/* обычная функция печати через цикл while */
void print_from_while( std::stack<int,std::list<int>>  s)
{
    while(!s.empty())
    {
        std::cout << s.top()<<" ";
        s.pop();
    }
    std::cout << std::endl;
}

/* функция печати через внутренний контейнет  */
template < typename T >
void print_from_inner_container( const std::stack<T>& stk )
{
    struct cheat : std::stack<T>                            /* определение нового класса стек через наследование   */
    {
        using std::stack<T>::c;                             /* метод доступа к внутреннему контейнеру */ 
    } ;
    const auto& seq = static_cast< const cheat& >(stk).c;  /* получение внутреннего контейнера */

    for( const auto& v : seq )                              /* обычная печать через контейнера */
        std::cout << v << ' ' ;
        
    std::cout << '\n' ;
}
