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
    StaToCsvDialog(QWidget* parent = nullptr);
    virtual ~StaToCsvDialog();

public slots:
    void onClickBtnBrowseRefFile();

private:
    void connectWidgets();

protected:
    Ui::StaToCsvDialog* ui;
};

#endif
