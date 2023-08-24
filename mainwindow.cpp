#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QScreen>
#include <QPixmap>
#include <QDebug>
#include <QCloseEvent>
#include <QClipboard>
#include <QMimeData>

MainWindow *MainWindow::GetInstance()
{
    static MainWindow *w = new MainWindow;
    return w;
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //    this->setWindowFlags(Qt::FramelessWindowHint);
    //    this->showFullScreen();
    //    QScreen *screen = QGuiApplication::primaryScreen();
    //    if (!screen) return;

    //    QPixmap screenshotPixmap = screen->grabWindow(0);
    //    QPalette palette;
    //    palette.setBrush(QPalette::Background, QBrush(screenshotPixmap));
    //    this->setPalette(palette);
    clipboard = QGuiApplication::clipboard();
    lastClipboardText = clipboard->text();

    // 连接剪贴板内容改变的信号
    connect(clipboard, &QClipboard::dataChanged, this, &MainWindow::onClipboardDataChanged);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    event->ignore();
    this->hide();
}

void MainWindow::onClipboardDataChanged()
{
    QString currentClipboardText = clipboard->text();
    if (currentClipboardText != lastClipboardText) {
        qDebug() << "Clipboard content has changed:";
        qDebug() << "Previous: " << lastClipboardText;
        qDebug() << "Current: " << currentClipboardText;
        lastClipboardText = currentClipboardText;
        ui->plainTextEdit->clear();
        ui->plainTextEdit->insertPlainText(lastClipboardText);
    }
    if (clipboard->mimeData()->hasUrls()) {
        QList<QUrl> urlList = clipboard->mimeData()->urls();
        qDebug() << "Copied URLs:";
        foreach (const QUrl &url, urlList) {
            ui->label->setPixmap(QPixmap(url.toLocalFile()));
            return;
        }
    } else {
        qDebug() << "No URLs found in clipboard.";
    }
    ui->label->setPixmap(QPixmap::fromImage(clipboard->image()));
}

