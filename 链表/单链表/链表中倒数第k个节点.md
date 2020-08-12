# 题目
输入一个链表，输出该链表中倒数第k个节点。为了符合大多数人的习惯，本题从1开始计数，即链表的尾节点是倒数第1个节点。例如，一个链表有6个节点，从头节点开始，它们的值依次是1、2、3、4、5、6。这个链表的倒数第3个节点是值为4的节点。
# 链接：https://leetcode-cn.com/problems/lian-biao-zhong-dao-shu-di-kge-jie-dian-lcof

为了求链表中倒数第 k 个节点，可以考虑用两个指针来做。先让这两个指针间距一段距离，
然后让两个指针一起走，当前面的指针走到链表末尾不能再走的时候，后面的指针刚好走到
链表的倒数第 k 个节点。

```c
struct ListNode* getKthFromEnd(struct ListNode* head, int k){
    struct ListNode *phead=head;
    int i;
    for(i=0;i<k;i++){
        phead=phead->next;
    }
    while(phead!=NULL){
        phead=phead->next;
        head=head->next;
    }
    return head;
}
```
