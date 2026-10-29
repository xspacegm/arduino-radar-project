# 📡 Arduino & Processing Tabanlı Mini Radar Sistemi

Bu proje, bir **HC-SR04 ultrasonik mesafe sensörünün** SG90 servo motor üzerine monte edilerek 0° - 180° açı aralığında tarama yapmasını ve elde edilen verilerin seri haberleşme (UART) üzerinden **Processing** arayüzüne aktarılarak gerçek zamanlı bir radar ekranında görselleştirilmesini sağlar.

Sistem, tespit edilen engelin mesafesine göre dinamik olarak uyarı LED'leri ve sesli uyarı (buzzer) mekanizmasını tetikler.

---

## 🛠️ Teknik Özellikler ve Kullanılan Teknolojiler

### Donanım Bileşenleri
* **Mikrodenetleyici:** Arduino Uno R3 (ATmega328P)
* **Mesafe Sensörü:** HC-SR04 Ultrasonik Sensör
* **Aktüatör:** SG90 Micro Servo Motor
* **Geri Bildirim:** Kırmızı/Yeşil LED, Buzzer, 220Ω Dirençler
* **Prototipleme:** Breadboard ve Jumper Kablolar

### Yazılım ve Geliştirme Ortamları
* **Gömülü Yazılım:** C / C++ (Arduino IDE)
* **Arayüz (GUI) Yazılımı:** Processing 4 (Java tabanlı)
* **Haberleşme:** UART (Serial) Protocol @ 9600 Baud Rate

---

## 🔌 Devre Şeması ve Pin Bağlantıları

| Bileşen | Arduino Uno Pini | Açıklama |
| :--- | :---: | :--- |
| **Servo Motor (Sinyal)** | `Pin 9` | PWM Kontrol Pini |
| **HC-SR04 (Trig)** | `Pin 10` | Tetikleme Pini |
| **HC-SR04 (Echo)** | `Pin 11` | Ses Dalgası Dönüş Pini |
| **Buzzer** | `Pin 8` | Sesli Uyarı Çıkışı |
| **Aşırı Uyarı LED (Kırmızı)** | `Pin 7` | Engel Yakın Uyarı |
| **Normal LED (Yeşil)** | `Pin 6` | Güvenli Bölge Göstergesi |

---

## 🚀 Kurulum ve Çalıştırma

### 1. Donanım Yazılımı (Arduino)
1. Arduino C/C++ kodunuzu Arduino IDE ile açın.
2. Arduino Uno kartınızı USB ile bilgisayarınıza bağlayın.
3. IDE üzerinden doğru **Kart** ve **COM Portunu** seçip kodu yükleyin.

### 2. Arayüz Yazılımı (Processing)
1. Processing IDE'yi bilgisayarınıza kurun ve açın.
2. Processing arayüz kodunuzu çalıştırın.
3. Kod içerisindeki seri port tanımını kendi sisteminize göre güncelleyin (`COM3` vb.).
4. **Run (Çalıştır)** butonuna basarak radar ekranını başlatın.

---

## 👨‍💻 Geliştirici

**Muharrem Hamit DUMAN**  
*Mekatronik Mühendisliği Öğrencisi | Fırat Üniversitesi*
