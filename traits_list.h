#ifndef TRAITS_LIST_H
#define TRAITS_LIST_H

#include "node.h"

template <typename Tr>
class TraitsList {     
    public:
        typedef typename Tr::T T;
        typedef typename Tr::Operation Operation;
      
    private:
        Node<T>* head;
        Operation cmp;

        bool find(T data, Node<T> **&pointer) {
            // TODO

            while(((*pointer)!=nullptr) and (!cmp(data,(*pointer)->data))){
                pointer = &((*pointer)->next);

            }
    
            return (*pointer != nullptr);
        }
              
    public:
        TraitsList() : head(nullptr) {};
             
        bool insert(T data) {
            // TODO

            Node<T> *nuevo = new Node<T>(data);
            Node<T> **temp = &this->head;
            
 
            if(find(data, temp) and (*temp)->data){
                return false;
            }
            nuevo->next = *temp;
            *temp = nuevo;
            return true;
            
            
        }
             
        bool remove(T data) {
            // TODO
            Node<T> **temp = &this->head;
            Node<T> *borrar = nullptr;

            if(find(data,temp)){
                borrar = *temp;
                (*temp) = (*temp)->next;
                delete borrar;
            }
            return false;
        }  

        bool find(T data) {
            // TODO
            
            Node<T> **temp = &this->head;
            return find(data,temp);

            
        }

        T operator [] (int index) {
            // TODO
            Node<T> **temp = &(this->head);
            if(index<0) throw out_of_range("Index is less than 0");

            for(int i=0;i<index;i++){
                if((*temp)==nullptr) throw out_of_range("Index bigger than actualy size");
                temp = &((*temp)->next);
            }
            return (*temp)->data;
        }
             
        int size() {
            // TODO
            int cont=0;
            Node<T> **temp = &(this->head);
            while(*temp!=nullptr){
                temp = &((*temp)->next);
                cont++;
            }
            return cont;
        }

        void print() {
            // TODO
            Node<T> **temp = &(this->head);
            while((*temp)!=nullptr){
                std::cout<<(*temp)->data<<" - ";
                temp = &((*temp)->next);
            }
            std::cout<<std::endl;
        }

        ~TraitsList() {
            // TODO
            if(this->head){
                this->head->killSelf();
            }
        }         
};

#endif