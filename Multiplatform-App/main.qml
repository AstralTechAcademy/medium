import QtQuick 2.12
import QtQuick.Window 2.15
import QtQuick.Controls 2.15


Window {
    id: mMainWindow
    visible: true
    height: Screen.height
    width: Screen.width
    //visibility: "FullScreen"
    color: "#e9e7e7"
    title: qsTr("Hello")
    
    Item
    {
        id: header
        height: 60
        anchors.top: parent.top
        anchors.topMargin: 0
        anchors.left: parent.left
        anchors.leftMargin: 0
        anchors.right: parent.right
        anchors.rightMargin: 0

        Rectangle
        {
            id: horizontalLineH // ids must be uniques
            anchors.bottom: parent.bottom // parent == footer
            anchors.bottomMargin: 0
            anchors.left: parent.left
            anchors.leftMargin: 0
            anchors.right: parent.right
            anchors.rightMargin: 0
            height: 2
            color: "black"
        }
    }

    Item
    {
        id: body
        anchors.top: header.bottom
        anchors.topMargin: 0
        anchors.bottom: footer.top
        anchors.bottomMargin: 0
        anchors.left: parent.left
        anchors.leftMargin: 0
        anchors.right: parent.right
        anchors.rightMargin: 0

        Rectangle
        {
            anchors.fill: body // Size of all body space
            color: "lightblue"
        }


        Rectangle
        {
            id: rCenter
            color: "white"
            width: 300
            height: 100
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.verticalCenter: parent.verticalCenter

            Text
            {
                id: rText
                text: "This is my first QML APP"
                color: "black"
                anchors.horizontalCenter: parent.horizontalCenter // parent == rCenter
                anchors.verticalCenter: parent.verticalCenter // parent == rCenter
            }
        }
    }

    Item
    {
        id: footer
        height: 30
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 0
        anchors.left: parent.left
        anchors.leftMargin: 0
        anchors.right: parent.right
        anchors.rightMargin: 0

        Rectangle
        {
            id: horizontalLineF // ids must be uniques
            anchors.top: parent.top // parent == footer
            anchors.topMargin: 0
            anchors.left: parent.left
            anchors.leftMargin: 0
            anchors.right: parent.right
            anchors.rightMargin: 0
            height: 2
            color: "#000000"
        }

        Text
        {
            id: name
            text: "Astral Academy"
            anchors.horizontalCenter: parent.horizontalCenter // parent == footer
            anchors.verticalCenter: parent.verticalCenter // parent == footer
        }

        Text
        {
            id: version
            text: "v1.0.0"
            anchors.verticalCenter: parent.verticalCenter // parent == footer
            anchors.right: parent.right
            anchors.rightMargin: 10 // 10 pixels between rigth border of the footer and the right border of the text
        }
    }
}