//
// Created by rjd67 on 2020/9/9.
//

#ifndef CPP_BINARYSEARCHST_H
#define CPP_BINARYSEARCHST_H

#include <vector>

template <class Key, class Value>
class BinarySearchST
{
public:
	BinarySearchST();
	~BinarySearchST();

	size_t Size() const;

	Value* Get(const Key& key);

	std::vector<Key> GetKeys() const;

	void Put(const Key& key, const Value& value);

	bool Empty() const;

	void Delete(const Key& key);
private:

	std::vector<Key> keys;
	std::vector<Value> values;
};


template <class Key, class Value>
size_t BinarySearchST<Key, Value>::Size() const
{
	return keys.size();
}

template <class Key, class Value>
Value* BinarySearchST<Key, Value>::Get(const Key& key)
{
	for (size_t keys_sub = 0; keys_sub < keys.size(); ++keys_sub)
	{
		if (keys[keys_sub] == key)
		{
			return &values[keys_sub];
		}
	}
}

template <class Key, class Value>
void BinarySearchST<Key, Value>::Put(const Key& key, const Value& value)
{
	for (size_t keys_sub = 0; keys_sub < keys.size(); ++keys_sub)
	{
		if (keys[keys_sub] > key)
		{
			keys.insert(keys.begin() + keys_sub, key);
			values.insert(values.begin() + keys_sub, value);
			return;
		}
		else if (keys[keys_sub] == key)
		{
			values[keys_sub] = value;
			return;
		}
	}

	keys.push_back(key);
	values.push_back(value);
}

template<class Key, class Value>
bool BinarySearchST<Key, Value>::Empty() const
{
	return keys.empty();
}

template<class Key, class Value>
void BinarySearchST<Key, Value>::Delete(const Key& key)
{
	for (size_t keys_sub = 0; keys_sub < keys.size(); ++keys_sub)
	{
		if (keys[keys_sub] == key)
		{
			keys.erase(keys.begin() + keys_sub);
			values.erase(values.begin() + keys_sub);
		}
	}
}

template<class Key, class Value>
BinarySearchST<Key, Value>::BinarySearchST():
		keys(),
		values()
{

}

template<class Key, class Value>
BinarySearchST<Key, Value>::~BinarySearchST()
{

}

template<class Key, class Value>
std::vector<Key> BinarySearchST<Key, Value>::GetKeys() const
{
	return keys;
}


#endif //CPP_BINARYSEARCHST_H
