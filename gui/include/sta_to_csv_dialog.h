#ifndef STA_TO_CSV_DIALOG_H
#define STA_TO_CSV_DIALOG_H

#include <QWidget>
#include <QString>
#include <memory>
#include "ui_sta_to_csv_dialog.h"

/**
 * STA to CSV Converter Dialog.
 */
class StaToCsvDialog: public QWidget
{
protected:
    /**
     * QtWidget UI for this dialog.
     */
    Ui::StaToCsvDialog ui;
    QString suggestionDir;
    
public:
    StaToCsvDialog(QWidget* parent = nullptr);

private:

    /**
     * Method to make all the Qt connections.
     */
    void makeConnections();

    /**
     * Validates if the user filled in all
     * required field.
     *
     * @return true, caso a dialog tenha sido validada. false, caso contrário
     */ 
    bool validateDialog() const;

public slots:
    // SLOTS for handling button clicks
    void onClickBtnBrowseRefFile();
    void onClickBtnBrowseDataFile();
    void onClickBtnBrowseOutputFile();
    void onClickBtnAddFilter();
    void onClickBtnRemoveFilter();
    void onClickBtnConvert();
};

#endif
