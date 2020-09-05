#include <stddef.h>

namespace algorithms { namespace common {

template<typename T>
struct Node {
    Node()
        : mNext(NULL)
    { }

    Node(const T& value)
        : mValue(value)
        , mNext(NULL)
    { }

    T mValue;
    
    Node* mNext;
};

template<typename T>
class Iterator {
public:
    Iterator(Node<T>* node)
        : mNode(node)
    { }

    bool operator==(const Iterator& other) const
    {
        if(this == &other)
            return true;

        return mNode == other.mNode;
    }

    bool operator!=(const Iterator& other) const
    {
        return !operator==(other);
    }

    T operator*() const
    {
        if(mNode) 
            return mNode->mValue;
        return T();
    }

    void operator++()
    {
        if(mNode)
            mNode = mNode->mNext;
    }

private:
    Node<T>* mNode;
};

template<typename T>
class LinkedList {
public:
    LinkedList()
        : mHead(NULL)
    { }

    void append(const T& t)
    {
        if(Node<T>* node = new Node<T>(t))
        {
            node->mNext = mHead;
            mHead = node;
        }
    }
    
    void remove()
    {
        if(mHead)
        {
            Node<T>* newHead = mHead->mNext;

            delete mHead;

            mHead = newHead;
        }
    }
    
    T head() const
    {
        return mHead->mValue;
    }

    Iterator<T> begin() const
    {
        return Iterator<T>(mHead);
    }
    
    Iterator<T> end() const
    {
        return Iterator<T>(NULL);
    }

    int size() const
    {
        int s = 0;
        for(Iterator<T> it = begin(); it != end(); ++it)
            ++s;

        return s;
    }

    ~LinkedList()
    {
        while(mHead)
            remove();
    }

private:
    Node<T>* mHead;
};

} } // algorithms::common
