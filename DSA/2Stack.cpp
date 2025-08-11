class twoStacks {
  public:
    static const int MAX = 100;
    int arr[MAX];
    int top1,top2;
    
    twoStacks() {
        top1 = -1;
        top2 = MAX;
    }

    // Function to push an integer into the stack1.
    void push1(int x) {
        if(top1 < top2-1){
            arr[++top1] = x;
        }
    }

    // Function to push an integer into the stack2.
    void push2(int x) {
        if(top1 < top2 -1){
            arr[--top2] = x;
        }
        
    }

    // Function to remove an element from top of the stack1.

        
    int pop1() {
        if(top1 == -1){
            return -1;
        }
        else{
           int x = arr[top1--];
            return x;
        }
    }

        
    // Function to remove an element from top of the stack2.
    int pop2() {
        if(top2 == MAX){
            return -1;
        }
        else{
           int x = arr[top2++];
            return x;
        }
    }
};
