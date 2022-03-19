#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

private slots:
    void input_numbers();
    void on_Button_equal_clicked();
    void operations();
    void on_Button_sqrt_clicked();
    void on_Button_sqr_clicked();
    void on_Button_clear_clicked();
};
#endif // MAINWINDOW_H
