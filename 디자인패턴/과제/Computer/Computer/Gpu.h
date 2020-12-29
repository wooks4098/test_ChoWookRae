#pragma once
class Gpu
{
	virtual bool On() = 0;

};

class Gpu_geforce : public Gpu
{
	virtual bool On();


};

class Gpu_mx : public Gpu
{
	virtual bool On();

};
