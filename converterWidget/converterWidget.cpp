#include <QtGui>

#include "converterWidget.h"


// initialize the static member array m2x: meters to unit x
// where the x position relates to the enum units
	double converterWidget::m2x[NUM_D_UNITS] = {1, 100, 0.001, 39.3701, 3.28084, 0.000621371, 0.546806649, 0.00497096954};

// now x2m for converting from unit x back to meters
	double converterWidget::x2m[NUM_D_UNITS] = {1, .01, 1000, 0.0254, 0.3048, 1609.34, 1.8288, 201.16800 };

// initialize the static member array kg2x: kilograms to unit x
// where the x position relates to the enum units
	double converterWidget::kg2x[NUM_M_UNITS] = {1, 1000, 2.20462, 35.274, 0.00110231, 0.157473, 5000, 0.0685217659};

// now x2m for converting from unit x back to kilograms
	double converterWidget::x2kg[NUM_M_UNITS] = {1, .001, 0.453592, 0.0283495, 907.185, 6.35029, 0.0002, 14.5939029 };


converterWidget::converterWidget(QWidget *parent) : QTabWidget(parent)
{
	setupUi(this);
	distInUnits=distOutUnits=MET;
	massInUnits=massOutUnits=KG;

	// signal-slot connections
	connect(distLineEdit,SIGNAL(textChanged(const QString &)),this,SLOT(distConvert(const QString &)));
	// changing the input distance units
	connect(meters1Button,SIGNAL(clicked()),this,SLOT(inMConvert()));
	connect(cm1Button,SIGNAL(clicked()),this,SLOT(inCmConvert()));
	connect(km1Button,SIGNAL(clicked()),this,SLOT(inKmConvert()));
	connect(inches1Button,SIGNAL(clicked()),this,SLOT(inInConvert()));
	connect(feet1Button,SIGNAL(clicked()),this,SLOT(inFtConvert()));
	connect(miles1Button,SIGNAL(clicked()),this,SLOT(inMiConvert()));
	connect(fathoms1Button,SIGNAL(clicked()),this,SLOT(inFaConvert()));
	connect(Fur1Button,SIGNAL(clicked()),this,SLOT(inFuConvert()));
	
	// changing the output distance units
	connect(meters2Button,SIGNAL(clicked()),this,SLOT(outMConvert()));
	connect(cm2Button,SIGNAL(clicked()),this,SLOT(outCmConvert()));
	connect(km2Button,SIGNAL(clicked()),this,SLOT(outKmConvert()));
	connect(inches2Button,SIGNAL(clicked()),this,SLOT(outInConvert()));
	connect(feet2Button,SIGNAL(clicked()),this,SLOT(outFtConvert()));
	connect(miles2Button,SIGNAL(clicked()),this,SLOT(outMiConvert()));
	connect(fathoms2Button,SIGNAL(clicked()),this,SLOT(outFaConvert()));
	connect(Fur2Button,SIGNAL(clicked()),this,SLOT(outFuConvert()));

	connect(massLineEdit,SIGNAL(textChanged(const QString &)),this,SLOT(massConvert(const QString &)));
	// changing the input distance units
	connect(kg1Button,SIGNAL(clicked()),this,SLOT(inKgConvert()));
	connect(g1Button,SIGNAL(clicked()),this,SLOT(inGConvert()));
	connect(lb1Button,SIGNAL(clicked()),this,SLOT(inLbConvert()));
	connect(oz1Button,SIGNAL(clicked()),this,SLOT(inOzConvert()));
	connect(T1Button,SIGNAL(clicked()),this,SLOT(inTConvert()));
	connect(st1Button,SIGNAL(clicked()),this,SLOT(inStConvert()));
	connect(ca1Button,SIGNAL(clicked()),this,SLOT(inCaConvert()));
	connect(sl1Button,SIGNAL(clicked()),this,SLOT(inSlConvert()));
	
	// changing the output distance units
	connect(kg2Button,SIGNAL(clicked()),this,SLOT(outKgConvert()));
	connect(g2Button,SIGNAL(clicked()),this,SLOT(outGConvert()));
	connect(lb2Button,SIGNAL(clicked()),this,SLOT(outLbConvert()));
	connect(oz2Button,SIGNAL(clicked()),this,SLOT(outOzConvert()));
	connect(T2Button,SIGNAL(clicked()),this,SLOT(outTConvert()));
	connect(st2Button,SIGNAL(clicked()),this,SLOT(outStConvert()));
	connect(ca2Button,SIGNAL(clicked()),this,SLOT(outCaConvert()));
	connect(sl2Button,SIGNAL(clicked()),this,SLOT(outSlConvert()));

}


void converterWidget::distConvert(const QString & text)
{

		//qDebug() << "massConvert():\n"; 
		double result = x2m[distInUnits]*m2x[distOutUnits] * (text.toDouble());
		QString newText;
		distOutputLabel->setText( newText.setNum( result ) );
}

void converterWidget::massConvert(const QString & text)
{
		double result = x2kg[massInUnits]*kg2x[massOutUnits] * (text.toDouble());
		QString newText;
		massOutputLabel->setText( newText.setNum( result, 'g', 4 ) );
}	

