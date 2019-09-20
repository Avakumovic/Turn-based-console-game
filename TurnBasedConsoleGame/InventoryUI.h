#pragma once
class InventoryUI
{
private:
	bool _inventoryActive = false;
public:
	InventoryUI();
	~InventoryUI();
	void SetInventoryActive(bool);
	bool GetInventoryActive();
	void OpenInventory(int);
};

