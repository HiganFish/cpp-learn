#include <vector>
#include <string>
#include <memory>

class StrBlob // 我还去查了下 Blob是二进制数据块...
{
public:
	typedef std::vector<std::string>::size_type size_type;
	StrBlob();
	StrBlob(std::initializer_list<std::string> il);
	size_type Size() const;
	bool Empty() const;
	// 增删
	void PushBack(const std::string &t);
	void PopBack();
	// 访问
	std::string& Front();
	std::string& Back();

	const std::string& Front() const;
	const std::string& Back() const;

private:
	std::shared_ptr<std::vector<std::string>> data_;
	// 如果data[i] 不合法, 抛出一个异常
	void Check(size_type i, const std::string &msg) const;
};