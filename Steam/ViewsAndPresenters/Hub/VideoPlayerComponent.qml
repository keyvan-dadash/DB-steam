import QtQuick 2.14
import QtQuick.Window 2.14
import QtQuick.Controls 2.14
import QtQuick.Layouts 1.14
import QtGraphicalEffects 1.14
import QtMultimedia 5.14

Item {
    property var index: 1
    width: 600
    height: 458

    property var video

    Rectangle {
        anchors.fill: parent
        anchors.leftMargin: if(index % 2 == 0){
                                return 0
                            } else {
                                return 10
                            }
        Rectangle {
            anchors.fill: parent
            color: "#0d131b"
            border.color: "#2f89bc"
            border.width: 0
            MouseArea {
                anchors.fill: parent
                hoverEnabled: true
                onEntered: {
                    parent.border.width = 1
                }
                onExited: {
                    parent.border.width = 0
                }
            }
        }

        Rectangle {
            id: videoBackgroundRectangle
            x: 0
            y: 0
            width: 595
            height: 358
            color: "transparent"

            Video {
                id: videoPlayer
                anchors.fill: parent
                anchors.leftMargin: 7
                anchors.rightMargin: 7
                anchors.topMargin: 7
                source: video.url
                fillMode: VideoOutput.PreserveAspectFit
                MouseArea {
                    anchors.fill: parent
                    onClicked: {
                        videoPlayer.play()
                    }
                }
            }
        }

        Rectangle {
            id: contentsBackgroundRectangle
            x: 8
            y: 358
            width: 579
            height: 56
            color: "transparent"

            Label {
                id: likesLabel
                x: 23
                y: 8
                width: 28
                height: 21
                color: "#7cc5fb"
                text: video.likes
                font.pixelSize: 15
                verticalAlignment: Label.AlignVCenter
                horizontalAlignment: Label.AlignHCenter

            }

            Image {
                id: rateIconImage
                x: 0
                y: 6
                width: 23
                height: 23
                fillMode: Image.PreserveAspectFit
                source: "qrc:/../../../Images/HubPage/icon_rate.png"

            }

            Text {
                id: videoNameText
                x: 0
                y: 30
                width: 571
                height: 26
                text: video.title
                font.pixelSize: 15
                color: "#636363"
                verticalAlignment: Text.AlignVCenter

            }
        }
    }
}
