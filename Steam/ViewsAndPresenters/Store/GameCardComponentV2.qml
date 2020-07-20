import QtQuick 2.12
import QtQuick.Controls 2.14
import QtQuick.Window 2.12
import QtGraphicalEffects 1.0

Item {
    height: 400
    width: 300

    property var game

    property var loadGamePage

    property var index: 0

    Rectangle {
        id: gamecard
        anchors.fill: parent
        color: "#000"

        Text {
            id: element
            x: 0
            y: 0
            width: 300
            height: 60
            text: game.title
            font.pixelSize: 26
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            wrapMode: Text.Wrap
            color: "#fff"

            MouseArea {
                anchors.fill: parent
                onClicked: {
                    loadGamePage(game.title)
                }
            }
        }

        Image {
            id: gameImages
            x: 0
            y: 60
            width: 300
            height: 253
            source: "file:///" + game.images[0].url
            fillMode: Image.PreserveAspectFit

            MouseArea {
                anchors.fill: parent
                Timer {
                    id: imagesTimer
                    interval: 1000
                    running: false
                    repeat: true
                    onTriggered: function (){
                        index = index + 1
                        gameImages.source = "file:///" + game.images[index % game.images.length].url
                    }
                }
                hoverEnabled: true
                onEntered: {
                    imagesTimer.restart()
                    imagesTimer.running = true
                }
                onExited: {
                    imagesTimer.stop()
                    imagesTimer.running = false
                    gameImages.source = "file:///" + game.images[0].url
                }
            }
        }

        Label {
            id: priceLabel
            x: 10
            y: 319
            width: 40
            height: 23
            text: "Price:"
            color: "#66c0f4"
            font.pixelSize: 15
            verticalAlignment: Label.AlignVCenter
        }

        Label {
            id: amountOfPriceLabel
            x: 50
            y: 319
            width: 99
            height: 23
            text: "$" + game.price
            color: "#acdbf5"
            verticalAlignment: Label.AlignVCenter
        }

        Label {
            id: likesLabel
            x: 155
            y: 319
            width: 40
            height: 23
            text: "Likes:"
            color: "#66c0f4"
            font.pixelSize: 15
            verticalAlignment: Label.AlignVCenter
        }

        Label {
            id: amountOflikesLabel
            x: 195
            y: 319
            width: 95
            height: 23
            text: game.likes
            color: "#7cc5fb"
            verticalAlignment: Label.AlignVCenter
        }

        Label {
            id: publishDateLabel
            x: 10
            y: 349
            width: 55
            height: 23
            text: "Publish:"
            color: "#66c0f4"
            font.pixelSize: 15
            verticalAlignment: Label.AlignVCenter
        }

        Label {
            id: dateLabel
            x: 65
            y: 349
            width: 75
            height: 23
            text: game.date_of_publish
            color: "#8f98a0"
            verticalAlignment: Label.AlignVCenter
        }

        Label {
            id: purchaseLabel
            x: 155
            y: 349
            width: 68
            height: 23
            text: "Purchase:"
            color: "#66c0f4"
            font.pixelSize: 15
            verticalAlignment: Label.AlignVCenter
        }

        Label {
            id: amountOfPurchaseLabel
            x: 223
            y: 349
            width: 75
            height: 23
            text: game.number_of_purchase
            color: "#7cc53f"
            verticalAlignment: Label.AlignVCenter
        }

        Label {
            id: companyLabel
            x: 10
            y: 375
            height: 23
            width: 70
            text: qsTr("Company:")
            color: "#66c0f4"
            font.pixelSize: 15
            verticalAlignment: Label.AlignVCenter
        }

        Label {
            id: companyNameLabel
            x: 80
            y: 375
            height: 23
            width: 220
            text: game.company
            verticalAlignment: Label.AlignVCenter
        }
    }

}
