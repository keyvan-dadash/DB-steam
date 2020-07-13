import QtQuick 2.0

Item {
    id: component
    width: 770
    height: 65

    property var discussion

    Rectangle {
        id: backgroundRectangle
        x: 0
        y: 0
        anchors.fill: parent
        color: "#354f6e"
        Rectangle {
            anchors.fill: parent
            color: Qt.rgba( 84, 133, 183, 0.4)
            z: 1
            MouseArea {
                anchors.fill: parent
                hoverEnabled: true
                z: 2
                DiscussionPreViewComponent {
                    id: preViewComponent
                    visible: false
                    z: component.z + 1
                    discussionObj: discussion
                }
                onEntered: {
                    parent.color = Qt.rgba( 117, 204, 255, 0.5)
                    preViewComponent.visible = true
                    preViewComponent.x = mouseX + 15
                    preViewComponent.y = mouseY + 15
                }
                onExited: {
                    parent.color = Qt.rgba( 84, 133, 183, 0.4)
                    preViewComponent.visible = false
                }
                onPositionChanged: {
                    if(preViewComponent.visible){
                        preViewComponent.x = mouseX + 15
                        preViewComponent.y = mouseY + 15
                    }
                }
            }
        }
    }

    Image {
        id: discussionTypeImage
        x: 0
        y: 0
        width: 65
        height: 65
        fillMode: Image.PreserveAspectFit
        source: "qrc:/qtquickplugin/images/template_image.png"
    }

    Text {
        id: titleText
        x: 77
        y: 0
        width: 482
        height: 31
        color: "#ffffff"
        text: discussion.title
        font.pixelSize: 20
        verticalAlignment: Text.AlignVCenter
    }

    Text {
        id: firstUsernameText
        x: 77
        y: 45
        width: 151
        height: 15
        color: "#8ED1F9"
        text: discussion.author.nickname
        font.pixelSize: 15
    }

    Text {
        id: lastPostDateText
        x: 565
        y: 25
        width: 89
        height: 15
        color: "#8ED1F9"
        text: discussion.last_comment_date;
        font.pixelSize: 13
    }

    Image {
        id: commentsImage
        x: 660
        y: 17
        width: 31
        height: 31
        fillMode: Image.PreserveAspectFit
        source: "qrc:/qtquickplugin/images/template_image.png"
    }

    Text {
        id: numberOfCommentsText
        x: 697
        y: 25
        width: 73
        height: 15
        color: "#dcdcdc"
        text: discussion.number_of_comments
        font.pixelSize: 14
    }

}
