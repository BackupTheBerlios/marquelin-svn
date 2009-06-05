#ifndef TRACK_NETWORK_VIEW_H
#define TRACK_NETWORK_VIEW_H

#include <QGraphicsView>

class TrackNetwork;
class Track;
class QMouseEvent;
class QGraphicsScene;
class QGraphicsItem;
class TrackNetworkView : public QGraphicsView
{
public:
	TrackNetworkView(QWidget *parent = 0);
	~TrackNetworkView();
	void setTrackNetwork(TrackNetwork*);
	void setCurrentTrack(Track* t);

private:
	TrackNetwork *m_network;

	void reset();
	void mouseMoveEvent(QMouseEvent *event);

	Track *m_currentTrack;

	QGraphicsItem *currentItem;
	QGraphicsScene *scene;
};

#endif
