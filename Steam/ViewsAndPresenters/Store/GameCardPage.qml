import QtQuick 2.12
import QtQuick.Controls 2.14
import QtQuick.Window 2.12
import QtGraphicalEffects 1.0

Item {
    property string mainImageSourceProperty
    property string image1Property
    property string image2Property
    property string image3Property
    property string image4Property
    property string gameNameProperty
    property string priceProperty
    property string descriptionProperty


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
        text: qsTr(gameNameProperty)
        font.pixelSize: 24
        font.family: "Sans-serif"
        color: "#FFF"
    }

    Image {
        id: image1
        x: 825
        y: 138
        width: 173
        height: 100
        fillMode: Image.PreserveAspectFit
        source: image1Property
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
        source: image2Property
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
        source: image3Property
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
        source: image4Property
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
        text: qsTr(priceProperty)
        font.pixelSize: 11
        color: "#acdbf5"
    }
    Text {
        id: description
        x: 825
        y: 389
        width: 342
        height: 86
        text: qsTr(descriptionProperty)
        font.pixelSize: 17
        font.family: "Sans-serif"
        wrapMode: Text.Wrap
        color: "#FFF"
    }


}
