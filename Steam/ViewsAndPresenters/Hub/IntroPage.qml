import QtQuick 2.14
import QtQuick.Window 2.14
import QtQuick.Controls 2.14
import QtQuick.Layouts 1.14
import QtGraphicalEffects 1.14

Item {
    property var changeParentHeight

    property var newsCount
    property var discussionCount
    property var description
    property var gamePrice
    property var gameHeaderImg
    property var purchase


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
                text: newsCount + " News"
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
                text: discussionCount + " Discussions"
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
                text: purchase + " purchases"
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
            source: gameHeaderImg
        }

        TextArea {
            id: discreptionTextArea
            x: 529
            y: 100
            width: 642
            height: 158
            text: description
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
                text: "$" + gamePrice
                color: "#636363"
                font.pixelSize: 18
            }
        }
    }

}
