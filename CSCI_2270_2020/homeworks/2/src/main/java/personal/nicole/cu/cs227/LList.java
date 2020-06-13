package personal.nicole.cu.cs227;

public class LList {

    ListNode head;
    ListNode tail;
    int size;

    public LList() {
        head = null;
        tail = null;
        size = 0;
    }

    public void add(Object obj) {
        if (head == null) {
            head = new ListNode(obj, null, null);
            tail = head;
            size = 1;
            return;
        }

        ListNode node = new ListNode(obj, null, tail);
        tail.next = node;
        tail = node;
        size++;
    }

    public void addAt(Object obj, int n) {
        ListNode oldNode = get(n);
        if (oldNode != null) {
            ListNode newNode = new ListNode(obj, oldNode, oldNode.previous);
            oldNode.previous.next = newNode;
        } else {
            add(obj);
        }
    }

    public void addAt(Object objNew, Object old) {
        int i = find(old);
        if (i != -1) {
            addAt(objNew, i);
        } else {
            add(objNew);
        }
    }

    public void delete(Object obj) {
        int i = find(obj);
        if (i != -1) {
            deleteAt(i);
        }
    }

    public void deleteAt(int n) {
        if (n == 0) {
            head = head.next;
            head.previous = null;
            return;
        }
        if (n == size - 1) {
            tail = tail.previous;
            tail.next = null;
            return;
        }
        ListNode listNode = get(n);

        if (listNode == null) {
            return; // nothing to delete at invalid position
        }

        listNode.previous.next = listNode.next;
        listNode.next.previous = listNode.previous;
    }

    public int find(Object obj) {
        for (int i = 0, j = size - 1; i < size && i != j + 1; i++, j--) {
            ListNode listNode = get(i);
            ListNode listNode1 = get(j);
            if (listNode != null && listNode.object.equals(obj)) {
                return i;
            }
            if (listNode1 != null && listNode1.object.equals(obj)) {
                return j;
            }
        }
        return -1;
    }

    public ListNode get(int n) {
        if (n < 0 || n >= size()) {
            return null;
        }
        if (n == 0) {
            return head;
        }
        if (n == size() - 1) {
            return tail;
        }

        ListNode temp = new ListNode(head);

        for (int i = 0; i < n; i++) {
            temp = temp.next;
        }
        return temp;
    }

    public ListNode head() {
        return head;
    }

    public ListNode tail() {
        return tail;
    }

    public int size() {
        return size;
    }

    public void print() {
        ListNode temp = new ListNode(head);
        for (int i = 0; i < size; i++) {
            System.out.println(temp.object);
            temp = temp.next;
        }
    }

    public static void main(String[] args) {
        LList myList = new LList();
        String nicole = new String("Nicole");
        String austin = new String("Austin");
        String angel = new String("Angel");
        String neny = new String("Neny");
        String paulina = new String("Paulina");
        String sarah = new String("Sarah");
        String desmond = new String("Desmond");

        myList.add(nicole); // 0
        myList.add(austin); // 1
        myList.add(angel); // 2
        myList.add(neny); // 3
        myList.add(paulina); // 4
        myList.add(sarah); // 5
        myList.add(desmond); // 6

        System.out.println(myList.get(5).object); // desmond
        System.out.println(myList.get(3).object); // paulina
        System.out.println(myList.get(0).object); // nicole
        System.out.println(myList.get(1).object); // austin
        System.out.println(myList.get(4).object); // sarah

        System.out.println("==");
        System.out.println(myList.find(angel));
        System.out.println(myList.find(neny));


        String mila = new String("Mila");
        myList.addAt(mila, neny);

        System.out.println(myList.find(mila));
        myList.print();
        System.out.println("==");
        myList.deleteAt(myList.find(mila));
        myList.print();
    }
}
