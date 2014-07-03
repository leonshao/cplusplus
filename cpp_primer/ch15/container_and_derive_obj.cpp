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
        sum += (*itr)->net_price();    // bulk_item对象应该返回0, 但是由于被切成Item_base对象, 调用了Item_base版本的net_price, 返回200; 元素类型改成Item_base*后, 由于net_price是虚函数, 动态绑定起作用, bulk_item对象的net_price被调用
    }

    cout << "sum: " << sum << endl;
}
