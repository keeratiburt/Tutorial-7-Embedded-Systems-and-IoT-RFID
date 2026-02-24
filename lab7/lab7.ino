// นำเข้า Libraries
#include <SPI.h>
#include <MFRC522.h>

// กำหนด pin ที่ต้องใช้
#define SS_PIN 21
#define RST_PIN 0

//Variables
byte nuidPICC[4] = {0, 0, 0, 0};
MFRC522::MIFARE_Key key;
MFRC522 rfid = MFRC522(SS_PIN, RST_PIN);

void setup() {
  //เริ่มต้นการทำงานของ Serial
  Serial.begin(115200);
  Serial.println(F("เริ่มการทำงาน"));
  
  //เริ่มต้นการทำงานของ RFID และการส่งข้อมูลผ่าน Serial
  SPI.begin();
  rfid.PCD_Init();

  // แสดงเวอร์ชันของ firmware
  Serial.print(F("Reader :"));
  rfid.PCD_DumpVersionToSerial();
}

void loop() {
  readRFID();
}

void readRFID(void ) { // ฟังก์ชันสำหรับการอ่าน tag
  //// อ่าน (Read) RFID card

  for (byte i = 0; i < 6; i++) {
    key.keyByte[i] = 0xFF;
  }
  // เงื่อนไขหากพบ tag
  if ( ! rfid.PICC_IsNewCardPresent())
    return;

  // เงื่อนไขหากตรวจพบ tag id
  if (  !rfid.PICC_ReadCardSerial())
    return;

  // บันทึกค่า tag id
  for (byte i = 0; i < 4; i++) {
    nuidPICC[i] = rfid.uid.uidByte[i];
  }

  // แสดง tag id ผ่าน serial monitor
  Serial.print(F("หมายเลข RFID แบบฐานสิบ: "));
  printDec(rfid.uid.uidByte, rfid.uid.size);
  Serial.println();

  // หยุดการทำงาน
  rfid.PICC_HaltA();

  // หยุดการเข้ารหัส
  rfid.PCD_StopCrypto1();

}

/**
   ฟังก์ชันในการนำค่า ID ที่เป็นเลขฐาน 10 ส่งผ่านช่องทาง Serial
*/
void printDec(byte *buffer, byte bufferSize) {
  for (byte i = 0; i < bufferSize; i++) {
    Serial.print(buffer[i] < 0x10 ? " 0" : " ");
    Serial.print(buffer[i], DEC);
  }
}
