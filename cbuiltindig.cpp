#include "cbuiltindig.h"
#include <QGridLayout>

CBuiltinDig::CBuiltinDig(QWidget *parent)
    : QDialog(parent)
{
    QGrindLayout *gridLayout = new QGridLayout;
    displayTextEdit = new QTextEdit(QStringLiteral("幹你娘"));
    colorPushBtn    = new QPushButton(QStringLiteral("顏色對話"));
    errorPushBtn    = new QPushButton(QStringLiteral("錯誤訊息"));
    filePushBtn     = new QPushButton(QStringLiteral("檔案對話"));
    fontPushBtn     = new QPushButton(QStringLiteral("字體對話"));
    inputPushBtn    = new QPushButton(QStringLiteral("輸入對話"));
    pagePushBtn     = new QPushButton(QStringLiteral("頁面設定對話"));
    progressPushBtn = new QPushButton(QStringLiteral("進度對話"));
    printPushBtn    = new QPushButton(QStringLiteral("印出對話"));
}

CBuiltinDig::~CBuiltinDig() {}
