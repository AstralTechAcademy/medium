
/*
   The version of import shoulbe in accordance with Qt Documentation
   https://doc.qt.io/qt-5/qml-qtquick-window-window.html
 */

import QtQuick 2.12
import QtQuick.Window 2.15
import QtQuick.Dialogs
import QtQuick.Controls 2.15


Window {
    id: mMainWindow
    visible: true
    height: Screen.height
    width: Screen.width
    //visibility: "FullScreen"
    color: "#e9e7e7"
    title: qsTr("Couple")
    
}