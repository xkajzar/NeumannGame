#include "../include/ObjectManager.hpp"
#include "../include/IObject.hpp"
#include <iostream>

namespace engine
{
	ObjectManager::ObjectManager() {}

	std::vector<IObjectPtr> ObjectManager::getPlayerObjects()
	{
		return playerObjectVector;
	}

	void ObjectManager::drawAll(sf::RenderWindow* window)
	{
		for (int it = 0; it < playerObjectVector.size(); it++)
		{
			playerObjectVector[it]->draw(window);
		}
	}

	void ObjectManager::addUnit(IObjectPtr unit)
	{
		playerObjectVector.push_back(unit);
	}

	IObjectPtr ObjectManager::findUnit(int x, int y, game::Ownership player)
	{
		for (int it = 0; it < playerObjectVector.size(); it++)
		{
			if (playerObjectVector[it]->getPosition().x == x && playerObjectVector[it]->getPosition().y == y)
			{
				std::cout << "found ";
				std::cout << (int)playerObjectVector[it]->getOwner();
				std::cout << '\n';
				if (player == playerObjectVector[it]->getOwner())
				{
					std::cout << "Unit selected\n";
					return playerObjectVector[it];
				}
				else
				{
					std::cout << "Other players unit\n";
				}
			}
			
		}
		return nullptr;
	}
}