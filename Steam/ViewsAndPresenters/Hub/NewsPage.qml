import QtQuick 2.14
import QtQuick.Window 2.14
import QtQuick.Controls 2.14
import QtQuick.Layouts 1.14
import QtGraphicalEffects 1.14

Item {
    property var changeParentHeight

    ListView {
        id: newsListView
        anchors.fill: parent
        spacing: 10
        model:28
        delegate: NewsComponent {


        }
        Component.onCompleted: {
            changeParentHeight(newsListView.contentHeight)
        }
    }
}
