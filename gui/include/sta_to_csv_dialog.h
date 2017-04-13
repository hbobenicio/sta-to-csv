#ifndef STA_TO_CSV_DIALOG_H
#define STA_TO_CSV_DIALOG_H

#include <QWidget>
#include <memory>
#include "ui_sta_to_csv_dialog.h"

class StaToCsvDialog: public QWidget
{
    //Q_OBJECT

public:
    StaToCsvDialog(QWidget* parent = nullptr);

public slots:
    void onClickBtnBrowseRefFile();
    void onClickBtnBrowseDataFile();
    void onClickBtnAddFilter();
    void onClickBtnRemoveFilter();
    void onClickBtnConvert();

private:
    void connectWidgets();

protected:
    std::unique_ptr<Ui::StaToCsvDialog> ui;
};

#endif
