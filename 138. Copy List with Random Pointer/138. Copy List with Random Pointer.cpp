/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head != NULL) {
            Node* newHead = new Node(head->val);

            Node* ptr = head->next;
            Node* newPtr = newHead;
            // Build the list's bones.
            while (true) {
                if (ptr == NULL) {
                    break;
                }
                else {
                    // Create new node.
                    Node* newNode = new Node(ptr->val);
                    newPtr->next = newNode;

                    ptr = ptr->next;
                    newPtr = newPtr->next;
                }
            }

            // Process random pointers.
            ptr = head;
            newPtr = newHead;
            while (true) {
                if (ptr == NULL) {
                    break;
                }
                else {
                    if (ptr->random == NULL) {
                        newPtr->random == NULL;
                    }
                    else {
                        Node* oldSearch = head;
                        Node* newSearch = newHead;
                        while (true) {
                            if (oldSearch == ptr->random) {
                                break;
                            }
                            else {
                                oldSearch = oldSearch->next;
                                newSearch = newSearch->next;
                            }
                        }

                        newPtr->random = newSearch;
                    }

                    ptr = ptr->next;
                    newPtr = newPtr->next;
                }
            }

            return newHead;
        }
        else {
            return NULL;
        }
    }
};