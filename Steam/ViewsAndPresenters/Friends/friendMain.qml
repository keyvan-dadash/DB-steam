import QtQuick 2.14
import QtQuick.Window 2.14
import QtQuick.Controls 2.14
import QtQuick.Layouts 1.14

Item {
    visible: true
    width: 1254
    height: 622
    property var originalHeight: height
    property Button currentButton

    //friend signal
    signal getFriends()
    property var friendArray : []

    //blocked signal
    signal getBlocked()
    property var blockedArray : []

    //pending signal
    signal getPending()
    property var pendingArray : []

    //recive signal
    signal getReceive()
    property var receiveArray : []

    //invite code
    property var inviteCode
    property var imageUrl
    property var name

    property var objects : []
    property var lengthOfModels: 0

    function fillArrayWithArray(sourceArray, destinationArray) {
        for (var i=0; i < sourceArray.length; i++) {
            destinationArray.push(sourceArray[i])
        }
        lengthOfModels = objects.length
    }

    function setObjectsArray(type, objArray) {
        if (type == 1) {
            fillArrayWithArray(objArray, friendArray)
            button.loadView()
        } else if (type == 2) {
            fillArrayWithArray(objArray, blockedArray)
            button3.loadView()
        } else if (type == 3) {
            fillArrayWithArray(objArray, pendingArray)
            preaperPendingPage(3)
        } else if (type == 4) {
            fillArrayWithArray(objArray, receiveArray)
            preaperPendingPage(4)
        }
    }

    property var pending : false
    property var receive : false

    function preaperPendingPage(type) {
        console.log(pending)
        console.log(receive)
        if (type == 3) {
            pending = true
        } else if (type == 4) {
            receive = true
        }
        if (pending && receive) {
            button2.loadView()
            pending = false
            receive = false
        }
    }

    Component.onCompleted: {
        originalHeight = originalHeight
    }
    Flickable {
        id: pageFlickable
        anchors.fill: parent
        contentHeight: parent.height

        function changeHeight(height) {
            if (height > originalHeight) {
                pageFlickable.contentHeight = height
            }
            else {
                pageFlickable.contentHeight = originalHeight
            }
        }

        Rectangle {
            id: backgroundRectangle
            anchors.fill: parent
            color: "#1b2838"
            Image {
                id: backgroundImage
                anchors.fill: parent
                source: "qrc:/../../../Images/colored_body_top2.png"
            }
        }

        Image {
            id: image
            x: 39
            y: 30
            width: 80
            height: 80
            fillMode: Image.Stretch
            source: "file:///" + imageUrl
        }

        Text {
            id: element
            x: 138
            y: 60
            width: 181
            height: 34
            color: "#ffffff"
            text: name
            font.family: "Motiva Sans"
            font.pixelSize: 24
        }

        Text {
            id: element1
            x: 39
            y: 159
            width: 66
            height: 22
            color: "#7092a5"
            text: qsTr("Friends")
            font.pixelSize: 18
        }

        Button {
            id: button
            x: 39
            y: 198
            width: 280
            height: 45
            text: qsTr("Your Friends")
            font.pointSize: 10
            leftPadding: 15
            contentItem: Text {
                text: button.text
                font: button.font
                color: "#fff"
                horizontalAlignment: Text.AlignLeft
                verticalAlignment: Text.AlignVCenter
                elide: Text.ElideRight
            }
            palette {
                button: currentButton == this ?  Qt.rgba(255, 255, 255, 0.1) : (this.hovered ? Qt.rgba(255, 255, 255, 0.2) : "transparent")
            }
            Component.onCompleted: currentButton = this
            onClicked: {
                getFriends()
            }
            function loadView() {
                viewLoader.setSource("YourFriendPage.qml",
                                     {
                                         "changeHeightFunction": pageFlickable.changeHeight,
                                         "parentHeight": y,
                                         "objArray": friendArray
                                     })
                currentButton = this
            }
        }

        Button {
            id: button1
            x: 39
            y: 243
            width: 280
            height: 45
            text: qsTr("Add a Friend")
            contentItem: Text {
                color: "#ffffff"
                text: button1.text
                horizontalAlignment: Text.AlignLeft
                verticalAlignment: Text.AlignVCenter
                font: button1.font
                elide: Text.ElideRight
            }
            leftPadding: 15
            font.pointSize: 10
            palette {
                button: currentButton == this ?  Qt.rgba(255, 255, 255, 0.1) : (this.hovered ? Qt.rgba(255, 255, 255, 0.2) : "transparent")
            }
            onClicked: {
                viewLoader.setSource("AddFriendPage.qml",
                                     {
                                         "changeHeightFunction": pageFlickable.changeHeight,
                                         "parentHeight": y,
                                         "inviteCode": inviteCode
                                     })
                currentButton = this 
            }
        }

        Button {
            id: button2
            x: 39
            y: 288
            width: 280
            height: 45
            text: qsTr("Pending Invites")
            contentItem: Text {
                color: "#ffffff"
                text: button2.text
                horizontalAlignment: Text.AlignLeft
                verticalAlignment: Text.AlignVCenter
                font: button2.font
                elide: Text.ElideRight
            }
            leftPadding: 15
            font.pointSize: 10
            palette {
                button: currentButton == this ?  Qt.rgba(255, 255, 255, 0.1) : (this.hovered ? Qt.rgba(255, 255, 255, 0.2) : "transparent")
            }
            onClicked: {
                getReceive()
                getPending()
            }

            function loadView() {
                viewLoader.setSource("PendingInvitePage.qml",
                                     {
                                         "changeHeightFunction": pageFlickable.changeHeight,
                                         "parentHeight": y,
                                         "receiveObjArray": receiveArray,
                                         "pendingObjArray": pendingArray
                                     })
                currentButton = this
            }
        }

        Button {
            id: button3
            x: 39
            y: 333
            width: 280
            height: 45
            text: qsTr("Blocked")
            contentItem: Text {
                color: "#ffffff"
                text: button3.text
                horizontalAlignment: Text.AlignLeft
                verticalAlignment: Text.AlignVCenter
                font: button3.font
                elide: Text.ElideRight
            }
            leftPadding: 15
            font.pointSize: 10
            palette {
                button: currentButton == this ?  Qt.rgba(255, 255, 255, 0.1) : (this.hovered ? Qt.rgba(255, 255, 255, 0.2) : "transparent")
            }
            onClicked: {
                getBlocked()
            }

            function loadView() {
                viewLoader.setSource("BlockedProfilesPage.qml",
                                     {
                                         "changeHeightFunction": pageFlickable.changeHeight,
                                         "parentHeight": y,
                                         "objArray": blockedArray
                                     })
                currentButton = this
            }
        }

        Loader {
            id: viewLoader
            x: 338
            y: 178
            width: 889
            height: 373
            Component.onCompleted: {
                viewLoader.setSource("YourFriendPage.qml",
                                     {
                                         "changeHeightFunction": pageFlickable.changeHeight,
                                         "parentHeight": y,
                                         "objArray": friendArray
                                     })
            }
        }
    }
}
