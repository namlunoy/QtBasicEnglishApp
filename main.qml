import QtQuick 2.6
import QtQuick.Controls 1.5

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    menuBar: MenuBar {
        Menu {
            title: qsTr("File")
            MenuItem {
                text: qsTr("&Open")
                onTriggered: console.log("Open action triggered");
            }
            MenuItem {
                text: qsTr("Exit")
                onTriggered: Qt.quit();
            }
        }
    }

    Label {
        id: label1
        x: 31
        y: 19
        text: qsTr("URL:")
    }

    TextField {
        id: txtUrl
        x: 76
        y: 16
        width: 466
        height: 22
        placeholderText: qsTr("Text Field")
    }

    Button {
        id: btGet
        x: 548
        y: 14
        text: qsTr("GET")
        onClicked: {
            txtResult.text = ui.getResult(txtUrl.text, txtStt.text)
        }
    }

    TextArea {
        id: txtResult
        x: 31
        y: 71
        width: 577
        height: 378
    }

    TextField {
        text: "1"
        id: txtStt
        x: 76
        y: 44
        placeholderText: qsTr("Text Field")
    }

    Label {
        id: label2
        x: 31
        y: 47
        text: qsTr("STT")
    }
}
