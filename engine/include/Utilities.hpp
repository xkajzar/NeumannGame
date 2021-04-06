#pragma once
#include <SFML/System/Vector2.hpp>
#include "JsonParser.hpp"

namespace engine
{
	static sf::Vector2u ScreenToTile(const sf::Vector2f& position)
	{
		return sf::Vector2u(position.x / config->getTileSize(), position.y / config->getTileSize());
	}

	static sf::Vector2f TileToScreen(const sf::Vector2u& position)
	{
		return sf::Vector2f(position.x * config->getTileSize(), position.y * config->getTileSize());
	}
}
