#include <QApplication>
#include "unitmainwindow.h"

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);
	UnitMainWindow mainWin;
	mainWin.show();
	return app.exec();
}
