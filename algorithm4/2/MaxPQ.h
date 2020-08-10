#pragma once

#include <vector>

template <class T>
class MaxPQ
{
public:
    MaxPQ();

    void Insert(const T &t);

    T Max();

    T DelMax();

    bool Empty();

    size_t Size();

private:
    std::vector<T> data_;
    size_t size_;

    void Sink(size_t data_sub);

    void Swim(size_t data_sub);

    void Swap(size_t sub_a, size_t sub_b);

    bool Less(size_t sub_a, size_t sub_b);
};

template<class T>
MaxPQ<T>::MaxPQ():
    data_(),
    size_(0)
{
    data_.push_back(0xFF);
}

template<class T>
void MaxPQ<T>::Insert(const T& t)
{
    data_.push_back(t);
    size_++;
    Swim(size_);
}

template<class T>
T MaxPQ<T>::Max()
{
    return data_[1];
}

template<class T>
T MaxPQ<T>::DelMax()
{
    T t = data_[1];

    Swap(1, size_);
    data_.pop_back();
    size_--;

    Sink(1);
    return t;
}

template<class T>
bool MaxPQ<T>::Empty()
{
    return size_ == 0;
}

template<class T>
size_t MaxPQ<T>::Size()
{
    return size_;
}

template<class T>
void MaxPQ<T>::Sink(size_t data_sub)
{
    size_t parent_sub = data_sub;
    size_t child_sub = 2 * parent_sub;
    
    while (child_sub <= size_)
    {
        if (child_sub + 1 <= size_)
        {
            if (Less(child_sub, child_sub + 1))
            {
                child_sub++;
            }
        }

        if (Less(child_sub, parent_sub))
        {
            break;
        }

        Swap(parent_sub, child_sub);
        parent_sub = child_sub;
        child_sub = 2 * parent_sub;
    }
}

template<class T>
void MaxPQ<T>::Swim(size_t data_sub)
{
    size_t child_sub = data_sub;
    size_t parent_sub = child_sub / 2;
    while ((parent_sub >= 1) && Less(parent_sub, child_sub))
    {

        Swap(parent_sub, child_sub);
        child_sub = parent_sub;
        parent_sub = child_sub / 2;
    }
}

template<class T>
void MaxPQ<T>::Swap(size_t sub_a, size_t sub_b)
{
    std::swap(data_[sub_a], data_[sub_b]);
}

template<class T>
bool MaxPQ<T>::Less(size_t sub_a, size_t sub_b)
{
    return data_[sub_a] < data_[sub_b];
}
