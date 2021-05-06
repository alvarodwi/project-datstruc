#include "../model/pasien.cpp"

namespace stack
{

    typedef pNode Stack;

    pNode createStack()
    {
        Stack top = new Node;
        top = nullptr;
        return top;
    }

    Pasien peek(Stack s) { return s->data; }

    bool isEmpty(Stack s) { return s == nullptr; }

    void push(Stack &s, pNode newNode)
    {
        if (isEmpty(s))
        {
            s = newNode;
        }
        else
        {
            newNode->next = s;
            s = newNode;
        }
    }

    pNode pop(Stack &s)
    {
        pNode target;
        if (isEmpty(s))
        {
            target = nullptr;
        }
        else if (s->next == nullptr)
        {
            target = s;
            s = nullptr;
        }
        else
        {
            target = s;
            s = s->next;
            s->next = nullptr;
        }
        return target;
    }

    void clearStack(Stack &s){
        while(!isEmpty(s)){
            pNode pDelete = pop(s);
            delete pDelete;
        }
    }

} // namespace stack