#include "common_include.h"
using std::ostream;

template <typename Type> class Queue;

// ���������<<, �������Queue����
template <typename T> ostream& operator<<(ostream&, const Queue<T>&);

// QueueԪ�ص���ģ��
template <typename Type> class QueueItem
{
    friend class Queue<Type>;
    // ע�⺯������������ʵ������<Type>
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
    // �����е����������������ƹ���
    template <typename It> Queue(It beg, It end): head(0), tail(0){ copy_elems(beg, end); }
    // �����е�Queue�����ƹ���
    Queue(const Queue<Type> &q): head(0), tail(0){ copy_elems(q); }
    ~Queue(){ destroy(); }

    // �����е�����������������, �����ǵ�ԭ��Queue������
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
