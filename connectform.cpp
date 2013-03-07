#include "connectform.h"
#include "ui_connectform.h"
#include "network.h"
#include <QMessageBox>

connectForm::connectForm(QWidget *parent, Client *c, MainWindow *w) :
    QWidget(parent),
    ui(new Ui::connectForm)
{
    ui->setupUi(this);
    client = c;
    window = w;

}
connectForm::~connectForm()
{
    delete ui;
}
void connectForm::on_buttonConnect_clicked()
{
    int n;
    client->set_username(ui->inputUname->text());
    client->set_port(ui->inputPort->text());
    client->set_hostname(ui->inputIP->text());

    if((n = client->connect_to_server()) == -1)
    {
       // perror("connect");
    }
   // QMessageBox::critical(0, QString("Client"), QString("Connected"));
    QObject::connect(&readThread, SIGNAL(messageRecieved(QString)), window, SLOT(dataRecieved(QString)));
    readThread.setSocket(client->get_sock());
    readThread.start();

    client->set_connect();
    hide();
}
