#include "common_include.h"
using std::ostream;

template <typename Type> class Queue;

// 重载运算符<<, 用于输出Queue对象
template <typename T> ostream& operator<<(ostream&, const Queue<T>&);

// Queue元素的类模板
template <typename Type> class QueueItem
{
    friend class Queue<Type>;
    // 注意函数的声明加上实例化的<Type>
    friend ostream& operator<< <Type> (ostream&, const Queue<Type>&);

    QueueItem(const Type &t):item(t), next(0){ }
    Type item;
    QueueItem* next;
};

template <typename Type> class Queue
{
    friend ostream& operator<< <Type> (ostream&, const Queue<Type>&);

public:
    Queue(): head(0), tail(0){ }
    // 从已有的其他序列容器复制构造
    template <typename It> Queue(It beg, It end): head(0), tail(0){ copy_elems(beg, end); }
    // 从已有的Queue对象复制构造
    Queue(const Queue<Type> &q): head(0), tail(0){ copy_elems(q); }
    ~Queue(){ destroy(); }

    // 从已有的其他序列容器复制, 并覆盖掉原来Queue的内容
    template <typename Iter> void assign(Iter, Iter);
    Type& front(){ return head->item; }
    const Type& front() const { return head->item; }
    void push(const Type&);
    void pop();
    bool empty() { return head == 0; }

private:
    QueueItem<Type>* head;
    QueueItem<Type>* tail;

    void copy_elems(const Queue<Type>&);
    template <typename Iter> void copy_elems(Iter, Iter);
    void destroy();
};

#include "template_queue.cpp"
