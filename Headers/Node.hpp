#pragma once 



template <typename T>
class Node;

template<typename T>
class NodeList {
    private:
        Node<T> *head, *tail;
        int length;
    public :
    NodeList<T>() : length(0) , head(nullptr) , tail(nullptr) {}

    bool isEmpty() const { return length == 0; }
    void AddRight(T *object);
    void AddLeft(T *object);
    Node<T> *getHead() { return head; };
    Node<T> *getTail() { return tail; };
    int getLength() { return length; };
};

template<typename T>
class Node {
    private:
        T *object;
        Node<T> *next, *prev;

    public:
        friend class NodeList<T>;
        Node<T>(T *object = nullptr) : object(object) , next(nullptr), prev(nullptr) {};
        T *getObject() { return object; };
        Node<T> *getnext() { return next; };
        Node<T> *getprev() { return prev; };
        
};



template <typename T>
void NodeList<T>::AddLeft(T *object)
{
    if(length >7) return;
        Node<T> *node = new Node<T>(object);
        if (isEmpty()){
            head = tail = node;
            
        }
        else {
            node->next = head;
            head->prev = node;
            head = node;
        }
        length++;
}

template <typename T>
void NodeList<T>::AddRight(T *object)
{
        if(length >7) return;
        Node<T> *node = new Node<T>(object);
        if (isEmpty()){
            head = tail = node;
        }
        else {
            node->prev = tail;
            tail->next = node;
            tail = node;
        }
        length++;
}
