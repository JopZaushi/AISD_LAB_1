#pragma once
#include <iostream>
using namespace std;

class List {

private:

    class node {
    public:
        int elem = 0;
        node* next;//pointer to the next element
    };
   
    node* head;//pointer to the begin
    node* tail;//pointer to the end

public:

    //Constructor with parameter
    List(int elem) {
        //Filled in by one element
        node* current = new node;
        current->elem = elem;
        head = current;
        tail = current;
    }
    //Constructor without parameter
    List() {
        //Empty list
        head = NULL;
        tail = NULL;
    }
    //Destructor 
    ~List() {
        //Releasing the memory
        node* current = head;
        while (head != NULL) {
            current = head;
            head = head->next;
            delete current;
        }
        tail = head;
    }

    //Inserting an item at the end of a list
    void push_back(int elem) {
        node* current = new node;
        if (head == NULL) {
            current->elem = elem;
            head = current;
            tail = head;
        }
        else {
            current->elem = elem;
            tail->next = current;
            tail = current;
        }
    }
    //Inserting an item at the beginning of a list
    void push_front(int elem) {
        node* current = new node;
        if (head == NULL) {
            current->elem = elem;
            head = current;
            tail = head;
        }
        else {
            current->next = head;
            current->elem = elem;
            tail = head;
            head = current;
        }
    }
    //Deleting the last element
    void pop_back() {
        if (head == NULL) {//Checking an exception
            throw invalid_argument("List is empty");
        }
        else {
            if (head->next == NULL) {
                pop_front();
            }
            else {
                node* current = head;
                while (current->next != NULL) {
                    tail = current;
                    current = current->next;
                }
                tail->next = NULL;
                delete current;
            }
        }
    }
    //Deleting the first element
    void pop_front() {
        if (head == NULL) {//Checking an exception
            throw invalid_argument("List is empty");
        }
        else {
            node* current = head;
            head = head->next;
            delete current;
            if (head == NULL)
                tail = head;
        }
    }
    //Adding an element to the middle of a list
    void insert(int elem, size_t index) {
        if (isEmpty() == true) {
            throw out_of_range("Out of range");
        }
        else {
            if (index > get_size() - 1) {//Checking an exception
                throw out_of_range("Out of range");
            }
            else {
                node* current = head;
                node* dopcurrent = new node;
                dopcurrent->elem = elem;
                for (int i = 0; i < index - 1; i++)
                    current = current->next;
                dopcurrent->next = current->next;
                current->next = dopcurrent;
            }
        }
    }
    //Retrieving an element by index
    int at(size_t index) {
        if (isEmpty() == true) {
            throw out_of_range("Out of range");
        }
        else {
            if (index > get_size() - 1) {//Checking an exception
                throw out_of_range("Out of range");
            }
            else {
                node* current = head;
                for (int i = 0; i < index; i++) {
                    current = current->next;
                }
                return current->elem;
            }
        }
    }
    //Removing an element from the middle of a list
    void remove(size_t index) {
        if (index > get_size() - 1) {//Checking an exception
            throw out_of_range("Out of range");
        }
        else {
            if ((head->next == NULL) || (index == 0)) {
                pop_front();
            }
            else {
                node* current = head;
                node* dopcurrent;
                for (int i = 0; i < index - 1; i++)
                    current = current->next;
                dopcurrent = current->next;
                current->next = dopcurrent->next;
                delete dopcurrent;
            }
        }
    }
    //Getting the size of the list
    size_t get_size() {
        size_t size_list = 0;
        node* current = head;
        while (current != NULL) {
            current = current->next;
            size_list++;
        }
        return size_list;
    }
    //Delete the entire list
    void clear() {
        node* current = head;
        while (head != NULL) {
            current = head;
            head = head->next;
            delete current;
        }
        tail = head;

    }
    //Replacing a list element with another
    void set(size_t index, int elem) {
        if (index > get_size() - 1) {//Checking an exception
            throw out_of_range("Out of range");
        }
        else {
            node* current = head;
            for (int i = 0; i < index; i++)
                current = current->next;
            current->elem = elem;
        }
    }
    //Checking for an empty list
    bool isEmpty() {
        bool empty = false;
        if (head == NULL) {
            empty = true;
        }
        return empty;
    }
    //Inserting a list at the beginning of another
    void push_front(const List& a) {
        node* current = tail;
        node* dopcurrent = a.head;
        while (dopcurrent != NULL) {
            current = new node;
            push_back(dopcurrent->elem);
            dopcurrent = dopcurrent->next;
        }
    }

    // Output of List
    friend ostream& operator << (ostream& stream, const List& list);
};

ostream& operator << (ostream& stream, const List& list)
{
    List::node* current = list.head;
    while (current != NULL) {
        stream << current->elem << " ";
        current = current->next;
    }
    return stream;
}