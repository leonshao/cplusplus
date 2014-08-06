#include <string>
#include <iostream>
#include <utility>
using std::string;
using std::size_t;
using std::cout;
using std::endl;

class Item_base
{
public:
    Item_base(const string &str = "", double item_price = 0.0, bool debug = false): 
        debug_enable(debug), isbn(str), price(item_price){ /* cout << "Item_base()" << endl; */ }
    Item_base(const Item_base &orig):debug_enable(orig.debug_enable), isbn(orig.isbn),
        price(orig.price) { /* cout << "Item_base() copy" << endl; */ }
    Item_base& operator=(const Item_base &orig);

    virtual ~Item_base() { /* cout << "~Item_base()" << endl;*/ }

    string book() const { return isbn; }
    virtual double net_price(size_t count) const { return price; }
    virtual Item_base* clone() const { return new Item_base(*this); }
    virtual void debug() const { if(debug_enable) print_member(); }
    virtual void debug(bool enable) const { if(enable) print_member(); }

    void set_debug(bool debug) { debug_enable = debug; }
    bool get_debug() const { return debug_enable; }
//    string get_isbn() { return isbn; }
//    double get_price() { return price; }
protected:
    void print_member() const
    {
        cout << "Object Member:" << endl;
        cout << "    isbn: " << isbn << endl;
        cout << "    price: " << price << endl;
    }

    bool debug_enable;

private:
    string isbn;
    double price;
};

Item_base& Item_base::operator=(const Item_base &orig)
{
    // cout << "Item_base& operator=()" << endl;
    if (this != &orig)
    {
        isbn = orig.isbn;
        price = orig.price;
        debug_enable = orig.debug_enable;
    }
    return *this;
}

class Disc_item: public Item_base
{
public:
    Disc_item(const string &str = "", double item_price = 0.0,
        double item_discount = 0.0, size_t quantity = 0, bool debug = false):
        Item_base(str, item_price, debug), discount(item_discount), qty(quantity)
    {
      //  cout << "Disc_item()" << endl;
    }
    Disc_item(const Disc_item &orig): Item_base(orig),
        discount(orig.discount), qty(orig.qty) { /* cout << "Disc_item() copy" << endl; */ }
    Disc_item& operator=(const Disc_item &orig);

    std::pair<size_t, double> discount_polocy()
    {
        return std::make_pair(qty, discount);
    }

    virtual double net_price(size_t count) const { return 0; }
    virtual Disc_item* clone() const { return new Disc_item(*this); }
    virtual void debug() const;
    virtual void debug(bool enable) const;

    virtual ~Disc_item() { /* cout << "~Disc_item()" << endl; */ }
protected:
    void print_member() const   // 隐藏了基类的print_member
    {
        cout << "    discount: " << discount << endl;
        cout << "    qty: " << qty << endl;
    }

private:
    double discount;
    size_t qty;
};

Disc_item& Disc_item::operator=(const Disc_item &orig)
{
    // cout << "Disc_item& operator=()" << endl;
    if(this != &orig)
    {
        Item_base::operator=(orig); // ***** 显示调用基类赋值操作 *****
        discount = orig.discount;
        qty = orig.qty;
    }
    return *this;
}

void Disc_item::debug() const
{
    if(debug_enable)
    {
        Item_base::debug(); // 调用基类虚函数需要作用域操作符::
        print_member();     // 由于基类的print_member被隐藏, 此处调用的是派生类的print_member
    }
}

void Disc_item::debug(bool enable) const
{
    if(enable)
    {
        Item_base::debug(enable);
        print_member();
    }
}

class Bulk_item: public Disc_item
{
public:
    Bulk_item(const string &str = "", double item_price = 0.0,
        double item_discount = 0.0, size_t quantity = 0, bool debug = false):
        Disc_item(str, item_price, item_discount, quantity, debug)
    {
        // cout << "Bulk_item()" << endl;
    }

    Bulk_item(const Bulk_item &orig): Disc_item(orig)      // ***** 显示调用基类复制构造 *****
    { 
        // cout << "Bulk_item() copy" << endl; 
    }

    Bulk_item& operator=(const Bulk_item &orig);

    virtual ~Bulk_item() { /* cout << "~Bulk_item()" << endl; */ }

    virtual double net_price(size_t count) { return 0; }
    virtual Bulk_item* clone() const { return new Bulk_item(*this); }

    virtual void debug() const;
    virtual void debug(bool enable) const;
};

Bulk_item& Bulk_item::operator=(const Bulk_item &orig)
{
    // cout << "Bulk_item& operator=()" << endl;
    if(this != &orig)
    {
        Disc_item::operator=(orig); // ***** 显示调用基类赋值操作 *****
    }
    return *this;
}

void Bulk_item::debug() const
{
    if(debug_enable)
    {
        Disc_item::debug(); // 调用基类虚函数需要作用域操作符::
    }
}

void Bulk_item::debug(bool enable) const
{
    if(enable)
    {
        Disc_item::debug(enable);
    }
}
