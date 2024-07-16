class Dll{
    int val;
    Dll next;
    Dll prev;
    Dll(int val){
        this.val=val;
        next=null;
        this.prev=null;
    }
    Dll(int val,Dll prev){
        this.val=val;
        next=null;
        this.prev=prev;
    }
};

class MyLinkedList {
    private int size;
    private Dll head;
    private Dll tail;
    public MyLinkedList() {
        size=0;
        head=tail=null;
    }
    
    public int get(int index) {
        if(index>=size) return -1;
        int mid=size/2;
        Dll temp=null;
        if(index>mid){
            temp=tail;
            index=size-1-index;
            while(index-->0)
                temp=temp.prev;
        }else{
            temp=head;
            while(index-->0)
                temp=temp.next;
        }
        
        return temp.val;
    }
    
    public void addAtHead(int val) {
        size++;
        Dll node=new Dll(val);
        node.next=head;
        if(head!=null)
            head.prev=node;
        else
            tail=node;
        head=node;
        //show();
    }
    
    public void addAtTail(int val) {
        size++;
        Dll node=new Dll(val,tail);
        if(tail!=null)
            tail.next=node;
        else
            head=node;
        tail=node;
        //show();
    }
    public void show(){
        Dll temp=head;
        while(temp!=null){
            System.out.print(temp.val+" ");
            temp=temp.next;
        }
        System.out.println();
    }
    public void addAtIndex(int index, int val) {
        if(index>size) return;
        if(index==0){
            addAtHead(val);
            return;
        }
        if(index==size) {
            addAtTail(val);
            return;
        }
        Dll node=new Dll(val);
        int mid=size/2;
        Dll temp=null;
        if(index>mid){
            index=size-index-1;
            temp=tail;
            while(index-->0)
                temp=temp.prev;
            Dll prev=temp.prev;
            node.prev=prev;
            node.next=temp;
            temp.prev=node;
            prev.next=node;
        }else{
            index--;
            temp=head;
            while(index-->0)
                temp=temp.next;
            Dll next=temp.next;
            node.prev=temp;
            node.next=next;
            if(next!=null)
                next.prev=node;
            temp.next=node;
        }
        size++;
        //show();
    }
    
    public void deleteAtIndex(int index) {
        if(index>=size) return;

        if(index==0){
            head=head.next;
            if(head!=null)
                head.prev=null;
            if(size==1) tail=null;
        }else if(index==size-1){
            tail=tail.prev;
            if(tail!=null)
                tail.next=null;
            if(size==1)
                head=null;
        }else{
            Dll temp=head;
            while(index-->0)
                temp=temp.next;
            temp.prev.next=temp.next;
            temp.next.prev=temp.prev;
        }
        size--;
        //show();
    }
}

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList obj = new MyLinkedList();
 * int param_1 = obj.get(index);
 * obj.addAtHead(val);
 * obj.addAtTail(val);
 * obj.addAtIndex(index,val);
 * obj.deleteAtIndex(index);
 */