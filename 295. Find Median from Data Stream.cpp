Intuition
Approach
solved using two heaps, left heap is a max heap which contains values less than current median and right heap is a min heap which contains values more then curren median

Complexity
Time complexity:
to add an element into heap time complexity will be O(logn)
to find median it will be O(1)

Space complexity:
requires two heaps to store all elements collectively therefore O(n)



class MedianFinder {
public:
    priority_queue<int> maxheap;
    priority_queue<int, vector<int>, greater<int>> minheap;

    MedianFinder() {
        
    }
    
    void addNum(int num) {

        int element = num;
        double median;

        if(maxheap.size() == minheap.size()){
            if(maxheap.size() == 0){
                maxheap.push(num);
                return;
            }

            median = (double)(maxheap.top() + minheap.top())/2;
            if( element > median)
                minheap.push(element);
            else 
                maxheap.push(element);    
            cout<<"adding "<<num<<" when both heaps were equal"<<endl;
        }

        else if(maxheap.size() +1 == minheap.size()){
            median = minheap.top();
            if(element > median){
                maxheap.push(minheap.top());
                minheap.pop();
                minheap.push(element);
            }
            else{
                maxheap.push(element);
            }
        }
        else{
            median = maxheap.top();
            if(element > median)
                minheap.push(element);
            else{
                minheap.push(maxheap.top());
                maxheap.pop();
                maxheap.push(element);
            }
        }
    }
    
    double findMedian() {
        double median;
        if(maxheap.size() == minheap.size()){
            median = (double)(maxheap.top() + minheap.top())/2;  
        }

        else if(maxheap.size() +1 == minheap.size()){
            median = minheap.top();
        }
        else{
            median = maxheap.top();
        }

        return median;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */