#ifndef STARTEXTERNALQMLDIALOG_H
#define STARTEXTERNALQMLDIALOG_H

#include <QDialog>

namespace Ui {
    class StartExternalQmlDialog;
}

namespace Qml {
namespace Internal {


class StartExternalQmlDialog : public QDialog
{
    Q_OBJECT

public:
    explicit StartExternalQmlDialog(QWidget *parent);
    ~StartExternalQmlDialog();

    void setDebuggerUrl(const QString &url);
    QString debuggerUrl() const;

    void setPort(quint16 port);
    quint16 port() const;

    void setProjectDisplayName(const QString &projectName);

private slots:

private:
    Ui::StartExternalQmlDialog *m_ui;
};

} // Internal
} // Qml

#endif // STARTEXTERNALQMLDIALOG_H
