// ConsoleApplication1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <string>
#include <iostream>

using std::cout;
using std::string;
using std::cin;
using std::endl;
// 一般情况下，忽略此文件，但如果你使用的是预编译标头，请保留它。

template<typename  T>
void Half_Search(T *a, int start, int end, T target)
{
	if (start >= end && a[start] != target)
	{
		cout << "没有" << endl;
		return;
	}
	//int j = ((unsigned int)start + (unsigned int)end) >> 1;
	int j = start + ((end - start) >> 1);
	if (a[j] == target)
	{
		cout << "找到了" << endl;
		return;
	}
	else if (a[j] > target)
	{
		Half_Search(a, start, j, target);
	}
	else if (a[j] < target)
	{
		Half_Search(a, j, end, target);
	}
}
namespace init
{
	long MAX = 500000L;

	//获取数据(数值)
	long Get_a_target_value()
	{
		long target;
		cout << "target (0~" << MAX << ")" << endl;
		cin >> target;
		return target;
	}
	//获取字符
	string Get_a_target_string()
	{
		long target = 0;
		char buf[10] = { 0 };
		cout << "target (0~" << MAX << ")" << endl;
		cin >> target;
		snprintf(buf, 10, "%d", target);
		return string(buf);
	}
	//比较
	int compareLongs(const void* a, const void* b)
	{
		return (*(long*)a - *(long*)b);
	}
}

#include <vector>
#include <time.h>
#include <algorithm>
#include <cstdio>
namespace practical_1
{
	void TestVector(long& value)
	{
		srand((int)time(0));
		std::vector<int> vec;
		for(int i=0;i<=value;i++)
		{
			try
			{
				vec.push_back(rand());
			}
			catch (std::exception& p)
			{
				cout << "i=" << i << " " << p.what() << endl;
				abort();
			}
		}
		int target = init::Get_a_target_value();
		int startTime = clock();
		auto pItem = ::std::find(vec.begin(), vec.end(), target);
		if(pItem!=vec.end())
		{
			cout << "找到了!"<<*pItem << endl;
		}else
		{
			cout << "没有" << endl;
		}
		cout << "花费的时间是："<<clock()-startTime << endl;
		std::sort(vec.begin(), vec.end());
		cout << "排序需要是时间：" << clock() - startTime << endl;
		cout << endl;
		int *p = vec.data();
		int Length = vec.size();
		Half_Search(p, 0, Length, target);
	}
	
}

int main()
{
	long value;
	cout << "请选择一个测试环境" << endl;
	int i=0;
	cin >> i;
	cout << "请输入元素数目" << endl;
	cin >> value;
	switch (i)
	{
	case 1:
		{
		practical_1::TestVector(value);
	}break;
	case 2:
		{
	}break;
	default:break;
	}
}
// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
