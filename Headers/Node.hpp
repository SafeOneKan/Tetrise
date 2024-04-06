    #pragma once 
    #include <iostream>
    #include "Colr.hpp"
    #include "../SDL/src/include/SDL2/SDL.h"
    #include "../SDL/src/include/SDL2/SDL_image.h"
    #include "../SDL/src/include/SDL2/SDL_ttf.h"
    #include <list>

    using namespace std;

    template <typename T>
    class NodeList;

    template <typename T>
    class Col_SubList;

    template<typename T>
    class Node {
    private:
        T *object;
        Node<T> *next, *prev;

    public:
        friend class NodeList<T>;
        Node<T>(T *object = nullptr) : object(object), next(nullptr), prev(nullptr) {};
        T *getObject() { return object; };
        Node<T> *getnext() { return next; };
        Node<T> *getprev() { return prev; };
    };



    template<typename T>
    class NodeList {
    private:
        Node<T> *head, *tail;
        int length;
        int sublists_count;
        list<Col_SubList<T>> colsub;
        list<Colr> usedColrs;

    public:

        NodeList<T>() : sublists_count(0), length(0), head(nullptr), tail(nullptr) {
            std::cout << "Col_sublists" << std::endl;
        }

        inline bool isEmpty() const { return length == 0; }
        void AddRight(T *object);
        void AddLeft(T *object);
        inline Node<T> *getHead() { return head; };
        inline Node<T> *getTail() { return tail; };
        inline int getLength() { return length; };
        void deleteNode(Node<T> *node);
        void ClearList();
        inline void SetLength(int newLength) { length = newLength; };
        inline void AddSubList_Col(Colr col);
        bool inused(Colr col) {
            for (auto it = usedColrs.begin(); it != usedColrs.end(); ++it) {
                if (col == *it)
                    return true;
            }
            return false;
        };

        void addusedCol(T *object) {
            int i = 0;
            if (inused(object->GetColor()) == false) {

                    usedColrs.push_back(object->GetColor());
                    
                    colsub.push_back(object->GetColor());
                    Col_SubList<T>& lastSubList = colsub.back();
                    lastSubList.AddRight(object);
                    std::cout << "Added   " << std::endl;
                    
                }
                else{
                    for (auto it = colsub.begin(); it != colsub.end(); ++it) {
                        
                        if (it->GetColor() == object->GetColor()){
                            it->AddRight(object);
                            cout << "Added obj" << std::endl;
                        }
                        if (it->GetColor() == Red) {
                            cout << "Count " << it->getLength() << std::endl;
                            
                        }
                    }
                }
                
        }
        Col_SubList<T>* Get_Col_SubList(Colr);
    };

    






    template<typename T>
    class SubList : public NodeList<T> {
    private:
        Type type;

    public:
        SubList(Type tp) : type(tp) {}
        void Decaler();
    };

    template<typename T>
    class Col_SubList : public SubList<T> {
    private:
        Colr color;

    public:
        Col_SubList(Colr clr = Black, Type tp = Type::Colorls) : SubList<T>(tp) {
            color = clr;
        }

        Colr GetColor() const { return color; }

    };











































    template <typename T> Col_SubList<T> *NodeList<T>::Get_Col_SubList(Colr col) {
            for (auto it = colsub.begin(); it != colsub.end(); ++it) {
            if (it->GetColor() == col) {
                return &(*it);
            }
        }
        return nullptr;
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

                
                // for (auto it = usedColrs.begin(); it != usedColrs.end(); ++it) 
                // {
                //    std::cout << "     " << it->r  << std::endl;
                // }
                
        
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

            for (auto& sublist : colsub) {
            sublist.ClearList();
        }
            
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

            delete node->object;
            delete node;
            this->length = --this->length;
            
            if (isEmpty()){
                this->ClearList();
            }
            
        }

        


    
        template<typename T>
        void SubList<T>::Decaler() {
            if (this->isEmpty() || this->getLength() < 2) {
                cout << "Empty sub" << endl;
                return;
                }

        Node<T>* head = this->getHead();
        Node<T>* currentNode = this->getHead();
        Node<T>* lastNode = this->getTail();
       
        // Store the shape of the first node
        Shape firstShape = currentNode->getObject()->GetShape();
        SDL_Texture *firsttex = currentNode->getObject()->GetTexture();
        cout << "First shape: " << firstShape << endl;
        while (currentNode != nullptr && currentNode->getnext() != nullptr) {
            
                currentNode->getObject()->SetShape(currentNode->getnext()->getObject()->GetShape());
                currentNode->getObject()->SetTexture(currentNode->getnext()->getObject()->GetTexture());
                currentNode = currentNode->getnext();
            
            
           
        }

        if(head == currentNode)
            return;

        lastNode->getObject()->SetShape(firstShape);
        lastNode->getObject()->SetTexture(firsttex);
            cout << "Decaled" << endl;
        
        }



    

    














        
        







