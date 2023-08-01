#include <bits/stdc++.h>
using namespace std;
struct Node {
    int value;
    struct Node* next;
};
//To find Maximum element
int findMaxInNextK(struct Node* current_node, int k) {
    int max_value = current_node->next->value;
    struct Node* node = current_node->next;
    for (int i = 0; i < k; ++i) {
        if (node->value > max_value) {
            max_value = node->value;
        }
        node = node->next;
    }
    return max_value;
}
//For updating Circular Linked List
void updateCircularLinkedList(struct Node* head, int k) {
    int length = 1;
    struct Node* node = head->next;
    while (node != head) {
        length++;
        node = node->next;
    }
    struct Node* current_node = head;
    int i;
    int temp[k];
    for (i = 0; i < k; ++i) {
        int max_value = findMaxInNextK(current_node, k);
        temp[i] = max_value;
        current_node = current_node->next;
    }
    for (; i < length; ++i) {
        int max_value = findMaxInNextK(current_node, k);
        current_node->value = max_value;
        current_node = current_node->next;
    }
    for(i=0;i<k;i++)
    {
        current_node->value=temp[i];
        current_node=current_node->next;
    }
}
//To print Circular Linked List
void printCircularLinkedList(struct Node* head) {
    if (head == NULL) {
        return;
    }
    struct Node* node = head;
    do {
        cout << node->value << " ";
        node = node->next;
    } while (node != head);
    cout << endl;
}
int main() {
    int m;//Number of nodes
    cin>>m;
    struct Node* nodes[m];
    int k=3;
    int temp[k];
    for (int i = 0; i < m; ++i) {
        nodes[i] = new Node;
        int n;
        cin >> n;
        nodes[i]->value=n;
    }
    for (int i = 0; i < m-1; ++i) {
        nodes[i]->next = nodes[i + 1];
    }
    nodes[m-1]->next = nodes[0];
    //Print original Circular Linked List
    cout << "Original Circular Linked List:" << endl;
    printCircularLinkedList(nodes[0]);
    updateCircularLinkedList(nodes[0], k);
    //Print Updated Circular Linked List
    cout << "\nUpdated Circular Linked List:" << endl;
    printCircularLinkedList(nodes[0]);
    for (int i = 0; i < m; ++i) {
        free(nodes[i]);
    }
    return 0;
}