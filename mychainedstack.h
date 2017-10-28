#ifndef DEF_MYCHAINEDSTACK
#define DEF_MYCHAINEDSTACK

#include "mystack.h"

class Mychainedstack: public Mystack
{
    // Attributs
    private:
        struct Node
        {
            int  value;
            Node *next;
        };
        Node *top;
    
        // Méthodes
    public:
        void push(int number);
        int pop(void);
        Mychainedstack *operator+(Mychainedstack s2);	
        void clear();
        void display();
};

#endif


