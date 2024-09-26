Introduction:
This project implements a Real-Time QR Code Scanner using OpenCV and QRCode libraries in Python. The system reads QR codes from a live webcam feed, checks the QR code content against predefined values, and provides access accordingly. The program also displays messages for "Access Granted" or "Access Denied" based on the code content and generates an alarm for unrecognized QR codes.

Features:
  1. Real-time QR Code Detection: Continuously scans the live webcam feed for QR codes.
  2. Access Control: Grants or denies access based on predefined QR code content.
  3. Visual Notifications: Displays "ACCESS GRANTED" or "ACCESS DENIED" on the screen.
  4. Alarm System: Plays a buzzer sound for denied access.
  5. Cross-Platform Support: Works on Windows and Linux

Installation:
  Prerequisites:
    1.Python 3.x installed on your system
    2. Webcam connected to your system
  Steps to Install:
    1. Clone the repository: git clone https://github.com/yourusername/qr-code-scanner-access-control.git
                             cd qr-code-scanner-access-control
    2. Install the required dependencies: pip install -r requirements.txt
                                          or manually do pip install numpy/qrcode/time and other required libraries
    3. Run the script: python qr_code_scanner.py

Usage:
  Once the script is running, the webcam feed will open, and the system will continuously scan for QR codes.
  1. Access Granted: If a QR code contains one of the predefined access values (ROYALS, CITIZEN, SOLDIERS), the system will display "ACCESS GRANTED".
  2. Access Denied: For unrecognized QR codes, the system will display "ACCESS DENIED" and play an alarm sound.
  3. Exit: To stop the script, press q or Esc.

Working Flow:
  1. First we import the libraries:
     cv2: Used for video capture, QR code detection, and image processing.
     numpy: For creating and manipulating images (arrays).
     qrcode: For generating QR codes from the decoded content.
     winsound: Used to trigger an alarm sound (Windows only).
     time: For adding delays in execution.
  2. Webcam is opened using cap = cv2.VideoCapture(0). If the webcam fails to open, an error message is displayed "Error: Could not open webcam."
  3. The code enters an infinite loop (while True:).
     Frame Capture: Each frame is grabbed using ret, frame = cap.read().
     If the frame is successfully captured (ret is True), it proceeds with QR code detection.
     If frame capture fails, the loop breaks.
  4. Function: read_qr_code(frame)
     Uses cv2.QRCodeDetector() to detect and decode the QR code in the frame. If a QR code is detected and successfully decoded, it prints the decoded value (val).
     If no QR code is detected, the frame is returned without modification.
  5. The decoded QR code text is compared against a predefined set of valid QR codes: {"ROYALS", "CITIZEN", "SOLDIERS"}.
     If the QR code content matches one of the predefined values: The message "ACCESS GRANTED" is displayed in a green image.
     If the QR code content does not match: The message "ACCESS DENIED" is displayed in a red image, and an alarm is triggered. The play_builtin_alarm() triggers a sound alarm using winsound.Beep() (Windows).
  6. Exit Condition: The loop continues until the user presses the Esc key (key == 27) or the q key (key == ord('q')). When the key is pressed, the program breaks the loop and releases the webcam using           
     cap.release(). The program also closes all OpenCV windows using cv2.destroyAllWindows().

Future Plans:
  1. Database Integration: Add a database to store authorized QR codes, access logs, and user information, allowing for more dynamic access control management.
  2. Multi-Level Access Control: Implement different access levels (e.g., Admin, User, Guest) based on the QR code content, offering more granular control over permissions.
  3. Email/SMS Notifications: Send alerts when access is denied or granted to a predefined email or phone number.

Author:
Kamaaksha Rajendra Kharul
