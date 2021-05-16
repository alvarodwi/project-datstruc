#include "../model/pasien.cpp"
#include <functional>

namespace queue
{

    struct Queue
    {
        pNode list;
        int size;
    };

    Queue createQueue()
    {
        Queue q;
        q.list = nullptr;
        q.size = 0;
        return q;
    }

    int size(Queue q) { return q.size; }

    bool isEmpty(Queue q) { return q.list == nullptr; }

    Pasien front(Queue q) { return q.list->data; }

    void push(Queue &q, pNode newNode)
    {
        if (isEmpty(q))
        {
            q.list = newNode;
        }
        else if (q.list->next == nullptr)
        {
            if (q.list->data.status > newNode->data.status)
            {
                newNode->next = q.list;
                q.list->prev = newNode;
                q.list = newNode;
            }
            else
            {
                q.list->next = newNode;
                newNode->prev = q.list;
            }
        }
        else
        {
            pNode pHelp = q.list;
            while (newNode->data.status >= pHelp->data.status)
            {
                if (pHelp->next == nullptr)
                    break;
                pHelp = pHelp->next;
            }

            if (pHelp == q.list && newNode->data.status < pHelp->data.status)
            {
                newNode->next = q.list;
                q.list->prev = newNode;
                q.list = newNode;
            }
            else
            {
                if (newNode->data.status < pHelp->data.status)
                {
                    pHelp->prev->next = newNode;
                    newNode->prev = pHelp->prev;
                    newNode->next = pHelp;
                    pHelp->prev = newNode;
                }
                else
                {
                    pHelp->next = newNode;
                    newNode->prev = pHelp;
                }
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
        else if (q.list->next == nullptr)
        {
            target = q.list;
            q.list = nullptr;
        }
        else
        {
            target = q.list;
            q.list = q.list->next;
            q.list->prev = nullptr;
            target->next = nullptr;
        }
        q.size--;
        return target;
    }

    pNode findByNama(Queue q, std::string sNama)
    {
        pNode pHelp = q.list;
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

    void eraseByNama(Queue &q, std::string sNama)
    {
        pNode pHelp = q.list, pRev = nullptr;
        pNode target = nullptr;

        if (q.list != nullptr && q.list->data.nama == sNama)
        {
            target = q.list;
            if (q.list->next != nullptr)
            {
                q.list = q.list->next;
            }
            else
            {
                q.list = nullptr;
            }
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
                return;

            target = pHelp;
            pRev->next = pHelp->next;
            q.size--;
        }

        delete target;
    }

    int checkIndex(Queue q, pNode target)
    {
        int index = 1;
        pNode pHelp = q.list;
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
        pNode pHelp = q.list;
        while (pHelp != nullptr)
        {
            func(pHelp->data);
            pHelp = pHelp->next;
        }
    }

} // namespace queue