#pragma once
#include <string>
using namespace std;

class French_fries
{
protected:
	virtual void fry() = 0;
public:
	French_fries();
	~French_fries();
};

class Original : public French_fries
{
	virtual void fry();
};

class Seasoned : public French_fries
{
	virtual void fry();
};
