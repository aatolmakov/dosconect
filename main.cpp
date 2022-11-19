#include <bits/stdc++.h>
using namespace std;
template <typename T>
struct node{
    T data = 0;
    node* next;
    node* prev;
    node(T x){
        data = x;
        next = nullptr;
        prev = nullptr;
    }
};
template <typename T>
class dosconecto{
    node<T>* head;
public:
    dosconecto(){
        head = nullptr;
    }
    bool emptycheck();
    void add_begin(T x);
    void add_end(T x);
    void add_before(node<T>* temp, T x);
    void pop_front();
    void pop_back();
    void delete_before(node<T>* temp);
    void move_cursor(node<T>* temp, char);    //если l - влево, если r - вправо
    template<typename T2>
    friend ostream& operator<<(ostream& out, const dosconecto<T2>);

};

template <typename T>
void dosconecto<T>::add_begin(T x) {
    node<T>* temp = new node<T>(x);
    if(!head){
        head = temp;
        head -> data = x;
    } else {
        temp -> next = head;
        head -> prev = temp;
        head = temp;
    }
}
template <typename T>
void dosconecto<T>::add_end(T x) {
    node<T>* temp = new node<T>(x);
    node<T>* t = head;
    while(t -> next){
        t = t -> next;
    }
    t -> next = temp;
    temp -> prev = t;
}

template <typename T>
bool dosconecto<T>::emptycheck(){
    return head == nullptr;
}

template <typename T>
void dosconecto<T>::add_before(node<T> *temp, T x) {
    node<T>* t = head;
    while(t -> next != temp){
        t = t -> next;
    }
    node<T>* new_elem = new node<T>(x);
    new_elem -> next = t -> next;
    t -> next -> prev = new_elem;
    t -> next = new_elem;
    new_elem -> prev = t;
}

template <typename T>
void dosconecto<T>::pop_front() {
    if(!head){
        throw string("its empty");
    } else if(!head -> next){
        node<T>* temp = head;
        delete temp;
        head = nullptr;
    } else{
        node<T>* temp = head;
        head = head -> next;
        head -> prev = nullptr;
        delete temp;
    }
}

template <typename T>
void dosconecto<T>::pop_back() {
    if(!head){
        throw string("its empty");
    } else if(head -> next){
        node<T>* temp = head;
        while(temp -> next -> next){
            temp = temp -> next;
        }
        node<T>* to_delete = temp -> next;
        temp -> next = nullptr;
        delete to_delete;
    } else{
        node<T>* temp = head;
        delete temp;
        head = nullptr;
    }
}

template<typename T>
void dosconecto<T>::delete_before(node<T> *temp) {
    node<T>* t = head;
    while(t -> next -> next != temp){
        t = t -> next;
    }
    node<T>* to_delete = t -> next;
    delete to_delete;
    t -> next = temp;
    t -> next -> prev = t;
}

template <typename T>
void dosconecto<T>::move_cursor(node<T>* temp, char a) {
    if(a == 'l'){
        if(!temp -> prev){
            throw string("nowhere to move");
        } else{
            temp = temp -> prev;
        }
    } else{
        if(!temp -> next){
            throw string("nowhere to move");
        } else{
            temp = temp -> next;
        }
    }
}

template<typename T>
ostream& operator<<(ostream& out, const dosconecto<T> List){
    node<T>* ptr = List.head;
    while(ptr){
        out << ptr -> data << ' ';
        ptr = ptr -> next;
    }
    return out;
}
int main(){
    //tests;
}
