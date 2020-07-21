import QtQuick 2.14
import QtQuick.Window 2.14
import QtQuick.Controls 2.14
import QtQuick.Layouts 1.14
import QtQuick.Controls.Styles 1.4

Item {
    property int blockedProfilesHeight
    property var changeHeightFunction
    property var parentHeight

    property var objArray

    Rectangle {
        id: blockedProfilesBackgroundRectangle
        x: 0
        y: 0
        width: parent.width - 100
        height: 46
        color: "#015e80"
        Text {
            id: blockedProfilesHeaderText
            width: parent.width / 4
            height: 46
            color: "#ffffff"
            text: qsTr("BLOCKED PROFILES")
            font.pixelSize: 17
            verticalAlignment: Text.AlignVCenter
            leftPadding: 10
        }

        Rectangle {
            id: blockedProfilesSearchBackgroundRectangle
            x: parent.width / 3
            y: 6
            width: parent.width / 2
            height: 34
            color: "#274e68"
            radius: 3
            border.width: 1
            border.color: Qt.rgba( 0, 0, 0, 0.3)
            TextField {
                id: blockedProfilesSearchTextField
                color: "#ffffff"
                text: qsTr("")
                anchors.fill: parent
                horizontalAlignment: Text.AlignLeft
                font.pixelSize: 17
                anchors.bottomMargin: 0
                background: {}
                anchors.rightMargin: 0
                placeholderText: "Search blocked profiles by name"
                anchors.leftMargin: 34
                anchors.topMargin: 0
                verticalAlignment: Text.AlignVCenter
            }

            Button {
                id: blockedProfilesSearchButton
                x: 0
                y: 0
                width: 34
                height: 34
                text: qsTr("")
                Image {
                    id: buttonImage1
                    source: "qrc:/../../../Images/searchbox_workshop_submit.jpg"
                    anchors.centerIn: parent
                }
                palette {
                    button: "transparent"
                }
            }
        }
    }
    Rectangle {
        id: blockedProfilesListBackgroundRectangle
        x: 0
        y: blockedProfilesBackgroundRectangle.height + 5
        width: blockedProfilesBackgroundRectangle.width
        height: blockedProfilesListGridView.contentHeight
        color: Qt.rgba( 0, 0, 0, 0.2)
        GridView {
            id: blockedProfilesListGridView
            x: 0
            y: 0
            anchors.fill: parent
            model: objArray.length
            cellWidth: parent.width / 2
            delegate: FriendProfileComponent {
                name: objArray[index].nickname
                lastOnlineTime: objArray[index].last_time_online
            }
            Component.onCompleted: {
                blockedProfilesHeight = blockedProfilesListGridView.contentHeight + blockedProfilesBackgroundRectangle.height + blockedProfilesBackgroundRectangle.y + 5
                changeHeightFunction(blockedProfilesHeight + parentHeight)
            }
        }
    }
}
