import QtQuick 2.0

Item {
    width: 400
    height: 25

    Rectangle {
        anchors.fill: parent
        color: "transparent"
        MouseArea {
            anchors.fill: parent
            hoverEnabled: true
            onEntered: {
                parent.color = "#323a4b"
                gameNameText.color = "#5b6373"
            }
            onExited: {
                parent.color = "transparent"
                gameNameText.color = "#4f545d"
            }
        }
    }

    Text {
        id: gameNameText
        anchors.fill: parent
        anchors.leftMargin: 5
        verticalAlignment: Text.AlignVCenter
        font.pixelSize: 16
        color: "#4f545d"
        text: qsTr("Tom Clancy's Rainbow Six Siege")
    }
}
