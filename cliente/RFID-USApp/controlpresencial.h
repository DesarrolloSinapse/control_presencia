#ifndef CONTROLPRESENCIAL_H
#define CONTROLPRESENCIAL_H

#include <QMainWindow>
#include <QMessageBox>

namespace Ui {
class ControlPresencial;
}

class ControlPresencial : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit ControlPresencial(QWidget *parent = 0);
    ~ControlPresencial();

private slots:
    void showTime();
    void RellenaDatosAula();
    void showModified(QString);
    void MonitorizaFicheros(QString);
    void LimpiaError();
private:
    Ui::ControlPresencial *ui;
};


#endif // CONTROLPRESENCIAL_H
