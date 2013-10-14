#include <QtGui>

#include "unitmainwindow.h"


UnitMainWindow::UnitMainWindow(QWidget *parent) : QMainWindow(parent)
{
	setupUi(this);
	// set the size of the window to be fixed
	setFixedSize(720,350);
	
	// setup and add the converterTabs widget
	conv = new converterWidget(this);
	
	QVBoxLayout *mainLayout = new QVBoxLayout(this);
	mainLayout->addWidget(conv);
	this->centralWidget()->setLayout(mainLayout);

	// signal-slot connections
	// menu actions
	connect(actionE_xit,SIGNAL(triggered()),this,SLOT(close()));
	connect(action_About,SIGNAL(triggered()),this,SLOT(about()));
}

void UnitMainWindow::about()
{
    QMessageBox::about(this, tr("About Unit Converter"),
            tr("<h2>Unit Converter 1.0</h2>"
               "<p>Copyright &copy; 2013 <it>Eric Addison</it>"
               "<p>Unit converter is a small unit conversion application. It represents my first solo foray into Qt."
				" The window was designed in Qt Designer, and the conversion logic implemented as SLOTs in C++"));
}
