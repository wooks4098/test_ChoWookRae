#include "Inventory.h"

void main()
{
	Inventory* inventory = new Bag("Main Bag");

	Inventory* item1 = new Item("��");
	Inventory* item2 = new Item("Ȱ");
	Inventory* item3 = new Item("������");

	Inventory* bag1 = new Bag("�ֹ��� ����");
	Inventory* item4 = new Item("���̾");
	Inventory* item5 = new Item("�����Ʈ");

	Inventory* bag2 = new Bag("ȭ�� ����");
	Inventory* item6 = new Item("�� ȭ��");
	Inventory* item7 = new Item("�� ȭ��");

	Inventory* item8 = new Item("��");

	inventory->AddInventory(item1);
	inventory->AddInventory(item2);
	inventory->AddInventory(item3);

	bag1->AddInventory(item4);
	bag1->AddInventory(item5);
	inventory->AddInventory(bag1);

	bag2->AddInventory(item6);
	bag2->AddInventory(item7);
	inventory->AddInventory(bag2);

	inventory->AddInventory(item8);

	inventory->View();

	delete inventory;
}