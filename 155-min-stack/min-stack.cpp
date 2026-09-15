class MinStack {
public:
    long long minElem ;
    stack<long long> st ;
    MinStack() {}
    
    void push(int value) 
    {
        if ( st.size() == 0 ) 
        {
            st.push( value ) ;
            minElem = value ;
            return ;
        } 
        if ( value >= minElem  ) st.push(value) ;
        else 
        {
            st.push( 2LL * value - minElem ) ;
            minElem = value ;
            return ;
        }
        return ;

    }
    
    void pop() 
    {
        if ( st.size() == 0 ) return ;
        if ( st.top() >= minElem ) 
        {
            st.pop() ;
            return ;
        }
        else 
        {
            minElem = 2LL*minElem - st.top() ;
            st.pop() ;
            return ;
        }
        return ;
    }
    
    int top() 
    {
        if ( st.size() == 0 ) return -1 ;
        if ( st.top() >= minElem ) return st.top() ;
        else return minElem ;
    }
    
    int getMin() 
    {
        if ( st.size() == 0 ) return -1 ;
        return minElem ;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */