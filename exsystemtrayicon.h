#ifndef EXSYSTEMTRAYICON_H
#define EXSYSTEMTRAYICON_H

#include <QSystemTrayIcon>
#include <QObject>

class ExSystemTrayIcon : public QSystemTrayIcon
{
    Q_OBJECT
public:
    explicit ExSystemTrayIcon(QObject *parent = nullptr);
    explicit ExSystemTrayIcon(const QIcon &icon, QObject *parent = nullptr);

protected:
    bool event(QEvent *event) override;
protected:
    virtual void processRightMouseClick();
    virtual void processLeftMouseClick();
    virtual void processMiddletMouseClick();
    virtual void processLeftMouseDoubleClick();
};

#endif // EXSYSTEMTRAYICON_H
