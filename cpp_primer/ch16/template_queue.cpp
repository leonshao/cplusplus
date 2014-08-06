template <typename Type> void Queue<Type>::push(const Type &t)
{
    QueueItem<Type>* item = new QueueItem<Type>(t);
    if(empty()) // empty()已经有空的判断
        head = tail = item; // Queue没有元素
    else
    {
        // Queue有元素,在队尾插入
        tail->next = item;
        tail = item;
    }
}

template <typename Type> void Queue<Type>::pop()
{
    QueueItem<Type>* p = head;
    head = head->next;
    delete p;
}

template <typename Type> template <typename Iter>
void Queue<Type>::assign(Iter beg, Iter end)
{
}

template <typename Type> void Queue<Type>::copy_elems(const Queue<Type> &q)
{
    
}

template <typename Type> template <typename Iter>
void Queue<Type>::copy_elems(Iter beg, Iter end)
{
}


