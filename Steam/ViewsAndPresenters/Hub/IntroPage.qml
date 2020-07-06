import QtQuick 2.14
import QtQuick.Window 2.14
import QtQuick.Controls 2.14
import QtQuick.Layouts 1.14
import QtGraphicalEffects 1.14

Item {
    property var changeParentHeight

    id: itemView
    width: 1190
    height: 345

    Component.onCompleted: {
        changeParentHeight(itemView.height)
    }

    Rectangle {
        id: backgroundRectangle
        anchors.fill: parent
        color: Qt.rgba( 0, 0, 0, 0.8 )

        Rectangle {
            id: backgroundRectangle1
            x: 0
            y: 0
            width: 1190
            height: 78
            color: "#2b405a"
            Rectangle {
                anchors.fill: parent
                color: Qt.rgba( 0, 0, 0, 0.4 )
            }

            Label {
                id: newLabel
                x: 1057
                y: 24
                width: 125
                height: 30
                text: qsTr("54 News")
                color: "white"
                verticalAlignment: Text.AlignVCenter
                font.pixelSize: 16
            }

            Label {
                id: numberOfDiscussionsLabel
                x: 908
                y: 24
                width: 125
                height: 30
                text: qsTr("219 Discussions")
                color: "white"
                verticalAlignment: Text.AlignVCenter
                font.pixelSize: 16
            }

            Label {
                id: numberOfInGame
                x: 759
                y: 24
                width: 125
                height: 30
                text: qsTr("1,684 In-Game")
                color: "#7cc53f"
                verticalAlignment: Text.AlignVCenter
                font.pixelSize: 16
            }
        }

        Image {
            id: gameHeaderImage
            x: 27
            y: 100
            width: 485
            height: 215
            fillMode: Image.PreserveAspectFit
            source: "qrc:/D:/fucking uni/DB/project/HubPage/header.jpg"
        }

        TextArea {
            id: discreptionTextArea
            x: 529
            y: 100
            width: 642
            height: 158
            text: qsTr("ASSASSIN’S CREED® ORIGINS IS A NEW BEGINNING *The Discovery Tour by Assassin’s Creed®: Ancient Egypt is available now as a free update!* Ancient Egypt, a land of majesty and intrigue, is disappearing in a ruthless fight for power.")
            wrapMode: TextArea.Wrap
            readOnly: true
            color: "#8c8b8a"
            font.pixelSize: 17
        }

        Button {
            id: visitStoreButton
            x: 690
            y: 265
            width: 198
            height: 40
            background: Rectangle {
                color: "#67c1f5"
                opacity: 0.2
                radius: 3
            }
            text: qsTr("Visit the Store Page")
            contentItem: Text {
                text: parent.text
                color: "#67c1f5"
                font.pixelSize: 18
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
            }
        }

        Rectangle {
            id: priceBackgroundRectangle
            x: 529
            y: 265
            width: 149
            height: 40
            color: "transparent"
            border.width: 1
            border.color: "#636363"
            Text {
                id: priceText
                anchors.fill: parent
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                text: qsTr("$59.99")
                color: "#636363"
                font.pixelSize: 18
            }
        }
    }

}
