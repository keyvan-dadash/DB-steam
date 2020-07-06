import QtQuick 2.14
import QtQuick.Window 2.14
import QtQuick.Controls 2.14
import QtQuick.Layouts 1.14
import QtGraphicalEffects 1.14

Item {
    property var flickableHeight: mainView.height
    property var loaderHeight
    property var currentBackgroundRectangle

    id: mainView
    visible: true
    width: 1254
    height: 621

    function setFlickableHeight(height) {
        if (height < mainView.height) {
            flickableHeight = mainView.height
        }
        else {
            flickableHeight = height
        }
    }

    function setLoaderHeight(height) {
        loaderHeight = height
    }

    function changePageHeight(height){
        console.log(height)
        setFlickableHeight(height + viewLoader.y)
        setLoaderHeight(height)
    }

    Flickable {
        id: pageFlickable
        anchors.fill: parent
        contentHeight: flickableHeight

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

        Button {
            id: button
            x: 1060
            y: 35
            width: 157
            height: 40
            background: Rectangle {
                color: "#67c1f5"
                opacity: 0.2
                radius: 3
            }
            text: qsTr("Store Page")
            contentItem: Text {
                text: parent.text
                color: "#67c1f5"
                font.pixelSize: 18
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
            }
        }

        Text {
            id: element
            x: 27
            y: 23
            width: 978
            height: 59
            text: qsTr("Assassin's Creed Origins")
            font.family: "Verdana"
            font.pixelSize: 30
            color: "#fff"
            verticalAlignment: Text.AlignVCenter
        }

        Button {
            id: introButton
            x: 39
            y: 110
            width: 82
            height: 40
            text: qsTr("Intro")
            background: Rectangle {
                id: introButtonBackgroundRectangle
                visible: true
                anchors.fill: parent
                color: "#0d121a"
                radius: 2
                border.width: 1
                border.color: "#67c1f5"
                anchors.bottomMargin: -border.width
            }
            contentItem: Text {
                text: parent.text
                color: "#dadada"
                font.pixelSize: 15
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
            }
            onClicked: {
                viewLoader.setSource("IntroPage.qml", {"changeParentHeight": changePageHeight})
                currentBackgroundRectangle.visible = false
                introButtonBackgroundRectangle.visible = true
                currentBackgroundRectangle = introButtonBackgroundRectangle
            }
        }

        Button {
            id: discussionsButton
            x: 131
            y: 110
            width: 82
            height: 40
            text: qsTr("Discussions")
            background: Rectangle {
                id: discussionsButtonBackgroundRectangle
                visible: false
                anchors.fill: parent
                color: "#0d121a"
                radius: 2
                border.width: 1
                border.color: "#67c1f5"
                anchors.bottomMargin: -border.width
            }
            contentItem: Text {
                text: parent.text
                color: "#dadada"
                font.pixelSize: 15
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
            }
            onClicked: {
                viewLoader.setSource("DiscussionPage.qml", {"changeParentHeight": changePageHeight})
                currentBackgroundRectangle.visible = false
                discussionsButtonBackgroundRectangle.visible = true
                currentBackgroundRectangle = discussionsButtonBackgroundRectangle
            }
        }

        Button {
            id: newsButton
            x: 223
            y: 110
            width: 82
            height: 40
            text: qsTr("News")
            background: Rectangle {
                id: newsButtonBackgroundRectangle
                visible: false
                anchors.fill: parent
                color: "#0d121a"
                radius: 2
                border.width: 1
                border.color: "#67c1f5"
                anchors.bottomMargin: -border.width
            }
            contentItem: Text {
                text: parent.text
                color: "#dadada"
                font.pixelSize: 15
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
            }
            onClicked: {
                viewLoader.setSource("NewsPage.qml", {"changeParentHeight": changePageHeight})
                currentBackgroundRectangle.visible = false
                newsButtonBackgroundRectangle.visible = true
                currentBackgroundRectangle = newsButtonBackgroundRectangle
            }
        }

        Button {
            id: videosButton
            x: 315
            y: 110
            width: 82
            height: 40
            text: qsTr("Videos")
            background: Rectangle {
                id: videosButtonBackgroundRectangle
                visible: false
                anchors.fill: parent
                color: "#0d121a"
                radius: 2
                border.width: 1
                border.color: "#67c1f5"
                anchors.bottomMargin: -border.width
            }
            contentItem: Text {
                text: parent.text
                color: "#dadada"
                font.pixelSize: 15
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
            }

            onClicked: {
                viewLoader.setSource("VideosPage.qml", {"changeParentHeight": changePageHeight})
                currentBackgroundRectangle.visible = false
                videosButtonBackgroundRectangle.visible = true
                currentBackgroundRectangle = videosButtonBackgroundRectangle
            }
        }

        Button {
            id: reviewsButton
            x: 407
            y: 110
            width: 82
            height: 40
            text: qsTr("Reviews")
            background: undefined
            contentItem: Text {
                text: parent.text
                color: "#dadada"
                font.pixelSize: 15
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
            }
        }

        Rectangle {
            id: rectangle
            x: 27
            y: 150
            width: 1200
            height: 8
            color: Qt.rgba( 0, 0, 0, 0.8 )
        }

        Loader {
            id: viewLoader
            x: 27
            y: 158
            width: 1200
            height: loaderHeight
            asynchronous: true
            visible: status == Loader.Ready
            Component.onCompleted: {
                viewLoader.setSource("IntroPage.qml", {"changeParentHeight": changePageHeight})
                currentBackgroundRectangle = introButtonBackgroundRectangle
            }
        }
    }
}
