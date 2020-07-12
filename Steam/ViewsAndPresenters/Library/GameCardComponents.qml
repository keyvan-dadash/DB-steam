import QtQuick 2.14
import QtQuick.Window 2.14
import QtQuick.Controls 2.14
import QtQuick.Layouts 1.14
import QtQuick.Controls.Styles 1.4

Item {

    id: item
    width: 135
    height: 200
    property var posIndex
    property var previewComponentWidth: 260
    property var previewComponentHeight: 320
    property var gamePreViewComponent
    property var gamePreViewComponentObj

    //list for game name and image lists
    property var images
    property var gameName
    property var totalGamePlay


    function getXPos(index) {
        var x
        if (index % 4 == 0 || index % 4 == 1) {
            x = this.x + this.width + 10
        } else {
            x = this.x - (previewComponentWidth + 10)
        }
        return x
    }

    function getYPos(index){
        return this.y - ((previewComponentHeight - this.height) / 2)
    }

    function createGamePreView() {
        gamePreViewComponent = Qt.createComponent("GamePreViewComponent.qml")
        if (gamePreViewComponent.status == Component.Ready)
            finishCreation();
        else
            gamePreViewComponent.statusChanged.connect(finishCreation);
    }

    function finishCreation() {
        if (gamePreViewComponent.status == Component.Ready) {
            var xLocal = getXPos(index)
            var yLocal = getYPos(index)
            gamePreViewComponentObj = gamePreViewComponent.createObject(item.parent, {
                                                                            xPos: xLocal,
                                                                            yPos: yLocal,
                                                                            z: 10,
                                                                            images: images,
                                                                            gameName: gameName,
                                                                            totalGamePlay: totalGamePlay
                                                                        });
            if (gamePreViewComponentObj == null) {
                console.log("Error creating object");
            } else if (gamePreViewComponent.status == Component.Error) {
                console.log("Error loading gamePreViewComponent:", gamePreViewComponent.errorString());
            }
        }
    }

    function destroyGamePreView() {
        if (gamePreViewComponentObj != undefined) {
            gamePreViewComponentObj.destroy()
        }
    }

    Timer {
        id: changeImageTimer
        interval: 1000
        running: false
        repeat: true
        onTriggered: {
            gamePreViewComponentObj.nextImage()
        }
    }

    Image {
        id: gameImage
        anchors.fill: parent
        source: images[0]
        z: 3
        MouseArea {
            anchors.fill: parent
            hoverEnabled: true
            onEntered: {
                parent.parent.width = parent.parent.width + 5
                parent.parent.height = parent.parent.height + 10
                createGamePreView()
                changeImageTimer.restart()
            }
            onExited: {
                parent.parent.width = parent.parent.width - 5
                parent.parent.height = parent.parent.height - 10
                destroyGamePreView()
                changeImageTimer.stop()
            }
        }
    }
}
