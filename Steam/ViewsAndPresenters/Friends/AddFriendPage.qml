import QtQuick 2.14
import QtQuick.Window 2.14
import QtQuick.Controls 2.14
import QtQuick.Layouts 1.14


Item {
    signal changeHeightOfParent(int height)
    property var changeHeightFunction
    property var parentHeight

    //invite code
    property var inviteCode
    Rectangle {
        id: headerRectangle
        x: 0
        y: 0
        width: parent.width - 100
        height: 38
        color: "#015e80"
        Text {
            id : headerText
            anchors.fill: parent
            color: "#fff"
            z: 0
            text: qsTr("ADD A FRIEND")
            font.pixelSize: 18
            verticalAlignment: Text.AlignVCenter
            anchors.leftMargin: 20
        }
    }
    Rectangle {
        id: inviteRectangle
        x: 0
        y: headerRectangle.height + headerRectangle.y
        width: headerRectangle.width
        height: 207
        color: Qt.rgba(0, 0, 0, 0.4)

        Text {
            id: inviteHeaderRectangle
            x: 20
            y: 18
            width: parent.width - x
            height: 33
            color: "whitesmoke"
            text: qsTr("Your Friend Code")
            font.pixelSize: 18
            verticalAlignment: Text.AlignVCenter
        }

        Rectangle {
            id: backgroundInviteCodeRectangle
            x: 20
            y: 51
            width: (parent.width * 3) / 4
            height: 64
            color: Qt.rgba(144, 144, 144, 0.1)
            border.width: 1
            border.color: Qt.rgba(144, 144, 144, 0.1)
            radius: 4
            Button {
                id: inviteCodeCopyButton
                x: parent.width - 50 - width
                y: 15
                width: 129
                height: 35
                text: qsTr("COPY")
                contentItem: Text {
                    text: parent.text
                    font.pixelSize: 15
                    color: "whitesmoke"
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                }
                palette {
                    button: Qt.rgba(144, 144, 144, 0.2)
                }
            }

            Text {
                id: inputCodeTextField
                x: 0
                y: 0
                width: parent.width
                height: 64
                color: "whitesmoke"
                text: inviteCode
                font.pixelSize: 30
                verticalAlignment: Text.AlignVCenter
                leftPadding: 10
            }
        }

        Text {
            id: enterFriendCodeHeaderText
            x: 20
            y: backgroundInviteCodeRectangle.height + backgroundInviteCodeRectangle.y + 5
            width: parent.width - 100
            height: 30
            color: "#8F98A0"
            text: qsTr("Enter your friend's Friend Code to invite them to connect.")
            font.pixelSize: 16
            verticalAlignment: Text.AlignVCenter
        }

        Rectangle {
            x: 20
            y: enterFriendCodeHeaderText.y + enterFriendCodeHeaderText.height
            width: parent.width * 3 / 4
            height: 43
            color: Qt.rgba( 0, 0, 0, 0.2 )
            border.width: 1
            radius: 3
            TextField {
                id: inputeFriendCodeTextField
                anchors.fill: parent
                text: ""
                color: "#909090"
                font.pixelSize: 22
                leftPadding: 10
                verticalAlignment: Text.AlignVCenter
                placeholderText: "Enter a Friend Code"
                background: {}
            }
        }
    }
    Rectangle {
        id: searchBackgroundRectangle
        x: 0
        y: inviteRectangle.height + inviteRectangle.y
        width: headerRectangle.width
        height: 107
        color: Qt.rgba(0, 0, 0, 0.2)

        Text {
            id: searchFriendHeaderText
            x: 20
            y: 8
            width: parent.width
            height: 31
            text: qsTr("Or try searching for your friend")
            font.pixelSize: 18
            color: "whitesmoke"
            verticalAlignment: Text.AlignVCenter
        }

        Rectangle {
            id: inputsearchFriendBackground
            x: 20
            y: 39
            width: (parent.width) * 3 / 4
            height: 47
            color: Qt.rgba( 0, 0, 0, 0.2 )
            border.width: 1
            radius: 3
            Button {
                id: searchFriendButton
                x: parent.width - width
                y: 0
                width: 47
                height: 47
                palette {
                    button: "transparent"
                }
                Image {
                    id: buttonImage
                    source: "qrc:/../../../Images/searchbox_workshop_submit.jpg"
                    anchors.centerIn: parent
                }
            }

            TextField {
                id: inputSearchFriendTextField
                x: 0
                y: 0
                width: parent.width - searchFriendButton.width
                height: 47
                text: ""
                font.pixelSize: 20
                background: {}
                placeholderText: "Enter your friend's profile name"
                leftPadding: 10
                color: "#909090"
                font.family: "Arial"
            }
        }
    }
    Component.onCompleted: {
        changeHeightOfParent.connect(changeHeightFunction)
        changeHeightOfParent(headerRectangle.height + inviteRectangle.height + searchBackgroundRectangle.height + parentHeight)
    }
}

/*##^##
Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
##^##*/
