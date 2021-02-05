package main

type ListNode struct {
	Val  int
	Next *ListNode
}

func hasCycle(head *ListNode) bool {
	if head == nil {
		return false
	}
	if head.Next == nil {
		return false
	}

	slow := head
	fast := head.Next

	for true {
		if fast == nil || slow == nil {
			return false
		}
		if slow == fast {
			return true
		}
		slow = slow.Next

		fast = fast.Next
		if fast == nil {
			return false
		}
		fast = fast.Next
	}
	return false
}
