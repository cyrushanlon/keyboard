#include "Keyboard.h"

int layout[11][6] = {
    {'`', KEY_TAB, KEY_ESC, KEY_LEFT_SHIFT, KEY_LEFT_CTRL, KEY_LEFT_GUI},
    {'1', '2', 'q', 'a', '\\', 'z'},
    {'3', 'w', 's', 'x', KEY_LEFT_ALT, ' '},
    {'4', 'e', 'd', 'c', 'v', 'b'},
    {'5', '6', 'r', 't', 'f', 'g'},
    {'7', '8', 'y', 'u', 'h', 'n'},
    {'9', 'i', 'j', 'k', 'm', ','},
    {'0', 'o', 'l', '.', KEY_CAPS_LOCK, KEY_DELETE},
    {'-', 'p', ';', '/', KEY_HOME, KEY_LEFT_ARROW},
    {'=', '[', '\'', '#', KEY_UP_ARROW, KEY_DOWN_ARROW},
    {KEY_BACKSPACE, ']', KEY_RETURN, KEY_END, KEY_RIGHT_ARROW},
};

int fnLayout[11][6] = {
    {'`', KEY_TAB, KEY_ESC, KEY_LEFT_SHIFT, KEY_LEFT_CTRL, KEY_LEFT_GUI},
    {KEY_F1, KEY_F2, 'q', 'a', '\\', 'z'},
    {KEY_F3, 'w', 's', 'x', KEY_LEFT_ALT, ' '},
    {KEY_F4, 'e', 'd', 'c', 'v', 'b'},
    {KEY_F5, KEY_F6, 'r', 't', 'f', 'g'},
    {KEY_F7, KEY_F8, 'y', 'u', 'h', 'n'},
    {KEY_F9, 'i', 'j', 'k', 'm', ','},
    {KEY_F10, 'o', 'l', '.', KEY_CAPS_LOCK, KEY_DELETE},
    {KEY_F11, 'p', ';', '/', KEY_HOME, KEY_LEFT_ARROW},
    {KEY_F12, '[', '\'', '#', KEY_UP_ARROW, KEY_DOWN_ARROW},
    {KEY_BACKSPACE, ']', KEY_RETURN, KEY_END, KEY_RIGHT_ARROW},
};

bool pressed[11][6];

int cols[11] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 0, 1};
int rows[6] = {16, 14, 15, 18, 20, 19};

const int colCount = sizeof(cols) / sizeof(cols[0]);
const int rowCount = sizeof(rows) / sizeof(rows[0]);

bool fnPressed = false;

void setup()
{
    // Open serial communications and wait for port to open:
    Serial.begin(9600);

    for (int i = 0; i < colCount; i++)
    {
        pinMode(cols[i], INPUT);
    }

    for (int i = 0; i < rowCount; i++)
    {
        pinMode(rows[i], INPUT_PULLUP);
    }

    Keyboard.begin();
}

void clearFN()
{
    for (int y = 0; y < rowCount; y++)
    {
        for (int x = 0; x < colCount; x++)
        {
            Keyboard.release(layout[x][y]);
            Keyboard.release(fnLayout[x][y]);
        }
    }
}

void loop()
{
    // loop through rows and set high, read col for high
    for (int y = 0; y < rowCount; y++)
    {
        for (int x = 0; x < colCount; x++)
        {
            pinMode(cols[x], INPUT);
            pinMode(rows[y], OUTPUT);
            digitalWrite(rows[y], HIGH);

            //check fn key is pressed
            bool shouldSend = true;
            int key = layout[x][y];
            // we dont want to send fn, and we want to get the key from the fnLayout array

            if (digitalRead(cols[x]) == 1 && !pressed[x][y])
            {
                pressed[x][y] = true;

                if (key == KEY_CAPS_LOCK)
                {
                    clearFN();
                    fnPressed = true;
                }
                else
                {
                    if (fnPressed)
                        key = fnLayout[x][y];

                    Keyboard.press(key);
                }
            }
            else if (digitalRead(cols[x]) == 0 && pressed[x][y])
            {
                pressed[x][y] = false;

                if (key == KEY_CAPS_LOCK)
                {
                    clearFN();
                    fnPressed = false;
                }
                else
                {
                    if (fnPressed)
                        key = fnLayout[x][y];

                    Keyboard.release(key);
                }
            }

            digitalWrite(rows[y], LOW);
            pinMode(cols[x], OUTPUT);
            pinMode(rows[y], INPUT);
        }
    }
}