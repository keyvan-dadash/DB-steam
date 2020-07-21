import QtQuick 2.14
import QtQuick.Window 2.14
import QtQuick.Controls 2.14
import QtQuick.Layouts 1.14


Item {
    signal changeHeightOfParent(int height)
    property var changeHeightFunction
    property var parentHeight

    //list friends
    property var objArray
    Rectangle {
        id: textBackground
        x: 0
        y: 0
        width: parent.width - 20
        height: 44
        color: "#015e80"
        Text {
            id: element2
            anchors.fill: parent
            text: qsTr("YOUR FRIENDS 3/270")
            anchors.leftMargin: 10
            horizontalAlignment: Text.AlignLeft
            verticalAlignment: Text.AlignVCenter
            font.pixelSize: 20
            color: "#fff"
        }

    }

    Rectangle{
        id: textInputBackground
        x: 0
        y: textBackground.height + textBackground.y + 10
        width: parent.width / 2
        height: 34
        color: "#274e68"
        border.color: Qt.rgba( 0, 0, 0, 0.3)
        border.width: 1
        radius: 3
        TextField {
            id: textField
            anchors.fill: parent
            text: qsTr("")
            font.pixelSize: 17
            color: "white"
            horizontalAlignment: Text.AlignLeft
            verticalAlignment: Text.AlignVCenter
            anchors.leftMargin: 34
            background: {}
            placeholderText: "Search friends by name or game"
        }

        Button {
            id: searchButton
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
                source: "qrc:/../../../Images/searchbox_workshop_submit.jpg"
                anchors.centerIn: parent
            }
            onClicked: {
                console.log(textField.text)
                textField.text = ""
            }
        }

    }
    GridView {
        id: listView
        x: 0
        y: textInputBackground.height + textInputBackground.y + 20
        width: parent.width
        height: listView.contentHeight
        model: objArray.length
        cellWidth: listView.width / 2
        delegate: FriendProfileComponent {
            name: objArray[index].nickname
            lastOnlineTime: objArray[index].last_time_online
            profileImageUrl: objArray[index].profileImg.url
        }
        Component.onCompleted: {
            parent.changeHeightOfParent.connect(changeHeightFunction)
            parent.changeHeightOfParent(listView.contentHeight + parentHeight + y)
        }
    }
}
