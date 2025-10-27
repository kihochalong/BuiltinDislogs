#include "cbuiltindig.h"
#include <QGridLayout>
#include <QDebug>
#include <QPalette>
#include <QtWidgets>
#include <QtPrintSupport/qprinter.h>
#include <QtPrintSupport/QPageSetupDialog>
#include <QtPrintSupport/QPrintDialog>
#include <QtPrintSupport/QPrintPreviewDialog>


CBuiltinDig::CBuiltinDig(QWidget *parent)
    : QDialog(parent)
{
    QGridLayout *gridLayout = new QGridLayout;
    displayTextEdit = new QTextEdit(QStringLiteral("四資工二乙_劉綜騏_41330247"));
    colorPushBtn    = new QPushButton(QStringLiteral("顏色對話盒"));
    errorPushBtn    = new QPushButton(QStringLiteral("錯誤訊息盒"));
    filePushBtn     = new QPushButton(QStringLiteral("檔案對話盒"));
    fontPushBtn     = new QPushButton(QStringLiteral("字體對話盒"));
    inputPushBtn    = new QPushButton(QStringLiteral("輸入對話盒"));
    pagePushBtn     = new QPushButton(QStringLiteral("頁面設定對話盒"));
    progressPushBtn = new QPushButton(QStringLiteral("進度對話盒"));
    printPushBtn    = new QPushButton(QStringLiteral("印出對話盒"));
    textColorPushBtn    = new QPushButton(QStringLiteral("文字顏色對話盒"));

    gridLayout->addWidget(colorPushBtn,0,0,1,1);
    gridLayout->addWidget(errorPushBtn,0,1,1,1);
    gridLayout->addWidget(filePushBtn,0,2,1,1);
    gridLayout->addWidget(fontPushBtn,1,0,1,1);
    gridLayout->addWidget(inputPushBtn,1,1,1,1);
    gridLayout->addWidget(pagePushBtn,1,2,1,1);
    gridLayout->addWidget(progressPushBtn,2,0,1,1);
    gridLayout->addWidget(printPushBtn,2,1,1,1);
    gridLayout->addWidget(textColorPushBtn,2,2,1,1);
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
    connect(textColorPushBtn,SIGNAL(clicked()),this,SLOT(doPushBtn()));
    connect(displayTextEdit,SIGNAL(clicked()),this,SLOT(doPushBtn()));

}

CBuiltinDig::~CBuiltinDig() {}
void CBuiltinDig::doPushBtn()
{
    QPushButton* btn = qobject_cast<QPushButton*>(sender());
    if(btn == colorPushBtn)
    {
        QPalette palette = displayTextEdit->palette();
        const QColor& color = QColorDialog::getColor(palette.color(QPalette::Base),
                                                     this, QStringLiteral("設定背景顏色"));
        if(color.isValid())
        {
            palette.setColor(QPalette::Base, color);
            displayTextEdit->setPalette(palette);
        }
    }
    if(btn == errorPushBtn)
    {
        QErrorMessage *box = new QErrorMessage(this);
        box->setWindowTitle(QStringLiteral("錯誤訊息盒"));
        box->showMessage(QStringLiteral("錯誤訊息實例XX"));
        box->showMessage(QStringLiteral("錯誤訊息實例YY"));
        box->showMessage(QStringLiteral("錯誤訊息實例ZZ"));
        box->show();
    }

    if(btn == filePushBtn){
        QString FileName = QFileDialog::getOpenFileName(this, tr("開啟檔案"),"."
                                                        ,tr("任何檔案(*.*)"
                                                            ";;文字檔(*.txt)"
                                                            ";;XML檔(*.xml)"));
        displayTextEdit->setText(FileName);

    }
    if(btn == fontPushBtn){
        bool ok;
        const QFont& font = QFontDialog::getFont(&ok,
                                                 displayTextEdit->font(),
                                                 this,
                                                 QStringLiteral("字體對話盒"));
        if(ok){
            displayTextEdit->setFont(font);
        }
    }
    if(btn == inputPushBtn){
        bool ok;
        QString text = QInputDialog:: getText(this,
                                               QStringLiteral("輸入對話盒"),
                                               QStringLiteral("輸入文字"),
                                               QLineEdit::Normal,
                                               QDir::home().dirName(),
                                               &ok);
        if (ok && !text.isEmpty()) {
            displayTextEdit->setText(text);
        }
    }

    if(btn == pagePushBtn){
        QPrinter printer(QPrinter::HighResolution);
        QPageSetupDialog* dlg = new QPageSetupDialog(&printer,this);
        dlg->setWindowTitle(QStringLiteral("頁面設定對話方塊"));
        if(dlg->exec() == QDialog::Accepted){

        }
    }
    if(btn == progressPushBtn){
        QProgressDialog progress(tr("正在複製檔案"),
                                 tr("取消"),
                                 0,
                                 10000,
                                 this);
        progress.setWindowTitle(tr("進度對話盒"));
        progress.show();
        for(int i=0;i<10000;i++)
        {
            progress.setValue(i);
            qApp->processEvents();
            if(progress.wasCanceled()){
                break;
            }
            qDebug()<< i;
        }
        progress.setValue(10000);
    }
    if(btn == printPushBtn){
        QPrinter printer (QPrinter::HighResolution);
        QPrintDialog dialog(&printer, this);
        if(dialog.exec() != QDialog::Accepted)
            return;
    }
    if(btn == textColorPushBtn){
        QPalette palette = displayTextEdit->palette();
        const QColor& color = QColorDialog::getColor(palette.color(QPalette::Text),
                                                     this, QStringLiteral("設定背景顏色"));
        if(color.isValid())
        {
            palette.setColor(QPalette::Text, color);
            displayTextEdit->setPalette(palette);
        }
    }
}

