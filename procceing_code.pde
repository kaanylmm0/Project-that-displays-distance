import processing.serial.*;

Serial myPort;  
String data = "";
PFont myFont;

void setup() {
  size(1366, 900); // Window size
  myPort = new Serial(this, "COM4", 9600);  // start serial port
  myPort.bufferUntil('\n');
  myFont = createFont("Arial", 50);  // Create font
  textFont(myFont);  // Set font
}

void draw() {
  // gradient background
  for (int y = 0; y < height; y++) {
    float inter = map(y, 0, height, 0, 1);
    int c = lerpColor(color(0, 0, 50), color(0, 0, 200), inter);
    stroke(c);
    line(0, y, width, y);
  }
  
  textAlign(CENTER, CENTER);  // center text
  fill(#4B5DCE);  // text color
  textSize(80);   // text size
  text("Arduino Verisi", width/2, 100);  // Title
  fill(255);      // text color
  textSize(60);   // text size
  text(data, width/2, height/2);  // print data
}

void serialEvent(Serial myPort) {
  data = myPort.readStringUntil('\n');  // Receive data from serial port
}
