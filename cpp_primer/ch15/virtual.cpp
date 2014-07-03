#include "item_derive.h"
int main()
{
    Disc_item item("bbb", 200, 0.2, 10, true);
    item.debug();

    Bulk_item bulk_item("ccc", 300, 0.3, 5, true);
    bulk_item.debug(true);

    return 0;
}
