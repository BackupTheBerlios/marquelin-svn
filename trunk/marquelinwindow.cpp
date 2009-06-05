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

#include <QAction>
#include <QPushButton>
#include <QDebug>

#include "marquelinwindow.h"
#include "track.h"
#include "tracknetwork.h"
#include "tracknetworkview.h"
#include "config.h"

MarquelinWindow::MarquelinWindow()
{
	ui.setupUi(this);

	//Setup actions
	QAction *loadAction = ui.toolBar->addAction("Load...");
	QAction *saveAction = ui.toolBar->addAction("Save...");

	connect(loadAction, SIGNAL(triggered(bool)), SLOT(loadNetwork(bool)));
	connect(saveAction, SIGNAL(triggered(bool)), SLOT(saveNetwork(bool)));

	//Setup tracks
	QLayout *layout = ui.verticalLayout;
	QLayoutItem *spacer = layout->takeAt(layout->count() - 1);
	
	tracks = Config::loadAllTracks();
	for (int i = 0; i < tracks.count(); i++)
	{
		QPushButton *pb = new QPushButton(tracks.at(i)->name());
		pb->setCheckable(true);
		trackButtons << pb;
		layout->addWidget(pb);
		connect(pb, SIGNAL(clicked()), SLOT(slotTrackChange()));
	}
	
	layout->addItem(spacer);

	currentTrack = 0;

	//Create Network view
	tnv = new TrackNetworkView(this);
	//tnv->setGrid(true);
	ui.horizontalLayout->addWidget(tnv);

	trackNetwork = new TrackNetwork();
}

MarquelinWindow::~MarquelinWindow()
{

}

void MarquelinWindow::loadNetwork(bool)
{

}

void MarquelinWindow::saveNetwork(bool)
{

}

void MarquelinWindow::slotTrackChange()
{
	QPushButton *pushed = dynamic_cast<QPushButton*>(sender());
	if (!pushed)
		return;

	for (int i = 0; i < trackButtons.count(); i++)
	{
		if (pushed == trackButtons.at(i))
		{
			trackButtons[i]->setChecked(true);
			setCurrentTrack(tracks.at(i));
		}
		else if (trackButtons.at(i)->isChecked())
			trackButtons[i]->setChecked(false);
	}
}

void MarquelinWindow::setCurrentTrack(Track* t)
{
	currentTrack = t;
	tnv->setCurrentTrack(t);
	qDebug() << "Current track =" << t->name();
}

