import QtQuick 2.14
import QtQuick.Window 2.14
import QtQuick.Controls 2.14
import QtQuick.Layouts 1.14
import QtQuick.Controls.Styles 1.4

Item {
    property int receivedInvitesHeight
    property int sentInvitesHeight
    property var changeHeightFunction
    property var parentHeight

    property var receiveObjArray
    property var pendingObjArray


    property var ne: function*(){
        var n = 0
        while(true){
            if(n == 2){
                changeHeightFunction(sentInvitesHeight + receivedInvitesHeight + mainGridLayout.rowSpacing + parentHeight)
                mainGridLayout.height = sentInvitesHeight + receivedInvitesHeight
                break;
            }
            yield ++n;
        }
    }
    property var cor: ne()
    Component.onCompleted: {
        cor.next()
    }

    GridLayout {
        id: mainGridLayout
        width: parent.width - 100
        height: parent.height
        rows: 2
        rowSpacing: 30

        Rectangle {
            id: receivedInvitesRectangle
            Layout.row: 0
            Layout.alignment: Qt.AlignTop
            width: parent.width
            height: receivedInvitesListBackgroundRectangle.height + receivedInvitesBackgroundRectangle.height + receivedInvitesBackgroundRectangle.y
            Layout.preferredHeight: height
            Layout.preferredWidth: width
            color: "transparent"
            Rectangle {
                id: receivedInvitesBackgroundRectangle
                x: 0
                y: 0
                width: parent.width
                height: 46
                color: "#015e80"

                Text {
                    id: receivedInvitesHeaderText
                    width: parent.width / 4
                    height: 46
                    text: qsTr("RECEIVED INVITES")
                    font.pixelSize: 17
                    verticalAlignment: Text.AlignVCenter
                    leftPadding: 10
                    color: "#fff"
                }
                Rectangle{
                    id: receivedInvitesSearchBackgroundRectangle
                    x: parent.width / 4
                    y: 6
                    width: parent.width / 2
                    height: 34
                    color: "#274e68"
                    border.color: Qt.rgba( 0, 0, 0, 0.3)
                    border.width: 1
                    radius: 3
                    TextField {
                        id: receivedInvitesSearchTextField
                        anchors.fill: parent
                        text: qsTr("")
                        anchors.rightMargin: 0
                        anchors.bottomMargin: 0
                        anchors.topMargin: 0
                        font.pixelSize: 17
                        color: "white"
                        horizontalAlignment: Text.AlignLeft
                        verticalAlignment: Text.AlignVCenter
                        anchors.leftMargin: 34
                        background: {}
                        placeholderText: "Search received invites by name"
                    }

                    Button {
                        id: receivedInvitesSearchButton
                        x: 0
                        y: 0
                        width: 34
                        height: 34
                        text: qsTr("")
                        palette {
                            button: "transparent"
                        }
                        Image {
                            id: buttonImage
                            source: "qrc:/D:/fucking uni/DB/project/searchbox_workshop_submit.jpg"
                            anchors.centerIn: parent
                        }
                        onClicked: {
                            console.log(textField.text)
                            textField.text = ""
                        }
                    }
                }
                Button {
                    id: receivedInvitesIgnoreButton
                    x: parent.width - 150
                    y: 9
                    width: 120
                    height: 28
                    text: qsTr("IGNORE ALL")
                    contentItem: Text {
                        text: parent.text
                        font.pixelSize: 15
                        color: "#67c1f5"
                        anchors.centerIn: parent
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                    }
                    background: Rectangle {
                        anchors.fill: parent
                        color: Qt.rgba( 103, 193, 245, 0.2 )
                        radius: 3
                        border.width: 1
                        border.color: color
                    }
                }
            }
            Rectangle {
                id: receivedInvitesListBackgroundRectangle
                x: 0
                y: receivedInvitesBackgroundRectangle.height + 5
                width: parent.width
                height: receivedInvitesListGridView.contentHeight
                color: Qt.rgba( 0, 0, 0, 0.2)
                GridView {
                    id: receivedInvitesListGridView
                    x: 0
                    y: 0
                    anchors.fill: parent
                    model: receiveObjArray.length
                    cellWidth: parent.width / 2
                    delegate: FriendProfileComponent {
                        name: receiveObjArray[index].nickname
                        lastOnlineTime: receiveObjArray[index].last_time_online
                    }
                    Component.onCompleted: {
                        receivedInvitesHeight = receivedInvitesListGridView.contentHeight + receivedInvitesBackgroundRectangle.height + receivedInvitesBackgroundRectangle.y + 5
                        cor.next()
                    }
                }
            }
        }

        Rectangle {
            id: sentInvitesRectangle
            Layout.row: 1
            Layout.alignment: Qt.AlignTop
            width: parent.width
            height: sentInvitesListBackgroundRectangle.height + sentInvitesBackgroundRectangle.height + sentInvitesBackgroundRectangle.y
            Layout.preferredWidth: width
            Layout.preferredHeight : height
            color: "transparent"

            Rectangle {
                id: sentInvitesBackgroundRectangle
                x: 0
                y: 0
                width: parent.width
                height: 46
                color: "#015e80"
                Text {
                    id: sentInvitesHeaderText
                    width: parent.width / 4
                    height: 46
                    color: "#ffffff"
                    text: qsTr("SENT INVITES")
                    font.pixelSize: 17
                    verticalAlignment: Text.AlignVCenter
                    leftPadding: 10
                }

                Rectangle {
                    id: sentInvitesSearchBackgroundRectangle
                    x: parent.width / 4
                    y: 6
                    width: parent.width / 2
                    height: 34
                    color: "#274e68"
                    radius: 3
                    border.width: 1
                    border.color: Qt.rgba( 0, 0, 0, 0.3)
                    TextField {
                        id: sentInvitesSearchTextField
                        color: "#ffffff"
                        text: qsTr("")
                        anchors.fill: parent
                        horizontalAlignment: Text.AlignLeft
                        font.pixelSize: 17
                        anchors.bottomMargin: 0
                        background: {}
                        anchors.rightMargin: 0
                        placeholderText: "Search sent invites by name"
                        anchors.leftMargin: 34
                        anchors.topMargin: 0
                        verticalAlignment: Text.AlignVCenter
                    }

                    Button {
                        id: sentInvitesSearchButton
                        x: 0
                        y: 0
                        width: 34
                        height: 34
                        text: qsTr("")
                        Image {
                            id: buttonImage1
                            source: "qrc:/D:/fucking uni/DB/project/searchbox_workshop_submit.jpg"
                            anchors.centerIn: parent
                        }
                        palette {
                            button: "transparent"
                        }
                    }
                }
            }
            Rectangle {
                id: sentInvitesListBackgroundRectangle
                x: 0
                y: sentInvitesBackgroundRectangle.height + 5
                width: parent.width
                height: sentInvitesListGridView.contentHeight
                color: Qt.rgba( 0, 0, 0, 0.2)
                GridView {
                    id: sentInvitesListGridView
                    x: 0
                    y: 0
                    anchors.fill: parent
                    model: pendingObjArray.length
                    cellWidth: parent.width / 2
                    delegate: FriendProfileComponent {
                        name: pendingObjArray[index].nickname
                        lastOnlineTime: pendingObjArray[index].last_time_online
                    }
                    Component.onCompleted: {
                        sentInvitesHeight = sentInvitesListGridView.contentHeight + sentInvitesBackgroundRectangle.height + sentInvitesBackgroundRectangle.y + 5
                        cor.next()
                    }
                }
            }
        }
    }
}
