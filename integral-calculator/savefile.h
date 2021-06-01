#ifndef SAVEFILE_H
#define SAVEFILE_H

#include <QDialog>
#include <string>
#include <fstream>

namespace Ui {
class saveFile;
}

class saveFile : public QDialog
{
    Q_OBJECT

public:
    explicit saveFile(QWidget *parent = nullptr, std::string result = "", std::string expression = "");
    ~saveFile();

private slots:
    void on_pushButton_clicked();

private:
    Ui::saveFile *ui;
    std::string file_name, expression, result;
};

#endif // SAVEFILE_H
