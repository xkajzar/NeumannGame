#include "../include/MapGenerator.hpp"
#include <stdlib.h>
#include <time.h>
#include <iostream>

namespace engine
{
	void MapGenerator::generateMap(Map/*&*/ map, unsigned short numberOfPlanets, unsigned char maxRadiusOfPlanet)
	{
		unsigned short height = map.getHeight();
		unsigned short width = map.getWidth();
		srand(static_cast<unsigned int>(time(nullptr)));
		for (unsigned short i = 0; i < numberOfPlanets; ++i)
		{
			unsigned short x = rand() % height;
			unsigned short y = rand() % width;
			unsigned char type = rand() % 3 + 1;
			unsigned char radius = rand() % maxRadiusOfPlanet;
			map.setTile(x, y, type);


			if (radius == 0)
			{
				continue;
			}

			unsigned short cislo = 0;
			bool flag = true;

			for (unsigned char i = x - radius; i <= x + radius; ++i)
			{
				if (i < 0 || i >= map.getHeight())
				{
					continue;
				}

				for (unsigned char j = y - cislo; j <= y + cislo; ++j)
				{
					if (j < 0 || j >= map.getWidth())
					{
						continue;
					}

					if (map.getTile(i, j) != 0)
					{
						map.setTile(i, j, type);
					}
				}

				if (cislo < radius && flag)
				{
					++cislo;
				}
				else
				{
					flag = false;
					--cislo;
				}
			}

			/*
			if (map.getTile(x, y) == 0)
			{
				map.setTile(x, y, type);
				setPlanet(map, x, y, type, radius);
			}*/
		}

		for (unsigned short i = 0; i < height; ++i)
		{
			for (unsigned short j = 0; j < width; ++j)
			{
				TilePtr a = map.getTile(i, j);
				if (a.get()->getType() == 0)
					std::cout << " ";
				else
					std::cout << a.get()->getType();
			}
			std::cout << '\n';
		}
	}

	void MapGenerator::setPlanet(Map map, unsigned short x, unsigned short y, unsigned char type, unsigned char radius)
	{
		if (radius == 0)
		{
			return;
		}

		for (unsigned char i = x - radius; i < x + radius; ++i)
		{
			if (i < 0 || i >= map.getHeight())
			{
				continue;
			}

			for (unsigned char j = y - radius; j <= y + radius; ++j)
			{
				if (j < 0 || j >= map.getWidth())
				{
					continue;
				}

				if (map.getTile(i, j) != 0)
				{
					map.setTile(i, j, type);
				}
			}
		}
	}
}

/*
radius = 3
x = 4
y = 4

x-r = 1
y-r = 1

x+r = 7
y+r = 7

  0 1 2 3 4 5 6 7
0
1         *      
2       * * *    
3     * * * * *  
4   * * * * * * *
5     * * * * *  
6       * * *    
7         *      
*/