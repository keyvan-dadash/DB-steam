import QtQuick 2.14
import QtQuick.Window 2.14
import QtQuick.Controls 2.14
import QtQuick.Layouts 1.14
import QtGraphicalEffects 1.14

Item {

    property var changeParentHeight
    property var componentHeight: 65 //sry i have no choice but to hardcode this

    property var loadViewFunction

    property var getCommentsFunction


    property var discussions

    width: 1200
    ListView {
        id: listViewDiscussion
        //anchors.fill: parent
        spacing: 10
        model: discussions.length
        width: 770
        height: parent.height
        anchors.rightMargin: 480
        x: 0
        y: 0
        delegate: DiscussionComponent {
            z: (listViewDiscussion.count - index)
            discussion: discussions[index]

            MouseArea {
                anchors.fill: parent
                onClicked: {
                    loadViewFunction("DiscussionContentPage.qml", {
                                         "getComments": getCommentsFunction,
                                         "changeParentHeight": changeParentHeight,
                                         "disucssion": parent.discussion
                                     })
                }
            }
        }
        Component.onCompleted: {
            changeParentHeight((componentHeight + listViewDiscussion.spacing) * listViewDiscussion.count + 200)
        }
    }

    Rectangle {
        id: rectangle
        x: 819
        y: 198
        width: 341
        height: 84
        color: Qt.rgba(0, 0, 0, 0.2)
        z:-1

        Button {
            id: button
            x: 8
            y: 17
            width: 274
            height: 39
            z:0
            text: qsTr("Start a New Discussion")
            contentItem: Text {
                text: parent.text
                font.pixelSize: 20
                color: "#A4D7F5"
            }
            background: Rectangle {
                color: "#2f89bc"
                radius: 2
            }
        }
    }
}
