import QtQuick 2.14
import QtQuick.Window 2.14
import QtQuick.Controls 2.14
import QtQuick.Layouts 1.14
import QtQuick.Controls.Styles 1.4

Item {

    property var images
    property var gameName
    property var totalGamePlay

    property var xPos
    property var yPos
    property var imageIndex: 0
    width: 260
    height: 320

    function nextImage() {
        gameImages.source = images[imageIndex % images.length]
        imageIndex = imageIndex + 1
    }

    x: xPos
    y: yPos

    Rectangle {
        id: backgroundRectangle
        anchors.fill: parent
        color: "#444a4f"
    }

    Text {
        id: element
        x: 8
        y: 8
        width: 244
        height: 52
        text: gameName
        color: "#fff"
        font.pixelSize: 20
        wrapMode: Text.Wrap
    }

    Image {
        id: gameImages
        x: 0
        y: 66
        width: 260
        height: 126
        fillMode: Image.PreserveAspectFit
        source: images[0]
    }

    Label {
        id: label
        x: 8
        y: 224
        width: 244
        height: 27
        color: "#5e6266"
        text: qsTr("TIME PLAYED")
        font.pixelSize: 15
        verticalAlignment: Label.AlignVCenter
    }

    Label {
        id: label1
        x: 8
        y: 257
        width: 105
        height: 26
        color: "#5e6266"
        text: qsTr("Last two weeks:")
        font.pixelSize: 14
        verticalAlignment: Label.AlignVCenter
    }

    Label {
        id: label2
        x: 8
        y: 289
        width: 40
        height: 23
        color: "#5e6266"
        text: qsTr("Total:")
        font.pixelSize: 14
        verticalAlignment: Label.AlignVCenter
    }

    Label {
        id: label3
        x: 119
        y: 257
        width: 129
        height: 26
        color: "#5e6266"
        text: qsTr("20 min")
        font.pixelSize: 14
        verticalAlignment: Label.AlignVCenter
    }

    Label {
        id: label4
        x: 49
        y: 289
        width: 203
        height: 24
        color: "#5e6266"
        text: totalGamePlay + "h"
        font.pixelSize: 14
        verticalAlignment: Label.AlignVCenter
    }
}
