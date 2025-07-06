#include <iostream>
#include <unordered_map>
#include <list>
/*
Implement the LRUCache class:

LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
int get(int key) Return the value of the key if the key exists, otherwise return -1.
void put(int key, int value) Update the value of the key if the key exists. Otherwise, add the key-value pair to the cache.
If the number of keys exceeds the capacity from this operation, remove the least recently used key.
The functions get and put must each run in O(1) average time complexity.
*/

struct Node
{
    int key;
    int value;
    Node *next;
    Node *prev;
    Node() : key(0), value(0), next(nullptr), prev(nullptr) {}
    Node(int key, int value) : key(key), value(value), next(nullptr), prev(nullptr) {}
};

struct Queue
{
    Node *head, *tail;
    Queue() : head(nullptr), tail(nullptr) {}

    void push(Node *node)
    {
        if (tail == nullptr)
        {
            head = tail = node;
            return;
        }
        tail->next = node;
        node->prev = tail;
        tail = node;
    }

    Node *pop()
    {
        if (head == nullptr)
        {
            return nullptr;
        }

        Node *temp = head;
        head = head->next;
        temp->next = nullptr;

        if (head != nullptr)
        {
            head->prev = nullptr;
        }
        else
        {
            tail = nullptr;
        }

        return temp;
    }

    void remove(Node *node)
    {
        if (head == node)
        {
            pop();
            return;
        }

        Node *prev = node->prev;
        Node *next = node->next;

        prev->next = next;

        if (next != nullptr)
        {
            next->prev = prev;
        }
        else
        {
            tail = tail->prev;
        }

        node->prev = node->next = nullptr;
    }

    void makeMostRecent(Node *node, int value)
    {
        remove(node);
        node->value = value;
        push(node);
    }
};

class LRUCache
{
    int capacity;
    Queue queue;
    std::unordered_map<int, Node *> map;

public:
    LRUCache(int capacity) : capacity(capacity) {}

    int get(int key)
    {
        if (map.find(key) == map.end())
        {
            return -1;
        }

        Node *node = map[key];
        queue.makeMostRecent(node, node->value);
        return node->value;
    }

    void put(int key, int value)
    {
        if (map.find(key) == map.end())
        {
            if (map.size() == capacity)
            {
                Node *delNode = queue.pop();
                if (delNode)
                {
                    map.erase(delNode->key);
                    delete delNode;
                }
            }

            Node *node = new Node(key, value);
            map[key] = node;
            queue.push(node);
        }
        else
        {
            Node *node = map[key];
            queue.makeMostRecent(node, value);
        }
    }
};

class LRUCache2
{
    size_t m_capacity;
    std::unordered_map<int, std::list<std::pair<int, int>>::iterator> m_map; // m_map_iter->first: key, m_map_iter->second: list iterator;
    std::list<std::pair<int, int>> m_list;                                   // m_list_iter->first: key, m_list_iter->second: value;
public:
    LRUCache2(size_t capacity) : m_capacity(capacity)
    {
    }
    int get(int key)
    {
        auto found_iter = m_map.find(key);
        if (found_iter == m_map.end()) // key doesn't exist
            return -1;
        m_list.splice(m_list.begin(), m_list, found_iter->second); // move the node corresponding to key to front
        return found_iter->second->second;                         // return value of the node
    }
    void set(int key, int value)
    {
        auto found_iter = m_map.find(key);
        if (found_iter != m_map.end()) // key exists
        {
            m_list.splice(m_list.begin(), m_list, found_iter->second); // move the node corresponding to key to front
            found_iter->second->second = value;                        // update value of the node
            return;
        }
        if (m_map.size() == m_capacity) // reached capacity
        {
            int key_to_del = m_list.back().first;
            m_list.pop_back();       // remove node in list;
            m_map.erase(key_to_del); // remove key in map
        }
        m_list.emplace_front(key, value); // create new node in list
        m_map[key] = m_list.begin();      // create correspondence between key and node
    }
};

int main()
{
    LRUCache *cache = new LRUCache(2);

    cache->put(1, 1);
    cache->put(2, 2);
    std::cout << cache->get(1) << std::endl;
    cache->put(3, 3);
    std::cout << cache->get(2) << std::endl;
    cache->put(4, 4);
    std::cout << cache->get(1) << std::endl;
    std::cout << cache->get(3) << std::endl;
    std::cout << cache->get(4) << std::endl;

    delete cache;
    return 0;
}