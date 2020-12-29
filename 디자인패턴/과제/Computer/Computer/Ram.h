#pragma once
class Ram
{
	virtual bool On() = 0;
};

class Ram_desktop : public Ram
{
	virtual bool On();

};

class Ram_laptop : public Ram
{
	virtual bool On();
};