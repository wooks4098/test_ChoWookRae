#include "Sprite.h"


void Sprite::Create_Sprite()
{
	DataSet_Sprite("엑스", IDB_PNG1);
	DataSet_Sprite("삼각형", IDB_PNG2);
	DataSet_Sprite("오각형", IDB_PNG3);
	DataSet_Sprite("원", IDB_PNG4);
	DataSet_Sprite("하트", IDB_PNG5);
	DataSet_Sprite("번개", IDB_PNG6);
	DataSet_Sprite("번개", IDB_PNG7);
	DataSet_Sprite("달", IDB_PNG8);
	DataSet_Sprite("물음표", IDB_PNG9);
}

void Sprite::DataSet_Sprite(std::string name, int Id)
{
	Image newimage;
	GetObject(m_pMyBitMap, sizeof(Bit_Info), &Bit_Info);
	m_size.cx = Bit_Info.bmWidth;
	m_size.cy = Bit_Info.bmHeight;
	newimage.ID = Id;
	newimage.Height = 
	sprite.insert(std::make_pair(name, newimage));
}

void Sprite::Find_Sprite(RECT* rect, int *id)
{

}