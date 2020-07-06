import QtQuick 2.14
import QtQuick.Window 2.14
import QtQuick.Controls 2.14
import QtQuick.Layouts 1.14
import QtGraphicalEffects 1.14

Item {
    width: 1200
    height: 480
    Rectangle {
        anchors.fill: parent
        color: '#0d131b'
    }

    Text {
        id: titleText
        x: 8
        y: 8
        width: 1184
        height: 31
        text: qsTr("Assassin's Creed Origins - 1.5.1 Patch Notes")
        font.pixelSize: 20
        color: '#fff'
        verticalAlignment: Text.AlignVCenter
    }

    Text {
        id: dateText
        x: 8
        y: 53
        width: 133
        height: 19
        text: qsTr('15 May, 2018')
        font.pixelSize: 12
        color: '#737271'
        verticalAlignment: Text.AlignVCenter
    }

    TextArea {
        id: contentTextArea
        x: 8
        y: 78
        width: 1184
        height: 400
        readOnly: true
        wrapMode: TextArea.Wrap
        font.pixelSize: 15
        color: "#8c8b8a"
        text: qsTr("Patch 1.5.1 is now live. Please see the latest changes below.

Patch Size
Steam: 590Mb

Patch Highlight:

Main Game: Fixed an issue where 'Serqet's Carapace' and 'Sting in the Tale' trophy/achievement wouldn't be unlocked after completing all Serqet locations
Discovery Tour: Added Brazilian Portuguese to the list of supported languages
ACP: Added a new “Uplay Recommends” preset, Hit’n’Roll, to the Animus Control Panel

Animus Control Panel

Highlight

Added a new 'Uplay Recommends' preset, Hit’n’Roll, to the Animus Control Panel
Quests

Fixed an issue during the 'A gift from the Gods' quest that could not be completed when using the 'Uplay Recommends' preset
Fixed an issue during the 'Plight of the Rebels' quest where players sometimes would not be able to complete the animal taming objective when the 'Uplay Recommends' preset is being used.
Fixed an issue during the 'The Oasis' quest where the quest objective wouldn't be updated when using the 'Uplay Recommends' preset
Activities
")
    }
}
