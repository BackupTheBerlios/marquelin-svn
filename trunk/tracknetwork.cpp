#include "tracknetwork.h"
#include "trackelement.h"

TrackNetwork::TrackNetwork()
{
	root = 0;
}

TrackNetwork::~TrackNetwork()
{

}

TrackElement* TrackNetwork::addTrack(Track* track, TrackElement* pos)
{
	if (!root)
	{
		root = new TrackElement(track);
		return root;
	}

	return new TrackElement(track);
}
