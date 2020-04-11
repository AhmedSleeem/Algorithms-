class MinStack {
    Stack<Pair> stack;
    

    /** initialize your data structure here. */
    public MinStack() {
        stack =new Stack();
    }
    
    public void push(int x) {
        int min=stack.isEmpty()?x:Math.min(x,stack.peek().second);
        stack.push(new Pair(x,min));
        
        
    }
    
    public void pop() {
        stack.pop();
        
    }
    
    public int top() {

		// first ->contains the min element for this index to start of this array
		//second -> the element it self
        return stack.peek().first;
    }
    
    public int getMin() {
        return stack.peek().second;
    }
}
class Pair implements Comparable<Pair> {
    int first, second;

    public Pair(int first, int second) {
        this.first = first;
        this.second = second;
    }


    @Override
    public int compareTo(Pair o) {
        if (first!=o.first)return first-o.first;
        return second-o.second;
    }
}

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */