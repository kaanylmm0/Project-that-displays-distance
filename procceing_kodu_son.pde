import processing.serial.*;

Serial myPort;  
String data = "";
PFont myFont;

void setup() {
  size(1366, 900); // Pencere boyutu
  myPort = new Serial(this, "COM4", 9600);  // Seri portu başlat
  myPort.bufferUntil('\n');
  myFont = createFont("Arial", 50);  // Yazı tipi oluştur
  textFont(myFont);  // Yazı tipini ayarla
}

void draw() {
  // Gradyan arka plan
  for (int y = 0; y < height; y++) {
    float inter = map(y, 0, height, 0, 1);
    int c = lerpColor(color(0, 0, 50), color(0, 0, 200), inter);
    stroke(c);
    line(0, y, width, y);
  }
  
  textAlign(CENTER, CENTER);  // Metni ortala
  fill(#4B5DCE);  // Yazı rengi
  textSize(80);   // Yazı boyutu
  text("Arduino Verisi", width/2, 100);  // Başlık
  fill(255);      // Metin rengi
  textSize(60);   // Metin boyutu
  text(data, width/2, height/2);  // Veriyi yazdır
}

void serialEvent(Serial myPort) {
  data = myPort.readStringUntil('\n');  // Seri olayında gelen veriyi al
}
