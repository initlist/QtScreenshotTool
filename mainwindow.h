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
    static MainWindow* GetInstance();

protected:
    void closeEvent(QCloseEvent *event) override;
    void onClipboardDataChanged();
private:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QClipboard *clipboard;
    QString lastClipboardText;
};
#endif // MAINWINDOW_H
