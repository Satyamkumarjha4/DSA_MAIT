#include <iostream>
using namespace std;

const int MAX = 100;

class Queue {
    int front, rear;
    int arr[MAX];

public:
    Queue() {
        front = 0;
        rear = 0;
    }

    bool isEmpty() {
        return front == rear;
    }

    bool isFull() {
        return (rear + 1) % MAX == front;
    }

    void enqueue(int x) {
        if (isFull()) {
            cout << "Queue is full. Cannot enqueue." << endl;
            return;
        }
        arr[rear] = x;
        rear = (rear + 1) % MAX;
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot dequeue." << endl;
            return -1;
        }
        int x = arr[front];
        front = (front + 1) % MAX;
        return x;
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }
        int i = front;
        while (i != rear) {
            cout << arr[i] << " ";
            i = (i + 1) % MAX;
        }
        cout << endl;
    }
};

int main() {
    Queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.display();
    cout << q.dequeue() << endl;
    q.display();
    q.enqueue(4);
    q.enqueue(5);
    q.display();
    cout << q.dequeue() << endl;
    q.display();
    return 0;
}