#include "exsystemtrayicon.h"
#include <QDebug>
#include "mainwindow.h"

ExSystemTrayIcon::ExSystemTrayIcon(QObject *parent)
    : QSystemTrayIcon{parent}
{

}

ExSystemTrayIcon::ExSystemTrayIcon(const QIcon &icon, QObject *parent)
    : QSystemTrayIcon{icon,parent}
{
    connect(this,&ExSystemTrayIcon::activated,[=](QSystemTrayIcon::ActivationReason reason){
        if(reason == Trigger)
            return processLeftMouseClick();
        if(reason == DoubleClick)
            return processLeftMouseDoubleClick();
        if(reason == Context)
            return processRightMouseClick();
        if(reason == MiddleClick)
            return processMiddletMouseClick();
    });
}

bool ExSystemTrayIcon::event(QEvent *event)
{
    qDebug() << event;
    return true;
}

void ExSystemTrayIcon::processRightMouseClick()
{

}

void ExSystemTrayIcon::processLeftMouseClick()
{
    MainWindow* w = MainWindow::GetInstance();
    if(w->isVisible())
        w->hide();
    else
    {
        w->activateWindow();
        w->raise();
        w->show();
    }

}

void ExSystemTrayIcon::processMiddletMouseClick()
{

}

void ExSystemTrayIcon::processLeftMouseDoubleClick()
{

}
