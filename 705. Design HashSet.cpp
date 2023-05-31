class MyHashSet {
    int* nums = nullptr;
    size_t size = 0;
    size_t capacity = 4;

    void resize()
    {
        capacity = capacity * 2;

        int* res = new int[capacity];

        for(size_t i = 0; i < size; i++)
        {
            res[i] = nums[i];
        }

        delete[] nums;
        nums = res;
    }

public:
    MyHashSet() {
        nums = new int[capacity];
    }
    
    void add(int key) {
        if(this->contains(key))
            return;

        if(size >= capacity)
            resize();

        nums[size++] = key;
    }
    
    void remove(int key) {
        if(!this->contains(key))
            return;
        
        for(size_t i = 0; i < size; i++)
        {
            if(nums[i] == key)
            {
                std::swap(nums[i], nums[size - 1]);
                break;
            }
        }

        size--;
    }
    
    bool contains(int key) {
        for(size_t i = 0; i < size; i++)
        {
            if(nums[i] == key)
                return true;
        }

        return false;
    }

    MyHashSet(const MyHashSet& other) = delete;
    void operator=(const MyHashSet& other) = delete;

    ~MyHashSet()
    {
        delete[] nums;
        nums = nullptr;
        size = capacity = 0;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */