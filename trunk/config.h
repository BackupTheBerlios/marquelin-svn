#ifndef CONFIG_H
#define CONFIG_H

#include <QList>

#include "track.h"

class Config
{
public:
	Config();
	~Config();

	static QList<Track*> loadAllTracks();

	static void saveNewTrack(Track*);
	static void saveNewTracks(QList<Track*>);
};

#endif //CONFIG_H
