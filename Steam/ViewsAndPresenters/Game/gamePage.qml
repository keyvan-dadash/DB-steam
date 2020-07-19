import QtQuick 2.14
import QtQuick.Window 2.14
import QtQuick.Controls 2.14
import QtQuick.Layouts 1.14
import QtGraphicalEffects 1.14

Item {
    property var mainImageSource: image1.source

    width: 1254
    height: 622

    signal openHubPage(gameName : string)

    property var game

    function imageError(image) {
        if (image.status == Image.Error) {
            return false
        }
        return true
    }

    function setGame(obj) {
        game = obj
    }

    function makeGamePlayable() {
        addToCartButton.text = "Play"
        addToCartButton.x = 6
        addToCartButton.y = 3
        addToCartButton.width += 58
        gamePriceText.width = 0
        gamePriceText.text = ""
        buyGameText.text = "Play " + game.title
    }

    Flickable {
        id: pageFlickable
        anchors.fill: parent
        contentHeight: parent.height + 250

        Rectangle {
            id: backgroundRectangle
            anchors.fill: parent
            color: "#1b2838"
            Image {
                id: backgroundImage
                anchors.fill: parent
                source: "qrc:/D:/fucking uni/DB/project/colored_body_top2.png"
            }
        }

        Text {
            id: gameNameText
            x: 18
            y: 23
            verticalAlignment: Text.AlignVCenter
            width: 986
            height: 43
            text: game.title
            font.family: "Verdana"
            font.pixelSize: 26
            color: "#fff"
        }

        Button {
            id: communityHubButton
            x: 1051
            y: 31
            width: 185
            height: 35
            background: Rectangle {
                color: "#67c1f5"
                opacity: 0.2
                radius: 3
            }
            text: qsTr("Community Hub")
            contentItem: Text {
                text: parent.text
                color: "#67c1f5"
                font.pixelSize: 18
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
            }
            onClicked: {
                openHubPage(game.title)
            }
        }

        Image {
            id: gameHeaderImage
            x: 856
            y: 85
            width: 380
            height: 180
            fillMode: Image.PreserveAspectFit
            source: "file:///" + game.images[0].url
        }

        TextArea {
            id: gameDescriptionTextArea
            x: 856
            y: 280
            width: 380
            height: 175
            color: "#c6d4df"
            font.family: "Verdana"
            font.pixelSize: 14
            text: game.description
            wrapMode: TextArea.Wrap
            readOnly: true
        }

        Label {
            id: releaseDateTextLabel
            x: 856
            y: 477
            width: 99
            height: 16
            color: "#556772"
            text: qsTr("RELEASE DATE:")
        }

        Label {
            id: developerTextLabel
            x: 856
            y: 514
            width: 99
            height: 16
            color: "#556772"
            text: qsTr("DEVELOPER:")
        }

        Label {
            id: publisherTextLabel
            x: 856
            y: 546
            width: 99
            height: 16
            color: "#556772"
            text: qsTr("PUBLISHER:")
        }

        Label {
            id: releaseDateLabel
            x: 1039
            y: 477
            width: 197
            height: 16
            color: "#8f98a0"
            text: game.date_of_publish
        }

        Label {
            id: developerLabel
            x: 1039
            y: 514
            width: 197
            height: 16
            color: "#66C0F4"
            text: game.company
            MouseArea {
                anchors.fill: parent
                hoverEnabled: true
                onEntered: {
                    parent.color = "#fff"
                }
                onExited: {
                    parent.color = "#66C0F4"
                }
            }
        }

        Label {
            id: publisherLabel
            x: 1039
            y: 546
            width: 197
            height: 16
            color: "#66C0F4"
            text: game.company
            MouseArea {
                anchors.fill: parent
                hoverEnabled: true
                onEntered: {
                    parent.color = "#fff"
                }
                onExited: {
                    parent.color = "#66C0F4"
                }
            }
        }

        Label {
            id: likesLabel
            x: 856
            y: 579
            width: 99
            height: 16
            text: qsTr("Likes")
            color: "#556772"
        }

        Label {
            id: numberOfLikesLabel
            x: 1039
            y: 579
            width: 197
            height: 16
            text: game.likes
            color: "#66C0F4"
            MouseArea {
                anchors.fill: parent
                hoverEnabled: true
                onEntered: {
                    parent.color = "#fff"
                }
                onExited: {
                    parent.color = "#66C0F4"
                }
            }
        }

        Label {
            id: dislikesLabel
            x: 856
            y: 614
            width: 99
            height: 16
            color: "#556772"
            text: qsTr("Dislikes")
        }

        Label {
            id: numberOfDislikesLabel
            x: 1039
            y: 614
            width: 197
            height: 16
            text: game.dislikes
            color: "#66C0F4"
            MouseArea {
                anchors.fill: parent
                hoverEnabled: true
                onEntered: {
                    parent.color = "#fff"
                }
                onExited: {
                    parent.color = "#66C0F4"
                }
            }
        }

        Label {
            id: purchaseLabel
            x: 856
            y: 649
            width: 99
            height: 16
            color: "#556772"
            text: qsTr("Purchase")
        }

        Label {
            id: numberOfPurchaseLabel
            x: 1039
            y: 649
            width: 197
            height: 16
            text: game.number_of_purchase
            color: "#7cc53f"
        }

        Image {
            id: mainImage
            x: 18
            y: 85
            width: 819
            height: 429
            fillMode: Image.PreserveAspectFit
            source: mainImageSource
        }

        Image {
            id: image1
            x: 18
            y: 522
            width: 105
            height: 100
            fillMode: Image.PreserveAspectFit
            source: "file:///" + game.images[1].url
            MouseArea {
                anchors.fill: parent
                onClicked: {
                    mainImageSource = parent.source
                }
            }

            Component.onCompleted: {
                this.visible = imageError(this)
            }
        }

        Image {
            id: image2
            x: 135
            y: 522
            width: 105
            height: 100
            source: "file:///" + game.images[2].url
            fillMode: Image.PreserveAspectFit
            MouseArea {
                anchors.fill: parent
                onClicked: {
                    mainImageSource = parent.source
                }
            }

            Component.onCompleted: {
                this.visible = imageError(this)
            }
        }

        Image {
            id: image3
            x: 252
            y: 522
            width: 105
            height: 100
            source: "file:///" + game.images[3].url
            fillMode: Image.PreserveAspectFit
            MouseArea {
                anchors.fill: parent
                onClicked: {
                    mainImageSource = parent.source
                }
            }

            Component.onCompleted: {
                this.visible = imageError(this)
            }
        }

        Image {
            id: image4
            x: 369
            y: 522
            width: 105
            height: 100
            fillMode: Image.PreserveAspectFit
            source: "file:///" + game.images[4].url
            MouseArea {
                anchors.fill: parent
                onClicked: {
                    mainImageSource = parent.source
                }
            }

            Component.onCompleted: {
                this.visible = imageError(this)
            }
        }

        Image {
            id: image5
            x: 486
            y: 522
            width: 105
            height: 100
            source: "file:///" + game.images[5].url
            fillMode: Image.PreserveAspectFit
            MouseArea {
                anchors.fill: parent
                onClicked: {
                    mainImageSource = parent.source
                }
            }

            Component.onCompleted: {
                this.visible = imageError(this)
            }
        }

        Image {
            id: image6
            x: 603
            y: 522
            width: 105
            height: 100
            fillMode: Image.PreserveAspectFit
            source: "file:///" + game.images[6].url
            MouseArea {
                anchors.fill: parent
                onClicked: {
                    mainImageSource = parent.source
                }
            }

            Component.onCompleted: {
                this.visible = imageError(this)
            }
        }

        Image {
            id: image7
            x: 720
            y: 522
            width: 105
            height: 100
            source: "file:///" + game.images[7].url
            fillMode: Image.PreserveAspectFit
            MouseArea {
                anchors.fill: parent
                onClicked: {
                    mainImageSource = parent.source
                }
            }

            Component.onCompleted: {
                this.visible = imageError(this)
            }
        }

        Rectangle {
            id: buyGameRectangle
            x: 18
            y: 669
            width: 690
            height: 109
            color: "#1b2838"
            LinearGradient {
                anchors.fill: parent
                start: Qt.point(0, 0)
                end: Qt.point(690, 134)
                gradient: Gradient {
                    GradientStop { position: 0.0; color: Qt.hsla(195, 2, 39, 0.2) }
                    GradientStop { position: 1.0; color: Qt.hsla(203, 100, 94, 0.7) }
                }

                Text {
                    id: buyGameText
                    x: 8
                    y: 10
                    width: 668
                    height: 66
                    text: "Buy " + game.title
                    font.pixelSize: 25
                    verticalAlignment: Text.AlignVCenter
                    color: "#c6d4df"
                }
            }
        }

        Rectangle {
            id: addToCartRectangle
            x: 524
            y: 752
            width: 170
            height: 42
            color: "#000"
            Button {
                z: 1
                id: addToCartButton
                x: 67
                y: 2
                width: 100
                height: 38
                text: qsTr("Purchase")
                background: Rectangle {
                    anchors.fill: parent
                    color: "#a4d007"
                    LinearGradient {
                        anchors.fill: parent
                        start: Qt.point(0, 0)
                        end: Qt.point(0, parent.height)
                        gradient: Gradient {
                            GradientStop {id:startGarient; position: 0.0; color: "#799905" }
                            GradientStop {id:endGarient; position: 1.0; color: "#536904" }
                        }
                    }
                }
                contentItem: Text {
                    text: parent.text
                    color: "#D2E885"
                    font.pixelSize: 14
                    verticalAlignment: Text.AlignVCenter
                    horizontalAlignment: Text.AlignHCenter
                }
                MouseArea {
                    anchors.fill: parent
                    hoverEnabled: true
                    onEntered: {
                        startGarient.color = "#a4d007"
                        endGarient.color = "#6b8705"
                    }
                    onExited: {
                        startGarient.color = "#799905"
                        endGarient.color = "#536904"
                    }
                }
            }

            Text {
                id: gamePriceText
                x: 4
                y: 3
                width: 58
                height: 36
                text: game.price
                color: "#acdbf5"
                font.pixelSize: 15
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
            }
        }

    }


}
