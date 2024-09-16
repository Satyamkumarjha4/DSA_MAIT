#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

// Create a new node
Node* createNode(int x) {
    Node* temp = new Node();
    temp->data = x;
    temp->next = NULL;
    return temp;
}

// Insert the new node at the desired position
Node* insertNode(Node* head, int x, int pos) {
    Node* temp = createNode(x);

    if (pos == 0) {
        temp->next = head;
        head = temp;
    } else {
        Node* ptr = head;
        for (int i = 0; i < pos - 1 && ptr != NULL; i++) {
            ptr = ptr->next;
        }
        if (ptr == NULL) {
            cout << "Position exceeds the list size. Inserting at the end." << endl;
            Node* end = head;
            while (end->next != NULL) {
                end = end->next;
            }
            end->next = temp;
        } else {
            temp->next = ptr->next;
            ptr->next = temp;
        }
    }
    return head;
}

// Delete the node with the specified value
Node* deleteNode(Node* head, int key) {
    if (head == NULL) {
        cout << "List is empty" << endl;
        return head;
    }

    Node* temp = head;

    // If head is the node to be deleted
    if (head->data == key) {
        cout << "Deleted Student ID: " << head->data << endl;
        head = head->next; // Move the head to the next node
        delete temp;
        return head;
    }

    // Traverse the list to find the node with the matching key
    Node* prev = NULL;
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    // If the key was not found
    if (temp == NULL) {
        cout << "ID " << key << " not found in the list." << endl;
        return head;
    }

    // Unlink the node from the list and delete it
    prev->next = temp->next;
    cout << "Deleted Student ID: " << temp->data << endl;
    delete temp;

    return head;
}

// Display the list
void display(Node* head) {
    if (head == NULL) {
        cout << "List is empty" << endl;
    } else {
        cout << "The list is: ";
        Node* ptr = head;
        while (ptr != NULL) {
            cout << ptr->data << " --> ";
            ptr = ptr->next;
        }
        cout << "nullptr" << endl;
    }
}

// Reverse the linked list
Node* reversal(Node* head) {
    Node* prev = NULL;
    Node* curr = head;
    Node* next = NULL;
    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
    return head;
}

int main() {
    int n, x;
    Node* head = NULL;

    cout << "Enter the number of Student you want to add: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Enter the Student ID: ";
        cin >> x;
        head = insertNode(head, x, i);
    }

    int choice;
    do {
        cout << "1. Insert Student ID" << endl;
        cout << "2. Delete Student ID" << endl;
        cout << "3. Display Linked List" << endl;
        cout << "4. Reverse Linked List" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int x, pos;
                cout << "Enter the Student ID to be inserted: ";
                cin >> x;
                cout << "Enter the position where you want to insert: ";
                cin >> pos;
                head = insertNode(head, x, pos);
                break;
            }
            case 2: {
                int key;
                cout << "Enter the Student ID to be deleted: ";
                cin >> key;
                head = deleteNode(head, key);
                break;
            }
            case 3: {
                display(head);
                break;
            }
            case 4: {
                head = reversal(head);
                break;
            }
            case 5: {
                cout << "Exiting..." << endl;
                break;
            }
            default: {
                cout << "Invalid choice" << endl;
            }
        }
    } while (choice != 5);

    return 0;
}
