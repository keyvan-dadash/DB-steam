import QtQuick 2.12
import QtQuick.Controls 2.14
import QtQuick.Window 2.12
import QtGraphicalEffects 1.0

Item {
    visible: true
    width: 1254
    height: 520

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


        Item {
            id: firstPage

            GameCardPage {
                anchors.rightMargin: 38
                anchors.fill: parent
                mainImageSourceProperty: "qrc:/D:/fucking uni/DB/project/ex4.jpg"
                image1Property: "qrc:/D:/fucking uni/DB/project/ex1.jpg"
                image2Property: "qrc:/D:/fucking uni/DB/project/ex2.jpg"
                image3Property: "qrc:/D:/fucking uni/DB/project/ex3.jpg"
                image4Property: "qrc:/D:/fucking uni/DB/project/ex4.jpg"
                gameNameProperty: "A Plague Tale: Innocence"
                priceProperty: "$49.99"
                descriptionProperty: "About 2 sister and brother"
            }
        }
        Item {
            id: secondPage

            GameCardPage {
                anchors.rightMargin: 38
                anchors.fill: parent
                mainImageSourceProperty: "qrc:/D:/fucking uni/DB/project/exx5.jpg"
                image1Property: "qrc:/D:/fucking uni/DB/project/exx1.jpg"
                image2Property: "qrc:/D:/fucking uni/DB/project/exx2.jpg"
                image3Property: "qrc:/D:/fucking uni/DB/project/exx3.jpg"
                image4Property: "qrc:/D:/fucking uni/DB/project/exx4.jpg"
                gameNameProperty: "Bulletstorm: Full Clip Edition"
                priceProperty: "$4.00"
                descriptionProperty: "I Dont know"
            }

        }
        Item {
            id: thirdPage

            GameCardPage {
                anchors.rightMargin: 38
                anchors.fill: parent
                mainImageSourceProperty: "qrc:/D:/fucking uni/DB/project/exxx5.jpg"
                image1Property: "qrc:/D:/fucking uni/DB/project/exxx1.jpg"
                image2Property: "qrc:/D:/fucking uni/DB/project/exxx2.jpg"
                image3Property: "qrc:/D:/fucking uni/DB/project/exxx3.jpg"
                image4Property: "qrc:/D:/fucking uni/DB/project/exxx4.jpg"
                gameNameProperty: "Fallout 76"
                priceProperty: "$59.00"
                descriptionProperty: "Famouse Fallout Series"
            }

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
        onTriggered: gameCards.currentIndex = (gameCards.currentIndex + 1) % 3
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
            gameCards.currentIndex = (gameCards.currentIndex +  2) % 3
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
            gameCards.currentIndex = (gameCards.currentIndex + 1) % 3
        }
    }
}
