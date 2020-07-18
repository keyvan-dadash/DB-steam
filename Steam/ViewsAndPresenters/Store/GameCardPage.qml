import QtQuick 2.12
import QtQuick.Controls 2.14
import QtQuick.Window 2.12
import QtGraphicalEffects 1.0

Item {
    property string mainImageSourceProperty : "file:///" + images[0].url
    property var index : 0

    property var images
    property var _gameName
    property var _price
    property var gameDescription
    property var loadGamePage

    function getImageSource() {
        var imgSource = "file:///" + images[index % images.length].url
        index = index + 1
        return imgSource
    }


    Image {
        id: mainImage
        x: 38
        y: 0
        width: 770
        height: 520
        fillMode: Image.PreserveAspectFit
        source: mainImageSourceProperty
        Component.onCompleted: {
            mainImageSourceProperty = mainImageSourceProperty
        }
    }
    Rectangle {
        id: gameInfoRectangle
        x: 808
        y: 0
        width: 412
        height: 520
        color: "#000"
    }
    Text {
        id: gameName
        x: 825
        y: 37
        width: 342
        height: 43
        text: _gameName
        font.pixelSize: 24
        font.family: "Sans-serif"
        color: "#FFF"

        MouseArea {
            anchors.fill: parent

            onClicked: {
                loadGamePage(_gameName)
            }
        }
    }

    Image {
        id: image1
        x: 825
        y: 138
        width: 173
        height: 100
        fillMode: Image.PreserveAspectFit
        source: "ff"
        Component.onCompleted: {
            source = getImageSource()
        }

        MouseArea {
            hoverEnabled: true
            anchors.fill: parent
            onEntered: {
                mainImage.source = parent.source
            }
            onExited: {
                mainImage.source = mainImageSourceProperty
            }
        }
    }

    Image {
        id: image2
        x: 1006
        y: 138
        width: 203
        height: 100
        fillMode: Image.PreserveAspectFit
        source: "ff"
        Component.onCompleted: {
            source = getImageSource()
        }
        MouseArea {
            hoverEnabled: true
            anchors.fill: parent
            onEntered: {
                mainImage.source = parent.source
            }
            onExited: {
                mainImage.source = mainImageSourceProperty
            }
        }
    }

    Image {
        id: image3
        x: 825
        y: 244
        width: 173
        height: 100
        fillMode: Image.PreserveAspectFit
        source: "ff"
        Component.onCompleted: {
            source = getImageSource()
        }
        MouseArea {
            hoverEnabled: true
            anchors.fill: parent
            onEntered: {
                mainImage.source = parent.source
            }
            onExited: {
                mainImage.source = mainImageSourceProperty
            }
        }
    }

    Image {
        id: image4
        x: 1006
        y: 244
        width: 203
        height: 100
        fillMode: Image.PreserveAspectFit
        source: "ff"
        Component.onCompleted: {
            source = getImageSource()
        }
        MouseArea {
            hoverEnabled: true
            anchors.fill: parent
            onEntered: {
                mainImage.source = parent.source
            }
            onExited: {
                mainImage.source = mainImageSourceProperty
            }
        }
    }

    Text {
        id: price
        x: 825
        y: 489
        width: 52
        height: 20
        text: _price
        font.pixelSize: 11
        color: "#acdbf5"
    }
    Text {
        id: description
        x: 825
        y: 389
        width: 342
        height: 86
        text: gameDescription
        font.pixelSize: 17
        font.family: "Sans-serif"
        wrapMode: Text.Wrap
        color: "#FFF"
    }


}
