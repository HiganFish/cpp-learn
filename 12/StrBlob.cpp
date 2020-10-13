#include "StrBlob.h"


StrBlob::StrBlob():
data_(std::make_shared<std::vector<std::string>>())
{

}

StrBlob::StrBlob(std::initializer_list<std::string> il)
:
data_(std::make_shared<std::vector<std::string>>(il))
{

}

std::string& StrBlob::Front()
{
	Check(0, "front on empty StrBlob");
	return data_->front();
}

std::string& StrBlob::Back()
{
	Check(0, "back on empty StrBlob");
	return data_->back();
}

const std::string& StrBlob::Front() const
{
	Check(0, "front on empty StrBlob");
	return data_->front();
}

const std::string& StrBlob::Back() const
{
	Check(0, "back on empty StrBlob");
	return data_->back();
}

void StrBlob::PopBack()
{
	Check(0, "pop_back on empty StrBlob");
	data_->pop_back();
}

// 下标检查
void StrBlob::Check(size_type i, const std::string &msg) const
{
	if (i >= data_->size())
	{
		throw std::out_of_range(msg);
	}
}

StrBlob::size_type StrBlob::Size() const
{
	return data_->size();
}

bool StrBlob::Empty() const
{
	return data_->empty();
}

void StrBlob::PushBack(const std::string& t)
{
	data_->push_back(t);
}
