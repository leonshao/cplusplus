#include "item_derive.h"
#include <stdexcept>
#include <set>
#include <iostream>
using std::cout;
using std::endl;

class Sales_item
{
public:
    Sales_item():p(0), use(new std::size_t(1)) { }
    Sales_item(const Item_base &item):p(item.clone()), use(new std::size_t(1)) { }  // 复制对象(clone), 并初始化引用记数
    Sales_item(const Sales_item &orig):p(orig.p), use(orig.use) { ++*use; } // 指针复制完成后, 增加引用记数
    Sales_item& operator=(const Sales_item &orig);
    ~Sales_item() { decr_use(); }

    const Item_base *operator->() const
        { if(p)return p; else throw std::logic_error("unbound Sales_item"); }
    const Item_base &operator*() const
        { if(p)return *p; else throw std::logic_error("unbound Sales_item"); }
private:
    Item_base *p;
    std::size_t *use;
    void decr_use()     // 析构函数和赋值操作调用的公共函数
        { if(--*use == 0){ delete p; delete use; } }
};

Sales_item& Sales_item::operator=(const Sales_item &orig)
{
    ++*orig.use;
    decr_use();
    p = orig.p;
    use = orig.use;

    return *this;
}

// 用作关联容器multiset的比较函数
inline bool compare(const Sales_item &lhs, const Sales_item &rhs)
{
    return lhs->book() < rhs->book();
}

class Basket
{
    typedef bool (*Comp)(const Sales_item &lhs, const Sales_item &rhs);
public:
    typedef std::multiset<Sales_item, Comp> set_type;
    typedef set_type::size_type size_type;
    typedef set_type::const_iterator const_iter;
    Basket():items(compare){ }
    void add_item(const Sales_item &item){ items.insert(item); }
    size_type size(const Sales_item &item) const { return items.count(item); }

    double total() const;
private:
    std::multiset<Sales_item, Comp> items;
};

double Basket::total() const
{
    double sum = 0.0;
    for(const_iter itr = items.begin(); itr != items.end(); itr = items.upper_bound(*itr))
    {
        sum += (*itr)->net_price(items.count(*itr));
    }
    return sum;
}

int main()
{
    Item_base base_item("aaa", 100);
    Disc_item disc_item("bbb", 200, 0.2, 10, true);
    Bulk_item bulk_item("ccc", 300, 0.3, 5, true);
    Sales_item item1(disc_item);
    Sales_item item2(bulk_item);
    Sales_item item3(item1);
    Sales_item item4(base_item);

    Basket basket;
    basket.add_item(item1);
    basket.add_item(item2);
    basket.add_item(item3);
    basket.add_item(item4);

    cout << "basket size of item1: " << basket.size(item1) << endl;
    cout << "basket total: " << basket.total() << endl;

    return 0;
}
