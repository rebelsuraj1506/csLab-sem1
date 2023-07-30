#include <bits/stdc++.h>
using namespace std;
struct Node {
    int value;
    struct Node* next;
};
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
    int m;
    cin>>m;
    struct Node* nodes[m];
    int k=3;
    int temp[k];
    for (int i = 0; i < m; ++i) {
        nodes[i] = (struct Node*)malloc(sizeof(struct Node));
        int n;
        // cout << "Enter the nodes: ";
        cin >> n;
        nodes[i]->value=n;
    }
    for (int i = 0; i < m-1; ++i) {
        nodes[i]->next = nodes[i + 1];
    }
    nodes[m-1]->next = nodes[0];
    cout << "Original Circular Linked List:" << endl;
    printCircularLinkedList(nodes[0]);
    updateCircularLinkedList(nodes[0], k);
    cout << "\nUpdated Circular Linked List:" << endl;
    printCircularLinkedList(nodes[0]);
    for (int i = 0; i < m; ++i) {
        free(nodes[i]);
    }
    return 0;
}
