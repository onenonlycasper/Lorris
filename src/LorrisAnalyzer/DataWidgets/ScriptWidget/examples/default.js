// You can use clearTerm() and appendTerm(string) to set term content
// You can use sendData(Array of ints) to send data to device. It expects array of uint8s

// This function gets called on data received
// it should return string, which is automatically appended to terminal
function onDataChanged(data, dev, cmd, index) {
    return "";
}

// This function is called on key press in terminal.
// Param is string
function onKeyPress(key) {

}