import QtQuick 2.0

Item {
    width: 350
    height: 65
    property var name
    property var lastOnlineTime

    Rectangle {
        anchors.fill: parent
        color: "#1d1f24"
        opacity: 0.8
        Image {
            id: profileImage
            x: 0
            y: 0
            width: 65
            height: 65
            fillMode: Image.Stretch
            source: "qrc:/qtquickplugin/images/template_image.png"
            clip: true
            Rectangle {
                anchors.leftMargin:  -border.width
                anchors.topMargin:  -border.width
                anchors.bottomMargin:  -border.width
                anchors.fill: parent
                border.color: "#57cbde"
                border.width: 4
            }
        }

        Text {
            id: nameText
            x: 76
            y: 8
            width: 274
            height: 31
            color: "#57cbde"
            text: name
            font.family: "Sans-serif"
            font.pixelSize: 22
            verticalAlignment: Qt.AlignVCenter
        }

        Text {
            id: lastOnlineText
            x: 76
            y: 45
            width: 266
            height: 20
            color: "#898989"
            text: "last online " + lastOnlineTime
            font.family: "Sans-serif"
            font.pixelSize: 14
            verticalAlignment: Qt.AlignVCenter
        }
    }
}
