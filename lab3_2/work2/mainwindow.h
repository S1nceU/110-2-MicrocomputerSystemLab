#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

    void on_switchbutton_clicked();

    void on_shinebutton_clicked();

    void update();

    void on_horizontalSlider_valueChanged(int value);

    void on_switchbutton_off_clicked();

private:
    Ui::MainWindow *ui;
    QTimer *cout = new QTimer();
    int LEDswitch,t = 0;
    int che = 1;
};

#endif // MAINWINDOW_H
