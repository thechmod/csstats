#include "csstats.hpp"
#include <iostream>
#include <fstream>

csstats::csstats (std::string p) {
    csstats::path = p;
    load ();
}

void csstats::load () {
    unsigned short int nextLine;
    FILE *bfp = fopen(path.c_str(), "rb");

    if(bfp) {
        short int VERSION;
        fread(&VERSION, sizeof(short int), 1, bfp);
        if (VERSION != 11) {
            std::cout << "Bad stats version.";
            return;
        }

        while (!feof(bfp)) {
            statsEntry entry;

            fread (&nextLine, sizeof(unsigned short int), 1, bfp);
            fread (&entry.name[0], nextLine, 1, bfp);
            fread (&nextLine, sizeof(unsigned short int), 1, bfp);
            fread (&entry.steamid[0], nextLine, 1, bfp);
            fread (&entry.tks, sizeof(unsigned int), 1, bfp);
            fread (&entry.damage, sizeof(unsigned int), 1, bfp);
            fread (&entry.deaths, sizeof(unsigned int), 1, bfp);
            fread (&entry.kills, sizeof(int), 1, bfp);
            fread (&entry.shots, sizeof(unsigned int), 1, bfp);
            fread (&entry.hits, sizeof(unsigned int), 1, bfp);
            fread (&entry.hs, sizeof(unsigned int), 1, bfp);
            fread (&entry.bDefusions, sizeof(unsigned int), 1, bfp);
            fread (&entry.bDefused, sizeof(unsigned int), 1, bfp);
            fread (&entry.bPlants, sizeof(unsigned int), 1, bfp);
            fread (&entry.bExplosions, sizeof(unsigned int), 1, bfp);
            fread (&entry.bodyHits, sizeof(entry.bodyHits), 1, bfp);

            csstats::stats.push_back(entry);
        }
    } else {
        std::cout << "File " << path << " not found.";
        return;
    }
}

void csstats::reload () {
    csstats::stats.clear ();
    load ();
}
