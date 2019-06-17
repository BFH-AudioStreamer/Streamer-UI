import QtQuick 2.0
import QtQuick.Controls 2.4
import QtQuick.Layouts 1.12

import "../element/" as Elements

Page {
    id: underConstruction

    ColumnLayout {
        spacing: 20

        Elements.FeatherButton {
            Layout.bottomMargin: 20
            width: 50
            height: 50
            iconCode: Elements.Feather.Icons.ArrowLeftCircle
            onClicked: underConstruction.StackView.view.pop()
        }

        Label {
            text: "Feature under construction ..."
            font.pointSize: 26
            //color: Material.primary
        }
    }
}
