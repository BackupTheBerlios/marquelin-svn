/*
 * This is Marquelin. Marquelin main window.
 * 
 * Copyright (C) 2009 Detlev Casanova <detlev.casanova@gmail.com>
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 *
 */

#ifndef MARQUELIN_WINDOW_H
#define MARQUELIN_WINDOW_H

#include <QObject>
#include <QMainWindow>

#include "ui_marquelinwindow.h"

class Track;
class TrackNetwork;
class TrackNetworkView;
class QPushButton;
class MarquelinWindow : public QMainWindow
{
	Q_OBJECT
public:
	MarquelinWindow();
	~MarquelinWindow();

private slots:
	void loadNetwork(bool);
	void saveNetwork(bool);
	void slotTrackChange();

private:
	Ui::marquelinWindow ui;
	QList<Track*> tracks;
	QList<QPushButton*> trackButtons;
	Track *currentTrack;
	TrackNetwork *trackNetwork;
	TrackNetworkView *tnv;

	void setCurrentTrack(Track*);
};

#endif //MARQUELIN_WINDOW_H
