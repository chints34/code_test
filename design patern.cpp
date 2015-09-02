//============================================================================
// Name        : design.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Design Pattern in C++, Ansi-style
//============================================================================
///

#define SINGLETON 0
#define ABSTRACT 0
#define TEMPLATE 0
#define BRIDGE 1
#define OBJECT_POOL 0

#if SINGLETON
//Design Pattern ::: Singleton
#include <iostream>
using namespace std;

class singlton
{
public:
	static singlton* geInstance();
private:
	static singlton *sobj;

	singlton()
	{
		cout << "welcome to singlton" << endl;
	}
};
singlton *singlton::sobj = 0;
singlton* singlton::geInstance()
{
	if(!sobj)
	{
		sobj = new singlton();
		cout << "welcome to singlton first time" << endl;
		return sobj;
	}
	else
	{
		cout << "welcome to singlton again" << endl;
		return sobj;
	}
}

int main()
{

	singlton *obj = singlton::geInstance();
	singlton *obj1 = singlton::geInstance();
	delete obj;
	return 0;
}
#endif

#if ABSTRACT
#include <string>
#include <iostream>

using namespace std;

class button
{
public:
	virtual void paint()=0;
	virtual ~button()
	{}
};

class scroll
{
public:
	virtual void paint()=0;
	virtual ~scroll()
	{}
};

class WinButton : public button
{
public:
	virtual void paint()
	{
		std::cout << "windows button creayted" << std:: endl;
	}
	~WinButton()
	{}
};

class MacButton : public button
{
public:
	virtual void paint()
	{
		std::cout << "Mac button creayted" << std:: endl;
	}
	~MacButton()
	{}
};

class WinScroll: public scroll
{
public:
	virtual void paint()
	{
		std::cout << "windows scroll creayted" << std:: endl;
	}
	~WinScroll()
	{}
};

class MacScroll : public scroll
{
public:
	virtual void paint()
	{
		std::cout << "Mac scroll creayted" << std:: endl;
	}
	~MacScroll()
	{}
};

class GuiFactory
{
public:

	virtual button* creteButton()=0;
	virtual scroll* creteScroll()=0;

	virtual ~GuiFactory()
	{}
};

/// windows factory
class WinFactory:public GuiFactory
{
public:
	button* creteButton()
	{
		return new WinButton;
	}
	scroll* creteScroll()
	{
		return new WinScroll;
	}

};

/// Mac factory
class MacFactory:public GuiFactory
{
public:

	button* creteButton()
	{
		return new MacButton;
	}
	scroll* creteScroll()
	{
		return new MacScroll;
	}

};

int main()
{
	GuiFactory *gptr;
	button *bptr;
	scroll *sptr;

	///create windows gui
	gptr = new WinFactory();
	bptr = gptr->creteButton();
	bptr->paint();
	sptr = gptr->creteScroll();
	sptr->paint();

///create Mac gui
	gptr = new MacFactory();
	bptr = gptr->creteButton();
	bptr->paint();
	sptr = gptr->creteScroll();
	sptr->paint();

	return 0;
}

#endif

#if TEMPLATE

#include <iostream>
using namespace std;

class CarBuilder
{

	//Template Method that specifies the general logic
public:
	void BuildCar()
	{
		cout << "common finctionality" << endl;
		BuildSkeleton();
		InstallEngine();
		InstallDoor();
	}
	virtual ~CarBuilder()
	{}
protected:
	virtual void BuildSkeleton() = 0;
	virtual void InstallEngine()=0;
	virtual void InstallDoor()=0;

};

class bmw : public CarBuilder
{
public:
	void BuildSkeleton()
	{
		std::cout << "bmw BuildSkeleton" << std::endl;
	}
	void InstallEngine()
	{
		std::cout << "bmw InstallEngine" << std::endl;
	}
	void InstallDoor()
	{
		std::cout << "bmw InstallDoor" << std::endl;

	}

};

class porche: public CarBuilder
{
public:
	void BuildSkeleton()
	{
		std::cout << "porche BuildSkeleton" << std::endl;
	}
	void InstallEngine()
	{
		std::cout << "porche InstallEngine" << std::endl;
	}
	void InstallDoor()
	{
		std::cout << "porche InstallDoor" << std::endl;

	}

};

int main()
{
	//build porche
	CarBuilder *car1 = new porche();
	car1->BuildCar();
	//build bmw
	CarBuilder *car2 = new bmw();
	car2->BuildCar();
	return 0;
}
#endif

#if BRIDGE

#include <iostream>

class TimeImpl
{
public:
	TimeImpl(int hr, int min)
			: _hr(hr), _min(min)
	{
	}
	virtual void tell()
	{
		std::cout << _hr << ":" << _min << std::endl;
	}
	virtual ~TimeImpl()
	{
	}

protected:
	int _hr;
	int _min;
};

class StdTimeImpl : public TimeImpl
{
public:
	StdTimeImpl(int hr, int min, char *std)
			: TimeImpl(hr, min)
	{
		_std = std;
	}

	virtual void tell()
	{
		std::cout << _hr << ":" << _min << " " << _std << std::endl;
	}
	~StdTimeImpl()
	{
	}
private:
	char *_std;
};

class Time
{
public:
	Time()
	{
		impl = NULL;
	}
	;
	Time(int hr, int min)
	{
		impl = new TimeImpl(hr, min);
	}
	virtual void tell()
	{
		impl->tell();
	}
	virtual ~Time()
	{
	}
protected:
	TimeImpl *impl;
};

class StdTime : public Time
{
public:
	StdTime(int hr, int min, char *pm)
	{
		impl = new StdTimeImpl(hr, min, pm);
	}

};

int main()
{
	Time *tptr;
	tptr = new Time(12, 11);
	tptr->tell();

	tptr = new StdTime(12, 11, "PM");
	tptr->tell();

	return 0;
}

#endif
