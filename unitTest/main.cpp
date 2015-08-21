/*
 * main.cpp
 *
 *  Created on: 21-Aug-2015
 *      Author: radix
 */


#include "test.h"
#include <iostream>

using namespace std;

void testOperation1()
{
cout << "operation1 started" << endl;

}

void testOperation2()
{
cout << "operation2 started" << endl;

}

int main()
{
	test tobj;

	tobj.add(testOperation1,"test");
	tobj.add(testOperation2,"test");
	tobj.run();

return 0;
}
