#include "csstats/csstats.hpp"
#include <iostream>

int main() {
	csstats obj ("csstats.dat");

	int rows = obj.stats.size ();
	if(rows) {
		std::cout << "Rows: " << rows << std::endl;

		for(int i = 0; i < rows; i++) {
			std::cout << "=====" << std::endl;
			std::cout << "Name: " << obj.stats[i].name << std::endl;
			std::cout << "SteamID: " << obj.stats[i].steamid << std::endl;
			std::cout << "Team kills: " << obj.stats[i].tks << std::endl;
			std::cout << "Damage: " << obj.stats[i].damage << std::endl;
			std::cout << "Deaths: " << obj.stats[i].deaths << std::endl;
			std::cout << "Kills: " << obj.stats[i].kills << std::endl;
			std::cout << "Shots: " << obj.stats[i].shots << std::endl;
			std::cout << "Hits: " << obj.stats[i].hits << std::endl;
			std::cout << "Headshots: " << obj.stats[i].hs << std::endl;
			std::cout << "Bomb defusions: " << obj.stats[i].bDefusions << std::endl;
			std::cout << "Bomb defused: " << obj.stats[i].bDefused << std::endl;
			std::cout << "Bomb plants: " << obj.stats[i].bPlants << std::endl;
			std::cout << "Bomb explosions: " << obj.stats[i].bExplosions << std::endl;
		}
	}

	return 0;
}
