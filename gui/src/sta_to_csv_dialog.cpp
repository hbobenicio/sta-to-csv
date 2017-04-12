#include "sta_to_csv_dialog.h"
#include "ui_sta_to_csv_dialog.h"

#include <QFileDialog>
#include <iostream>

StaToCsvDialog::StaToCsvDialog(QWidget* parent)
    : QWidget(parent), ui(new Ui::StaToCsvDialog)
{
    ui->setupUi(this);
    connectWidgets();
}

StaToCsvDialog::~StaToCsvDialog() {
    delete ui;
}

void StaToCsvDialog::connectWidgets() {
    QObject::connect(
        ui->btnBrowseRefFile, &QPushButton::clicked,
        this, &StaToCsvDialog::onClickBtnBrowseRefFile
    );
}

void StaToCsvDialog::onClickBtnBrowseRefFile() {
    QString fileName {
        QFileDialog::getOpenFileName(this, tr("Open File"), "/home", tr("REF Files (*.txt *.ref)"))
    };

    std::cout << fileName.toStdString() << '\n';
}
