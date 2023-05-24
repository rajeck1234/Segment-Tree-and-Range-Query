As seen in the presentation, the segment tree data structure is built.
The data structure may be utilized as follows:




To begin, we create a segment tree by doing segment_Tree* DS = new segment Tree(arr, n), where DS is our data structure, arr is the input array, and n is the array size.




Following that, the DS may be used to do both queries as follows:
i) To query a range, use DS->query(l, r), where [l, r] is the closed interval on which the query is to be performed, and these should be 1-based indices.
ii) For an update query, use DS->update(index, newValue), where the index is the indices whose values are to be modified to newValue, and newValue is the newValue.




InteractiveTest: There is interactive code that allows the user to view the output from the segment tree and array after each update and range query.




The code may be built with g++ and run as a standard C++ application.