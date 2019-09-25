#ifndef SELF_LIST_H
#define SELF_LIST_H

#include "node.h"

template <typename T>
class SelfList {
    public: 
        enum Method {
            Move, Count, Transpose
        };

    protected:
        Node<T>* head;
        Method method;

    public:
        SelfList(Method method) : head(nullptr), method(method){};

        void insert(T data) {
            // TODO
            Node<T> **temp = &(this->head);
            Node<T> *nuevo = new Node<T>(data);
            while((*temp)!=nullptr){
                temp = &((*temp)->next);
            }
            *temp = nuevo;
        
            // Te faltó cambiar el return bool to void


        }
             
        bool remove(T data) {
            // TODO
            Node<T> **temp = &(this->head);
            while((*temp)!=nullptr){
                if((*temp)->data == data){
                    Node<T> *borrar = *temp;
                    *temp = (*temp)->next;
                    delete borrar;
                    return true;
                }
                temp = &((*temp)->next);
            }
            return false;
        }  

        bool find(T data) {
            // TODO
            Node<T> *current = this->head;

            switch(this->method){
                case Move:
                // Podrías tener métodos privados para cada case
                    while((current)!=nullptr){
                        if(current->data == data){
                            if((this->method) == Move){
                                T temp_data = (this->head)->data;
                                ((this->head)->data)=current->data;
                                current->data = temp_data;
                            }
                            return true;
                        }
                        current = current->next;
                    }
                    return false;

                    break;

                case Count:
                    
                    while((current)!=nullptr){
                        
                        if(current->data == data){
                            current->query++;
                            int size = this->size();
                            for(int i=0;i<size;i++){
                                Node<T> *move = this->head;
                                for(int j=0;j<size - i -1 ; j++){
                                    if(move->query < move->next->query){
                                        T current_data = move->data;
                                        int current_query = move->query;
                                        move->data = (move->next)->data;
                                        move->query = (move->next)->query;
                                        (move->next)->data = current_data;
                                        (move->next)->query = current_query;
                                    }
                                    move = move->next;
                                }       
                            }
                            return true;
                        }
                        current = current->next;
                    }
                    return false;

                    break;

                case Transpose:
                    

                    while((current->next) != nullptr){
                        if((current->next)->data == data){
                            T current_data = current->data;
                            current->data = (current->next)->data;
                            (current->next)->data = current_data;
                            return true;
                        }
                        current = current->next;
                    }
                    return false;

                    

            }

          
                
                

        }

        T operator [] (int index) {
            // TODO
            if(index < 0) throw out_of_range("Index is less  than 0");
            Node<T>**temp = &(this->head);
            for(int i=0; i<index;i++){
                if(*temp == nullptr) throw out_of_range("Indes is bigger than actualy size");
                temp = &((*temp)->next);
            }

            return (*temp)->data;


        }
             
        int size() {
            // TODO
            int size = 0;
            Node<T> **temp = &(this->head);

            while(*temp!=nullptr){
                temp = &((*temp)->next);
                size++;
            }
            return size;

        }

        void print() {
            // TODO
            Node<T> **temp = &(this->head);
            while(*temp!=nullptr){
                std::cout<<(*temp)->data<<" - ";
                temp = &((*temp)->next); 
            }
            std::cout<<std::endl;
        }

        ~SelfList() {
            // TODO
            if(this->head){
                this->head->killSelf();
            }

        }  
};

#endif