/****************************************************************************
**
** Copyright (C) 2010 Yngve Inntjore Levinsen.
** This application is licensed under GPL v. 3, which
** means it can be used and modified freely as long as any
** modified source code is made public.
**
** $QT_BEGIN_LICENSE:LGPL$
** Commercial Usage
** Licensees holding valid Qt Commercial licenses may use this file in
** accordance with the Qt Commercial License Agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and Nokia.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 2.1 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU Lesser General Public License version 2.1 requirements
** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Nokia gives you certain additional
** rights.  These rights are described in the Nokia Qt LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 3.0 as published by the Free Software
** Foundation and appearing in the file LICENSE.GPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU General Public License version 3.0 requirements will be
** met: http://www.gnu.org/copyleft/gpl.html.
**
** If you have questions regarding the use of this file, please contact
** Nokia at qt-info@nokia.com.
** $QT_END_LICENSE$
**
****************************************************************************/

#include <QtGui>
#include <iostream>
#include "shoppinglistform.h"

//! [0]
ShoppingListForm::ShoppingListForm(QWidget *parent)
    : QWidget(parent)
{
    ui.setupUi(this);
    widgetsize=40;

}
//! [0]



//! [1]
void ShoppingListForm::on_newItemButton_clicked()
{
    std::cout << "Clicked new item button\n";
    addNewItem();
    ui.mainLayout->setSizeConstraint(QLayout::SetFixedSize);
    ui.scrollArea->update();
    //itemFrame myItem;
    //ui.mainLayout->addWidget(myItem);
//    ui.outputWidget->setText(QString::number(value + ui.inputSpinBox2->value()));
}
//! [1]

void ShoppingListForm::addNewItem()
{
    // copied from ui_itemFrame.h
    QHBoxLayout *itemLayout = new QHBoxLayout();
    itemLayout->setObjectName(QString::fromUtf8("itemLayout"));
    itemLayout->setSizeConstraint(QLayout::SetNoConstraint);
    //QCheckBox *haveFoundCheckBox = new QCheckBox();
    //haveFoundCheckBox->setObjectName(QString::fromUtf8("haveFoundCheckBox"));

    //itemLayout->addWidget(haveFoundCheckBox);

    QLineEdit *amountBox = new QLineEdit();
    amountBox->setObjectName(QString::fromUtf8("amountBox"));
    amountBox->setMaximumSize(QSize(80, 16777215));
    amountBox->setMinimumHeight(38);

    itemLayout->addWidget(amountBox);

    QLineEdit *itemName = new QLineEdit();
    itemName->setObjectName(QString::fromUtf8("itemName"));
    itemName->setMinimumHeight(38);

    itemLayout->addWidget(itemName);

    //QSpacerItem *horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

    //itemLayout->addItem(horizontalSpacer);

    QPushButton *deleteButton = new QPushButton();
    deleteButton->setObjectName(QString::fromUtf8("deleteButton"));
    deleteButton->setText("Remove");
    deleteButton->setMinimumHeight(38);
    //deleteButton->setCenterButtons(false);

    itemLayout->addWidget(deleteButton);
    // end of copied from ui_itemFrame.h
    // Doesn't work atm?
    //QObject::connect(deleteButton, SIGNAL(clicked(QAbstractButton*)), haveFoundCheckBox, SLOT(deleteLater()));
    QObject::connect(deleteButton, SIGNAL(clicked()), amountBox, SLOT(deleteLater()));
    QObject::connect(deleteButton, SIGNAL(clicked()), itemName, SLOT(deleteLater()));
    QObject::connect(deleteButton, SIGNAL(clicked()), deleteButton, SLOT(deleteLater()));
    QObject::connect(deleteButton, SIGNAL(clicked()), itemLayout, SLOT(deleteLater()));
    QObject::connect(deleteButton, SIGNAL(clicked()), this,SLOT(itemWasRemoved()));
    ui.mainLayout->addLayout(itemLayout);
    widgetsize+=80; // in principle should also reduce when removing item, need to create a slot...
    ui.scrollAreaContents->setFixedHeight(widgetsize);
}

void ShoppingListForm::itemWasRemoved() {
    widgetsize-=80;
    ui.scrollAreaContents->setFixedHeight(widgetsize);
}
