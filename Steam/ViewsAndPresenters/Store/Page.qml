import QtQuick 2.0
import QtGraphicalEffects 1.0


Item {
    id: gameCard
    width: 1220
    height: 551

    property var objects : []

    property var index: 0

    property var firstRowY : 21
    property var secondRowY: 282

    property var xPositions: [49, 280, 514, 737, 969]

    function createGameCard(x, y, obj) {
        var component = Qt.createComponent("GameCardComponent.qml")
        var instance = component.createObject(gameCard, {
                                                  "x" : x,
                                                  "y": y,
                                                  "obj": obj
                                              })
    }

    function addGameCard() {
        if(index < 5) {
            createGameCard(xPositions[index], firstRowY, objects[index])
        } else {
            createGameCard(xPositions[index % xPositions.length], secondRowY, objects[index])
        }
        index = index + 1
    }

    Component.onCompleted: {
        for(var i = 0; i < objects.length; i++) {
            addGameCard()
        }
    }
}
