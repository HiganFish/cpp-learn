//
// Created by rjd67 on 2020/5/24.
//

#include <tuple>
#include <iostream>
#include <bitset>

class Money
{
public:
	explicit Money(int dollar):
	dollar_(dollar)
	{}

	void DebugAgeString(const std::string& msg)
	{ std::cout << dollar_ << "- msg: "  << msg << std::endl; }

private:
	int dollar_;
};

class Bank
{
public:
	explicit Bank(Money money):
	money_(money)
	{
		money_.DebugAgeString("Constructor");
	}

private:

	Money money_;
};

void Foo1()
{
	Money money(1);
	Bank bank1(money);
	// Bank bank2(2);


	auto item = std::make_tuple("123-123-123", 3, 20.00);
	std::tuple<std::string, int, float> item1("234-234-234", 2, 30.00);

	auto book = std::get<0>(item);
	std::get<2>(item) *= 0.8;
	std::cout << "money: " << std::get<2>(item);
}


int main(int argc, char* argv[])
{
	std::bitset<32> b;

	// 以下位不足 高位都补0

	unsigned long long u = ULLONG_MAX;
	std::bitset<32> bu(u);

	std::string s1 = "10101010101010";
	std::bitset<32> bs1(s1);
	std::string s2 = "ababaabbababb";
	// std::bitset<32> bs2(s2); std::invalid_argument
	// a instand 0 b instand 1
	std::bitset<32> bs2(s2, 0, 32, 'a', 'b');

	bu.any(); // 存在 置位(1) 的二进制位吗
	bu.all(); // 所有位都置位了吗
	bu.none(); // b中不存在置位的二进制位吗
	bu.count(); // 置位数目
	bu.size(); // 数目

	bu.test(1); // 位置1是置位的返回true 否则返回false
	bu.set(1, true); // 将1位 置 true->1 false->0
	bu.reset(1); // 将1位复位 置0
	bu.reset(); // 将所有位复位 置0

	bu.flip(1); // 1位取反
	bu.flip(); // 全部取反
	bu[1].flip();

	bu[1]; // 1位 1->true 0->false

	bu.to_ulong();
	bu.to_ullong();

	bu.to_string('a', 'b'); // 0->a 1->b

}
