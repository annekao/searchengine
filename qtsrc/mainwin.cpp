#include "mainwin.h"
#include <QSize>
#include <QVBoxLayout>
#include <QFormLayout>
#include <QHBoxLayout>
#include <QMessageBox>
#include <QGroupBox>
#include <QString>
#include <stdexcept>
#include <iostream>

using namespace std;

MainWin::MainWin(map< string, Set<WebPage*> > allWords, map<string,WebPage*> allLinks, QWidget *parent) : 
				QWidget(parent), words(allWords), links(allLinks){
	btnQuit = new QPushButton("&Quit");
	btnQuit->setMaximumWidth(80);
	btnAbout = new QPushButton("&About");
	btnAbout->setMaximumWidth(80);
	btnSearch = new QPushButton("&Search");
	btnSearch->setMaximumWidth(80);
	txtSearch = new QLineEdit;
	txtSearch->setMinimumWidth(490);
	results = new QListWidget;

	//QGroupBox *radio = new QGroupBox;
	btnAnd = new QRadioButton(tr("A&ND"));
	btnOr = new QRadioButton(tr("&OR"));
	btnAnd->setChecked(true);

	QFormLayout* fLayout = new QFormLayout;
	fLayout->addRow(txtSearch, btnSearch);

	QHBoxLayout* radioselect = new QHBoxLayout;
	radioselect->addWidget(btnAnd);
	radioselect->addWidget(btnOr);
	radioselect->addStretch(1);

	QHBoxLayout* botRow = new QHBoxLayout;
	botRow->addWidget(btnAbout, 0, Qt::AlignLeft);
	botRow->addWidget(btnQuit, 0, Qt::AlignRight);

	QVBoxLayout* mainLayout = new QVBoxLayout;
	mainLayout->addLayout(fLayout);
	mainLayout->addLayout(radioselect);
	mainLayout->addWidget(results);
	mainLayout->addLayout(botRow);

	connect(btnQuit, SIGNAL(clicked()), this, SLOT(quitClicked()));
	connect(btnAbout, SIGNAL(clicked()), this, SLOT(aboutClicked()));
	connect(btnSearch, SIGNAL(clicked()), this, SLOT(search()));
	connect(txtSearch, SIGNAL(returnPressed()), this, SLOT(search()));
	connect(results, SIGNAL(itemDoubleClicked(QListWidgetItem*)), this, SLOT(openpageinfo(QListWidgetItem*)));

	setLayout(mainLayout);
}

MainWin::~MainWin(){
}


void MainWin::quitClicked(){
	cout << "Thank you! Exiting." << endl;
	close();
}

void MainWin::aboutClicked(){
	QMessageBox::information(this, tr("About"), tr("This is a search engine designed for Project Part 2 for CSCI104 Spring 2014.\nMade by Anne Kao."));
}

void MainWin::search(){
	results->clear();

	string input =  txtSearch->text().toStdString();

    for(int j = 0; input[j]; j++){    //converts to lower case and checks for valid input
    	if(input[j] != ' ' && !isalnum(input[j])){
			QMessageBox *message = new QMessageBox;
			message->setWindowTitle("Error!");
			message->setText("Invalid search. \nIs your input alphanumeric?");
			message->show();
			return void();
		}
		else
    	input[j] = tolower(input[j]);
    }
    try{
    	Set<WebPage*> result;
    	char cinput[input.size()+1];
        strcpy(cinput, input.c_str());	//convert to char* to tokenize
        char* cword1 = strtok(cinput," ");	//extract first word
        string word1(cword1);		//convert char* to string to trim and input into set
        trim(word1);
        Set<WebPage*> and1 = words.at(word1);
        result = and1; 

    	if(btnAnd->isChecked()){
        	cword1 = strtok(NULL," ");	//could just do ", " to get rid of leading white space
        	while(cword1!=NULL){		//but i already made the trim function so too bad
        		string word2(cword1);	//essentially doing what I did above
        		trim(word2);
        		Set<WebPage*> and2 = words.at(word2);
        		result = and1.setIntersection(and2);	//check for intersections
        		Set<WebPage*> and1 = result;		//*** resets and1 to be result thus and2 will check for 
        		cword1 = strtok(NULL," ");		//an intersection of previous words
        	}
    	}

    	else if (btnOr->isChecked()){
			cword1 = strtok(NULL," ");	//could just do ", " to get rid of leading white space
        	while(cword1!=NULL){		//but i already made the trim function so too bad
        		string word2(cword1);
        		trim(word2);
        		Set<WebPage*> and2 = words.at(word2);
        		result = and1.setUnion(and2);
        		Set<WebPage*> and1 = result;
        		cword1 = strtok(NULL," ");	
    		}
    	}

    	if(result.size() == 0){
			QMessageBox *message = new QMessageBox;
			message->setWindowTitle("Error!");
			message->setText("No search results.");
			message->show();
    	}
   	 	else{
    		for(Set<WebPage*>::iterator it = result.begin(); it != result.end(); ++it){
    			WebPage* wp = *it;
    			results->addItem(QString::fromStdString(wp->filename()));
    		}
    	}
	}
	catch(logic_error &e){
		QMessageBox *message = new QMessageBox;
		message->setWindowTitle("Error!");
		message->setText("No search results.");
		message->show();
	}
}

void MainWin::openpageinfo(QListWidgetItem* item){
	string select = item->text().toStdString();
	info = new ResultsWin(links[select],links);
	info->setWindowTitle(QString::fromStdString(select+=" info"));
	info->setFixedSize(700,500);
	info->show();
}

//helper function to trim white space
void trim(string& word){
	int pos = word.find_first_not_of(" "); //finds extra white space from beginning
    word = word.substr(pos);				//trims
    pos = word.find_last_not_of(" "); //finds trailing white space
    word = word.substr(0, pos+1);			//trims
}