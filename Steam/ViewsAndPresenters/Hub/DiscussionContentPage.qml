import QtQuick 2.14
import QtQuick.Window 2.14
import QtQuick.Controls 2.14
import QtQuick.Layouts 1.14
import QtGraphicalEffects 1.14

Item {
    property var changeParentHeight

    width: 1200

    Flickable {
        width: parent.width
        height: ops.height + newsListView.height + (newsListView.y - (ops.y + ops.height))

        Rectangle {
            id: ops
            x: 0
            y: 0
            width: 860
            height: 492

            Image {
                id: back
                anchors.fill: parent
                source: "qrc:/D:/fucking uni/DB/project/HubPage/forum_op_gradient.png"
            }

            Image {
                id: image
                x: 8
                y: 8
                width: 40
                height: 41
                source: "qrc:/qtquickplugin/images/template_image.png"
                fillMode: Image.PreserveAspectFit
            }

            Label {
                id: label4
                x: 54
                y: 14
                width: 581
                height: 21
                color: "#aedd08"
                font.pixelSize: 16
                text: qsTr("UbiQuB3")
            }

            Label {
                id: label5
                x: 657
                y: 14
                width: 195
                height: 21
                color: "#8f98a0"
                text: qsTr("Oct 26, 2017 @ 10:55am")
            }

            Text {
                id: element
                x: 54
                y: 61
                width: 752
                height: 73
                color: "#fff"
                wrapMode: Text.Wrap
                text: qsTr("Assassin's Creed Origins - Known Issues [Updated: May 15]")
                font.pixelSize: 25
            }

            TextArea {
                id: textArea
                x: 8
                y: 140
                width: 844
                height: 352
                color: "#dbdbdb"
                readOnly: true
                wrapMode: TextArea.Wrap
                font.pixelSize: 14
                text: qsTr("Hey everyone,

Please find the current list of known issues below.


In-Game Issues

Game crashes
Description: We’ are currently investigating various user reports of crashes on all platforms.
Status: Under Investigation
PC specific note: Please do get in touch with the support team and provide them with ms info and dxdiag.

PC-specific

HBCC causes performance drops
Description: Enabling HBCC on AMD Radeon settings can result in a drop of performance.
Workaround: We advise to turn off this setting until AMD resolved the issue with a future")
            }
        }

        Rectangle {
            id: rectangle
            x: 866
            y: 12
            width: 328
            height: 86
            color: Qt.rgba( 0, 0, 0, 0.8 )
            Rectangle {
                id: backgroundRectangle1
                anchors.fill: parent
                color: "#2b405a"
                Rectangle {
                    anchors.fill: parent
                    color: Qt.rgba( 0, 0, 0, 0.25 )

                    Label {
                        id: label
                        x: 8
                        y: 8
                        width: 96
                        height: 21
                        color: "#61686d"
                        font.pixelSize: 16
                        text: qsTr("Date Posted:")
                    }

                    Label {
                        id: label1
                        x: 110
                        y: 8
                        width: 210
                        height: 21
                        color: "#8f98a0"
                        font.pixelSize: 16
                        text: qsTr("Oct 26, 2017 @ 10:55am")
                        verticalAlignment: Label.AlignLeft
                    }

                    Label {
                        id: label2
                        x: 8
                        y: 42
                        width: 68
                        height: 21
                        color: "#61686d"
                        font.pixelSize: 16
                        text: qsTr("Posts:")
                    }

                    Label {
                        id: label3
                        x: 110
                        y: 42
                        width: 210
                        height: 21
                        color: "#8f98a0"
                        font.pixelSize: 16
                        text: qsTr("1,715")
                        verticalAlignment: Label.AlignLeft
                    }
                }
            }
        }


        ListView {
            id: newsListView
            y: 500
            width: 860
            height: newsListView.contentHeight
            spacing: 10
            interactive: false
            model:20
            delegate: DiscussionCommentComponent {


            }
        }
        Component.onCompleted: {
            changeParentHeight(this.height)
        }
    }
}
