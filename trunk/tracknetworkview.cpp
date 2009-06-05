#include <QDebug>
#include <QMouseEvent>
#include <QGraphicsScene>
#include <QGraphicsTextItem>

#include "track.h"
#include "tracknetworkview.h"

TrackNetworkView::TrackNetworkView(QWidget *parent)
 : QGraphicsView(parent),
   m_currentTrack(0),
   currentItem(0),
   scene(0)
{

}

TrackNetworkView::~TrackNetworkView()
{
	//delete scene;
	//delete currentItem;
}


void TrackNetworkView::setTrackNetwork(TrackNetwork* tn)
{
	m_network = tn;
	reset();
}

void TrackNetworkView::setCurrentTrack(Track* t)
{
	m_currentTrack = t;
	scene->removeItem(currentItem);
	currentItem = t->graphicsItem();
	scene->addItem(currentItem);
}

void TrackNetworkView::reset()
{

}

void TrackNetworkView::mouseMoveEvent(QMouseEvent *event)
{
	if (!scene)
	{
		scene = new QGraphicsScene(this);
		setScene(scene);
		centerOn(width(), height());
	}
	
	if (!currentItem)
	{
		currentItem = new QGraphicsTextItem(QString("(%1, %2)").arg(event->x()).arg(event->y()));
		scene->addItem(currentItem);
	}
	else if (!m_currentTrack)
		dynamic_cast<QGraphicsTextItem*>(currentItem)->setPlainText(QString("(%1, %2)").arg(event->x()).arg(event->y()));
	
	currentItem->setPos(mapToScene(QPoint(event->x(), event->y())));
}
