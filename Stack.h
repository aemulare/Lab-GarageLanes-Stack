#pragma once
#include <cstdlib>


template<class T> class Stack 
{
		// LIFO objects

	public:
		Stack(int MaxStackSize = 10)			// constructor
		{
			//Pre: none'
			//Post: Array of size MaxStackSaize to implement stack
			MaxTop = MaxStackSize - 1;
			stack = new T[MaxStackSize];
			top = -1;
		}

		~Stack() { delete[] stack; }			// destructor

		bool IsEmpty() const { return top == -1; }
		bool IsFull() const { return top == MaxTop; }

		T& Top() const
		{
			//Pre: stack is not empty
			// Post:  Returns top element.
			if (IsEmpty())
				throw logic_error("Top fails: Stack is empty");// Top fails
			return stack[top];
		}
		

		void push(const T& x)
		{
			//Pre: Stack is not full
			//Post: Push x to stack.
			//		Stack has one more element
			if (IsFull()) throw logic_error("Push fails: full stack"); // Push fails
			stack[++top] = x;
		}

		void pop()
		{
			//Pre: Stack is not Empty
			//Post: Stack has one less element
			if (IsEmpty()) {
				throw logic_error("Pop fails: Stack is empty");
			}; // Pop fails
			top--;
		}

		int search(const T& x)
		{
			for (int i = 0; i <= top; i++)
			{
				if (x == stack[i])
					return i;
			}
			return -1;
		}


	private:
		int top;    // current top of stack
		int MaxTop; // max value for top
		T *stack;   // element array
};