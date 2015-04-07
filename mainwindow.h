#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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

    void on_button_hw_clicked();

    void on_button_fb_clicked();

    void on_tempcon_clicked();

    void on_button_isprime_clicked();

    void on_button_shuffle_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
