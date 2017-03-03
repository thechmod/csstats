#ifndef CSSTATS_H
#define CSSTATS_H

#include "csstats.hpp"
#include <iostream>
#include <vector>

struct hitmapEntry {
    int alwaysZero;
    int head;
    int chest;
    int stomach;
    int leftArm;
    int rightArm;
    int leftLeg;
    int rightLeg;
};

struct statsEntry {
	char name[512];
	char steamid[512];
	unsigned int tks;
	unsigned int damage;
	unsigned int deaths;
	int kills;
	unsigned int shots;
	unsigned int hits;
	unsigned int hs;
	unsigned int bDefusions;
	unsigned int bDefused;
	unsigned int bPlants;
	unsigned int bExplosions;
	hitmapEntry hitmap;
};

class csstats {
	private:
		std::string path;
		void load ();

	public:
		std::vector<statsEntry> stats;
		csstats (std::string p);
		void reload ();
};

#endif
