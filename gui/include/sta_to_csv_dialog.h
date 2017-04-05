#ifndef STA_TO_CSV_DIALOG_H
#define STA_TO_CSV_DIALOG_H

#include <QWidget>

namespace Ui {
    class StaToCsvDialog;
}

class StaToCsvDialog: public QWidget
{
    //Q_OBJECT

public:
    StaToCsvDialog(QWidget* parent = nullptr)
    virtual ~StaToCsvDialog();

protected:
    Ui::StaToCsvDialog* ui;
};

#endif
