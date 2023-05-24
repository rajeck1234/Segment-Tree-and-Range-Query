#include<bits/stdc++.h>
using namespace std;
#define int long long
class segment_Tree{
private:
    int *seg_t, size = -1;

    // initialises the segment tree nodes
    void build(int st, int end, int node, int *arr){
        // if it is a leaf node
        // then the value at this node equals
        // value in the array at this index
        if(st == end){
            seg_t[node] = arr[st];
            return;   
        }

        // otherwise ,first find values of left and right
        // halves and then combine them to get the value
        // for current range.
        int mid = (st + end) / 2;
    
        build(st, mid, 2*node, arr);
        build(mid + 1, end, 2*node + 1, arr);

        seg_t[node] = min(seg_t[2*node],seg_t[2*node + 1]);
    }

    // recursively finds the value for queried range
    // by first obtaining the right and left half
    // contributions and then combining them. 
    int query(int st, int end, int node, int l, int r){
        // if current range does not
        // overlap with query range, return INFINITY
        if((st > r) || (end < l))
            return INT_MAX;
        
        // if current range lies completely
        // in query range,  return its value
        if((l <= st) && (end <= r))
            return seg_t[node];
        
        // otherwise recursively find the contribution
        // of current range
        int mid = (st + end) / 2;

        return min( query(st, mid, 2 * node, l, r),
                    query(mid + 1, end, 2 * node + 1, l, r));
    }

    // recursively updates the segment tree 
    // recurses by updating the left and right halves 
    // and then updating the current node
    void update(int st, int end, int node, int indx, int Updval){
        // if range does not contain indx
        // return from there, as nothing inside
        // that range needs to updated
        if((st > indx) || (end < indx))
            return;
        
        // If it is a leaf node that 
        // is our updated index
        // update it
        if(st == end){
            seg_t[node] = Updval;
            return;
        }

        int mid = (st + end) / 2;

        // recursively updating the other nodes
        // after updating their left and right halves
        update(st, mid, 2 * node, indx, Updval);
        update(mid + 1, end, 2 * node + 1, indx, Updval);

        seg_t[node] = min(seg_t[2*node], seg_t[2*node + 1]);
    }

public:
    // default constructor
    segment_Tree(){
        size = -1;
        seg_t = nullptr;
    }

    // initialises the segment tree
    // with the input array arr with
    // size n 
    segment_Tree(int *arr, int n){
        size = n;
        seg_t = new int[4*n];
        build(0, n - 1, 1, arr);
    }

    // use for quering a range [l, r]
    int query(int l, int r){
        if(size == -1){
            cerr << "Segment Tree is not initialised\n";
            exit(1); 
        }
        l --;
        r --;
        
        assert((l >= 0) && (l <= r) && (r < size));
        return query(0, size - 1, 1, l, r);
    }

    // use to update a index 
    void update(int Updindx, int UpdVal){
        if(size == -1){
            cerr << "Segment Tree is not initialised\n";
            exit(1); 
        }
        Updindx --;
        
        assert((Updindx >= 0) && (Updindx < size));
        update(0, size - 1, 1, Updindx, UpdVal);
    }
};
// Manual testing
void ManualTest(){
    cout << "-----------------------------------------------------------------------------------------------------\n";
    cout << "Starting Interactive program for segment tree testing\n";
    
    cout << "Enter n: ";
    int n;
    cin >> n;
    
    cout << "Enter the values of array:\n";
    int *arr = new int[n];
    for(int i = 0; i < n; i ++){
        cin >> arr[i];
    }
    
    segment_Tree* DS = new segment_Tree(arr, n);
    
    cout  << "Enter total number of queries: ";
    int q;
    cin >> q;

    cout << "\n0 for range query followed by l and r\n";
    cout << "1 for update followed by index and new value\n";
    cout << "Enter queries\n";

    while(q --){
        cout << "Enter type of query: ";
        
        int t;
        cin >> t;
        
        if(t == 0){
            cout << "Enter the range of query: ";
            
            int l, r;
            cin >> l >> r;
            
            cout << "The value for the query is " << DS->query(l, r) << '\n';
        }else if(t == 1){
            cout << "Enter the index and new value: ";
            
            int indx, val;
            cin >> indx >> val;
            
            arr[indx - 1] = val;
            DS->update(indx, val);
        }else{
            cout << "Invalid query\n";
            return;
        }
        
        cout << "\nThe array after the query is:\n";
        
        for(int i = 0; i < n; i ++){
            cout << arr[i] << ' ';
        }
        cout << '\n';
        cout << '\n';
    }
    cout << "-----------------------------------------------------------------------------------------------------\n";
}

signed main(){
    ManualTest();
}