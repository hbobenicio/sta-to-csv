#include "sta_to_csv_dialog.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app{argc, argv};
    StaToCsvDialog dialog;

    dialog.show();
    return app.exec();
}