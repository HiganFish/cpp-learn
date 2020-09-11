#pragma once
#include <vector>

template <class Key, class Value>
class SequentialSearchST
{
public:
    SequentialSearchST();
    ~SequentialSearchST();

    void Put(Key key, Value value);

    Value* Get(Key key);

    void Delete(Key key);

    bool Contains(Key key) const;

    bool Empty() const;

    size_t Size() const;

    std::vector<Key> GetKeys() const;

private:

    struct Node
    {
        Node(Key k, Value v, Node* n):
            key(k),
            value(v),
            next(n)
        {

        }
        Key key;
        Value value;

        Node* next;
    };

    Node* head_;

};

template <class Key, class Value>
SequentialSearchST<Key, Value>::SequentialSearchST() :
    head_(nullptr)
{

}

template <class Key, class Value>
SequentialSearchST<Key, Value>::~SequentialSearchST()
{
    Node* next_node = nullptr;
    while (head_)
    {
        next_node = head_->next;

        delete head_;
        head_ = next_node;
    }
}

template <class Key, class Value>
void SequentialSearchST<Key, Value>::Put(Key key, Value value)
{
//    if (head_ == nullptr)
//    {
//        head_ = new Node(key, value, nullptr);
//    }
//    else
//    {
//        Node* node = head_;
//        while (node->next != nullptr)
//        {
//            node = node->next;
//        }
//        node->next = new Node(key, value, nullptr);
//    }

	// 2020年9月9日15:13:31
	for (Node* node = head_; node != nullptr; node = node->next)
	{
		if (node->key == key)
		{
			node->value = value;
			return;
		}
	}
	head_ = new Node(key, value, head_);
}

template <class Key, class Value>
Value* SequentialSearchST<Key, Value>::Get(Key key)
{
//    Node* node = head_;
//    while (node)
//    {
//        if (node->key == key)
//        {
//            return &node->value;
//        }
//        else
//        {
//            node = node->next;
//        }
//    }

	// 2020年9月9日15:13:26
	for (Node* node = head_; node != nullptr; node = node->next)
	{
		if (node->key == key)
		{
			return &node->value;
		}
	}

    return nullptr;
}

template <class Key, class Value>
void SequentialSearchST<Key, Value>::Delete(Key key)
{
    Node* node = head_;

    if (!node)
    {
        return;
    }

//    Node* last_node = node;
//    while (node)
//    {
//        if (node->key == key)
//        {
//            if (node == head_)
//            {
//                Node* node = head_->next;
//                delete head_;
//                head_ = node;
//            }
//            else
//            {
//                last_node->next = node->next;
//                delete node;
//            }
//            return;
//        }
//
//        last_node = node;
//        node = node->next;
//    }

	// 2020年9月9日15:13:18
	Node* last_node = head_;
	for (Node* node = head_; node != nullptr; node = node->next)
	{
		if (node->key == key)
		{
			Node* new_next = node->next;
			delete last_node->next;
			last_node->next = new_next;
		}

		last_node = node;
	}
}

template<class Key, class Value>
 std::vector<Key> SequentialSearchST<Key, Value>::GetKeys() const
{
    std::vector<Key> keys;

    for (Node* node = head_; node != nullptr; node = node->next)
    {
        keys.push_back(node->key);
    }

    return keys;
}

template <class Key, class Value>
bool SequentialSearchST<Key, Value>::Contains(Key key) const
{
    return Get(key) != nullptr;
}

template <class Key, class Value>
bool SequentialSearchST<Key, Value>::Empty() const
{
    return Size() == 0;
}

template<class Key, class Value>
size_t SequentialSearchST<Key, Value>::Size() const
{
    size_t size = 0;
    Node* node = head_;
    while (node)
    {
        size++;
        node = node->next;
    }

    return size;
}
