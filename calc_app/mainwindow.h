#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "engine.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onButtonClicked();
    void refreshLabels();

private:
    Ui::MainWindow *ui;
    Engine m_engine;
};
#endif // MAINWINDOW_H
