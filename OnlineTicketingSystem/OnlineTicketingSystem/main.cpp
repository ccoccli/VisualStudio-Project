#include "OnlineTicketingSystem.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    OnlineTicketingSystem w;
    w.show();
    return a.exec();
}
