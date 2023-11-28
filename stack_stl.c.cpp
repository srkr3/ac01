#include <iostream>
#include <stack>
int main()
{
    std::stack<int> myStack;
    myStack.push(1);
    myStack.push(2);
    myStack.push(3);

    std::cout << "Top element of the stack: " << myStack.top() << std::endl;

	while (!myStack.empty()) {
        std::cout << myStack.top() << " "<< std::endl;
        myStack.pop();
    }

    if (myStack.empty())
		std::cout << "Stack is empty." << std::endl;
    
    else
        std::cout << "Stack is not empty." << std::endl;
    

    return 0;
}
