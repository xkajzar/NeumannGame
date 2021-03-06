#include "../../include/buildings/SpaceStation.hpp"
#include "../../../engine/include/UnitFactory.hpp"

namespace game
{
	SpaceStation::SpaceStation(unsigned short hp,
							   ObjectType type,
							   const sf::Texture& texture,
							   engine::TilePtr location,
							   unsigned short ironCost,
							   unsigned short copperCost,
							   unsigned short siliconCost,
							   Ownership owner)
							   :
							   IBuilding{ hp, type, texture, location, ironCost, copperCost, siliconCost, owner },
							   IObject{ hp, type, texture, location, owner }
	{}

	bool SpaceStation::update(PlayerState& playerState1, PlayerState& playerState2, int* changed, 
							  std::shared_ptr<engine::Map> map,
							  std::shared_ptr<engine::ObjectManager> objMan)
	{
		if (playerState1.checkBalance(getIronCost(), getCopperCost(), getSiliconCost()))
		{
			playerState1.updatePlayerBalances(-getIronCost(), -getCopperCost(), -getSiliconCost());
			auto xy = engine::GetNearestFreeLocation(getLocation(), objMan);
			engine::TilePtr location = map->getTile(xy.first, xy.second);

			if (location->getTileType() != TileType::Void)
			{
				if (location->getOccupied() == getOwner()) {}
				else if (location->getOccupied() == Ownership::Unoccupied)
				{
					playerState1.updateLand(1);
					location->setOccupied(getOwner());
					*changed = 1;
				}
				else
				{
					playerState1.updateLand(1);
					playerState2.updateLand(-1);
					location->setOccupied(getOwner());
					*changed = 1;
				}
			}

			build(location, objMan);
			return true;
		}
		return false;
	}

	void SpaceStation::build(engine::TilePtr location, std::shared_ptr<engine::ObjectManager> OM)
	{
		auto unit = engine::unitFactory->create(ObjectType::Worker, location, getOwner());
		OM->addUnit(unit);
	}
  
	std::string SpaceStation::getBuildUnitName()
	{
		return "Worker";
	}

	std::string SpaceStation::getName()
	{
		return "Space station";
	}
}