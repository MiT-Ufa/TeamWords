#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWebKitWidgets>
#include <QSystemTrayIcon>
#include <QWinTaskbarButton>
#include <QWinTaskbarProgress>
#include <QtWinExtras>
#include <QWebNotificationData>
#include <QtNetwork/QNetworkAccessManager>
#include "qwebkitplatformplugin.h"
#include "cookiejar.h"
#include "networkaccessmanager.h"
#include "asemantools/asemannativenotificationitem.h"

namespace Ui {
class MainWindow;
}

class CookieJar;
class NetworkAccessManager;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);

    virtual void showEvent(QShowEvent *event);
    virtual void hideEvent(QHideEvent *event);

    void showNotification(QString title, QString message);

    ~MainWindow();

//    static NetworkAccessManager *networkAccessManager();

public slots:
    void featureRequest(QWebFrame *frame, QWebPage::Feature feature);
    void trayActivated(QSystemTrayIcon::ActivationReason reason);

private:
    CookieJar *jar;
    Ui::MainWindow *ui;
    QSystemTrayIcon *trayIcon;
    QWinTaskbarButton *button;
    QWinTaskbarProgress* progress;
    AsemanNativeNotificationItem *item;

    const QString teamLoginUrl = QString("https://%1.slack.com");
    const QString loginUrl = QString("https://slack.com/signin");

    void applyNativeFont();
};

#endif // MAINWINDOW_H