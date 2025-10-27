#include "cbuiltindig.h"
#include <QGridLayout>
#include <QDebug>
#include <QPalette>
#include <QtWidgets>

CBuiltinDig::CBuiltinDig(QWidget *parent)
    : QDialog(parent)
{
    QGridLayout *gridLayout = new QGridLayout;
    displayTextEdit = new QTextEdit(QStringLiteral("幹你娘"));
    colorPushBtn    = new QPushButton(QStringLiteral("顏色對話"));
    errorPushBtn    = new QPushButton(QStringLiteral("錯誤訊息"));
    filePushBtn     = new QPushButton(QStringLiteral("檔案對話"));
    fontPushBtn     = new QPushButton(QStringLiteral("字體對話"));
    inputPushBtn    = new QPushButton(QStringLiteral("輸入對話"));
    pagePushBtn     = new QPushButton(QStringLiteral("頁面設定對話"));
    progressPushBtn = new QPushButton(QStringLiteral("進度對話"));
    printPushBtn    = new QPushButton(QStringLiteral("印出對話"));

    gridLayout->addWidget(colorPushBtn,0,0,1,1);
    gridLayout->addWidget(errorPushBtn,0,1,1,1);
    gridLayout->addWidget(filePushBtn,0,2,1,1);
    gridLayout->addWidget(fontPushBtn,1,0,1,1);
    gridLayout->addWidget(inputPushBtn,1,1,1,1);
    gridLayout->addWidget(pagePushBtn,1,2,1,1);
    gridLayout->addWidget(progressPushBtn,2,0,1,1);
    gridLayout->addWidget(printPushBtn,2,1,1,1);
    gridLayout->addWidget(displayTextEdit,3,0,3,3);

    setLayout(gridLayout);
    setWindowTitle(QStringLiteral("內建對話盒展示"));
    resize(400,300);
    connect(colorPushBtn,SIGNAL(clicked()),this,SLOT(doPushBtn()));
    connect(errorPushBtn,SIGNAL(clicked()),this,SLOT(doPushBtn()));
    connect(filePushBtn,SIGNAL(clicked()),this,SLOT(doPushBtn()));
    connect(fontPushBtn,SIGNAL(clicked()),this,SLOT(doPushBtn()));
    connect(inputPushBtn,SIGNAL(clicked()),this,SLOT(doPushBtn()));
    connect(pagePushBtn,SIGNAL(clicked()),this,SLOT(doPushBtn()));
    connect(progressPushBtn,SIGNAL(clicked()),this,SLOT(doPushBtn()));
    connect(printPushBtn,SIGNAL(clicked()),this,SLOT(doPushBtn()));
    connect(displayTextEdit,SIGNAL(clicked()),this,SLOT(doPushBtn()));

}

CBuiltinDig::~CBuiltinDig() {}
void CBuiltinDig::doPushBtn()
{
    QPushButton* btn = qobject_cast<QPushButton*>(sender());
    if(btn == colorPushBtn)
    {
        QPalette palette = displayTextEdit->palette();
        const QColor& color = QColorDialog::getColor(palette.color(QPalette::Text),
                                                     this, QStringLiteral("設定背景顏色"));
        if(color.isValid())
        {
            palette.setColor(QPalette::Text, color);
            displayTextEdit->setPalette(palette);
        }
    }
    if(btn == errorPushBtn)
    {
        QErrorMessage box(this);
        box.setWindowTitle(QStringLiteral("錯誤訊息盒"));
        box.showMessage(QStringLiteral("錯誤訊息實例XX"));
        box.showMessage(QStringLiteral("錯誤訊息實例XX"));
        box.showMessage(QStringLiteral("錯誤訊息實例XX"));
        box.exec();
    }
    if(btn == filePushBtn){
        QString FileName = QFileDialog::getOpenFileName(this, tr("開啟檔案"),"."
                                                        ,tr("任何檔案(*.*)"
                                                            ";;文字檔(*.txt)"
                                                            ";;XML檔(*.xml)"));
        displayTextEdit->setText(FileName);

    }
}

