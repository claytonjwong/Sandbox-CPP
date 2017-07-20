/*
 
 Image a (literal) stack of plates.  If the stack gets too high, it might topple.  Therefore, in real life, we would likely start a new stack when the previous stack exceeds some threshold.  Implement a data structure StackSet that mimics this.  StackSet should be composed of several stacks and should create a new stack once the previous one exceeds capacity.  StackSet.push() and StackSet.pop() should behave identically to a single stack (that is pop() should return the same values as it would if there were just a single stack).
 
 FOLLOW UP
 
 Implement a function popAt(int index) which performs a pop operation on a specific sub-stack.
 
 */

#include <iostream>

using namespace std;



template <class T>
class Node{
public:
    Node(T v);

    T val;
    Node<T>* next;
};

template <class T>
Node<T>::Node(T v){
    val = v;
    next = NULL;
}

template <class T>
class NodeList{
public:
    NodeList(T val);

    Node<T>* head;
    NodeList<T>* next;
};


template <class T>
NodeList<T>::NodeList(T val){
    head = new Node<T>(val);
    next = NULL;
}


class EmptyStackSetException: public exception
{
    virtual const char* what() const throw()
    {
        return "EmptyStackSetException occurred: new failed or pop()/peek() inovked on empty stack";
    }
} stackset_ex;


template <class T>
class StackSet {
public:
    StackSet(void);

    
    void push(T val){
        
        try{
        
            if ( stack_list == NULL ){
            
                stack_list = new NodeList<T>(val);
                stack_list->head->next = NULL;
            
            
            } else {
            
                Node<T>* new_node = new Node<T>(val);
                new_node->next = stack_list->head;
                stack_list->head = new_node;
            }
            
        } catch(std::bad_alloc& exc) {
            
            throw stackset_ex;
        }
    }
    
    
    T pop(){
        
        if ( stack_list && stack_list->head ){

            // pop head off the stack
            Node<T>* popped_node = stack_list->head;
            stack_list->head = stack_list->head->next;
            
            // free the popped head
            T return_value = popped_node->val;
            delete popped_node;
            
            return return_value;

        } else {
            
            throw stackset_ex;
            
        }
    }

    
    T peek(){
        
        if ( stack_list && stack_list->head ){
            
            return stack_list->head->val;
            
        } else {
            
            throw stackset_ex;
            
        }
    }
    
    bool isEmpty(){
        return stack_list->head == NULL;
    }

private:
    
    NodeList<T>* stack_list;
};

template <class T>
StackSet<T>::StackSet(void){

}

int main(int argc, const char * argv[]) {
    
    int val;
    StackSet<int>* ss = new StackSet<int>;
    
    ss->push(0);
    ss->push(1);
    ss->push(2);
    
    while ( ! ss->isEmpty() ){
    
        val = ss->pop();
        cout << "Popped node value: " << val << endl << endl;
    }

    try{
        
        val = ss->pop();
        cout << "Popped node value: " << val << endl << endl;
        
    } catch ( EmptyStackSetException ex ) {
        
        cout << "Exception caught, this is expected since we popped off an empty list." << endl << endl;
    }
    
    return 0;
}
