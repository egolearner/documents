/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        transform(nestedList.begin(), nestedList.end(), back_inserter(holder), [](const NestedInteger& nest) {return &nest;});
    }
    
    int next() {
        return nextV;
    }
    
    bool hasNext() {
        while (!holder.empty()) {
            auto nest = holder.front();
            holder.pop_front();
            if (nest->isInteger()) {
                nextV = nest->getInteger();
                return true;
            } else {
                const auto& nestedList = nest->getList();
                transform(nestedList.begin(), nestedList.end(), inserter(holder, holder.begin()), [](const NestedInteger& nnest) {return &nnest;});
            }
        }
        return false;
    }
private:
    list<const NestedInteger*> holder;
    int nextV = -1;
};

// XXX lambda no return; dupliate variable name nnest, nextV

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
