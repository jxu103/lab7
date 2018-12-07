#include "iterator.h"
#include <stack>

using namespace std;

PreorderIterator::PreorderIterator(Base* ptr) : Iterator(ptr){}

void PreorderIterator::first() {
    // Empty the stack (just in case we had something leftover from another run)
    // Create an iterator for the Base* that we built the iterator for
    // Initialize that iterator and push it onto the stack
	while(!itstack.empty()) {
		itstack.pop();
	}	
	
	Iterator* temp = self_ptr->create_iterator();
	temp->first();		
	itstack.push(temp);
}

void PreorderIterator::next() {
    // Create an iterator for the item on the top of the stack
    // Initialize the iterator and push it onto the stack
    // As long as the top iterator on the stack is_done(), pop it off the stack and then advance whatever iterator is now on top of the stack
	Iterator* temp = itstack.top()->current()->create_iterator();
	temp->first();
	itstack.push(temp);	
	if(temp->is_done()) {
		//cout << "check done" << endl;
		//itstack.top()->current()->print();
		itstack.pop();
		//cout << "check done" << endl;	
		itstack.top()->current()->print();
		cout << endl;
		itstack.pop();
		itstack.top()->next();
	}

}

bool PreorderIterator::is_done() {
    // Return true if there are no more elements on the stack to iterate
	if(itstack.empty()) {
		return true;
	}
	else {
		return false;
	}
}

Base* PreorderIterator::current() {
    // Return the current for the top iterator in the stack
	return itstack.top()->current();
}


OperatorIterator::OperatorIterator(Base* ptr) : Iterator(ptr) {}

void OperatorIterator::first() {
	this->current_ptr = self_ptr->get_left();
}

void OperatorIterator::next() {
        if(current_ptr == self_ptr->get_left() ) {
                this->current_ptr = self_ptr->get_right();
        }
        else {
                this->current_ptr = NULL;
        }
	
}

bool OperatorIterator::is_done() {
	if(current_ptr == NULL) {
		return true;
	}
	else {	
		return false;
	}
}

Base* OperatorIterator::current() {
	return this->current_ptr;
}

UnaryIterator::UnaryIterator(Base* ptr) : Iterator(ptr) {}

void UnaryIterator::first() {
	this->current_ptr = self_ptr->get_left();
}

void UnaryIterator::next() {
	this->current_ptr = NULL;
}

bool UnaryIterator::is_done() {
	if(current_ptr == NULL) {
		return true;
	}
	else {
		return false;
	}	
}

Base* UnaryIterator::current() {
	return this->current_ptr;
}

NullIterator::NullIterator(Base* ptr): Iterator(ptr) {}

void NullIterator::first() {
	
}

void NullIterator::next() {

}

bool NullIterator::is_done() {
	return true;
}

Base* NullIterator::current() {
	return this->current_ptr;
}


