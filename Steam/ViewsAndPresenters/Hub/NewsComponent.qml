import QtQuick 2.14
import QtQuick.Window 2.14
import QtQuick.Controls 2.14
import QtQuick.Layouts 1.14
import QtGraphicalEffects 1.14

Item {
    width: 1200
    height: 480

    property var newsObj


    Rectangle {
        anchors.fill: parent
        color: '#0d131b'
    }

    Text {
        id: titleText
        x: 8
        y: 8
        width: 1184
        height: 71
        text: newsObj.title
        wrapMode: Text.Wrap
        font.pixelSize: 20
        color: '#fff'
        verticalAlignment: Text.AlignVCenter
    }

    Text {
        id: dateText
        x: 8
        y: 85
        width: 133
        height: 19
        text: newsObj.publish_date
        font.pixelSize: 12
        color: '#737271'
        verticalAlignment: Text.AlignVCenter
    }

    TextArea {
        id: contentTextArea
        x: 8
        y: 114
        width: 1184
        height: 364
        readOnly: true
        wrapMode: TextArea.Wrap
        font.pixelSize: 15
        color: "#8c8b8a"
        text: newsObj.body
    }
}
