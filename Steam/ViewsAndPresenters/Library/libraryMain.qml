import QtQuick 2.14
import QtQuick.Window 2.14
import QtQuick.Controls 2.14
import QtQuick.Layouts 1.14
import QtQuick.Controls.Styles 1.4


Item {
    visible: true
    width: 1254
    height: 622

    property var gamesList
    property var imagesList
    property var totalGamePlayList

    Rectangle {
        id: gamelistAndSearchRectangle
        x: 0
        y: 0
        width: 402
        height: 622
        color: "#24282f"

        Button {
            id: homeButton
            x: 8
            y: 30
            width: 340
            height: 40
            text: qsTr("HOME")
            background: Rectangle {
                anchors.fill: parent
                color: "#46484f"
                radius: 2
            }
            contentItem: Text {
                anchors.fill: parent
                font.pixelSize: 18
                text: parent.text
                color: "#fff"
                anchors.leftMargin: 5
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignLeft
            }
        }

        Button {
            id: button1
            x: 354
            y: 30
            width: 40
            height: 40
            background: Rectangle {
                anchors.fill: parent
                radius: 1
                Image {
                    id: collectionIconImage
                    anchors.fill: parent
                    source: "qrc:/D:/fucking uni/DB/project/collection.png"
                }
                MouseArea {
                    anchors.fill: parent
                    hoverEnabled: true
                    onEntered: {
                        collectionIconImage.source = "qrc:/D:/fucking uni/DB/project/collectionHover.png"
                        yourCollectionHoverBackgroundRectangle.visible = true
                    }
                    onExited: {
                        collectionIconImage.source = "qrc:/D:/fucking uni/DB/project/collection.png"
                        yourCollectionHoverBackgroundRectangle.visible = false
                    }
                }
            }
        }

        Rectangle{
            id: textInputBackground
            x: 8
            y: 92
            width: 386
            height: 34
            color: "#222429"
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
                placeholderText: "Search game by name"
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
                    source: "qrc:/D:/fucking uni/DB/project/searchbox_workshop_submit.jpg"
                    anchors.centerIn: parent
                }
                onClicked: {
                    console.log(textField.text)
                    textField.text = ""
                }
            }

        }

        Rectangle {
            id: rectangle
            x: 0
            y: 152
            width: 400
            height: 31
            color: "#292f3b"
            Label {
                id: allgameLabel
                x: 0
                y: 0
                width: 44
                height: 31
                text: "ALL"
                verticalAlignment: Label.AlignVCenter
                horizontalAlignment: Label.AlignHCenter
                color: "#b1c8de"
                font.pixelSize: 15
            }

            Label {
                id: numberOfGamesLabel
                x: 45
                y: 0
                width: 39
                height: 31
                text: "(" + gamesList.length + ")"
                verticalAlignment: Label.AlignVCenter
                horizontalAlignment: Label.AlignLeft
                color: "#484d57"
                font.pixelSize: 14
            }
        }
        ListView {
            id: gameNamesListView
            x: 0
            y: 190
            spacing: 5
            width: 402
            height: 431
            anchors.leftMargin: 3
            model: gamesList.length
            delegate: GameNameComponent {
                gameName: gamesList[index]
            }
        }
    }

    Rectangle {
        id: yourCollectionHoverBackgroundRectangle
        visible: false
        x: 400
        y: 30
        width: 135
        height: 40
        color: "#696773"
        radius: 2
        z: 2
        Text {
            anchors.fill: parent
            id: yourCollectionHoverText
            text: qsTr("Your collections")
            font.pixelSize: 15
            color: "#fff"
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
        }
    }

    Flickable {
        id: gamelistWtihImageRectangle
        x: 402
        y: 0
        width: 855
        height: 622
        contentHeight: gameListGridView.contentHeight + gameListGridView.y > 622 ? gameListGridView.contentHeight + gameListGridView.y : 622
        Rectangle {
            id: gameListBackgroundRectangle
            color: "#2b3039"
            anchors.fill: parent
        }

        Label {
            id: label2
            x: 8
            y: 33
            width: 126
            height: 36
            text: "ALL GAMES"
            verticalAlignment: Label.AlignVCenter
            horizontalAlignment: Label.AlignRight
            color: "#8c8e90"
            font.pixelSize: 20
        }

        Label {
            id: label3
            x: 140
            y: 33
            width: 46
            height: 36
            text: "(" + gamesList.length + ")"
            verticalAlignment: Label.AlignVCenter
            horizontalAlignment: Label.AlignLeft
            color: "#484b50"
            font.pixelSize: 17
        }

        GridView {
            id: gameListGridView
            x: 30
            y: 75
            width: 800
            height: gameListGridView.contentHeight
            interactive: false
            cellHeight: 220
            cellWidth: 200
            model: gamesList.length
            delegate: GameCardComponents {
                posIndex: index
                z: 2
                images: imagesList[index]
                gameName: gamesList[index]
                totalGamePlay: totalGamePlayList[index]
            }
        }
    }
}
