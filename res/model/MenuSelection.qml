import QtQuick 2.0

import "../element" as Elements

ListModel {
    ListElement {
        name: "Now Playing"
        featherCode: 0xe89d
        view: "TrackInfo"
    }
    ListElement {
        name: "Search"
        featherCode: 0xe8bd
        view: "UnderConstruction"
    }
    ListElement {
        name: "Radio"
        featherCode: 0xe8b5
        view: "UnderConstruction"
    }
    ListElement {
        name: "Settings"
        featherCode: 0xe8c3
        view: "UnderConstruction"
    }

}
