#include "config.h"

Config::Config()
{
}

Config::~Config()
{
}

QList<Track*> Config::loadAllTracks()
{
	QList<Track*> ret;

	ret << new Track("Test track1");
	ret << new Track("Test track2");
	ret << new Track("Test track3");
	ret << new Track("Test track4");

	return ret;
}

void Config::saveNewTrack(Track*)
{

}

void Config::saveNewTracks(QList<Track*>)
{

}
