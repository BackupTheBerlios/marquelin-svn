#ifndef TRACK_H
#define TRACK_H

#include <QString>

class QGraphicsItem;
class Track
{
public:
	Track(const QString& name);
	~Track();

	QString name() const;

	QGraphicsItem* graphicsItem();

	enum UnitType {
		Millimeters,
		Radians
	};

private:
	QString m_name;
	QGraphicsItem *item;
	
	UnitType lengthUnit;
	int length;
	UnitType raduisUnit;
	int radius;
};

#endif
