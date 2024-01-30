// https://leetcode.com/problems/linked-list-random-node

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
    public static List<Integer> list = new ArrayList<>();
    private static Random r = new Random();

    public Solution(ListNode head) {
        while(head != null){
            list.add(head.val);
            head = head.next;
        }
        
    }
    
    public int getRandom() {
        int size = list.size();
        int n = r.nextInt(size);
        if(n == 0){
            return list.get(n);
        }
        n = size % n;
        return list.get(n);
        
    }
}

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(head);
 * int param_1 = obj.getRandom();
 */