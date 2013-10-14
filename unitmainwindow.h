#ifndef UNITMAINWINDOW_H
#define UNITMAINWINDOW_H

#include <QtGui>
#include <string>
#include "ui_mainWindow.h"
#include "converterWidget/converterWidget.h"

// the main window class for the unit conversion program
// subclasses QMainWindow and the Ui::MainWindow I made in QtDesigner
class UnitMainWindow : public QMainWindow, public Ui::MainWindow
{
	Q_OBJECT	// macro for qmake

	public:
		UnitMainWindow(QWidget *parent=0);


	private slots:
		// menu actions
		void about();


	private:
		converterWidget *conv;
	
};



#endif
