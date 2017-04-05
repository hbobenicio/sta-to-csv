#include "sta_to_csv_dialog.h"
#include "ui_sta_to_csv_dialog.h"

StaToCsvDialog::StaToCsvDialog(QWidget* parent)
    : QWidget(parent), ui(new Ui::StaToCsvDialog)
{
    ui->setupUi(this);
}

StaToCsvDialog::~StaToCsvDialog() {
    delete ui;
}
