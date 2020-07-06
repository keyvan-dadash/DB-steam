import QtQuick 2.14
import QtQuick.Window 2.14
import QtQuick.Controls 2.14
import QtQuick.Layouts 1.14
import QtGraphicalEffects 1.14
import QtMultimedia 5.14

Item {
    property var changeParentHeight
    Rectangle {
        anchors.fill: parent
        color: "transparent"
    }

    Rectangle {
        id: backgroundRectangle
        x: 0
        y: 0
        width: 1200
        height: 78
        color: "#2b405a"
        Rectangle {
            anchors.fill: parent
            color: Qt.rgba( 0, 0, 0, 0.4 )

            Label {
                id: showLabel
                x: 29
                y: 28
                width: 95
                height: 23
                text: qsTr("Show")
                color: "#2f89bc"
                font.pixelSize: 15
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignRight
            }
        }
        ComboBox{
            x: 138
            y: 25
            width: 285
            height: 29
            model: [ "Most Popular (All time)", "Most Popular (Week)", "Most Popular (Month)", "Most Popular (Year)", "Most Popular (Today)" ]

            background: Rectangle {
                anchors.fill: parent
                color: "#1b2838"
                radius: 2
                Rectangle {
                    anchors.fill: parent
                    color: "#67c1f5"
                    opacity: 0.2
                    radius: 2
                }
            }
            contentItem: Text {
                text: parent.displayText
                color: "#67c1f5"
                font.pixelSize: 16
                verticalAlignment: Text.AlignVCenter
                leftPadding: 4
            }

            delegate: ItemDelegate {
                width: parent.width
                contentItem: Text {
                    text: modelData
                    color: "white"
                    font.pixelSize: 16
                    verticalAlignment: Text.AlignVCenter
                }
                background: Rectangle{
                    anchors.fill: parent
                    color: "#417A9B"
                }
            }
        }
    }

    GridView {
        id: videosGridView
        x: 0
        y: 100
        width: parent.width
        height: videosGridView.contentHeight
        model: 16
        cellWidth: videosGridView.width / 2
        cellHeight: 465
        delegate: VideoPlayerComponent {
            index: model.index
        }

        Component.onCompleted: {
            changeParentHeight(videosGridView.contentHeight + videosGridView.y)
        }
    }
}
