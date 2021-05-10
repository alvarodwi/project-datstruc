#include "../model/pasien.cpp"
#include <functional>

namespace queue
{

    struct Queue
    {
        pNode head;
        pNode tail;
        int size;
    };

    Queue createQueue()
    {
        Queue q;
        q.head = nullptr;
        q.tail = nullptr;
        q.size = 0;
        return q;
    }

    int size(Queue q) { return q.size; }

    bool isEmpty(Queue q) { return (q.head == nullptr && q.tail == nullptr); }

    Pasien front(Queue q) { return q.head->data; }

    void push(Queue &q, pNode newNode)
    {
        if (isEmpty(q))
        {
            q.head = newNode;
            q.tail = newNode;
        }
        else if (q.head->next == nullptr)
        {
            if (q.head->data.status > newNode->data.status)
            {
                newNode->next = q.head;
                q.head = newNode;
            }
            else
            {
                q.head->next = newNode;
                q.tail = newNode;
            }
        }
        else
        {
            pNode pRev = nullptr;
            pNode pHelp = q.head;
            while (newNode->data.status >= pHelp->data.status)
            {
                if (pHelp->next == nullptr)
                    break;
                pRev = pHelp;
                pHelp = pHelp->next;
            }

            if (pHelp == q.head && newNode->data.status < pHelp->data.status)
            {
                newNode->next = pHelp;
                q.head = newNode;
            }
            else if (pHelp == q.tail && newNode->data.status > pHelp->data.status)
            {
                pHelp->next = newNode;
                q.tail = newNode;
            }
            else if (newNode->data.status < pHelp->data.status)
            {
                pRev->next = newNode;
                newNode->next = pHelp;
            }
            else
            {
                pHelp->next = newNode;
                newNode->next = pHelp->next;
            }
        }
        q.size++;
    }

    pNode pop(Queue &q)
    {
        pNode target;
        if (isEmpty(q))
        {
            target = nullptr;
        }
        else if (q.head->next == nullptr)
        {
            target = q.head;
            q.head = nullptr;
            q.tail = nullptr;
        }
        else
        {
            target = q.head;
            q.head = q.head->next;
            target->next = nullptr;
        }
        q.size--;
        return target;
    }

    pNode findByNama(Queue q, std::string sNama)
    {
        pNode pHelp = q.head;
        while (pHelp != nullptr)
        {
            if (pHelp->data.nama == sNama)
            {
                return pHelp;
            }
            pHelp = pHelp->next;
        }

        return nullptr;
    }

    pNode eraseByNama(Queue &q, std::string sNama)
    {
        pNode pHelp = q.head, pRev = nullptr;
        pNode target = nullptr;

        if (q.head != nullptr && q.head->data.nama == sNama)
        {
            target = pHelp;
            q.head = pHelp->next;
            q.size--;
        }
        else
        {
            while (pHelp != nullptr && pHelp->data.nama != sNama)
            {
                pRev = pHelp;
                pHelp = pHelp->next;
            }

            if (pHelp == nullptr)
                return nullptr;

            target = pHelp;
            pRev->next = pHelp->next;
            q.size--;
        }

        return target;
    }

    int checkIndex(Queue q, pNode target)
    {
        int index = 1;
        pNode pHelp = q.head;
        while (pHelp != nullptr)
        {
            if (pHelp->data.nama == target->data.nama)
            {
                return index;
            }
            pHelp = pHelp->next;
            index++;
        }

        return -1;
    }

    void traversal(Queue q, std::function<void(const Pasien &)> func)
    {
        pNode pHelp = q.head;
        while (pHelp != nullptr)
        {
            func(pHelp->data);
            pHelp = pHelp->next;
        }
    }

} // namespace queue