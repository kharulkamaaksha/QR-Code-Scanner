import cv2
import numpy as np
import qrcode
import winsound
import time

def show_message_image(message, color, image_name):
    print(f"Displaying message: {message}")
    width, height = 640, 480
    image = np.full((height, width, 3), color, dtype=np.uint8)
    font = cv2.FONT_HERSHEY_SIMPLEX
    font_scale = 1
    font_thickness = 2
    text_color = (0, 0, 0)
    text_size = cv2.getTextSize(message, font, font_scale, font_thickness)[0]
    x = int((width - text_size[0]) / 2)
    y = int((height + text_size[1]) / 2)
    cv2.putText(image, message, (x, y), font, font_scale, text_color, font_thickness, lineType=cv2.LINE_AA)
    cv2.imwrite(image_name, image)
    cv2.imshow(message, image)
    cv2.waitKey(0)
    cv2.destroyAllWindows()

def play_builtin_alarm():
    try:
        frequency = 1000  # in Hz
        duration = 5000   # in milliseconds (5 seconds)
        winsound.Beep(frequency, duration)
    except RuntimeError:
        print("Failed to play alarm")

def create_qr_image(qr_text):
    print(f"Creating QR image for: {qr_text}")
    qr = qrcode.QRCode(
        version=1,
        error_correction=qrcode.constants.ERROR_CORRECT_L,
        box_size=10,
        border=4,
    )
    qr.add_data(qr_text)
    qr.make(fit=True)
    qr_img = qr.make_image(fill_color="black", back_color="white")
    qr_img.show()

def read_qr_code(frame):
    detector = cv2.QRCodeDetector()
    try:
        val, _, _ = detector.detectAndDecode(frame)
        print(f"Decoded value: {val}")
    except cv2.error as e:
        print("Error while detecting QR code:", e)
        return frame

    if val:
        qr_text = val.strip()
        if qr_text:
            print(f"QR Code content: {qr_text}")

            # Define the QR code content to match
            predefined_qr_codes = {"ROYALS", "CITIZEN", "SOLDIERS"}

            if qr_text in predefined_qr_codes:
                print("Recognized QR Code:", qr_text)
                print("ACCESS GRANTED")
                show_message_image("ACCESS GRANTED", (0, 255, 0), "access_granted.png")
            else:
                print("Unrecognized QR Code:", qr_text)
                print("ACCESS DENIED")
                show_message_image("ACCESS DENIED", (0, 0, 255), "access_denied.png")
                play_builtin_alarm()
                time.sleep(2)

            # Create and display QR code image
            create_qr_image(qr_text)
        else:
            print("Empty QR Code content")
    else:
        print("No QR Code detected")

    return frame

# Open the webcam
cap = cv2.VideoCapture(0)

if not cap.isOpened():
    print("Error: Could not open webcam.")
else:
    print("Webcam successfully opened.")

while True:
    ret, frame = cap.read()

    if not ret:
        print("Failed to grab frame.")
        break

    frame = read_qr_code(frame)

    cv2.imshow("QR Code Scanner", frame)

    key = cv2.waitKey(1)
    if key == 27 or key == ord('q'):
        print("Exiting...")
        break

cap.release()
cv2.destroyAllWindows()
