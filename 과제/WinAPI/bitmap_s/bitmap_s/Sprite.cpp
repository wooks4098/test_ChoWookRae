#include "Sprite.h"


void Sprite::Create_Sprite()
{
	DataSet_Sprite("����", IDB_PNG1);
	DataSet_Sprite("�ﰢ��", IDB_PNG2);
	DataSet_Sprite("������", IDB_PNG3);
	DataSet_Sprite("��", IDB_PNG4);
	DataSet_Sprite("��Ʈ", IDB_PNG5);
	DataSet_Sprite("����", IDB_PNG6);
	DataSet_Sprite("����", IDB_PNG7);
	DataSet_Sprite("��", IDB_PNG8);
	DataSet_Sprite("����ǥ", IDB_PNG9);
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