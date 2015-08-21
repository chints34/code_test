/*
 * test.h
 *
 *  Created on: 21-Aug-2015
 *      Author: radix
 */

#ifndef TEST_H_
#define TEST_H_

#include <string>
#include <list>

class test
{
public:

	typedef void (*funcPtr)();
	test()
	{
		_ptr = NULL;
	}
	struct test_info
	{
		funcPtr _func;
		std::string _name;

		test_info(funcPtr func, std::string name)
				: _func(func), _name(name)
		{

		}
	};

	void add(funcPtr func, std::string name);
	void run();

private:
	std::list<test_info> listTestInfo;
	test_info* _ptr;

};

#endif /* TEST_H_ */
