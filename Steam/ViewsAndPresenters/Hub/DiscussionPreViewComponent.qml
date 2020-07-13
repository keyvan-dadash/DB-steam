import QtQuick 2.14
import QtQuick.Window 2.14
import QtQuick.Controls 2.14
import QtQuick.Layouts 1.14
import QtGraphicalEffects 1.14

Item {
    width: 300
    height: 200

    property var discussionObj

    Rectangle {
        id: backgroundRectangle
        anchors.fill: parent
        color: "#417A9B"
    }

    TextArea {
        id: preViewTextArea
        width: 300
        height: 146
        color: "#dcdcdc"
        text: discussionObj.body
        wrapMode: TextArea.Wrap
        font.pixelSize: 18
    }

    Text {
        id: postedByText
        x: 7
        y: 152
        width: 53
        height: 15
        color: "#8F98A0"
        text: qsTr("Posted by:")
        font.pixelSize: 13
    }

    Text {
        id: firstUsernameText
        x: 67
        y: 152
        width: 83
        height: 15
        color: "#dcdcdc"
        text: discussionObj.author.nickname
        font.pixelSize: 14
        leftPadding: 3
        verticalAlignment: Text.AlignVCenter
    }

    Text {
        id: firstDateText
        x: 152
        y: 152
        width: 142
        height: 15
        color: "#8F98A0"
        text: discussionObj.discussion_start_date
        font.pixelSize: 13
    }

    Text {
        id: lastPostByText
        x: 8
        y: 177
        width: 53
        height: 15
        color: "#8F98A0"
        text: qsTr("Last post:")
        font.pixelSize: 13
    }

    Text {
        id: lastUsernameText
        x: 67
        y: 177
        width: 83
        height: 15
        color: "#dcdcdc"
        text: discussionObj.last_comment_username
        font.pixelSize: 14
        leftPadding: 3
        verticalAlignment: Text.AlignVCenter
    }

    Text {
        id: lastPostDateText
        x: 150
        y: 177
        width: 142
        height: 15
        color: "#8F98A0"
        text: discussionObj.last_comment_date
        font.pixelSize: 13
    }
}
