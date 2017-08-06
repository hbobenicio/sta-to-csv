#include "sta_to_csv_dialog.h"
#include "ui_sta_to_csv_dialog.h"

#include <QFileDialog>
#include <QMessageLogger>
#include <QMessageBox>
#include <QDir>
#include <QFileInfo>
#include <iostream>
#include "sta-parser.h"

StaToCsvDialog::StaToCsvDialog(QWidget* parent):
    QWidget(parent),
    suggestionDir(QDir::homePath())
{
    ui.setupUi(this);
    makeConnections();
}

void StaToCsvDialog::makeConnections() {
    QObject::connect(ui.btnBrowseRefFile,    &QPushButton::clicked, this, &StaToCsvDialog::onClickBtnBrowseRefFile);
    QObject::connect(ui.btnBrowseDataFile,   &QPushButton::clicked, this, &StaToCsvDialog::onClickBtnBrowseDataFile);
    QObject::connect(ui.btnBrowseOutputFile, &QPushButton::clicked, this, &StaToCsvDialog::onClickBtnBrowseOutputFile);
    QObject::connect(ui.btnAddFilter,        &QPushButton::clicked, this, &StaToCsvDialog::onClickBtnAddFilter);
    QObject::connect(ui.btnRemoveFilter,     &QPushButton::clicked, this, &StaToCsvDialog::onClickBtnRemoveFilter);
    QObject::connect(ui.btnConvert,          &QPushButton::clicked, this, &StaToCsvDialog::onClickBtnConvert);
}

/**
 * SLOT
 * called when the Ref Browse Button is clicked.
 */
void StaToCsvDialog::onClickBtnBrowseRefFile() {
    QString fileName = QFileDialog::getOpenFileName(
        this, tr("Selecionar arquivo"), this->suggestionDir, tr("REF Files (*.txt *.ref)")
    );

    // Define the LineEdit's text with the selected file
    ui.txtRefFile->setText(fileName);

    // Updates the suggestionDir with the directory where
    // the selected file is located
    if (!fileName.isEmpty()) {
        QFileInfo fileInfo{fileName};
        this->suggestionDir = fileInfo.dir().absolutePath();
    }
}

/**
 * SLOT
 * called when the Data Browse Button is clicked.
 */
void StaToCsvDialog::onClickBtnBrowseDataFile() {
    QString fileName = QFileDialog::getOpenFileName(
        this, tr("Selecionar arquivo"), this->suggestionDir, tr("STA Files (*.txt)")
    );

    // Define the LineEdit's text with the selected file
    ui.txtDataFile->setText(fileName);

    // Updates the suggestionDir with the directory where
    // the selected file is located
    if (!fileName.isEmpty()) {
        QFileInfo fileInfo{fileName};
        this->suggestionDir = fileInfo.dir().absolutePath();
    }
}

/**
 * SLOT
 * called when the Output Browse Button is clicked.
 */
void StaToCsvDialog::onClickBtnBrowseOutputFile() {
    QString fileName = QFileDialog::getSaveFileName(
        this, tr("Selecionar arquivo"), this->suggestionDir, tr("CSV Files (*.csv)")
    );

    // Define the LineEdit's text with the selected file
    ui.txtOutputFile->setText(fileName);

    // Updates the suggestionDir with the directory where
    // the selected file is located
    if (!fileName.isEmpty()) {
        QFileInfo fileInfo{fileName};
        this->suggestionDir = fileInfo.dir().absolutePath();
    }
}

void StaToCsvDialog::onClickBtnAddFilter() {
    qInfo("Operação não implementada ainda.");
}

void StaToCsvDialog::onClickBtnRemoveFilter() {
    qInfo("Operação não implementada ainda.");
}

bool StaToCsvDialog::validateDialog() const {
    QString refFile{ui.txtRefFile->text()};
    QString dataFile{ui.txtDataFile->text()};
    QString outputFile{ui.txtOutputFile->text()};

    bool invalidated = refFile.isEmpty()
        || dataFile.isEmpty()
        || outputFile.isEmpty();

    return !invalidated;
}

void StaToCsvDialog::onClickBtnConvert() {
    if (!validateDialog()) {
        QMessageBox::critical(
            this, tr("Erro na validação"), tr("Por favor, preencha todos os campos acima.")
        );
        return;
    }

    std::string refFilepath{ui.txtRefFile->text().toStdString()};
		std::string dataFilePath{ui.txtDataFile->text().toStdString()};
    std::string outputFilePath{ui.txtOutputFile->text().toStdString()};

		STAParser parser{refFilepath, dataFilePath, outputFilePath};
    parser.parse();

    // TODO Replace this MessageBox with a Open Dialog on success
    QMessageBox::information(this, tr("Sucesso na conversão"), tr("Conversão realizada com sucesso!"));
}
