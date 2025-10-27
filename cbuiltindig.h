#ifndef CBUILTINDIG_H
#define CBUILTINDIG_H

#include <QDialog>
#include <QPushButton>
#include <QTextEdit>

class CBuiltinDig : public QDialog
{
    Q_OBJECT

public:
    CBuiltinDig(QWidget *parent = nullptr);
    ~CBuiltinDig();
private:
    QTextEdit       *displayTextEdit;
    QPushButton     *colorPushBtn;
    QPushButton     *errorPushBtn;
    QPushButton     *filePushBtn;
    QPushButton     *fontPushBtn;
    QPushButton     *inputPushBtn;
    QPushButton     *pagePushBtn;
    QPushButton     *progressPushBtn;
    QPushButton     *printPushBtn;
    QPushButton     *textColorPushBtn;
private slots: //槽函數(slot)宣告
    void doPushBtn();
};
#endif // CBUILTINDIG_H
