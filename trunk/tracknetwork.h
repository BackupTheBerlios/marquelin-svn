#ifndef TRACK_NETWORK_H
#define TRACK_NETWORK_H

class TrackElement;
class Track;
class TrackNetwork
{
public:
	TrackNetwork();
	~TrackNetwork();

	TrackElement* addTrack(Track*, TrackElement*);
private:
	TrackElement *root;
};

#endif
