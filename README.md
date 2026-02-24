# Tutorial-7-Embedded-Systems-and-IoT-RFID
การใช้งาน RFID (Radio Frequency Identification)


Objectives
1. เขียนโปรแกรมเพื่ออ่านบัตรจาก RFID tag ได้

Hardware
1.	ESP32                 1	        
2.	RFID module (RC522)		1
3.	Breadboard            1
4.	Computer	            1
5.	microUSB	            1 

Software
1. Arduino IDE v
--------------------
Instruction

1. ต่อสาย ESP32 กับ โมดูล RFID RC522 ดังนี้
  - SDA > GPIO21
  - SCK > SCK
  - MOSI > MOSI
  - MISO > MISO
  - GND > GND
  - RST > GPIO 00
  - 3v3 > 3v3
2. ติดตั้ง library ของ RFID module โดยพิมพ์คำว่า MFRC522 ในช่องค้นหา library แล้วเลือกติดตั้ง "MFRC522 by GithubCommunity" เวอร์ชัน 1.4.10
3. ดาวน์โหลดโค้ดจากไฟล์ lab7.ino
4. อัพโหลดโค้ดและทดสอบโดยการนำ tag ไปสแกนและดูหมายเลขของ tag ผ่าน serial monitor


โมดูล RC522 เป็นโมดูล RFID (Radio-Frequency Identification) ที่ทำงานอยู่บนการสื่อสารผ่านโปรโตคอล SPI (Serial Peripheral Interface) โดยประกอบไปด้วยตัวอ่าน (Reader/controller) และแท็ก (Tag) โดย reader/controller ทำหน้าที่เป็น Master และ tag ทำหน้าที่เป็น Slave ในระบบการทำงานแบบ Master/Slave<br> <br>

Master (Reader): ทำหน้าที่ในการควบคุมการทำงานของระบบโดยรวมโดยทั่วไปจะเป็นในส่วนของการอ่าน tag รวมไปถึง microcontroller<br>
Slave (RC522 RFID Module): เป็นอุปกรณ์ที่จะตอบสนองโดยการส่งข้อมูลของ tag ไปยัง master<br>

SDA <br>
คือ Serial Data คือขาสัญญาณสำหรับรับ/ส่งข้อมูล <br>
SCK <br>
คือ Serial Clock คือขาสัญญาณนาฬิกา ใช้เพื่อทำการ synchronize การรับส่งข้อมูลระหว่างอุปกรณ์ <br>
MOSI <br>
คือ Master Out Slave In หมายถึงอุปกรณ์ที่เป็น master ส่งข้อมูลให้อุปกรณ์ที่เป็น slave ผ่านช่องทางนี้ <br>
MISO <br>
คือ Master In Slave Out หมายถึงอุปกรณ์ที่เป็น slave ส่งข้อมูลให้อุปกรณ์ที่เป็น master ผ่านช่องทางนี้ <br>
