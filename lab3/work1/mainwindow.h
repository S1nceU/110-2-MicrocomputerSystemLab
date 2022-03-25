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
private:
    Ui::MainWindow *ui;
    QTimer *cout = new QTimer();
    int LEDswitch = 0;
    int t = 0;
};

#endif // MAINWINDOW_H
