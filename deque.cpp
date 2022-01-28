/*
deque двустронняя очередь
deque с ограниченным входом и ограпниченным выходом
стуктура удаления добавления даннх с двух сторон
организация с помощью дминамического массива или двухсвязного списка
*/

#include <deque>

int main()
{
	deque<int> dqu;
    qDebug()<<sizeof(dqu);
    for (int i = 0; i < 160; ++i) {
        dqu.push_back(i);
    }
    qDebug()<<dqu.at(10);
    qDebug()<<dqu[10];
	
	return 0;
}