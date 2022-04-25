/*
 * Below is the interface for Iterator, which is already defined for you.
 * **DO NOT** modify the interface for Iterator.
 *
 *  class Iterator {
 *		struct Data;
 * 		Data* data;
 *  public:
 *		Iterator(const vector<int>& nums);
 * 		Iterator(const Iterator& iter);
 *
 * 		// Returns the next element in the iteration.
 *		int next();
 *
 *		// Returns true if the iteration has more elements.
 *		bool hasNext() const;
 *	};
 */

class PeekingIterator : public Iterator {
public:
    stack<int>st;
	PeekingIterator(const vector<int>& v) : Iterator(v) {
	    // Initialize any member here.
	    // **DO NOT** save a copy of nums and manipulate it directly.
	    // You should only use the Iterator interface methods.
	    for(int i=v.size()-1;i>=0;i--) st.push(v[i]);
	}
	
    // Returns the next element in the iteration without advancing the iterator.
	int peek() {
        return st.top();
	}
	
	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() {
	    int el=st.top();
        st.pop();
        return el;
	}
	
	bool hasNext() const {
	    if(!st.empty()) return 1;
        return 0;
	}
};