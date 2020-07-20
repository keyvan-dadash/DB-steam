import QtQuick 2.0
import QtGraphicalEffects 1.0


Item {
    id: gameCard
    width: 1220
    height: 551

    property var objects : []

    property var index: 0

    property var firstRowY : 65

    property var xPositions: [90, 470, 860]

    function createGameCard(x, y, obj) {
        var component = Qt.createComponent("GameCardComponentV2.qml")
        var instance = component.createObject(gameCard, {
                                                  "x" : x,
                                                  "y": y,
                                                  "game": obj,
                                                  "loadGamePage": loadGamePage
                                              })
    }

    function addGameCard() {
        createGameCard(xPositions[index], firstRowY, objects[index])
        index = index + 1
    }

    Component.onCompleted: {
        for(var i = 0; i < objects.length; i++) {
            addGameCard()
        }
    }
}
