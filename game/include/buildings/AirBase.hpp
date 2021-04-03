#pragma once
#include "IBuilding.hpp"

namespace game
{
	class AirBase : public IBuilding
	{
	private:

	protected:

	public:
		AirBase(unsigned short hp,
			game::ObjectType type,
			const sf::Texture& texture,
			TilePtr location,
			unsigned short ironCost,
			unsigned short copperCost,
			unsigned short siliconCost,
			Player owner);
	};
}