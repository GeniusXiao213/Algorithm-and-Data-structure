#pragma once

#include <iostream>
#include <sstream>
#include <ostream>
#include <exception>
#include <functional>

using namespace std;

template <typename Key, typename Info>
class Ring {
    private:
        struct node{
            Key key;
            Info info;
            node* m_next;
            node* m_prev;

            node(const Key& key, const Info& info, node* next = nullptr, node* prev = nullptr)
                : key(key), info(info), m_next(next), m_prev(prev) {};
            ~node() {};

            node& operator=(node& el){
                this->key = el->key;
                this->info = el->info;
                this->m_next = el->m_next;
                this->m_prev = el->m_prev;
            };
            bool operator==(node& el){
                return this->key == el.key
                    && this->info == el.info
                    && this->m_next == el.m_next
                    && this->m_prev == el.m_prev;
            };
            bool operator!=(node& el){
                return !(*this == el);
            };

            void print() const {
                cout << this->key << " " << this->info << endl;
            };

            Key get_key(){
                return key;
            };
            Info get_info(){
                return info;
            };
        };
        node* head;
        unsigned int m_length;

    public:
        class iterator{
            private:
                node* itr;
                friend class Ring;
            public:
                iterator(node* b): itr(b){};
                iterator(): itr(nullptr){};
                iterator(const Key&key,const Info& info)
                {
                    node newNode=new node(key,info);
                    itr=newNode;
                }
                ~iterator(){
                };

                bool is_nullptr(){
                    return itr == nullptr;
                };
                iterator& next(){
                    if(itr != nullptr) itr = itr->m_next;
                    return *this;
                };
                iterator& prev(){
                    if(itr != nullptr) itr = itr->m_prev;
                    return *this;
                };
                iterator& operator++(){
                    return this->next();
                };
                iterator& operator--(){
                    return this->prev();
                };
                friend bool operator==(const iterator& lhs, const iterator& rhs){
                    return lhs.itr == rhs.itr;
                };
                friend bool operator!=(const iterator& lhs, const iterator& rhs){
                    return lhs.itr != rhs.itr;
                };
                node* operator*() const{
                    return this->itr;
                };
                node* operator->() const{
                    return this->itr;
                };
        };
        class const_iterator{
            private:
                const node* itr;
                friend class Ring;
            public:
                const_iterator(const node* b): itr(b){};
                const_iterator(): itr(nullptr){};
                ~const_iterator(){
                };

                bool is_nullptr() const{
                    return itr == nullptr;
                };
                const_iterator& next(){
                    if(itr != nullptr) itr = itr->m_next;
                    return *this;
                };
                const_iterator& prev(){
                    if(itr != nullptr) itr = itr->m_prev;
                    return *this;
                };
                const_iterator& operator++(){
                    return this->next();
                };
                const_iterator& operator--(){
                    return this->prev();
                };
                friend bool operator==(const const_iterator& lhs, const const_iterator& rhs){
                    return lhs.itr == rhs.itr;
                };
                friend bool operator!=(const const_iterator& lhs, const const_iterator& rhs){
                    return lhs.itr != rhs.itr;
                };
                node* operator*() const{
                    return this->itr;
                };
                node* operator->() const{
                    return this->itr;
                };
        };
        Ring(): head(nullptr), m_length(0) {
        };
        Ring(const Ring& src) : head(nullptr), m_length(0) {
            *this = src;
        };
        
        ~Ring(){
            this->clear();
        };

        Ring& operator=(const Ring& src){
            this->clear();
            Ring<Key, Info>::iterator i = src.begin();
            do{
                this->push_back(i->get_key(), i->get_info());
                ++i;
            }while(i != this->begin());
            this->m_length = src.size();
            return *this;
        };

        bool operator==(const Ring& src){
            /*
                checks if two lists are equal i.e.,
                the value of key and info of the corresponding
                elements in both the lists are equal
                (Mathematical definition:
                for all k1_j, i1_j in this Ring
                    and k2_j, i2_j in src Ring
                    k1_i = k2_i and i1_j == i2_j)
            */
            if(this->size() != src.size()) return false;
            else if(this->size() == 0) return true;
            Ring<Key, Info>::iterator i = src.begin(), j = this->begin();
            do{
                if(i->key != j->key || i->info != j->info)
                    return false;
                ++i;
                ++j;
            }while(j != this->begin());
            return true;
        };

        bool operator!=(const Ring& src){
            return !(*this == src);
        }

        bool is_empty() const{
            
            return this->m_length == 0;
        };
        unsigned int size() const{
            
            return this->m_length;
        };

        iterator begin() const{
            
            return iterator(this->head);
        };

