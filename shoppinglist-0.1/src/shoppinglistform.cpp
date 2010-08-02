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
}
//! [0]



//! [1]
void ShoppingListForm::on_newItemButton_clicked()
{
    std::cout << "Clicked new item button\n";
    addNewItem();
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
    QCheckBox *haveFoundCheckBox = new QCheckBox();
    haveFoundCheckBox->setObjectName(QString::fromUtf8("haveFoundCheckBox"));

    itemLayout->addWidget(haveFoundCheckBox);

    QLineEdit *numberOfItems = new QLineEdit();
    numberOfItems->setObjectName(QString::fromUtf8("numberOfItems"));
    numberOfItems->setMaximumSize(QSize(40, 16777215));

    itemLayout->addWidget(numberOfItems);

    QLineEdit *itemName = new QLineEdit();
    itemName->setObjectName(QString::fromUtf8("itemName"));

    itemLayout->addWidget(itemName);

    QSpacerItem *horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

    itemLayout->addItem(horizontalSpacer);

    QDialogButtonBox *deleteButton = new QDialogButtonBox();
    deleteButton->setObjectName(QString::fromUtf8("deleteButton"));
    deleteButton->setStandardButtons(QDialogButtonBox::Discard);
    deleteButton->setCenterButtons(false);

    itemLayout->addWidget(deleteButton);
    // end of copied from ui_itemFrame.h
    QObject::connect(deleteButton, SIGNAL(clicked(QAbstractButton*)), haveFoundCheckBox, SLOT(deleteLater()));
    QObject::connect(deleteButton, SIGNAL(clicked(QAbstractButton*)), numberOfItems, SLOT(deleteLater()));
    QObject::connect(deleteButton, SIGNAL(clicked(QAbstractButton*)), itemName, SLOT(deleteLater()));
    QObject::connect(deleteButton, SIGNAL(clicked(QAbstractButton*)), deleteButton, SLOT(deleteLater()));
    QObject::connect(deleteButton, SIGNAL(clicked(QAbstractButton*)), itemLayout, SLOT(deleteLater()));
    QObject::connect(deleteButton, SIGNAL(clicked(QAbstractButton*)), ui.mainLayout, SLOT(update()));
    ui.mainLayout->addLayout(itemLayout);
}

