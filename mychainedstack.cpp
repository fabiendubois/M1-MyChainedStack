#include "mychainedstack.h"
#include <iostream>
using namespace std;

void Mychainedstack::push(int number)
{
	struct Node *newNode = new Node;
	newNode->value = number;
	newNode->next = top;
	top = newNode;
	return;
}

int Mychainedstack::pop(void)
{
	// IF vide -> return 42	
	if (top == NULL) 
	{
        return 42;
	}
	int tampon = top->value;
	top = top->next;
	return tampon;
}

Mychainedstack* Mychainedstack::operator+(Mychainedstack s2)
{
	Mychainedstack *appendStack = new Mychainedstack();	
	Mychainedstack *s1_inverse = new Mychainedstack();
	Mychainedstack *s2_inverse = new Mychainedstack();
	
	Node* temp = s2.top;
	while (temp != nullptr) 
	{
		s2_inverse->push(s2.pop());
		temp = temp->next;
	}
	
	Node* temp5 = this->top;
	while (temp5 != nullptr) 
	{
		s1_inverse->push(this->pop());
		temp5 = temp5->next;
	}        
	
	Node* temp3 = s1_inverse->top;
	int value_tampon;
	while (temp3 != nullptr) 
	{
		value_tampon = s1_inverse->pop();
		appendStack->push(value_tampon);
		this->push(value_tampon);
		temp3 = temp3->next;
	}

	Node* temp2 = s2_inverse->top;
	while (temp2 != nullptr) 
	{
		appendStack->push(temp2->value);
		temp2 = temp2->next;
	}
	
	return appendStack;
}

void Mychainedstack::clear(void)
{
	while(top != NULL)
	{
		pop();
	}
    return;
}

void Mychainedstack::display()
{
	if(top==NULL){
        cout<<"List is empty!"<<endl;
        return;
    }
    struct Node *temp=top;
    while(temp!=NULL){
        printf(" %d ",temp->value);
        temp=temp->next;
    }
    cout<<endl;
}

