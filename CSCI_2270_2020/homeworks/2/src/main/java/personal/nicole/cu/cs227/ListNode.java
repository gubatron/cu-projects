package personal.nicole.cu.cs227;

public class ListNode {

    Object object;
    ListNode next;
    ListNode previous;

    ListNode(Object object, ListNode next, ListNode previous) {
        this.object = object;
        this.next = next;
        this.previous = previous;
    }

    ListNode(Object object) {
        this(object, null, null);
    }

    ListNode(Object object, ListNode next) {
        this(object, next, null);
    }

    ListNode(ListNode copyMe) {
        this.object = copyMe.object;
        this.next = copyMe.next;
        this.previous = copyMe.previous;
    }
}