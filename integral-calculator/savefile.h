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
    explicit saveFile(QWidget *parent = nullptr, std::string result = "", std::string expression = "", int divides = 0, int depth = 0, double low = 0, double up = 0);
    ~saveFile();

private slots:
    void on_pushButton_clicked();

private:
    Ui::saveFile *ui;
    std::string file_name, expression, result;
    int divides, depth;
    double a, b;
};

#endif // SAVEFILE_H
