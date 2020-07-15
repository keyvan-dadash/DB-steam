import QtQuick 2.12
import QtQuick.Controls 2.14
import QtQuick.Window 2.12
import QtGraphicalEffects 1.0

Item {
    visible: true
    width: 1254
    height: 520

    property int numberOfPage: 0


    property var objects : []
    function setObjectsArray(objArray) {
        for (var i=0; i < objArray.length; i++) {
            objects.push(objArray[i])
        }
    }

    function createFeatureGamesView() {
        gameCards.addFetureGamesPage(objects)
    }

    function createTop100GamesView() {
        gameCards.addTop100GamesPage(objects)
    }

    function createNewGamesView() {

    }

    Rectangle {
        id: backgroundRectangle
        x: 0
        y: 0
        anchors.fill: parent
        Image {
            id: background
            anchors.fill: parent
            source: "qrc:/D:/fucking uni/DB/project/colored_body_top2.png"
        }
    }
    SwipeView {
        id: gameCards
        anchors.rightMargin: 0
        anchors.leftMargin: 0

        currentIndex: 0
        anchors.fill: parent

        function addPage(page) {
            addItem(page)
            page.visible = true
        }

        //feature games functions
        function createFeatureGamesPage(obj) {
            var component = Qt.createComponent("GameCardPage.qml");
            var page = component.createObject(gameCards,
                                              {
                                                  "images": obj.images,
                                                  "_gameName": obj.title,
                                                  "_price": obj.price,
                                                  "gameDescription": obj.description,
                                                  "anchors.rightMargin": 38
                                              });
            return page
        }

        function addFetureGamesPage(objects) {
            for (var i=0; i < objects.length; i++) {
                addPage(createFeatureGamesPage(objects[i]))
            }
            numberOfPage = objects.length
        }

        //Top 100 Games functions
        function createTop100GamesPage(objArray) {
            var component = Qt.createComponent("Page.qml");
            var page = component.createObject(gameCards,
                                              {
                                                  "objects" : objArray
                                              });
            return page
        }

        function addTop100GamesPage(objects) {
            for (var i=0; i < objects.length; i = i + 10) {
                addPage(createTop100GamesPage(objects.slice(i, i + 10)))
            }
            numberOfPage = Math.ceil(objects.length / 10)
        }
    }

    PageIndicator {
        id: indicator
        wheelEnabled: false

        count: gameCards.count
        currentIndex: gameCards.currentIndex

        anchors.bottom: gameCards.bottom
        anchors.horizontalCenter: parent.horizontalCenter

        delegate: Rectangle {
            implicitHeight: 10
            implicitWidth: 10

            radius: width
            color: index === gameCards.currentIndex ? Qt.hsla(202, 60,  100, 0.4) : Qt.hsla(202, 60,  100, 0.2)


        }
    }
    Timer {
        id: timer
        interval: 5000
        running: true
        repeat: true
        onTriggered: gameCards.currentIndex = (gameCards.currentIndex + 1) % numberOfPage
    }
    Button {
        id: leftButton
        x: 0
        y: 194
        width: 37
        height: 132
        background: Rectangle {
            id: leftRectangle
            anchors.fill: parent
            color: Qt.rgba(0, 0, 0, 0.2)
            Image {
                id: leftButtonArrow
                source: "qrc:/D:/fucking uni/DB/project/arrowsLeft.png"
                width: 23;
                height: 36;
                anchors.centerIn: parent
            }
        }
        onClicked: {
            gameCards.currentIndex = (gameCards.currentIndex +  (numberOfPage - 1)) % numberOfPage
        }
    }
    Button {
        id: rightButton
        x: 1217
        y: 194
        width: 37
        height: 132
        background: Rectangle {
            id: rightRectangle
            anchors.fill: parent
            color: Qt.rgba(0, 0, 0, 0.3)
            clip: true
            Image {
                id: rightButtonArrow
                source: "qrc:/D:/fucking uni/DB/project/arrowsRight.png"
                width: 23;
                height: 36;
                anchors.centerIn: parent
            }
        }

        onClicked: {
            gameCards.currentIndex = (gameCards.currentIndex + 1) % numberOfPage
        }
    }
}
