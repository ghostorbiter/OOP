#ifndef H_StackType
#define H_StackType

#include <iostream>
#include <cassert>
#include "stackADT.h"
using namespace std;


//Definition of the node
template <class T>
struct nodeType
{
    T info;
    nodeType* link;
};

template <class T>
class linkedStack : public stackADT<T>
{
public:
    const linkedStack& operator=(const linkedStack&);
    //Overload the assignment operator.

    bool isEmptyStack() const;
    //Function to determine whether the stack is empty.
    //Postcondition: Returns true if the stack is empty;
    //               otherwise returns false.

    bool isFullStack() const;
    //Function to determine whether the stack is full.
    //Postcondition: Returns false.

    void initializeStack();
    //Function to initialize the stack to an empty state. 
    //Postcondition: The stack elements are removed; 
    //               stackTop = NULL;

    void push(const T& newItem);
    //Function to add newItem to the stack.
    //Precondition: The stack exists and is not full.
    //Postcondition: The stack is changed and newItem 
    //               is added to the top of the stack.

    T top() const;
    //Function to return the top element of the stack.
    //Precondition: The stack exists and is not empty.
    //Postcondition: If the stack is empty, the program 
    //               terminates; otherwise, the top 
    //               element of the stack is returned.

    void pop();
    //Function to remove the top element of the stack.
    //Precondition: The stack exists and is not empty.
    //Postcondition: The stack is changed and the top 
    //               element is removed from the stack.

    linkedStack();
    //Default constructor
    //Postcondition: stackTop = NULL;

    linkedStack(const linkedStack& otherStack);
    //Copy constructor

    ~linkedStack();
    //Destructor
    //Postcondition: All the elements of the stack are 
    //               removed from the stack.

    template <class N>
    friend ostream& operator<<(ostream& out, const linkedStack<N>& ls);
private:
    nodeType<T>* stackTop; //pointer to the stack

    void copyStack(const linkedStack<T>& otherStack);
    //Function to make a copy of otherStack.
    //Postcondition: A copy of otherStack is created and
    //               assigned to this stack.
};

//Implementation
//Default constructor
template <class T>
linkedStack<T>::linkedStack()
{
    stackTop = NULL;
}

template <class T>
bool linkedStack<T>::isEmptyStack() const
{
    return(stackTop == NULL);
} //end isEmptyStack

template <class T>
bool linkedStack<T>::isFullStack() const
{
    return false;
} //end isFullStack

template <class T>
void linkedStack<T>::initializeStack()
{
    nodeType<T>* temp; //pointer to delete the node

    while (stackTop != NULL)  //while there are elements in 
                              //the stack
    {
        temp = stackTop;    //set temp to point to the 
                            //current node
        stackTop = stackTop->link;  //advance stackTop to the
                                    //next node
        delete temp;    //deallocate memory occupied by temp
    }
} //end initializeStack


template <class T>
void linkedStack<T>::push(const T& newElement)
{
    nodeType<T>* newNode;  //pointer to create the new node

    newNode = new nodeType<T>; //create the node

    newNode->info = newElement; //store newElement in the node
    newNode->link = stackTop; //insert newNode before stackTop
    stackTop = newNode;       //set stackTop to point to the 
                              //top node
} //end push


template <class T>
T linkedStack<T>::top() const
{
    assert(stackTop != NULL); //if stack is empty,
                              //terminate the program
    return stackTop->info;    //return the top element 
}//end top

template <class T>
void linkedStack<T>::pop()
{
    nodeType<T>* temp;   //pointer to deallocate memory

    if (stackTop != NULL)
    {
        temp = stackTop;  //set temp to point to the top node

        stackTop = stackTop->link;  //advance stackTop to the 
                                    //next node
        delete temp;    //delete the top node
    }
    else
        cout << "Cannot remove from an empty stack." << endl;
}//end pop

template <class T>
void linkedStack<T>::copyStack(const linkedStack<T>& otherStack)
{
    nodeType<T>* newNode, * current, * last;

    if (stackTop != NULL) //if stack is nonempty, make it empty
        initializeStack();

    if (otherStack.stackTop == NULL)
        stackTop = NULL;
    else
    {
        current = otherStack.stackTop;  //set current to point
                                   //to the stack to be copied

            //copy the stackTop element of the stack 
        stackTop = new nodeType<T>;  //create the node

        stackTop->info = current->info; //copy the info
        stackTop->link = NULL;  //set the link field of the
                                //node to NULL
        last = stackTop;        //set last to point to the node
        current = current->link;    //set current to point to
                                    //the next node

            //copy the remaining stack
        while (current != NULL)
        {
            newNode = new nodeType<T>;

            newNode->info = current->info;
            newNode->link = NULL;
            last->link = newNode;
            last = newNode;
            current = current->link;
        }//end while
    }//end else
} //end copyStack

//copy constructor
template <class T>
linkedStack<T>::linkedStack(
    const linkedStack<T>& otherStack)
{
    stackTop = NULL;
    copyStack(otherStack);
}//end copy constructor

//destructor
template <class T>
linkedStack<T>::~linkedStack()
{
    initializeStack();
}//end destructor

//overloading the assignment operator
template <class T>
const linkedStack<T>& linkedStack<T>::operator=(const linkedStack<T>& otherStack)
{
    if (this != &otherStack) //avoid self-copy
        copyStack(otherStack);

    return *this;
}//end operator=

template <class T>
ostream& operator<<(ostream& out, const linkedStack<T>& ls)
{
    if (ls.isEmptyStack())
        out << "Stack is empty" << endl;
    else {
        nodeType<T>* tmpNode = ls.stackTop;
        while (tmpNode != nullptr)
        {
            out << tmpNode->info << endl;
            tmpNode = tmpNode->link;
        }
    }
    return out;
}

#endif