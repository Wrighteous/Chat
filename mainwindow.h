#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QString>
#include <QThread>
#include "connectform.h"
#include "readthread.h"

class connectForm;
class Client;

namespace Ui {
class MainWindow;
}
class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0, Client *c = 0);
    ~MainWindow();
public slots:
    void dataRecieved(QString data);

private slots:
    void on_input_returnPressed();
    void on_actionNew_Chat_triggered();
    void on_actionExit_triggered();

private:
    Ui::MainWindow *ui;
    connectForm *cf;
    Client *client;
    ReadThread readThread;
    void append_to_output(QString s);
};

#endif // MAINWINDOW_H