        iterator end() const{
            if(this->is_empty()) return iterator();
            return iterator(this->head->m_prev);
        };
        const_iterator cbegin() const{
            return const_iterator(this->head);
        };
        const_iterator cend() const{
            if(this->is_empty()) return iterator();
            return const_iterator(this->head->m_prev);
        };
        void print() const{
           
            if (this->is_empty()){
                cout << "This list is empty." << endl;
                return;
            }
            Ring<Key, Info>::iterator i = this->begin();
            do{
                cout << i->key << " " << i->info << endl;
                ++i;
            }while(i != this->begin());
        };
        void clear(){
            /*
                deallocates all the memory occupied by the
                elements of the list
            */
            while(!this->is_empty())
                this->pop_front();
        };

        template <typename K, typename I>
        friend ostream& operator<<(ostream& os, Ring<K, I>& B);

        iterator push_front(const Key& key, const Info& info){
            /*
                adds a new element with key and info in
                the beginning of the Ring; sets the
                head to the inserted element
            */
            return this->insert_before(this->begin(), key, info);
        };
        iterator pop_front(){
            /*
                removes the first element;
                returns iterator pointing to the next node
            */
            return this->erase(this->begin());
        };

        iterator push_back(const Key& key, const Info& info){
            /*
                adds a new element with key and info in
                the end of the Ring; doesn't sets the
                head to the inserted element
            */
            return this->insert_after(this->end(), key, info);
        };
        iterator pop_back(){
            /*
                removes the last element
                returns iterator pointing to the next node
            */
            return this->erase(this->end());
        };

        iterator insert_before(iterator position, const Key& key, const Info& info){
            /*
                inserts a new element with key and info
                before the position; if position is nullptr,
                the new element is pushed front (first element);
                returns an iterator pointing to the inserted
                node
            */
            if(this->is_empty()){
                this->head = new node(key, info);
                this->head->m_prev = this->head;
                this->head->m_next = this->head;
                this->m_length = 1;
                return iterator(this->head);
            }
            if(position.is_nullptr())
                position = this->begin();
            node* temp = position->m_prev;
            position->m_prev = new node(key, info, *position, temp);
            temp->m_next = position->m_prev;
            if(*position == this->head)
                this->head = position->m_prev;
            this->m_length++;
            return iterator(position->m_prev);
        };

        iterator insert_after(iterator position, const Key& key, const Info& info){
            /*
                inserts a new element with key and info
                after the position; returns an iterator
                pointing to the inserted node
            */
            if(*position == nullptr){
                this->head = new node(key, info);
                this->head->m_prev = this->head;
                this->head->m_next = this->head;
                this->m_length = 1;
                return iterator(this->head);
            }
            node* temp = position->m_next;
            position->m_next = new node(key, info, temp, *position);
            temp->m_prev = position->m_next;
            this->m_length++;
            return iterator(position->m_next);
        };

        iterator erase(iterator position){
            /*
                deletes the element pointed by the
                position iterator; returns and iterator
                pointing to the next element in the list
            */
            if(position.is_nullptr()) throw invalid_argument("Invalid Argument.");
            position->m_prev->m_next = position->m_next;
            position->m_next->m_prev = position->m_prev;
            node* temp = position->m_next;
            if(*position == this->head)
                this->head = temp;
            delete *position;
            this->m_length--;
            return iterator(temp);
        };

};

template <typename K, typename I>
ostream& operator<<(ostream& os, Ring<K, I>& B){
    /*
        operator overloading; prints the list
    */
        if (B.is_empty()){
            os << "This list is empty." << endl;
            return os;
        }
        typename Ring<K, I>::iterator i = B.begin();
        do{
            os << i->get_key() << " " << i->get_info() << endl;
            ++i;
        }while(i != B.begin());
        return os;
};

template<typename Key,typename Info>
void split(const Ring<Key,Info> &source,Ring<Key,Info> &result1,int seq1,int repeat1,Ring<Key,Info> &result2,
int seq2,int repeat2)
{
    typename Ring<Key,Info>::const_iterator iterSource=source.cbegin();
    typename Ring<Key,Info>::const_iterator iterRes1=result1.cbegin();
    typename Ring<Key,Info>::const_iterator iterRes2=result2.cbegin();
    
    if(*iterSource==nullptr)return;
    if(*iterRes1!=nullptr||*iterRes2!=nullptr)
    {
        result1.clear();
        result2.clear();
    }
    while(repeat1+repeat2!=0)
    {
        if(repeat1!=0)
        {
            for(int i =seq1;i!=0;i--){
                result1.push_back(iterSource);
                iterSource++;
            }
            repeat1--;
        }
        if(repeat2!=0){
            for(int i =seq2;i!=0;i--){
                result2.push_back(iterSource);
                iterSource++;
            }
            repeat2--;
        }
        
    }
}