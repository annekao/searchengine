#ifndef MAINWIN_H_
#define MAINWIN_H_
#include "../webpage.h"
#include "resultswin.h"
#include <QWidget>
#include <QMainWindow>
#include <QPushButton>
#include <QLineEdit>
#include <QListWidget>
#include <QRadioButton>
#include <QString>
#include <string>

// helper function
void trim(std::string&);

class MainWin : public QWidget
{
	Q_OBJECT

	public:
		MainWin(map< string, Set<WebPage*> > allWords, map<string,WebPage*> allLinks, QWidget *parent = 0);
		~MainWin();

	private slots:
		void quitClicked();
		void aboutClicked();
		void search();
		void openpageinfo(QListWidgetItem* item);

	private:
		map< string, Set<WebPage*> > words;
		map <string, WebPage*> links;
		ResultsWin * info;
		QPushButton * btnAbout;
		QPushButton * btnQuit;
		QPushButton * btnSearch;
		QLineEdit * txtSearch;
		QListWidget * results;
		QRadioButton * btnAnd;
		QRadioButton * btnOr;
};
#endif