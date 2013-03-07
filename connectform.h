#ifndef CONNECTFORM_H
#define CONNECTFORM_H
#include <QWidget>
#include <QString>
#include "client.h"
#include "readthread.h"

class Client;
class MainWindow;
namespace Ui{
class connectForm;
}
class connectForm : public QWidget
{
    Q_OBJECT
    
public:
    explicit connectForm(QWidget *parent = 0, Client *c = 0, MainWindow *w = 0);
    ~connectForm();
     QString getPort();
     QString getHostname();
     QString getUsername();
    
private slots:
    void on_buttonConnect_clicked();

private:
    Ui::connectForm *ui;
    Client *client;
    ReadThread readThread;
    MainWindow *window;

};

#endif // CONNECTFORM_H
