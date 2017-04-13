#include "sta_to_csv_dialog.h"

#include <QFileDialog>
#include <QMessageLogger>
#include <iostream>

StaToCsvDialog::StaToCsvDialog(QWidget* parent):
    QWidget(parent),
    ui(std::make_unique<Ui::StaToCsvDialog>())
{
    ui->setupUi(this);
    connectWidgets();
}

void StaToCsvDialog::connectWidgets() {
    // Connection the btnBrowseRefFile
    QObject::connect(
        ui->btnBrowseRefFile, &QPushButton::clicked,
        this, &StaToCsvDialog::onClickBtnBrowseRefFile
    );

    // Connection the btnBrowseDataFile
    QObject::connect(
        ui->btnBrowseDataFile, &QPushButton::clicked,
        this, &StaToCsvDialog::onClickBtnBrowseDataFile
    );

    // Connection the btnAddFilter
    QObject::connect(
        ui->btnAddFilter, &QPushButton::clicked,
        this, &StaToCsvDialog::onClickBtnAddFilter
    );

    // Connection the btnRemoveFilter
    QObject::connect(
        ui->btnRemoveFilter, &QPushButton::clicked,
        this, &StaToCsvDialog::onClickBtnRemoveFilter
    );

    // Connection the btnConvert
    QObject::connect(
        ui->btnConvert, &QPushButton::clicked,
        this, &StaToCsvDialog::onClickBtnConvert
    );
}

/**
 * SLOT
 * called when the Ref Browse Button is clicked.
 */
void StaToCsvDialog::onClickBtnBrowseRefFile() {
    QString fileName {
        QFileDialog::getOpenFileName(this, tr("Open File"), "/home", tr("REF Files (*.txt *.ref)"))
    };
    ui->txtRefFile->setText(fileName);
}

void StaToCsvDialog::onClickBtnBrowseDataFile() {
    QString fileName {
        QFileDialog::getOpenFileName(this, tr("Open File"), "/home", tr("STA Files (*.txt)"))
    };
    ui->txtDataFile->setText(fileName);
}

void StaToCsvDialog::onClickBtnAddFilter() {
    qInfo("Operation not implemented yet.");
}

void StaToCsvDialog::onClickBtnRemoveFilter() {
    qInfo("Operation not implemented yet.");
}

void StaToCsvDialog::onClickBtnConvert() {
    qInfo("Operation not implemented yet.");
}

