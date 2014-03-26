#include "resultswin.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QString>
#include <QPushButton>
#include <stdexcept>
#include <iostream>
#include <sstream>

using namespace std;

ResultsWin::ResultsWin(WebPage* webpage, map <string, WebPage*> allLinks, QWidget *parent) : 
					wp(webpage), links(allLinks), QWidget(parent){
	content = new QTextEdit;
	linkcontent(wp);

	incoming = new QListWidget;
	outgoing = new QListWidget;
	btnQuit = new QPushButton("&Quit");
	btnQuit->setMaximumWidth(80);
	in = new QLabel("Incoming:");
	out = new QLabel("Outgoing:");
	
	inLinks(wp);
	outLinks(wp);

	QVBoxLayout* inoutlinks = new QVBoxLayout;
	inoutlinks->addWidget(in);
	inoutlinks->addWidget(incoming);
	inoutlinks->addWidget(out);
	inoutlinks->addWidget(outgoing);
	inoutlinks->addWidget(btnQuit, 0, Qt::AlignRight);

	QHBoxLayout* mainLayout = new QHBoxLayout;
	mainLayout->addWidget(content);
	mainLayout->addLayout(inoutlinks);

	setLayout(mainLayout);
	connect(btnQuit, SIGNAL(clicked()), this, SLOT(quitClicked()));
	connect(incoming, SIGNAL(itemDoubleClicked(QListWidgetItem*)), this, SLOT(refresh(QListWidgetItem*)));
	connect(outgoing, SIGNAL(itemDoubleClicked(QListWidgetItem*)), this, SLOT(refresh(QListWidgetItem*)));
}

ResultsWin::~ResultsWin(){
}

void ResultsWin::quitClicked(){
	close();
}

void ResultsWin::linkcontent(WebPage* newwp){
	content->clear();
	stringstream ss;
	string text;
	string word;
	ss << *newwp;
	while(ss >> word){
		text += word;
		text += " ";
	}
	content->setText(QString::fromStdString(text));
	content->setFixedSize(420,480);
}

void ResultsWin::inLinks(WebPage* newwp){
	incoming->clear();
	Set<WebPage*> i = newwp->allIncomingLinks();
	for(Set<WebPage*>::iterator it = i.begin(); it != i.end(); ++it){
    	WebPage* temp = *it;
    	incoming->addItem(QString::fromStdString(temp->filename()));
    }
}

void ResultsWin::outLinks(WebPage* newwp){
	outgoing->clear();
	Set<WebPage*> o = newwp->allOutgoingLinks();
	for(Set<WebPage*>::iterator it = o.begin(); it != o.end(); ++it){
    	WebPage* temp = *it;
    	outgoing->addItem(QString::fromStdString(temp->filename()));
    }
}

void ResultsWin::refresh(QListWidgetItem* item){
	string select = item->text().toStdString();
	linkcontent(links[select]);
	inLinks(links[select]);
	outLinks(links[select]);
}