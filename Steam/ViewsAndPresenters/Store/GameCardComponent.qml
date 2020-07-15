import QtQuick 2.0
import QtGraphicalEffects 1.0

Item {
    width: 200
    height: 237

    property var obj

    Rectangle {
        id: rectangleImage1
        anchors.fill: parent

        LinearGradient {
            anchors.fill: parent
            source: parent
            start: Qt.point(0, 0)
            end: Qt.point(200, 237)
            gradient: Gradient {
                GradientStop { position: 1.0; color: "#407999" }
                GradientStop { position: 0.0; color: "#2a3e59" }
            }
        }

        Text {
            id: name1
            x: 0
            y: 0
            width: 200
            height: 51
            text: obj.title
            font.pixelSize: 20
            color: "#fff"
            font.family: "Sans-serif"
            horizontalAlignment: Text.Center
            wrapMode: Text.WordWrap
        }

        Image {
            id: image1
            x: 0
            y: 51
            width: 200
            height: 150
            source: "file:///" + obj.images[0].url
            fillMode: Image.Stretch
        }

        Text {
            id: price1
            x: 0
            y: 201
            width: 200
            height: 36
            text: obj.price
            font.pixelSize: 12
            color: "#66c0f4"
            horizontalAlignment: Text.Center
        }

    }
}
