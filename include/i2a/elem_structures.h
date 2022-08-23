#ifndef ELEM_STRUCTURES_H
#define ELEM_STRUCTURES_H

#include <iostream>
#include <iterator>
#include <algorithm>

#include <exception>

#define STACK_INIT_SIZE 8
#define QUEUE_INIT_SIZE 8

namespace i2a::structures {

    /*
        STACK
    */
    template<typename T>
    class Stack {

        public:
            Stack() {
                m_size = STACK_INIT_SIZE;
                m_elementss = new T[m_size];
                m_top = -1;
            }

            ~Stack() {
                delete[] m_elementss;
            }

            void push(T element);
            T pop();

            bool is_empty();
            void print();

        private:
            T* m_elementss;
            int m_top;
            int m_size;
    };

    template<typename T>
    bool Stack<T>::is_empty() {
        return m_top == -1;
    }

    template<typename T>
    void Stack<T>::print() {
        for (int i = 0 ; i <= m_top; i++) {
            std::cout << m_elementss[i] << "\n";
        }
    }

    template<typename T>
    void Stack<T>::push(T element) {

        // Need to allocate larger array
        if ((m_top + 1) >= m_size) {
            int old_size = m_size;
            m_size += STACK_INIT_SIZE;
            T* n_elements = new T[m_size];
            std::copy(m_elementss, m_elementss + old_size, n_elements);

            delete[] m_elementss;
            m_elementss = n_elements;
        }

        m_top++;
        m_elementss[m_top] = element;
    }

    template<typename T>
    T Stack<T>::pop() {
        T ret = m_elementss[m_top];
        m_top--;
        return ret;
    }

    /*
        QUEUE
    */
    template<typename T>
    class Queue  {
        public:
            Queue() {
                m_elements = new T[QUEUE_INIT_SIZE];
                m_head = 0;
                m_tail = 0;
                m_size = QUEUE_INIT_SIZE;
            }

            ~Queue() {
                delete[] m_elements;
            }

            void enqueue(T element);
            T dequeue();

            bool is_empty();

        private:
            T* m_elements;
            int m_head;
            int m_tail;
            int m_size;

    };

    template<typename T>
    bool Queue<T>::is_empty() {
        return m_head == m_tail;
    }

    template<typename T>
    void Queue<T>::enqueue(T element) {
        // Need to allocate bigger array
        if (m_tail + 1 >= m_size) {
            int old_size = m_size;
            
            m_size += QUEUE_INIT_SIZE;
            T* n_elements = new T[m_size];

            std::copy(m_elements + m_head, m_elements + m_head + m_tail, n_elements);
            delete[] m_elements;

            m_elements = n_elements;

            m_tail -= m_head;
            m_head = 0;
        }

        m_elements[m_tail] = element;
        m_tail++;
    }

    template<typename T>
    T Queue<T>::dequeue() {
        if (m_head == m_tail) {
            throw std::invalid_argument("[Queue::dequeue]: Empty queue\n");
        } else {
            T elem = m_elements[m_head];
            m_head++;
            return elem;
        }
    }

    /*
        DOUBLE-LINKED LIST
    */
    template<typename T>
    class DLList {
        public:
            struct DLNode {
                struct DLNode* previous;
                struct DLNode* next;
                T key;

                DLNode(T k) {
                    previous = nullptr;
                    next = nullptr;
                    key = k;
                }

                DLNode(int k, struct DLNode* p, struct DLNode* n) {
                    previous = p;
                    next = n;
                    key = k;
                }
            };

            DLList<T>() {
                m_head = nullptr;
            }

            DLList<T>(std::initializer_list<T> list) {

                DLNode* head = nullptr;

                if (list.size() > 0) {
                    head = new DLNode(list.begin()[0]);
                }

                DLNode* tmp = head;

                for(int i = 1; i < list.size(); ++i) {
                    tmp->next = new DLNode(list.begin()[i]);
                    tmp = tmp->next;    
                }

                m_head = head;
            }

            template<typename F>
            void traverse(F& lambda);

            DLNode* search(T key);

        private:
            DLNode* m_head;

    };

    template<typename T>
    template<typename F>
    void DLList<T>::traverse(F& lambda) {
        DLList::DLNode* head_tmp = m_head;

        while (head_tmp != nullptr) {
            lambda(*head_tmp);
            head_tmp = head_tmp->next;
        }
    }

    template<typename T>
    typename DLList<T>::DLNode* DLList<T>::search(T key) {
        DLList<T>::DLNode* tmp = m_head;

        while (tmp != nullptr && tmp->key != key) {
            tmp = tmp->next;
        }

        return tmp;
    }
}

#endif