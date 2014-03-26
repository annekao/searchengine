#ifndef RESULTSWIN_H_
#define RESULTSWIN_H_
#include <QWidget>
#include <QListWidget>
#include <QMessageBox>
#include <QTextEdit>
#include <QLabel>
#include "../webpage.h"

class ResultsWin : public QWidget
{
	Q_OBJECT

	public:
		ResultsWin(WebPage* webpage, map <string, WebPage*> allLinks, QWidget *parent = 0);
		~ResultsWin();

	private slots:
		void quitClicked();
		void linkcontent(WebPage* newwp);
		void inLinks(WebPage* newwp);
		void outLinks(WebPage* newwp);
		void refresh(QListWidgetItem* item);

	private:
		WebPage * wp;
		map <string, WebPage*> links;
		QPushButton * btnQuit;
		QTextEdit * content;
		QListWidget * incoming;
		QListWidget * outgoing;
		QLabel * in;
		QLabel * out;
};
#endif