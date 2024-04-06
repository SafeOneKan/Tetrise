
#include "Headers/Node.hpp"

  template <typename T>
    void NodeList<T>::AddSubList_Col(Colr col)
    {
        
            // Col_sublists = new Col_SubList<T>(col);
        
    }


template <typename T>
    void NodeList<T>::AddLeft(T *object)
    {
         
        if(length > 14) {
        
            return;
        };
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

            if (inused(object->GetColor()) == false) {
                AddSubList_Col(object->GetColor());
                
            }
       
    }

    template <typename T>
    void NodeList<T>::AddRight(T *object)
    {
            if(length >14) {
            return;
            };

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


 template <typename T>
    inline void NodeList<T>::ClearList()
    {
        while(head){
            Node<T> * tmp = head;
            head = head->next;
            delete tmp;
            
        }
        length = 0;
        head = tail = nullptr;
            
        
    }

template <typename T>
    void NodeList<T>::deleteNode(Node<T> *node)
    {       
        if (node == nullptr)
            return;
        
        if (node->prev == nullptr){
            head = node->next;
            head->prev = nullptr;   
        }else if (node->next == nullptr){
            tail = node->prev;
            tail->next = nullptr;
        }
        else {
            node->prev->next = node->next;
            node->next->prev = node->prev;
        }
        
        
        
        this->length = --this->length;
        
        if (isEmpty()){
            this->ClearList();
        }
        
    }

    


   
    template<typename T>
    void SubList<T>::Decaler() {
        if (this->isEmpty() || this->getLength() < 2)
            return; 

        Node<T>* currentNode = this->head;
        Node<T>* lastNode = this->tail;

        // Move the first object to the end
        this->head = this->head->next;
        this->head->prev = nullptr;
        currentNode->prev = lastNode;
        currentNode->next = nullptr;
        lastNode->next = currentNode;
        this->tail = currentNode;
    }


