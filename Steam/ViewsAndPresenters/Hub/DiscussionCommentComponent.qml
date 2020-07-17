import QtQuick 2.14
import QtQuick.Window 2.14
import QtQuick.Controls 2.14
import QtQuick.Layouts 1.14
import QtGraphicalEffects 1.14

Item {
    width: 860
    height: 200

    property var comment

    Rectangle {
        anchors.fill: parent
        color: "#202f43"
        opacity: 0.8
    }

    Image {
        id: image
        x: 8
        y: 8
        width: 50
        height: 51
        source: "qrc:/qtquickplugin/images/template_image.png"
        fillMode: Image.PreserveAspectFit
    }

    Label {
        id: label
        x: 76
        y: 26
        width: 582
        height: 21
        text: comment.user_comment.nickname
        color: "#ebebeb"
        font.pixelSize: 16
    }

    Label {
        id: label1
        x: 684
        y: 26
        width: 159
        height: 21
        color: "#999999"
        text: comment.sent_date
    }

    TextArea {
        id: textArea
        x: 8
        y: 91
        width: 844
        height: parent.height - this.y - 8
        color: "#acb2b8"
        font.pixelSize: 14
        wrapMode: Text.Wrap
        text: comment.body
    }
}
