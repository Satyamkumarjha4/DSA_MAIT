#include<iostream>
using namespace std;

int push(int* stack, int top, int n, int x) {
    if(top == n - 1) {
        cout << "Stack overflow" << endl;
    } else {
        top++;
        stack[top] = x;
    }
    return top;
}

int pop(int* stack, int top) {
    if(top == -1) {
        cout << "Stack underflow" << endl;
    } else {
        cout << "Popped element: " << stack[top] << endl;
        top--;
    }
    return top;
}

void display(int* stack, int top) {
    if(top == -1) {
        cout << "Stack is empty" << endl;
    } else {
        cout << "The stack is: ";
        for(int i = 0; i <= top; i++) {
            cout << stack[i] << " ";
        }
        cout << endl;
    }
}

int main() {
    int n;
    cout << "Enter the size of the stack: ";
    cin >> n;

    int* stack = new int[n];
    int top = -1;

    int choice;
    do {
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Display" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1: {
                int x;
                cout << "Enter the element to be pushed: ";
                cin >> x;
                top = push(stack, top, n, x);
                break;
            }
            case 2: {
                top = pop(stack, top);
                break;
            }
            case 3: {
                display(stack, top);
                break;
            }
            case 4: {
                cout << "Exiting..." << endl;
                break;
            }
            default: {
                cout << "Invalid choice" << endl;
            }
        }
    } while(choice != 4);

    delete[] stack;

    return 0;
}