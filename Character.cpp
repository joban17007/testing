#include "Character.h"
#include <iostream>

Character::Character(const std::string& name, Room* startingRoom)
	: name(name), currentRoom(startingRoom) {}

std::string Character::getName() const {
	return name;
}

Room* Character::getCurrentRoom() const {
	return currentRoom;
}

void Character::move(char direction) {
	Room* nextRoom = nullptr;
	switch (toupper(direction)) {
	case 'N':
		nextRoom = currentRoom->moveNorth();
		break;
	case 'S':
		nextRoom = currentRoom->moveSouth();
		break;
	case 'E':
		nextRoom = currentRoom->moveEast();
		break;
	case 'W':
		nextRoom = currentRoom->moveWest();
		break;
	default:
		std::cout << "Invalid direction!" << std::endl;
		return;
	}

	if (nextRoom) {
		currentRoom = nextRoom;
	}
	else {
		std::cout << "Invalid move!" << std::endl;
	}
}

void Character::pickUpWeapon(Weapon* weapon) {
	weapons.push_back(weapon);
	std::cout << "Picked up " << weapon->getName() << "." << std::endl;
}

void Character::displayInventory() const {
	std::cout << "Inventory: " << std::endl;
	for (const auto& weapon : weapons) {
		std::cout << "- " << weapon->getName() << std::endl;
	}
}

void Character::attackEnemy(Enemy* enemy) {
	if (!weapons.empty()) {
		Weapon* weapon = weapons.back();
		enemy->takeDamage(weapon->getDamage());
		std::cout << "Attacked " << enemy->getName() << " with " << weapon->getName() << " for " << weapon->getDamage() << " damage." << std::endl;
	}
	else {
		std::cout << "No weapons to attack with!" << std::endl;
	}
}

const std::vector<Weapon*>& Character::getWeapons() const {
	return weapons;
}
