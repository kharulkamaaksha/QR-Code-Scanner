**Introduction:**
This project implements a Real-Time QR Code Scanner using OpenCV and QRCode libraries in Python. The system reads QR codes from a live webcam feed, checks the QR code content against predefined values, and provides access accordingly. The program also displays messages for "Access Granted" or "Access Denied" based on the code content and generates an alarm for unrecognized QR codes.

**Features:**
  1. Real-time QR Code Detection: Continuously scans the live webcam feed for QR codes.
  2. Access Control: Grants or denies access based on predefined QR code content.
  3. Visual Notifications: Displays "ACCESS GRANTED" or "ACCESS DENIED" on the screen.
  4. Alarm System: Plays a buzzer sound for denied access.
  5. Cross-Platform Support: Works on Windows and Linux

**Installation:**
  Prerequisites:
    1.Python 3.x installed on your system
    2. Webcam connected to your system
  Steps to Install:
    1. Clone the repository: git clone https://github.com/yourusername/qr-code-scanner-access-control.git
                             cd qr-code-scanner-access-control
    2. Install the required dependencies: pip install -r requirements.txt
                                          or manually do pip install numpy/qrcode/time and other required libraries
    3. Run the script: python qr_code_scanner.py

**Usage:**
  Once the script is running, the webcam feed will open, and the system will continuously scan for QR codes.
  1. Access Granted: If a QR code contains one of the predefined access values (ROYALS, CITIZEN, SOLDIERS), the system will display "ACCESS GRANTED".
  2. Access Denied: For unrecognized QR codes, the system will display "ACCESS DENIED" and play an alarm sound.
  3. Exit: To stop the script, press q or Esc.

**Working Flow:**
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

**Future Plans:**
  1. Database Integration: Add a database to store authorized QR codes, access logs, and user information, allowing for more dynamic access control management.
  2. Multi-Level Access Control: Implement different access levels (e.g., Admin, User, Guest) based on the QR code content, offering more granular control over permissions.
  3. Email/SMS Notifications: Send alerts when access is denied or granted to a predefined email or phone number.

**Contribution:**
  1. Fork the project: Click the gray Fork button at the top right of the previous page. This creates your copy of the project and saves it as a new repository in your GitHub account.
  
  2. Clone this project on your computer: Go to your profile. You will find forked repo named eventTimer. go to the repo by clicking on it.
     Click on the green Code button, then either the HTTPS or SSH option, and, click the icon to copy the URL. Now you have a copy of the project. Thus, you can play around with it locally on your computer.
     git clone https://github.com/<your-github-username>/qr_scanner.git
     Switch to the cloned folder. You can paste this command into the same terminal window.
     cd QR_scanner

  3. Open in code Editor: Open the README.md File: Use your code editor (like VS Code) to open the README.md file.

  4. Create a new branch: A branch name can represent the changes you're making. A good practice is to use your GitHub username for the branch name to make it unique.
   To create a new branch, run the following command in your terminal:
   git checkout -b <name-of-new-branch>

  5. Edit the File: Make the required changes to the code as per the issue told
   For example - [Full Name](https://github.com/your-username)
   Stage your changes:
   git add README.md
   or
   git add .

  7. Commit the changes:
   git commit -m "Add <your-github-username>"
   Check the status of your repository.
   git status
  
  8. Pushing your repository to GitHub:
   git push origin <name-of-your-branch>
   or
   git branch -M main
   git push -u origin main
   Warning: If you get an error message like the one below, you probably forgot to fork the repository before cloning it. It is best to start over and fork the project repository first.
   ERROR: Permission to https://github.com/QR-code-scanner/qr_scanner.git denied to <your-github-username>.
   fatal: Could not read from remote repository.
   Please make sure you have the correct access rights and that the repository exists.

  9. Raise a Pull Request:
   On the GitHub website, navigate to your forked repo - on the top of the files section, you'll notice a new section containing a Compare & Pull Request button!
   Click on that button, this will load a new page, comparing the local branch in your forked repository against the main branch QR-code-scanner repository. Do not make any changes in the selected             
   values of the branches (do so only if needed), and click the green Create Pull Request button. Note: A pull request allows us to merge your changes with the original project repo.
   Your pull request will be reviewed and then eventually merged.
   Hurray! You successfully made your first contribution! 

**Author:**
Kamaaksha Rajendra Kharul
