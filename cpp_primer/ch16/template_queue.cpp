template <typename Type> void Queue<Type>::push(const Type &t)
{
    QueueItem<Type>* item = new QueueItem<Type>(t);
    if(empty()) // empty()�Ѿ��пյ��ж�
        head = tail = item; // Queueû��Ԫ��
    else
    {
        // Queue��Ԫ��,�ڶ�β����
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


