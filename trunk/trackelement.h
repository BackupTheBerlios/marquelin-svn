#ifndef TRACK_ELEMENT_H
#define TRACK_ELEMENT_H

class Track;
class TrackElement
{
public:
	TrackElement(Track *t = 0);
	~TrackElement();
	
private:
	Track *m_track;
};

#endif
