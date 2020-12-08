#include "slist.h"
#include <stdlib.h> 

class Node {
    public:
        int data;
        Node* next;
        Node (int value) {
            data = value;
            next = nullptr;
        }
};

class slist{
    private:
        Node* HEAD;
        int length;
    public:
        slist () {
            HEAD = nullptr;
        }
        ~slist () {
            Node* last;
            Node* nextNode = HEAD;
            for (int i = 0; i < size(); i++) {
                last = nextNode;
                nextNode = nextNode->next;
                free(last);
            }
            free(HEAD);
            free(&length);
        }

        //Adds a new value to the end of this list.
        void add (int value) {
            Node* nextNode = HEAD;
            Node* newNode = new Node(value);
            for (int i = 0; i < size(); i++) {
                nextNode = nextNode->next;
            }
            nextNode->next = newNode;
        }
        //Removes all elements from this list.
        void clear () {
            Node* last;
            Node* nextNode = HEAD;
            for (int i = 0; i < size(); i++) {
                last = nextNode;
                nextNode = nextNode->next;
                free(last);
            }
            HEAD = nullptr;
        }
        //Returns true if the two lists contain the same elements in the same order.
        bool equals(slist olist) {

        }
    // get(index)				//Returns the element at the specified index in this list.

    // insert(index, value)		//Inserts the element into this list before the specified index.

    // exchg(index1, index2)	//Switches the payload data of specified indexex.

    // swap(index1,index2)		//Swaps node located at index1 with node at index2

    // isEmpty()				//Returns true if this list contains no elements.

    // remove(index)			//Removes the element at the specified index from this list.

    // set(index, value)		//Replaces the element at the specified index in this list with a new value.

    // size()					//Returns the number of elements in this list.
        int size () {
            Node* nextNode = HEAD;
            int size = 0;
            while (nextNode->next != nullptr) {
                nextNode = nextNode->next;
                size++;
            }
            return size;
        }

    // subList(start, length)	//Returns a new list containing elements from a sub-range of this list.

    // toString()				//Converts the list to a printable string representation.

};