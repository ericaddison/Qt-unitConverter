#ifndef CONVERTERWIDGET_H
#define CONVERTERWIDGET_H

#include <QtGui>
#include <string>
#include "ui_converterWidget.h"

// the converter widget class for the unit conversion program
// subclasses QTabWidget and the Ui::converterWidget I made in QtDesigner
class converterWidget : public QTabWidget, public Ui::ConverterWidget
{
	Q_OBJECT	// macro for qmake

	public:
		converterWidget(QWidget *parent=0);


	private slots:
		// mass conversion slots		
		void distConvert(const QString &);
		void inMConvert()  { distInUnits = MET; distConvert(distLineEdit->text()); }
		void inCmConvert() { distInUnits = CM; distConvert(distLineEdit->text()); }
		void inKmConvert() { distInUnits = KM; distConvert(distLineEdit->text()); }
		void inInConvert() { distInUnits = IN; distConvert(distLineEdit->text()); }
		void inFtConvert() { distInUnits = FT; distConvert(distLineEdit->text()); }
		void inMiConvert() { distInUnits = MI; distConvert(distLineEdit->text()); }
		void inFaConvert() { distInUnits = FA; distConvert(distLineEdit->text()); }
		void inFuConvert() { distInUnits = FU; distConvert(distLineEdit->text()); }
		void outMConvert()  { distOutUnits = MET; distConvert(distLineEdit->text()); }
		void outCmConvert() { distOutUnits = CM; distConvert(distLineEdit->text()); }
		void outKmConvert() { distOutUnits = KM; distConvert(distLineEdit->text()); }
		void outInConvert() { distOutUnits = IN; distConvert(distLineEdit->text()); }
		void outFtConvert() { distOutUnits = FT; distConvert(distLineEdit->text()); }
		void outMiConvert() { distOutUnits = MI; distConvert(distLineEdit->text()); }
		void outFaConvert() { distOutUnits = FA; distConvert(distLineEdit->text()); }
		void outFuConvert() { distOutUnits = FU; distConvert(distLineEdit->text()); }

		// distance conversion slots
		void massConvert(const QString &);
		void inKgConvert()  { massInUnits = KG; massConvert(massLineEdit->text()); }
		void inGConvert() { massInUnits = GM; massConvert(massLineEdit->text()); }
		void inLbConvert() { massInUnits = LB; massConvert(massLineEdit->text()); }
		void inOzConvert() { massInUnits = OZ; massConvert(massLineEdit->text()); }
		void inTConvert() { massInUnits = T; massConvert(massLineEdit->text()); }
		void inStConvert() { massInUnits = ST; massConvert(massLineEdit->text()); }
		void inCaConvert() { massInUnits = CA; massConvert(massLineEdit->text()); }
		void inSlConvert() { massInUnits = SL; massConvert(massLineEdit->text()); }
		void outKgConvert()  { massOutUnits = KG; massConvert(massLineEdit->text()); }
		void outGConvert() { massOutUnits = GM; massConvert(massLineEdit->text()); }
		void outLbConvert() { massOutUnits = LB; massConvert(massLineEdit->text()); }
		void outOzConvert() { massOutUnits = OZ; massConvert(massLineEdit->text()); }
		void outTConvert() { massOutUnits = T; massConvert(massLineEdit->text()); }
		void outStConvert() { massOutUnits = ST; massConvert(massLineEdit->text()); }
		void outCaConvert() { massOutUnits = CA; massConvert(massLineEdit->text()); }
		void outSlConvert() { massOutUnits = SL; massConvert(massLineEdit->text()); }


	private:
		static const int NUM_D_UNITS = 8;
		static const int NUM_M_UNITS = 8;
		enum distUnits { MET, CM, KM, IN, FT, MI, FA, FU };
		enum massUnits { KG, GM, LB, OZ, T, ST, CA, SL };	
		static double x2m[NUM_D_UNITS];
		static double m2x[NUM_D_UNITS];
		static double x2kg[NUM_M_UNITS];
		static double kg2x[NUM_M_UNITS];
		massUnits massInUnits, massOutUnits;
		distUnits distInUnits, distOutUnits;
};



#endif
