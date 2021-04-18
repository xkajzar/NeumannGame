#pragma once
#include "IUnit.hpp"

namespace game
{
	class Ranged : public IUnit
	{
	private:

	protected:

	public:
		Ranged(unsigned short hp,
			   ObjectType type,
			   const sf::Texture& texture,
			   engine::TilePtr location,
			   unsigned char moveSpeed,
			   unsigned char attackDamage,
			   unsigned char armour,
			   Ownership owner);

		virtual void update(std::shared_ptr<engine::Map> map,
							std::shared_ptr<engine::ObjectManager> objMan,
							bool toUpdate,
							PlayerState& playerState,
							ObjectType objType) override;
		virtual void attack(engine::IObjectPtr object) override;
		std::string getName() override;
	};
}