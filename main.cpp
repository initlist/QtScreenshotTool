#include "mainwindow.h"

#include <QApplication>
#include <QAction>
#include <QSystemTrayIcon>
#include <QMenu>
#include "exsystemtrayicon.h"
#include <QKeyEvent>
#include <Windows.h>
#include <QDebug>
#include <QDesktopWidget>
#include <QObject>
#include <QAbstractNativeEventFilter>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    auto w = MainWindow::GetInstance();
    w->show();
    ExSystemTrayIcon trayIcon(QIcon("C:\\Users\\admin\\Pictures\\Flat_tick_icon.svg.png"));
    QMenu menu;
    QAction *quitAction = menu.addAction("Quit");
    QObject::connect(quitAction, &QAction::triggered, &app, &QCoreApplication::quit);
    trayIcon.setContextMenu(&menu);
    trayIcon.show();
    return app.exec();
}
