#include "item_derive.h"
#include <vector>
using std::vector;

int main()
{
    vector<Item_base*> basket;
    Item_base item("aaa", 100);
    Bulk_item bulk_item("bbb", 200, 0.2, 10);
    
    basket.push_back(&item);
    basket.push_back(&bulk_item);

    double sum = 0;
    vector<Item_base*>::iterator itr;
    for(itr = basket.begin(); itr != basket.end(); ++itr)
    {
        sum += (*itr)->net_price();    // bulk_item����Ӧ�÷���0, �������ڱ��г�Item_base����, ������Item_base�汾��net_price, ����200; Ԫ�����͸ĳ�Item_base*��, ����net_price���麯��, ��̬��������, bulk_item�����net_price������
    }

    cout << "sum: " << sum << endl;
}
