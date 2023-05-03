import QtQuick 2.0
import QtLocation 5.6
import QtPositioning 5.6
import QtQuick.Controls 2.0
import QtQuick.Controls.Styles 1.4


Rectangle {

    id: window
    property MapQuickItem marker: null
    property double oldLat: 36.8065
    property double oldLng: 10.1815

    property Component comMarker: mapMarker

    Plugin {
        id: mapPlugin
        name: "osm"
    }

    Map {
        id: mapView
        anchors.fill: parent
        plugin: mapPlugin
        center: QtPositioning.coordinate(oldLat, oldLng);
        zoomLevel: 8
    }
    Row {
           spacing: 10
           anchors {
               top: parent.top
               left: parent.left
               right: parent.right
               margins: 10
           }

           Label {
               text: "Latitude:"
           }

           TextField {
               width: parent.width * 0.15
               id: latitudeField
               text: oldLat.toString()
               onTextChanged: {
                   oldLat = parseFloat(text)
                   addMarker(oldLat, oldLng)
               }
           }

           Label {
               text: "Longitude:"
           }

           TextField {
               width: parent.width * 0.15
               id: longitudeField
               text: oldLng.toString()
               onTextChanged: {
                   oldLng = parseFloat(text)
                   addMarker(oldLat, oldLng)
               }
           }
       }

    function setCenter(lat, lng) {
        mapView.pan(oldLat - lat, oldLng - lng)
        oldLat = lat
        oldLng = lng
    }

    function addMarker(lat, lng, label, unit) {
        if(marker !== null) {
            mapView.removeMapItem(marker)
            marker.destroy()
        }
        var item = comMarker.createObject(window, {
            coordinate: QtPositioning.coordinate(lat, lng),
            markerLabel: unit
        })
        mapView.addMapItem(item)
        marker = item // store reference to the added marker

    }

    Component {
        id: mapMarker
                MapQuickItem {
                    id: markerImg
                    anchorPoint.x: image.width/4
                    anchorPoint.y: image.height
                    coordinate: position

                    sourceItem: Image {
                        id: image
                        source: "http://maps.gstatic.com/mapfiles/ridefinder-images/mm_20_red.png"
                    }
                }
    }
}
