#include <string>
#include <iostream>
using std::string;
using std::size_t;
using std::cout;
using std::endl;

class Item_base
{
public:
    Item_base(const string &str = "", double item_price = 0.0): 
        isbn(str), price(item_price){ cout << "Item_base()" << endl; }
    Item_base(const Item_base &orig):isbn(orig.isbn), price(orig.price) { cout << "Item_base() copy" << endl; }
    Item_base& operator=(const Item_base &orig);

    virtual ~Item_base() { cout << "~Item_base()" << endl;}

//    string get_isbn() { return isbn; }
//    double get_price() { return price; }
private:
    string isbn;
    double price;
};

Item_base& Item_base::operator=(const Item_base &orig)
{
    cout << "Item_base& operator=()" << endl;
    if (this != &orig)
    {
        isbn = orig.isbn;
        price = orig.price;
    }
    return *this;
}

class Bulk_item: public Item_base
{
public:
    Bulk_item(const string &str = "", double item_price = 0.0,
        double item_discount = 0.0, size_t quantity = 0):
        Item_base(str, item_price), discount(item_discount), qty(quantity)
    {
        cout << "Bulk_item()" << endl;
    }
    Bulk_item(const Bulk_item &orig): Item_base(orig),      // ***** 显示调用基类复制构造 *****
        discount(orig.discount), qty(orig.qty) { cout << "Bulk_item() copy" << endl; }
    Bulk_item& operator=(const Bulk_item &orig);

    virtual ~Bulk_item() { cout << "~Bulk_item()" << endl;}

private:
    double discount;
    size_t qty;
};

Bulk_item& Bulk_item::operator=(const Bulk_item &orig)
{
    cout << "Bulk_item& operator=()" << endl;
    if(this != &orig)
    {
        Item_base::operator=(orig); // ***** 显示调用基类赋值操作 *****
        discount = orig.discount;
        qty = orig.qty;
    }
    return *this;
}

int main()
{
    cout << "基类构造, 析构:" << endl;
    Item_base *ptr = new Item_base;
    delete ptr;
    cout << endl;

    cout << "基类指针指向派生类对象, 析构:" << endl;
    ptr = new Bulk_item;
    delete ptr;
    cout << endl;

    cout << "基类复制控制:" << endl;
    ptr = new Item_base;
    Item_base *ptr2 = new Item_base(*ptr);
    *ptr2 = *ptr;
    delete ptr;
    delete ptr2;
    cout << endl;

    cout << "派生类复制控制:" << endl;
    Bulk_item bulk_item;
    Bulk_item bulk_item2(bulk_item);
    bulk_item2 = bulk_item;

    return 0;
}
