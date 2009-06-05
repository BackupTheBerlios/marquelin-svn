#include <QGraphicsItem>
#include <QGraphicsTextItem>

#include "track.h"

Track::Track(const QString& name)
 : item(0)
{
	m_name = name;
	lengthUnit = Millimeters;
	length = 150;
	raduisUnit = Radians;
	radius = 0;
}

Track::~Track()
{

}

QString Track::name() const
{
	return m_name;
}

QGraphicsItem* Track::graphicsItem()
{
	if (!item)
		item = new QGraphicsTextItem(m_name);
	
	return item;
}
