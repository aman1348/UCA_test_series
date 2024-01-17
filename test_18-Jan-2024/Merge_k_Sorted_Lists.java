// leetcode problem no: 23
// problem name : Merge k Sorted Lists
// problem link: https://leetcode.com/problems/merge-k-sorted-lists/description/

// solution:


/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode mergeKLists(ListNode[] lists) {
        if(lists.length == 0) return null;

        for(int i = 1; i<lists.length; i++) {
            ListNode current_node = lists[0];
            ListNode previous_node = null;
            while(current_node!= null && lists[i] != null) {
                if(current_node.val >= lists[i].val) {
                    ListNode inserting_node = lists[i];
                    lists[i] = lists[i].next;
                    if(previous_node != null) {
                        previous_node.next = inserting_node;
                        previous_node = inserting_node;
                    }
                    else {
                        previous_node = inserting_node;
                        lists[0] = previous_node;
                    }
                    inserting_node.next = current_node;
                }
                else {
                    previous_node = current_node;
                    current_node = current_node.next;
                }
            }
            if(lists[i] != null) {
                if(previous_node == null) lists[0] = lists[i];
                else previous_node.next = lists[i];
            }
        }
        return lists[0];
    }
}