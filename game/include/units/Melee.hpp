#pragma once
#include "IUnit.hpp"

namespace game
{
	class Melee : public IUnit
	{
	private:

	protected:

	public:
		Melee(unsigned short hp,
			game::ObjectType type,
			const sf::Texture& texture,
			engine::TilePtr location,
			unsigned char moveSpeed,
			unsigned char attackDamage,
			unsigned char armour,
			game::Ownership owner);

		virtual void update() override;
		virtual void attack(engine::IObjectPtr object) override;
	};
}