/*
 * test.cpp
 *
 *  Created on: 21-Aug-2015
 *      Author: radix
 */
#include "test.h"
using namespace std;

void test::add(funcPtr func, std::string name)
{
	test_info test1(func, name);
	listTestInfo.push_back(test1);

}

void test::run()
{
	list<test_info>::iterator itr;
	itr = listTestInfo.begin();
	itr = listTestInfo.end();

	for (itr = listTestInfo.begin(); itr != listTestInfo.end(); itr++)
	{
		_ptr = &(*itr);
		_ptr->_func();
	}

}

