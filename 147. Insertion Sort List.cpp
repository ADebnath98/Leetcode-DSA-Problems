Intuition
approach involves repeatedly selecting the minimum element from the unsorted part of the list and moving it to the sorted part. It maintains two subarrays, one sorted and the other unsorted. In each iteration, it finds the minimum element in the unsorted subarray and swaps it with the first element in the unsorted subarray. This process continues until the entire list is sorted.
Approach
Brute Force Approach (O(n^2)):
The brute force approach involves repeatedly selecting the minimum element from the unsorted part of the list and moving it to the sorted part. It maintains two subarrays, one sorted and the other unsorted. In each iteration, it finds the minimum element in the unsorted subarray and swaps it with the first element in the unsorted subarray. This process continues until the entire list is sorted. The time complexity is O(n^2) in the worst and average cases, making it inefficient for large lists. SPACE->O(1)

Optimal Approach (O(n*log(n))):
The optimal approach is to use a more efficient sorting algorithm like Merge Sort or Quick Sort. Merge Sort divides the list into smaller sublists, sorts them, and then merges them back together. It has a time complexity of O(nlog(n)), which is significantly faster than the brute force approach for large lists. Quick Sort is another efficient option, with an average-case time complexity of O(nlog(n)), although it may require additional optimizations for certain cases.

Complexity
Time complexity:
nlogn

Space complexity:

logn


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;           // Value of the node.
 *     ListNode *next;    // Pointer to the next node in the list.
 *     ListNode() : val(0), next(nullptr) {}               // Default constructor.
 *     ListNode(int x) : val(x), next(nullptr) {}          // Constructor with value.
 *     ListNode(int x, ListNode *next) : val(x), next(next) {} // Constructor with value and next node pointer.
 * };
 */
class Solution {
public:
    // Helper function to merge two sorted linked lists.
    ListNode* merge(ListNode* left, ListNode* right) {
        if (!left) return right; // If one list is empty, return the other.
        if (!right) return left;
        
        if (left->val < right->val) {
            // Recursively merge the smaller value node with the rest of the merged list.
            left->next = merge(left->next, right);
            return left; // Return the merged list with 'left' as the new head.
        } else {
            right->next = merge(left, right->next);
            return right; // Return the merged list with 'right' as the new head.
        }
    }
    
    // Main function to perform insertion sort on a linked list.
    ListNode* insertionSortList(ListNode* head) {
        if (!head || !head->next) return head; // Base case: empty list or single node is already sorted.
        
        ListNode* slow = head;
        ListNode* fast = head->next;
        
        // Use the slow and fast pointer technique to split the list into two halves.
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        ListNode* left = head;     // Left half of the list.
        ListNode* right = slow->next; // Right half of the list.
        slow->next = nullptr;      // Break the link between the two halves.
        
        left = insertionSortList(left); // Recursively sort the left half.
        right = insertionSortList(right); // Recursively sort the right half.
        
        // Merge the sorted left and right halves to obtain the final sorted list.
        return merge(left, right);
    }
};

// /**
//  * Definition for singly-linked list.
//  * struct ListNode {
//  *     int val;
//  *     ListNode *next;
//  *     ListNode() : val(0), next(nullptr) {}
//  *     ListNode(int x) : val(x), next(nullptr) {}
//  *     ListNode(int x, ListNode *next) : val(x), next(next) {}
//  * };
//  */
// class Solution {
// public:
//     ListNode* insertionSortList(ListNode* head) {
//         // Create a dummy node with a high value. This node acts as the sorted list's head.
//         ListNode* dumm = new ListNode(1000);

//         // Iterate through the original linked list until all nodes are inserted into the sorted list.
//         while (head) {
//             // Initialize pointers: temp for traversal in sorted list, and next to preserve next node in the original list.
//             ListNode* temp = dumm;
//             ListNode* next = head->next;
            
//             // Find the correct position in the sorted list to insert the current node.
//             while (temp->next && temp->next->val < head->val) {
//                 temp = temp->next;
//             }

//             // Insert the current node into the sorted list at its correct position.
//             head->next = temp->next; // Connect the current node to the next node in the sorted list.
//             temp->next = head;       // Connect the previous node to the current node.

//             // Move to the next unsorted node in the original list.
//             head = next;
//         }
        
//         // Return the sorted list starting from the next node of the dummy node.
//         return dumm->next;
//     }
// };