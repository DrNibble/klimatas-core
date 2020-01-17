// Copyright (c) 2017-2019 The KTSX developers
// Copyright (c) 2019-2020 The Klimatas developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef ZKTSCONTROLDIALOG_H
#define ZKTSCONTROLDIALOG_H

#include <QDialog>
#include <QTreeWidgetItem>
#include "zkts/zerocoin.h"

class CZerocoinMint;
class WalletModel;

namespace Ui {
class ZKtsControlDialog;
}

class CZKtsControlWidgetItem : public QTreeWidgetItem
{
public:
    explicit CZKtsControlWidgetItem(QTreeWidget *parent, int type = Type) : QTreeWidgetItem(parent, type) {}
    explicit CZKtsControlWidgetItem(int type = Type) : QTreeWidgetItem(type) {}
    explicit CZKtsControlWidgetItem(QTreeWidgetItem *parent, int type = Type) : QTreeWidgetItem(parent, type) {}

    bool operator<(const QTreeWidgetItem &other) const;
};

class ZKtsControlDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ZKtsControlDialog(QWidget *parent);
    ~ZKtsControlDialog();

    void setModel(WalletModel* model);

    static std::set<std::string> setSelectedMints;
    static std::set<CMintMeta> setMints;
    static std::vector<CMintMeta> GetSelectedMints();

private:
    Ui::ZKtsControlDialog *ui;
    WalletModel* model;

    void updateList();
    void updateLabels();

    enum {
        COLUMN_CHECKBOX,
        COLUMN_DENOMINATION,
        COLUMN_PUBCOIN,
        COLUMN_VERSION,
        COLUMN_PRECOMPUTE,
        COLUMN_CONFIRMATIONS,
        COLUMN_ISSPENDABLE
    };
    friend class CZKtsControlWidgetItem;

private slots:
    void updateSelection(QTreeWidgetItem* item, int column);
    void ButtonAllClicked();
};

#endif // ZKTSCONTROLDIALOG_H
