/*
  Copyright 2010 Dally Richard
  This file is part of QNetSoul.
  QNetSoul is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  QNetSoul is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with QNetSoul.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef QNETSOUL_H_
#define QNETSOUL_H_

#include <QAbstractSocket>
#include <QSystemTrayIcon>
#include "AddContact.h"
#include "ui_QNetsoul.h"

class   Chat;
class   QTimer;
class   QAction;
class   Network;
class   Pastebin;
class   TrayIcon;
class   VieDeMerde;
class   SlidingPopup;
class   InternUpdater;
class   OptionsWidget;
class   ChuckNorrisFacts;
class   PortraitResolver;
class   PluginsManager;

class   QNetsoul : public QMainWindow, public Ui_QNetsoul
{
  Q_OBJECT

  public:
  QNetsoul(void);
  ~QNetsoul(void);

  static void openOptionsDialog(OptionsWidget* options,
                                const int currentTab = -1,
                                QWidget* focus = NULL);

protected:
  void  closeEvent(QCloseEvent*);

private slots:
  void  connectToServer(void);
  void  ping(void);
  void  reconnect(void);
  void  disconnect(void);
  void  updateWidgets(const QAbstractSocket::SocketState&);
  void  openOptionsDialog(void);
  void  disableChats(const QString& login);
  void  saveStateBeforeQuiting(void);
  void  handleClicksOnTrayIcon(QSystemTrayIcon::ActivationReason);
  void  changeStatus(const QStringList& properties);
  void  updateContact(const QStringList& properties);
  void  showConversation(const QStringList&, const QString& msg = "");
  void  processHandShaking(int, QStringList);
  void  notifyTypingStatus(const int id, const bool typing);
  void  setPortrait(const QString&);
  void  aboutQNetSoul(void);
  void  darkFusionStyle(void);

private:
  Chat* getChat(const int id);
  void  disableChat(Chat* chat);
  void  resetAllContacts(void);
  void  readSettings(void);
  void  writeSettings(void);
  void  setupTrayIcon(void);
  void  connectQNetsoulModules(void);
  void  connectActionsSignals(void);
  void  connectNetworkSignals(void);
  Chat* createWindowChat(const int, const QString&, const QString&);
  void  deleteAllWindowChats(void);

  Network*          _network;
  OptionsWidget*    _options;
  TrayIcon*         _trayIcon;
  QHash<int, Chat*> _windowsChat;
  QString           _timeStamp;
  QPoint            _oldPos;
  PortraitResolver* _portraitResolver;
  Pastebin*         _pastebin;
  SlidingPopup*     _popup;
  VieDeMerde*       _vdm;
  ChuckNorrisFacts* _cnf;
  QTimer*           _ping;
  InternUpdater*    _internUpdater;
  PluginsManager*   _pluginsManager;
  QPalette         _initPalette;
};

#endif // QNETSOUL_H_
