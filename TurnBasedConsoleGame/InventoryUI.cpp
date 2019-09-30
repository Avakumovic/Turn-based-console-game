#include "pch.h"
#include "InventoryUI.h"
#include "Player.h"
#include "Render.h"
#include <memory>
#include <Windows.h>
#include <string>
#include <conio.h>


InventoryUI::InventoryUI()
{
}


InventoryUI::~InventoryUI()
{
}

void InventoryUI::SetInventoryActive(bool inventoryActive)
{
	this->_inventoryActive = inventoryActive;
}

bool InventoryUI::GetInventoryActive()
{
	return _inventoryActive;
}

void InventoryUI::OpenInventory(int pressed_key)
{
	std::shared_ptr<Render> render(Render::GetRender());
	if (pressed_key == 105) {
		_inventoryActive = true;
		system("cls");
		std::vector<Item> inventoryItems = Player::GetPlayer()->GetInventoryItems();
		for (unsigned int i = 0; i < inventoryItems.size(); i++) {
			std::cout << i + 1 << ". " << (inventoryItems[i]).GetItemName() << std::endl;
		}
		int signed key;
		while(true)
		{
			char pressed_key = _getch();
			key = pressed_key - '0';
			if (key > (signed)0 && key <= (signed)inventoryItems.size()) {
				Player::GetPlayer()->UseItem(key-1);
				_inventoryActive = false;
				system("cls");
				render->MapRender();
				render->ItemPrintRender(inventoryItems[key - 1]);
				break;
			}
			if (pressed_key == 'i') {
				_inventoryActive = false;
				system("cls");
				render->MapRender();
				break;
			}
		}	
	}
}
