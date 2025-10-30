//DLL
class Node {
public:
    int key;
    int val;
    Node* next;
    Node* prev;
    Node(int k,int v)
    {
        key=k;
        val=v;
        next=nullptr;
        prev=nullptr;
    }

};

class LRUCache {
private:
    int cap;
    unordered_map<int,Node*> cache;
    Node *right;
    Node *left;
    
    void remove(Node* node) {
        Node* prev = node->prev;
        Node* nxt = node->next;
        prev->next = nxt;
        nxt->prev = prev;
    }

    void insert(Node* node) {
        Node* prev = right->prev;
        prev->next = node;
        node->prev = prev;
        node->next = right;
        right->prev = node;
    }
public:
    LRUCache(int capacity) {
            cap = capacity;
            cache.clear();
            left = new Node(0, 0);
            right = new Node(0, 0);
            left->next = right;
            right->prev = left;
        }
    
    int get(int key) {
        if (cache.find(key) != cache.end()) {
            Node* node = cache[key];
            remove(node);
            insert(node);
            return node->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            remove(cache[key]);
        }
        Node* newNode = new Node(key, value);
        cache[key] = newNode;
        insert(newNode);

        if (cache.size() > cap) {
            Node* lru = left->next;
            remove(lru);
            cache.erase(lru->key);
            delete lru;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */



// Using Map
class LRUCache {
private:
    unordered_map<int,pair<int,list<int> :: iterator>> cache;
    list<int> order;
    int capacity;
public:
    LRUCache(int capacity) {
       this-> capacity=capacity;
    }
    
    int get(int key) {
        if(cache.find(key)== cache.end())
            return -1;
        order.erase(cache[key].second);
        order.push_back(key);
        cache[key].second=--order.end();
        return cache[key].first;
    }
    
    void put(int key, int value) {
        if(cache.find(key)!=cache.end())
        {
            order.erase(cache[key].second);
        }
        else if(cache.size()==capacity)
        {
            int lru=order.front();
            order.pop_front();
            cache.erase(lru);
        }
        order.push_back(key);
        cache[key]={value,--order.end()};
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */